/****************************************************************************
** Meta object code from reading C++ file 'AppEngine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../AppVideo/AppEngine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppEngine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AppEngine_t {
    QByteArrayData data[19];
    char stringdata0[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppEngine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppEngine_t qt_meta_stringdata_AppEngine = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AppEngine"
QT_MOC_LITERAL(1, 10, 19), // "videoSurfaceChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 22), // "QAbstractVideoSurface*"
QT_MOC_LITERAL(4, 54, 12), // "videoSurface"
QT_MOC_LITERAL(5, 67, 15), // "durationChanged"
QT_MOC_LITERAL(6, 83, 8), // "duration"
QT_MOC_LITERAL(7, 92, 15), // "positionChanged"
QT_MOC_LITERAL(8, 108, 8), // "position"
QT_MOC_LITERAL(9, 117, 10), // "showWindow"
QT_MOC_LITERAL(10, 128, 5), // "appID"
QT_MOC_LITERAL(11, 134, 10), // "hideWindow"
QT_MOC_LITERAL(12, 145, 18), // "registerDbusVolume"
QT_MOC_LITERAL(13, 164, 17), // "onRecceivedVolume"
QT_MOC_LITERAL(14, 182, 6), // "volume"
QT_MOC_LITERAL(15, 189, 11), // "requestShow"
QT_MOC_LITERAL(16, 201, 13), // "sendInfo2Home"
QT_MOC_LITERAL(17, 215, 8), // "fileName"
QT_MOC_LITERAL(18, 224, 8) // "isPaused"

    },
    "AppEngine\0videoSurfaceChanged\0\0"
    "QAbstractVideoSurface*\0videoSurface\0"
    "durationChanged\0duration\0positionChanged\0"
    "position\0showWindow\0appID\0hideWindow\0"
    "registerDbusVolume\0onRecceivedVolume\0"
    "volume\0requestShow\0sendInfo2Home\0"
    "fileName\0isPaused"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppEngine[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,
       7,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   68,    2, 0x0a /* Public */,
      11,    1,   71,    2, 0x0a /* Public */,
      12,    0,   74,    2, 0x0a /* Public */,
      13,    1,   75,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      15,    1,   78,    2, 0x02 /* Public */,
      16,    2,   81,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::LongLong,    6,
    QMetaType::Void, QMetaType::LongLong,    8,

 // slots: parameters
    QMetaType::Int, QMetaType::Int,   10,
    QMetaType::Int, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   17,   18,

       0        // eod
};

void AppEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AppEngine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->videoSurfaceChanged((*reinterpret_cast< QAbstractVideoSurface*(*)>(_a[1]))); break;
        case 1: _t->durationChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 2: _t->positionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: { int _r = _t->showWindow((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->hideWindow((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->registerDbusVolume(); break;
        case 6: _t->onRecceivedVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->requestShow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->sendInfo2Home((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractVideoSurface* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AppEngine::*)(QAbstractVideoSurface * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppEngine::videoSurfaceChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AppEngine::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppEngine::durationChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AppEngine::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppEngine::positionChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AppEngine::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AppEngine.data,
    qt_meta_data_AppEngine,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AppEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AppEngine.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AppEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void AppEngine::videoSurfaceChanged(QAbstractVideoSurface * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AppEngine::durationChanged(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AppEngine::positionChanged(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
