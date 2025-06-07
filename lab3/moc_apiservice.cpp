/****************************************************************************
** Meta object code from reading C++ file 'apiservice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "include/apiservice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'apiservice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ApiService_t {
    QByteArrayData data[22];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ApiService_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ApiService_t qt_meta_stringdata_ApiService = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ApiService"
QT_MOC_LITERAL(1, 11, 13), // "booksReceived"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11), // "QList<Book>"
QT_MOC_LITERAL(4, 38, 5), // "books"
QT_MOC_LITERAL(5, 44, 12), // "bookReceived"
QT_MOC_LITERAL(6, 57, 4), // "Book"
QT_MOC_LITERAL(7, 62, 4), // "book"
QT_MOC_LITERAL(8, 67, 11), // "bookCreated"
QT_MOC_LITERAL(9, 79, 11), // "bookUpdated"
QT_MOC_LITERAL(10, 91, 11), // "bookDeleted"
QT_MOC_LITERAL(11, 103, 2), // "id"
QT_MOC_LITERAL(12, 106, 13), // "errorOccurred"
QT_MOC_LITERAL(13, 120, 12), // "errorMessage"
QT_MOC_LITERAL(14, 133, 18), // "onGetBooksFinished"
QT_MOC_LITERAL(15, 152, 17), // "onGetBookFinished"
QT_MOC_LITERAL(16, 170, 20), // "onCreateBookFinished"
QT_MOC_LITERAL(17, 191, 20), // "onUpdateBookFinished"
QT_MOC_LITERAL(18, 212, 20), // "onDeleteBookFinished"
QT_MOC_LITERAL(19, 233, 14), // "onNetworkError"
QT_MOC_LITERAL(20, 248, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(21, 276, 5) // "error"

    },
    "ApiService\0booksReceived\0\0QList<Book>\0"
    "books\0bookReceived\0Book\0book\0bookCreated\0"
    "bookUpdated\0bookDeleted\0id\0errorOccurred\0"
    "errorMessage\0onGetBooksFinished\0"
    "onGetBookFinished\0onCreateBookFinished\0"
    "onUpdateBookFinished\0onDeleteBookFinished\0"
    "onNetworkError\0QNetworkReply::NetworkError\0"
    "error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ApiService[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       5,    1,   77,    2, 0x06 /* Public */,
       8,    1,   80,    2, 0x06 /* Public */,
       9,    1,   83,    2, 0x06 /* Public */,
      10,    1,   86,    2, 0x06 /* Public */,
      12,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,
      16,    0,   94,    2, 0x08 /* Private */,
      17,    0,   95,    2, 0x08 /* Private */,
      18,    0,   96,    2, 0x08 /* Private */,
      19,    1,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString,   13,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,

       0        // eod
};

void ApiService::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ApiService *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->booksReceived((*reinterpret_cast< const QList<Book>(*)>(_a[1]))); break;
        case 1: _t->bookReceived((*reinterpret_cast< const Book(*)>(_a[1]))); break;
        case 2: _t->bookCreated((*reinterpret_cast< const Book(*)>(_a[1]))); break;
        case 3: _t->bookUpdated((*reinterpret_cast< const Book(*)>(_a[1]))); break;
        case 4: _t->bookDeleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->errorOccurred((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->onGetBooksFinished(); break;
        case 7: _t->onGetBookFinished(); break;
        case 8: _t->onCreateBookFinished(); break;
        case 9: _t->onUpdateBookFinished(); break;
        case 10: _t->onDeleteBookFinished(); break;
        case 11: _t->onNetworkError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ApiService::*)(const QList<Book> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApiService::booksReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ApiService::*)(const Book & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApiService::bookReceived)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ApiService::*)(const Book & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApiService::bookCreated)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ApiService::*)(const Book & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApiService::bookUpdated)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ApiService::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApiService::bookDeleted)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ApiService::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApiService::errorOccurred)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ApiService::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ApiService.data,
    qt_meta_data_ApiService,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ApiService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ApiService::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ApiService.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ApiService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ApiService::booksReceived(const QList<Book> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ApiService::bookReceived(const Book & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ApiService::bookCreated(const Book & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ApiService::bookUpdated(const Book & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ApiService::bookDeleted(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ApiService::errorOccurred(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
