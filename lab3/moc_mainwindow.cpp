/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "include/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[265];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "onBooksReceived"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "QList<Book>"
QT_MOC_LITERAL(4, 40, 5), // "books"
QT_MOC_LITERAL(5, 46, 13), // "onBookCreated"
QT_MOC_LITERAL(6, 60, 4), // "Book"
QT_MOC_LITERAL(7, 65, 4), // "book"
QT_MOC_LITERAL(8, 70, 13), // "onBookUpdated"
QT_MOC_LITERAL(9, 84, 13), // "onBookDeleted"
QT_MOC_LITERAL(10, 98, 2), // "id"
QT_MOC_LITERAL(11, 101, 15), // "onErrorOccurred"
QT_MOC_LITERAL(12, 117, 12), // "errorMessage"
QT_MOC_LITERAL(13, 130, 22), // "on_actionAdd_triggered"
QT_MOC_LITERAL(14, 153, 23), // "on_actionEdit_triggered"
QT_MOC_LITERAL(15, 177, 25), // "on_actionDelete_triggered"
QT_MOC_LITERAL(16, 203, 26), // "on_actionRefresh_triggered"
QT_MOC_LITERAL(17, 230, 29), // "on_searchLineEdit_textChanged"
QT_MOC_LITERAL(18, 260, 4) // "text"

    },
    "MainWindow\0onBooksReceived\0\0QList<Book>\0"
    "books\0onBookCreated\0Book\0book\0"
    "onBookUpdated\0onBookDeleted\0id\0"
    "onErrorOccurred\0errorMessage\0"
    "on_actionAdd_triggered\0on_actionEdit_triggered\0"
    "on_actionDelete_triggered\0"
    "on_actionRefresh_triggered\0"
    "on_searchLineEdit_textChanged\0text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       5,    1,   67,    2, 0x08 /* Private */,
       8,    1,   70,    2, 0x08 /* Private */,
       9,    1,   73,    2, 0x08 /* Private */,
      11,    1,   76,    2, 0x08 /* Private */,
      13,    0,   79,    2, 0x08 /* Private */,
      14,    0,   80,    2, 0x08 /* Private */,
      15,    0,   81,    2, 0x08 /* Private */,
      16,    0,   82,    2, 0x08 /* Private */,
      17,    1,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onBooksReceived((*reinterpret_cast< const QList<Book>(*)>(_a[1]))); break;
        case 1: _t->onBookCreated((*reinterpret_cast< const Book(*)>(_a[1]))); break;
        case 2: _t->onBookUpdated((*reinterpret_cast< const Book(*)>(_a[1]))); break;
        case 3: _t->onBookDeleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onErrorOccurred((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_actionAdd_triggered(); break;
        case 6: _t->on_actionEdit_triggered(); break;
        case 7: _t->on_actionDelete_triggered(); break;
        case 8: _t->on_actionRefresh_triggered(); break;
        case 9: _t->on_searchLineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
