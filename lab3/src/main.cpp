#include "../include/mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // Set application information
    QApplication::setApplicationName("Book Client");
    QApplication::setApplicationVersion("1.0");
    QApplication::setOrganizationName("231-329");
    
    // Set Russian locale
    QLocale::setDefault(QLocale(QLocale::Russian, QLocale::Russia));
    
    // Load translator for Qt
    QTranslator translator;
    if (translator.load(QLocale(), QLatin1String("qt"), QLatin1String("_"),
                       QLatin1String("/usr/share/qt5/translations"))) {
        QApplication::installTranslator(&translator);
    }
    
    MainWindow w;
    w.show();
    return a.exec();
}

