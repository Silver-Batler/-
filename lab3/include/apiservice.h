#ifndef APISERVICE_H
#define APISERVICE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrl>
#include "book.h"

class ApiService : public QObject
{
    Q_OBJECT
    
public:
    explicit ApiService(QObject *parent = nullptr);
    ~ApiService();
    
    void getBooks();
    void getBook(int id);
    void createBook(const Book &book);
    void updateBook(const Book &book);
    void deleteBook(int id);
    
signals:
    void booksReceived(const QList<Book> &books);
    void bookReceived(const Book &book);
    void bookCreated(const Book &book);
    void bookUpdated(const Book &book);
    void bookDeleted(int id);
    void errorOccurred(const QString &errorMessage);
    
private slots:
    void onGetBooksFinished();
    void onGetBookFinished();
    void onCreateBookFinished();
    void onUpdateBookFinished();
    void onDeleteBookFinished();
    void onNetworkError(QNetworkReply::NetworkError error);
    
private:
    QNetworkAccessManager *m_networkManager;
    QUrl m_baseUrl;
    
    QNetworkRequest createRequest(const QString &endpoint);
    void handleNetworkError(QNetworkReply *reply);
};

#endif // APISERVICE_H

