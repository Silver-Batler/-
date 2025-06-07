#include "../include/apiservice.h"
#include <QDebug>

ApiService::ApiService(QObject *parent)
    : QObject(parent)
{
    m_networkManager = new QNetworkAccessManager(this);
    m_baseUrl = QUrl("http://localhost/api/books/");
}

ApiService::~ApiService()
{
}

void ApiService::getBooks()
{
    QNetworkRequest request = createRequest("");
    QNetworkReply *reply = m_networkManager->get(request);
    
    connect(reply, &QNetworkReply::finished, this, &ApiService::onGetBooksFinished);
    connect(reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::errorOccurred),
            this, &ApiService::onNetworkError);
}

void ApiService::getBook(int id)
{
    QNetworkRequest request = createRequest(QString::number(id) + "/");
    QNetworkReply *reply = m_networkManager->get(request);
    
    connect(reply, &QNetworkReply::finished, this, &ApiService::onGetBookFinished);
    connect(reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::errorOccurred),
            this, &ApiService::onNetworkError);
}

void ApiService::createBook(const Book &book)
{
    QNetworkRequest request = createRequest("");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    
    QJsonDocument jsonDoc(book.toJson());
    QByteArray jsonData = jsonDoc.toJson();
    
    QNetworkReply *reply = m_networkManager->post(request, jsonData);
    
    connect(reply, &QNetworkReply::finished, this, &ApiService::onCreateBookFinished);
    connect(reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::errorOccurred),
            this, &ApiService::onNetworkError);
}

void ApiService::updateBook(const Book &book)
{
    QNetworkRequest request = createRequest(QString::number(book.id()) + "/");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    
    QJsonDocument jsonDoc(book.toJson());
    QByteArray jsonData = jsonDoc.toJson();
    
    QNetworkReply *reply = m_networkManager->put(request, jsonData);
    
    connect(reply, &QNetworkReply::finished, this, &ApiService::onUpdateBookFinished);
    connect(reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::errorOccurred),
            this, &ApiService::onNetworkError);
}

void ApiService::deleteBook(int id)
{
    QNetworkRequest request = createRequest(QString::number(id) + "/");
    QNetworkReply *reply = m_networkManager->deleteResource(request);
    
    // Store the ID in the reply's property for later use
    reply->setProperty("bookId", id);
    
    connect(reply, &QNetworkReply::finished, this, &ApiService::onDeleteBookFinished);
    connect(reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::errorOccurred),
            this, &ApiService::onNetworkError);
}

void ApiService::onGetBooksFinished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) {
        return;
    }
    
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        
        if (jsonDoc.isArray()) {
            QJsonArray jsonArray = jsonDoc.array();
            QList<Book> books;
            
            for (const QJsonValue &value : jsonArray) {
                if (value.isObject()) {
                    Book book = Book::fromJson(value.toObject());
                    books.append(book);
                }
            }
            
            emit booksReceived(books);
        } else {
            emit errorOccurred("Invalid response format");
        }
    } else {
        handleNetworkError(reply);
    }
    
    reply->deleteLater();
}

void ApiService::onGetBookFinished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) {
        return;
    }
    
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        
        if (jsonDoc.isObject()) {
            Book book = Book::fromJson(jsonDoc.object());
            emit bookReceived(book);
        } else {
            emit errorOccurred("Invalid response format");
        }
    } else {
        handleNetworkError(reply);
    }
    
    reply->deleteLater();
}

void ApiService::onCreateBookFinished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) {
        return;
    }
    
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        
        if (jsonDoc.isObject()) {
            Book book = Book::fromJson(jsonDoc.object());
            emit bookCreated(book);
        } else {
            emit errorOccurred("Invalid response format");
        }
    } else {
        handleNetworkError(reply);
    }
    
    reply->deleteLater();
}

void ApiService::onUpdateBookFinished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) {
        return;
    }
    
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        
        if (jsonDoc.isObject()) {
            Book book = Book::fromJson(jsonDoc.object());
            emit bookUpdated(book);
        } else {
            emit errorOccurred("Invalid response format");
        }
    } else {
        handleNetworkError(reply);
    }
    
    reply->deleteLater();
}

void ApiService::onDeleteBookFinished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) {
        return;
    }
    
    if (reply->error() == QNetworkReply::NoError) {
        int bookId = reply->property("bookId").toInt();
        emit bookDeleted(bookId);
    } else {
        handleNetworkError(reply);
    }
    
    reply->deleteLater();
}

void ApiService::onNetworkError(QNetworkReply::NetworkError)
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (reply) {
        handleNetworkError(reply);
    }
}

QNetworkRequest ApiService::createRequest(const QString &endpoint)
{
    QUrl url = m_baseUrl;
    if (!endpoint.isEmpty()) {
        url = QUrl(m_baseUrl.toString() + endpoint);
    }
    
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::UserAgentHeader, "BookClient/1.0");
    return request;
}

void ApiService::handleNetworkError(QNetworkReply *reply)
{
    QString errorMessage = reply->errorString();
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    
    if (statusCode > 0) {
        errorMessage = QString("Network error: %1 (HTTP %2)").arg(errorMessage).arg(statusCode);
    } else {
        errorMessage = QString("Network error: %1").arg(errorMessage);
    }
    
    emit errorOccurred(errorMessage);
}

