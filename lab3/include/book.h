#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

class Book
{
public:
    Book();
    Book(int id, const QString &title, const QString &author, int publicationYear,
         const QString &genre, int pages, double rating, bool isBestseller);
    
    // Getters
    int id() const;
    QString title() const;
    QString author() const;
    int publicationYear() const;
    QString genre() const;
    int pages() const;
    double rating() const;
    bool isBestseller() const;
    
    // Setters
    void setId(int id);
    void setTitle(const QString &title);
    void setAuthor(const QString &author);
    void setPublicationYear(int year);
    void setGenre(const QString &genre);
    void setPages(int pages);
    void setRating(double rating);
    void setIsBestseller(bool isBestseller);
    
    // JSON conversion
    static Book fromJson(const QJsonObject &json);
    QJsonObject toJson() const;
    
    // Genre helpers
    static QString genreDisplayName(const QString &genreCode);
    static QString genreCodeFromDisplay(const QString &displayName);
    static QStringList genreDisplayNames();
    
private:
    int m_id;
    QString m_title;
    QString m_author;
    int m_publicationYear;
    QString m_genre;
    int m_pages;
    double m_rating;
    bool m_isBestseller;
};

#endif // BOOK_H

