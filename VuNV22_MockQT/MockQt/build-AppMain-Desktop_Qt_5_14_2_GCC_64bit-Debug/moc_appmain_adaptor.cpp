/****************************************************************************
** Meta object code from reading C++ file 'appmain_adaptor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "appmain_adaptor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appmain_adaptor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AppMainAdaptor_t {
    QByteArrayData data[13];
    char stringdata0[786];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppMainAdaptor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppMainAdaptor_t qt_meta_stringdata_AppMainAdaptor = {
    {
QT_MOC_LITERAL(0, 0, 14), // "AppMainAdaptor"
QT_MOC_LITERAL(1, 15, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 31, 13), // "local.AppMain"
QT_MOC_LITERAL(3, 45, 19), // "D-Bus Introspection"
QT_MOC_LITERAL(4, 65, 632), // "  <interface name=\"local.App..."
QT_MOC_LITERAL(5, 633, 19), // "deregistrationAppID"
QT_MOC_LITERAL(6, 653, 0), // ""
QT_MOC_LITERAL(7, 654, 5), // "appid"
QT_MOC_LITERAL(8, 660, 7), // "appname"
QT_MOC_LITERAL(9, 668, 17), // "registrationAppID"
QT_MOC_LITERAL(10, 686, 11), // "servicename"
QT_MOC_LITERAL(11, 698, 10), // "objectpath"
QT_MOC_LITERAL(12, 709, 11) // "requestShow"

    },
    "AppMainAdaptor\0D-Bus Interface\0"
    "local.AppMain\0D-Bus Introspection\0"
    "  <interface name=\"local.AppMain\">\n    <method name=\"registrationA"
    "ppID\">\n      <arg direction=\"in\" type=\"i\" name=\"appid\"/>\n    "
    "  <arg direction=\"in\" type=\"s\" name=\"appname\"/>\n      <arg dire"
    "ction=\"in\" type=\"s\" name=\"servicename\"/>\n      <arg direction=\""
    "in\" type=\"s\" name=\"objectpath\"/>\n    </method>\n    <method name"
    "=\"deregistrationAppID\">\n      <arg direction=\"in\" type=\"i\" name"
    "=\"appid\"/>\n      <arg direction=\"in\" type=\"s\" name=\"appname\"/"
    ">\n    </method>\n    <method name=\"requestShow\">\n      <arg direct"
    "ion=\"in\" type=\"i\" name=\"appid\"/>\n    </method>\n  </interface>\n\0"
    "deregistrationAppID\0\0appid\0appname\0"
    "registrationAppID\0servicename\0objectpath\0"
    "requestShow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppMainAdaptor[] = {

 // content:
       8,       // revision
       0,       // classname
       2,   14, // classinfo
       3,   18, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // slots: name, argc, parameters, tag, flags
       5,    2,   33,    6, 0x0a /* Public */,
       9,    4,   38,    6, 0x0a /* Public */,
      12,    1,   47,    6, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    7,    8,   10,   11,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void AppMainAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AppMainAdaptor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deregistrationAppID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->registrationAppID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 2: _t->requestShow((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AppMainAdaptor::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractAdaptor::staticMetaObject>(),
    qt_meta_stringdata_AppMainAdaptor.data,
    qt_meta_data_AppMainAdaptor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AppMainAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppMainAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AppMainAdaptor.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int AppMainAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
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
