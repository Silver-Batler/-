QT       += core gui network

QT += core gui network widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/book.cpp \
    src/bookmodel.cpp \
    src/apiservice.cpp \
    src/bookdialog.cpp

HEADERS += \
    include/mainwindow.h \
    include/book.h \
    include/bookmodel.h \
    include/apiservice.h \
    include/bookdialog.h

FORMS += \
    ui/mainwindow.ui \
    ui/bookdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/resources.qrc

