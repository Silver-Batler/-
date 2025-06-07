#include "../include/book.h"
#include <QMap>

Book::Book()
    : m_id(0), m_title(""), m_author(""), m_publicationYear(0),
      m_genre(""), m_pages(0), m_rating(0.0), m_isBestseller(false)
{
}

Book::Book(int id, const QString &title, const QString &author, int publicationYear,
           const QString &genre, int pages, double rating, bool isBestseller)
    : m_id(id), m_title(title), m_author(author), m_publicationYear(publicationYear),
      m_genre(genre), m_pages(pages), m_rating(rating), m_isBestseller(isBestseller)
{
}

int Book::id() const
{
    return m_id;
}

QString Book::title() const
{
    return m_title;
}

QString Book::author() const
{
    return m_author;
}

int Book::publicationYear() const
{
    return m_publicationYear;
}

QString Book::genre() const
{
    return m_genre;
}

int Book::pages() const
{
    return m_pages;
}

double Book::rating() const
{
    return m_rating;
}

bool Book::isBestseller() const
{
    return m_isBestseller;
}

void Book::setId(int id)
{
    m_id = id;
}

void Book::setTitle(const QString &title)
{
    m_title = title;
}

void Book::setAuthor(const QString &author)
{
    m_author = author;
}

void Book::setPublicationYear(int year)
{
    m_publicationYear = year;
}

void Book::setGenre(const QString &genre)
{
    m_genre = genre;
}

void Book::setPages(int pages)
{
    m_pages = pages;
}

void Book::setRating(double rating)
{
    m_rating = rating;
}

void Book::setIsBestseller(bool isBestseller)
{
    m_isBestseller = isBestseller;
}

Book Book::fromJson(const QJsonObject &json)
{
    Book book;
    book.setId(json["id"].toInt());
    book.setTitle(json["title"].toString());
    book.setAuthor(json["author"].toString());
    book.setPublicationYear(json["publication_year"].toInt());
    book.setGenre(json["genre"].toString());
    book.setPages(json["pages"].toInt());
    book.setRating(json["rating"].toString().toDouble());
    book.setIsBestseller(json["is_bestseller"].toBool());
    return book;
}

QJsonObject Book::toJson() const
{
    QJsonObject json;
    if (m_id > 0) {
        json["id"] = m_id;
    }
    json["title"] = m_title;
    json["author"] = m_author;
    json["publication_year"] = m_publicationYear;
    json["genre"] = m_genre;
    json["pages"] = m_pages;
    json["rating"] = m_rating;
    json["is_bestseller"] = m_isBestseller;
    return json;
}

QString Book::genreDisplayName(const QString &genreCode)
{
    static QMap<QString, QString> genreMap = {
        {"fiction", "Художественная литература"},
        {"non_fiction", "Нехудожественная литература"},
        {"science", "Научная литература"},
        {"fantasy", "Фэнтези"},
        {"sci_fi", "Научная фантастика"},
        {"detective", "Детектив"},
        {"romance", "Романтика"},
        {"horror", "Ужасы"},
        {"other", "Другое"}
    };
    
    return genreMap.value(genreCode, "Неизвестный жанр");
}

QString Book::genreCodeFromDisplay(const QString &displayName)
{
    static QMap<QString, QString> reverseGenreMap = {
        {"Художественная литература", "fiction"},
        {"Нехудожественная литература", "non_fiction"},
        {"Научная литература", "science"},
        {"Фэнтези", "fantasy"},
        {"Научная фантастика", "sci_fi"},
        {"Детектив", "detective"},
        {"Романтика", "romance"},
        {"Ужасы", "horror"},
        {"Другое", "other"}
    };
    
    return reverseGenreMap.value(displayName, "other");
}

QStringList Book::genreDisplayNames()
{
    return {
        "Художественная литература",
        "Нехудожественная литература",
        "Научная литература",
        "Фэнтези",
        "Научная фантастика",
        "Детектив",
        "Романтика",
        "Ужасы",
        "Другое"
    };
}

