/****************************************************************************
** Meta object code from reading C++ file 'apiservice.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/apiservice.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'apiservice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10ApiServiceE_t {};
} // unnamed namespace

template <> constexpr inline auto ApiService::qt_create_metaobjectdata<qt_meta_tag_ZN10ApiServiceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ApiService",
        "booksReceived",
        "",
        "QList<Book>",
        "books",
        "bookReceived",
        "Book",
        "book",
        "bookCreated",
        "bookUpdated",
        "bookDeleted",
        "id",
        "errorOccurred",
        "errorMessage",
        "onGetBooksFinished",
        "onGetBookFinished",
        "onCreateBookFinished",
        "onUpdateBookFinished",
        "onDeleteBookFinished",
        "onNetworkError",
        "QNetworkReply::NetworkError",
        "error"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'booksReceived'
        QtMocHelpers::SignalData<void(const QList<Book> &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'bookReceived'
        QtMocHelpers::SignalData<void(const Book &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Signal 'bookCreated'
        QtMocHelpers::SignalData<void(const Book &)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Signal 'bookUpdated'
        QtMocHelpers::SignalData<void(const Book &)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Signal 'bookDeleted'
        QtMocHelpers::SignalData<void(int)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 11 },
        }}),
        // Signal 'errorOccurred'
        QtMocHelpers::SignalData<void(const QString &)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 13 },
        }}),
        // Slot 'onGetBooksFinished'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onGetBookFinished'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onCreateBookFinished'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onUpdateBookFinished'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onDeleteBookFinished'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onNetworkError'
        QtMocHelpers::SlotData<void(QNetworkReply::NetworkError)>(19, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 20, 21 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ApiService, qt_meta_tag_ZN10ApiServiceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ApiService::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10ApiServiceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10ApiServiceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10ApiServiceE_t>.metaTypes,
    nullptr
} };

void ApiService::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ApiService *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->booksReceived((*reinterpret_cast< std::add_pointer_t<QList<Book>>>(_a[1]))); break;
        case 1: _t->bookReceived((*reinterpret_cast< std::add_pointer_t<Book>>(_a[1]))); break;
        case 2: _t->bookCreated((*reinterpret_cast< std::add_pointer_t<Book>>(_a[1]))); break;
        case 3: _t->bookUpdated((*reinterpret_cast< std::add_pointer_t<Book>>(_a[1]))); break;
        case 4: _t->bookDeleted((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->onGetBooksFinished(); break;
        case 7: _t->onGetBookFinished(); break;
        case 8: _t->onCreateBookFinished(); break;
        case 9: _t->onUpdateBookFinished(); break;
        case 10: _t->onDeleteBookFinished(); break;
        case 11: _t->onNetworkError((*reinterpret_cast< std::add_pointer_t<QNetworkReply::NetworkError>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ApiService::*)(const QList<Book> & )>(_a, &ApiService::booksReceived, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ApiService::*)(const Book & )>(_a, &ApiService::bookReceived, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ApiService::*)(const Book & )>(_a, &ApiService::bookCreated, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ApiService::*)(const Book & )>(_a, &ApiService::bookUpdated, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (ApiService::*)(int )>(_a, &ApiService::bookDeleted, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (ApiService::*)(const QString & )>(_a, &ApiService::errorOccurred, 5))
            return;
    }
}

const QMetaObject *ApiService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ApiService::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10ApiServiceE_t>.strings))
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
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ApiService::booksReceived(const QList<Book> & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void ApiService::bookReceived(const Book & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void ApiService::bookCreated(const Book & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void ApiService::bookUpdated(const Book & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void ApiService::bookDeleted(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void ApiService::errorOccurred(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}
QT_WARNING_POP
