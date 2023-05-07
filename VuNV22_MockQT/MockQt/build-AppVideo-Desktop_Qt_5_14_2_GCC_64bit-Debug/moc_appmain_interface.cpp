/****************************************************************************
** Meta object code from reading C++ file 'appmain_interface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "appmain_interface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appmain_interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LocalAppMainInterface_t {
    QByteArrayData data[10];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LocalAppMainInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LocalAppMainInterface_t qt_meta_stringdata_LocalAppMainInterface = {
    {
QT_MOC_LITERAL(0, 0, 21), // "LocalAppMainInterface"
QT_MOC_LITERAL(1, 22, 19), // "deregistrationAppID"
QT_MOC_LITERAL(2, 42, 19), // "QDBusPendingReply<>"
QT_MOC_LITERAL(3, 62, 0), // ""
QT_MOC_LITERAL(4, 63, 5), // "appid"
QT_MOC_LITERAL(5, 69, 7), // "appname"
QT_MOC_LITERAL(6, 77, 17), // "registrationAppID"
QT_MOC_LITERAL(7, 95, 11), // "servicename"
QT_MOC_LITERAL(8, 107, 10), // "objectpath"
QT_MOC_LITERAL(9, 118, 11) // "requestShow"

    },
    "LocalAppMainInterface\0deregistrationAppID\0"
    "QDBusPendingReply<>\0\0appid\0appname\0"
    "registrationAppID\0servicename\0objectpath\0"
    "requestShow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LocalAppMainInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   29,    3, 0x0a /* Public */,
       6,    4,   34,    3, 0x0a /* Public */,
       9,    1,   43,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2, QMetaType::Int, QMetaType::QString,    4,    5,
    0x80000000 | 2, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    5,    7,    8,
    0x80000000 | 2, QMetaType::Int,    4,

       0        // eod
};

void LocalAppMainInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LocalAppMainInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QDBusPendingReply<> _r = _t->deregistrationAppID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 1: { QDBusPendingReply<> _r = _t->registrationAppID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 2: { QDBusPendingReply<> _r = _t->requestShow((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LocalAppMainInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractInterface::staticMetaObject>(),
    qt_meta_stringdata_LocalAppMainInterface.data,
    qt_meta_data_LocalAppMainInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LocalAppMainInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LocalAppMainInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LocalAppMainInterface.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int LocalAppMainInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
