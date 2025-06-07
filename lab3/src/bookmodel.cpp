#include "../include/bookmodel.h"

BookModel::BookModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int BookModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    
    return m_books.size();
}

int BookModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    
    return ColumnCount;
}

QVariant BookModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_books.size())
        return QVariant();
    
    const Book &book = m_books.at(index.row());
    
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case Id:
            return book.id();
        case Title:
            return book.title();
        case Author:
            return book.author();
        case PublicationYear:
            return book.publicationYear();
        case Genre:
            return Book::genreDisplayName(book.genre());
        case Pages:
            return book.pages();
        case Rating:
            return QString::number(book.rating(), 'f', 1);
        case IsBestseller:
            return book.isBestseller() ? "Да" : "Нет";
        default:
            return QVariant();
        }
    } else if (role == Qt::TextAlignmentRole) {
        switch (index.column()) {
        case Id:
        case PublicationYear:
        case Pages:
            return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
        case Rating:
            return Qt::AlignCenter;
        default:
            return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
        }
    }
    
    return QVariant();
}

QVariant BookModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    
    if (orientation == Qt::Horizontal) {
        switch (section) {
        case Id:
            return "ID";
        case Title:
            return "Название";
        case Author:
            return "Автор";
        case PublicationYear:
            return "Год издания";
        case Genre:
            return "Жанр";
        case Pages:
            return "Страниц";
        case Rating:
            return "Рейтинг";
        case IsBestseller:
            return "Бестселлер";
        default:
            return QVariant();
        }
    }
    
    return QVariant();
}

void BookModel::setBooks(const QList<Book> &books)
{
    beginResetModel();
    m_books = books;
    endResetModel();
}

void BookModel::addBook(const Book &book)
{
    beginInsertRows(QModelIndex(), m_books.size(), m_books.size());
    m_books.append(book);
    endInsertRows();
}

void BookModel::updateBook(const Book &book)
{
    for (int i = 0; i < m_books.size(); ++i) {
        if (m_books[i].id() == book.id()) {
            m_books[i] = book;
            QModelIndex topLeft = index(i, 0);
            QModelIndex bottomRight = index(i, ColumnCount - 1);
            emit dataChanged(topLeft, bottomRight);
            break;
        }
    }
}

void BookModel::removeBook(int id)
{
    for (int i = 0; i < m_books.size(); ++i) {
        if (m_books[i].id() == id) {
            beginRemoveRows(QModelIndex(), i, i);
            m_books.removeAt(i);
            endRemoveRows();
            break;
        }
    }
}

Book BookModel::getBook(int row) const
{
    if (row >= 0 && row < m_books.size()) {
        return m_books.at(row);
    }
    return Book();
}

