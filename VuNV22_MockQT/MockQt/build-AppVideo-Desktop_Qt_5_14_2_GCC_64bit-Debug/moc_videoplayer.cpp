/****************************************************************************
** Meta object code from reading C++ file 'videoplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../AppVideo/videoplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videoplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VideoPlayer_t {
    QByteArrayData data[22];
    char stringdata0[301];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoPlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoPlayer_t qt_meta_stringdata_VideoPlayer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "VideoPlayer"
QT_MOC_LITERAL(1, 12, 19), // "videoSurfaceChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 15), // "filenameChanged"
QT_MOC_LITERAL(4, 49, 8), // "filename"
QT_MOC_LITERAL(5, 58, 15), // "durationChanged"
QT_MOC_LITERAL(6, 74, 8), // "duration"
QT_MOC_LITERAL(7, 83, 15), // "positionChanged"
QT_MOC_LITERAL(8, 99, 8), // "position"
QT_MOC_LITERAL(9, 108, 24), // "handlePlayingTimeChanged"
QT_MOC_LITERAL(10, 133, 27), // "handlePlaybackStatusChanged"
QT_MOC_LITERAL(11, 161, 19), // "QMediaPlayer::State"
QT_MOC_LITERAL(12, 181, 6), // "status"
QT_MOC_LITERAL(13, 188, 11), // "setFilename"
QT_MOC_LITERAL(14, 200, 11), // "setDuration"
QT_MOC_LITERAL(15, 212, 11), // "setPosition"
QT_MOC_LITERAL(16, 224, 8), // "seekSong"
QT_MOC_LITERAL(17, 233, 11), // "requestPlay"
QT_MOC_LITERAL(18, 245, 9), // "nextVideo"
QT_MOC_LITERAL(19, 255, 9), // "prevVideo"
QT_MOC_LITERAL(20, 265, 12), // "videoSurface"
QT_MOC_LITERAL(21, 278, 22) // "QAbstractVideoSurface*"

    },
    "VideoPlayer\0videoSurfaceChanged\0\0"
    "filenameChanged\0filename\0durationChanged\0"
    "duration\0positionChanged\0position\0"
    "handlePlayingTimeChanged\0"
    "handlePlaybackStatusChanged\0"
    "QMediaPlayer::State\0status\0setFilename\0"
    "setDuration\0setPosition\0seekSong\0"
    "requestPlay\0nextVideo\0prevVideo\0"
    "videoSurface\0QAbstractVideoSurface*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoPlayer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       4,  110, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    1,   80,    2, 0x06 /* Public */,
       5,    1,   83,    2, 0x06 /* Public */,
       7,    1,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   89,    2, 0x0a /* Public */,
      10,    1,   92,    2, 0x0a /* Public */,
      13,    1,   95,    2, 0x0a /* Public */,
      14,    1,   98,    2, 0x0a /* Public */,
      15,    1,  101,    2, 0x0a /* Public */,
      16,    1,  104,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      17,    0,  107,    2, 0x02 /* Public */,
      18,    0,  108,    2, 0x02 /* Public */,
      19,    0,  109,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::LongLong,    6,
    QMetaType::Void, QMetaType::LongLong,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong,    8,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::LongLong,    6,
    QMetaType::Void, QMetaType::LongLong,    8,
    QMetaType::Void, QMetaType::LongLong,    8,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      20, 0x80000000 | 21, 0x0049510b,
       4, QMetaType::QString, 0x00495103,
       6, QMetaType::LongLong, 0x00495103,
       8, QMetaType::LongLong, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void VideoPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VideoPlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->videoSurfaceChanged(); break;
        case 1: _t->filenameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->durationChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: _t->positionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 4: _t->handlePlayingTimeChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: _t->handlePlaybackStatusChanged((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        case 6: _t->setFilename((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setDuration((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 8: _t->setPosition((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 9: _t->seekSong((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 10: _t->requestPlay(); break;
        case 11: _t->nextVideo(); break;
        case 12: _t->prevVideo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VideoPlayer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPlayer::videoSurfaceChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VideoPlayer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPlayer::filenameChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VideoPlayer::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPlayer::durationChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (VideoPlayer::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPlayer::positionChanged)) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractVideoSurface* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<VideoPlayer *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QAbstractVideoSurface**>(_v) = _t->videoSurface(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->filename(); break;
        case 2: *reinterpret_cast< qint64*>(_v) = _t->duration(); break;
        case 3: *reinterpret_cast< qint64*>(_v) = _t->position(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<VideoPlayer *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setVideoSurface(*reinterpret_cast< QAbstractVideoSurface**>(_v)); break;
        case 1: _t->setFilename(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setDuration(*reinterpret_cast< qint64*>(_v)); break;
        case 3: _t->setPosition(*reinterpret_cast< qint64*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject VideoPlayer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_VideoPlayer.data,
    qt_meta_data_VideoPlayer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VideoPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VideoPlayer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VideoPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void VideoPlayer::videoSurfaceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VideoPlayer::filenameChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VideoPlayer::durationChanged(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void VideoPlayer::positionChanged(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
