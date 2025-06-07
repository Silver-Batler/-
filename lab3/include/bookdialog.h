#ifndef BOOKDIALOG_H
#define BOOKDIALOG_H

#include <QDialog>
#include "book.h"

namespace Ui {
class BookDialog;
}

class BookDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit BookDialog(QWidget *parent = nullptr);
    ~BookDialog();
    
    void setBook(const Book &book);
    Book book() const;
    
private slots:
    void validate();
    
private:
    Ui::BookDialog *ui;
    Book m_book;
    
    void setupValidators();
    void fillGenreComboBox();
};

#endif // BOOKDIALOG_H

