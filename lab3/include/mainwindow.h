#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include "apiservice.h"
#include "bookmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
private slots:
    void onBooksReceived(const QList<Book> &books);
    void onBookCreated(const Book &book);
    void onBookUpdated(const Book &book);
    void onBookDeleted(int id);
    void onErrorOccurred(const QString &errorMessage);
    
    void on_actionAdd_triggered();
    void on_actionEdit_triggered();
    void on_actionDelete_triggered();
    void on_actionRefresh_triggered();
    void on_searchLineEdit_textChanged(const QString &text);
    
private:
    Ui::MainWindow *ui;
    ApiService *m_apiService;
    BookModel *m_bookModel;
    QSortFilterProxyModel *m_proxyModel;
    
    void setupUi();
    void setupConnections();
    void loadBooks();
    void showError(const QString &message);
};
#endif // MAINWINDOW_H

