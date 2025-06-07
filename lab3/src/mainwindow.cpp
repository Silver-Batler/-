#include "../include/mainwindow.h"
#include "ui_mainwindow.h"
#include "../include/bookdialog.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_apiService(new ApiService(this))
    , m_bookModel(new BookModel(this))
    , m_proxyModel(new QSortFilterProxyModel(this))
{
    ui->setupUi(this);
    setupUi();
    setupConnections();
    loadBooks();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUi()
{
    // Setup proxy model for filtering
    m_proxyModel->setSourceModel(m_bookModel);
    m_proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    m_proxyModel->setFilterKeyColumn(-1); // Search all columns
    
    // Setup table view
    ui->booksTableView->setModel(m_proxyModel);
    ui->booksTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->booksTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->booksTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->booksTableView->horizontalHeader()->setStretchLastSection(true);
    ui->booksTableView->verticalHeader()->setVisible(false);
    ui->booksTableView->setSortingEnabled(true);
    
    // Hide ID column
    ui->booksTableView->hideColumn(BookModel::Id);
    
    // Set column widths
    ui->booksTableView->setColumnWidth(BookModel::Title, 200);
    ui->booksTableView->setColumnWidth(BookModel::Author, 150);
    ui->booksTableView->setColumnWidth(BookModel::PublicationYear, 100);
    ui->booksTableView->setColumnWidth(BookModel::Genre, 150);
    ui->booksTableView->setColumnWidth(BookModel::Pages, 80);
    ui->booksTableView->setColumnWidth(BookModel::Rating, 80);
    ui->booksTableView->setColumnWidth(BookModel::IsBestseller, 80);
    
    // Setup toolbar
    ui->mainToolBar->addAction(ui->actionAdd);
    ui->mainToolBar->addAction(ui->actionEdit);
    ui->mainToolBar->addAction(ui->actionDelete);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(ui->actionRefresh);
    
    // Setup status bar
    statusBar()->showMessage("Готово");
}

void MainWindow::setupConnections()
{
    // Connect API service signals
    connect(m_apiService, &ApiService::booksReceived, this, &MainWindow::onBooksReceived);
    connect(m_apiService, &ApiService::bookCreated, this, &MainWindow::onBookCreated);
    connect(m_apiService, &ApiService::bookUpdated, this, &MainWindow::onBookUpdated);
    connect(m_apiService, &ApiService::bookDeleted, this, &MainWindow::onBookDeleted);
    connect(m_apiService, &ApiService::errorOccurred, this, &MainWindow::onErrorOccurred);
    
    // Connect double-click on table to edit action
    connect(ui->booksTableView, &QTableView::doubleClicked, this, &MainWindow::on_actionEdit_triggered);
}

void MainWindow::loadBooks()
{
    statusBar()->showMessage("Загрузка данных...");
    m_apiService->getBooks();
}

void MainWindow::showError(const QString &message)
{
    QMessageBox::critical(this, "Ошибка", message);
    statusBar()->showMessage("Ошибка: " + message, 5000);
}

void MainWindow::onBooksReceived(const QList<Book> &books)
{
    m_bookModel->setBooks(books);
    statusBar()->showMessage(QString("Загружено %1 книг").arg(books.size()));
}

void MainWindow::onBookCreated(const Book &book)
{
    m_bookModel->addBook(book);
    statusBar()->showMessage("Книга добавлена: " + book.title());
}

void MainWindow::onBookUpdated(const Book &book)
{
    m_bookModel->updateBook(book);
    statusBar()->showMessage("Книга обновлена: " + book.title());
}

void MainWindow::onBookDeleted(int id)
{
    m_bookModel->removeBook(id);
    statusBar()->showMessage("Книга удалена");
}

void MainWindow::onErrorOccurred(const QString &errorMessage)
{
    showError(errorMessage);
}

void MainWindow::on_actionAdd_triggered()
{
    BookDialog dialog(this);
    dialog.setBook(Book()); // Empty book for new entry
    
    if (dialog.exec() == QDialog::Accepted) {
        Book book = dialog.book();
        m_apiService->createBook(book);
    }
}

void MainWindow::on_actionEdit_triggered()
{
    QModelIndex proxyIndex = ui->booksTableView->currentIndex();
    if (!proxyIndex.isValid()) {
        QMessageBox::information(this, "Информация", "Выберите книгу для редактирования");
        return;
    }
    
    QModelIndex sourceIndex = m_proxyModel->mapToSource(proxyIndex);
    Book book = m_bookModel->getBook(sourceIndex.row());
    
    BookDialog dialog(this);
    dialog.setBook(book);
    
    if (dialog.exec() == QDialog::Accepted) {
        Book updatedBook = dialog.book();
        m_apiService->updateBook(updatedBook);
    }
}

void MainWindow::on_actionDelete_triggered()
{
    QModelIndex proxyIndex = ui->booksTableView->currentIndex();
    if (!proxyIndex.isValid()) {
        QMessageBox::information(this, "Информация", "Выберите книгу для удаления");
        return;
    }
    
    QModelIndex sourceIndex = m_proxyModel->mapToSource(proxyIndex);
    Book book = m_bookModel->getBook(sourceIndex.row());
    
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Подтверждение удаления",
        QString("Вы действительно хотите удалить книгу \"%1\"?").arg(book.title()),
        QMessageBox::Yes | QMessageBox::No
    );
    
    if (reply == QMessageBox::Yes) {
        m_apiService->deleteBook(book.id());
    }
}

void MainWindow::on_actionRefresh_triggered()
{
    loadBooks();
}

void MainWindow::on_searchLineEdit_textChanged(const QString &text)
{
    m_proxyModel->setFilterFixedString(text);
}

