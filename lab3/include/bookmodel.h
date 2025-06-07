#ifndef BOOKMODEL_H
#define BOOKMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include "book.h"

class BookModel : public QAbstractTableModel
{
    Q_OBJECT
    
public:
    enum Column {
        Id,
        Title,
        Author,
        PublicationYear,
        Genre,
        Pages,
        Rating,
        IsBestseller,
        ColumnCount
    };
    
    explicit BookModel(QObject *parent = nullptr);
    
    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    
    // Add/remove data:
    void setBooks(const QList<Book> &books);
    void addBook(const Book &book);
    void updateBook(const Book &book);
    void removeBook(int id);
    
    // Get book by index
    Book getBook(int row) const;
    
private:
    QList<Book> m_books;
};

#endif // BOOKMODEL_H

