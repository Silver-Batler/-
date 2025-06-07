#include "../include/bookdialog.h"
#include "ui_bookdialog.h"
#include <QIntValidator>
#include <QDoubleValidator>
#include <QPushButton>
#include <QMessageBox>

BookDialog::BookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookDialog)
{
    ui->setupUi(this);
    
    setupValidators();
    fillGenreComboBox();
    
    connect(ui->titleLineEdit, &QLineEdit::textChanged, this, &BookDialog::validate);
    connect(ui->authorLineEdit, &QLineEdit::textChanged, this, &BookDialog::validate);
    connect(ui->yearLineEdit, &QLineEdit::textChanged, this, &BookDialog::validate);
    connect(ui->pagesLineEdit, &QLineEdit::textChanged, this, &BookDialog::validate);
    connect(ui->ratingLineEdit, &QLineEdit::textChanged, this, &BookDialog::validate);
    
    validate();
}

BookDialog::~BookDialog()
{
    delete ui;
}

void BookDialog::setBook(const Book &book)
{
    m_book = book;
    
    ui->titleLineEdit->setText(book.title());
    ui->authorLineEdit->setText(book.author());
    ui->yearLineEdit->setText(book.publicationYear() > 0 ? QString::number(book.publicationYear()) : "");
    ui->genreComboBox->setCurrentText(Book::genreDisplayName(book.genre()));
    ui->pagesLineEdit->setText(book.pages() > 0 ? QString::number(book.pages()) : "");
    ui->ratingLineEdit->setText(book.rating() > 0 ? QString::number(book.rating(), 'f', 1) : "");
    ui->bestsellerCheckBox->setChecked(book.isBestseller());
    
    if (book.id() > 0) {
        setWindowTitle("Редактирование книги");
    } else {
        setWindowTitle("Добавление новой книги");
    }
}

Book BookDialog::book() const
{
    Book book = m_book;
    
    book.setTitle(ui->titleLineEdit->text());
    book.setAuthor(ui->authorLineEdit->text());
    book.setPublicationYear(ui->yearLineEdit->text().toInt());
    book.setGenre(Book::genreCodeFromDisplay(ui->genreComboBox->currentText()));
    book.setPages(ui->pagesLineEdit->text().toInt());
    book.setRating(ui->ratingLineEdit->text().toDouble());
    book.setIsBestseller(ui->bestsellerCheckBox->isChecked());
    
    return book;
}

void BookDialog::validate()
{
    bool isValid = !ui->titleLineEdit->text().isEmpty() &&
                   !ui->authorLineEdit->text().isEmpty() &&
                   !ui->yearLineEdit->text().isEmpty() &&
                   !ui->pagesLineEdit->text().isEmpty() &&
                   !ui->ratingLineEdit->text().isEmpty();
    
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(isValid);
}

void BookDialog::setupValidators()
{
    // Year validator (1000-2100)
    QIntValidator *yearValidator = new QIntValidator(1000, 2100, this);
    ui->yearLineEdit->setValidator(yearValidator);
    
    // Pages validator (1-10000)
    QIntValidator *pagesValidator = new QIntValidator(1, 10000, this);
    ui->pagesLineEdit->setValidator(pagesValidator);
    
    // Rating validator (0.0-10.0)
    QDoubleValidator *ratingValidator = new QDoubleValidator(0.0, 10.0, 1, this);
    ratingValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->ratingLineEdit->setValidator(ratingValidator);
}

void BookDialog::fillGenreComboBox()
{
    ui->genreComboBox->addItems(Book::genreDisplayNames());
}

