/****************************************************************************
** Meta object code from reading C++ file 'Thread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Source/Core/Thread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Core__Thread_t {
    QByteArrayData data[9];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Core__Thread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Core__Thread_t qt_meta_stringdata_Core__Thread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Core::Thread"
QT_MOC_LITERAL(1, 13, 6), // "Finish"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 15), // "ProgressPercent"
QT_MOC_LITERAL(4, 37, 7), // "percent"
QT_MOC_LITERAL(5, 45, 10), // "IndexApply"
QT_MOC_LITERAL(6, 56, 5), // "index"
QT_MOC_LITERAL(7, 62, 10), // "SendObject"
QT_MOC_LITERAL(8, 73, 6) // "objOut"

    },
    "Core::Thread\0Finish\0\0ProgressPercent\0"
    "percent\0IndexApply\0index\0SendObject\0"
    "objOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Core__Thread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,
       5,    1,   38,    2, 0x06 /* Public */,
       7,    1,   41,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::VoidStar,    8,

       0        // eod
};

void Core::Thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Thread *_t = static_cast<Thread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Finish(); break;
        case 1: _t->ProgressPercent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->IndexApply((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->SendObject((*reinterpret_cast< void*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Thread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Thread::Finish)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Thread::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Thread::ProgressPercent)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Thread::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Thread::IndexApply)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Thread::*_t)(void * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Thread::SendObject)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Core::Thread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Core__Thread.data,
      qt_meta_data_Core__Thread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Core::Thread::metaObject() const
{
    return d_ptr->metaObject ? d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Core::Thread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Core__Thread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int Core::Thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Core::Thread::Finish()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Core::Thread::ProgressPercent(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Core::Thread::IndexApply(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Core::Thread::SendObject(void * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
