/****************************************************************************
** Meta object code from reading C++ file 'SettingsView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Source/Client/View/SettingsView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SettingsView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Client__View__SettingsView_t {
    QByteArrayData data[8];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Client__View__SettingsView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Client__View__SettingsView_t qt_meta_stringdata_Client__View__SettingsView = {
    {
QT_MOC_LITERAL(0, 0, 26), // "Client::View::SettingsView"
QT_MOC_LITERAL(1, 27, 24), // "LeftOnlyCboxIndexChanged"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 5), // "index"
QT_MOC_LITERAL(4, 59, 23), // "LeftNewCboxIndexChanged"
QT_MOC_LITERAL(5, 83, 24), // "RightNewCboxIndexChanged"
QT_MOC_LITERAL(6, 108, 25), // "RightOnlyCboxIndexChanged"
QT_MOC_LITERAL(7, 134, 9) // "OkClicked"

    },
    "Client::View::SettingsView\0"
    "LeftOnlyCboxIndexChanged\0\0index\0"
    "LeftNewCboxIndexChanged\0"
    "RightNewCboxIndexChanged\0"
    "RightOnlyCboxIndexChanged\0OkClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Client__View__SettingsView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       5,    1,   45,    2, 0x0a /* Public */,
       6,    1,   48,    2, 0x0a /* Public */,
       7,    0,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void Client::View::SettingsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SettingsView *_t = static_cast<SettingsView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->LeftOnlyCboxIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->LeftNewCboxIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->RightNewCboxIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->RightOnlyCboxIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->OkClicked(); break;
        default: ;
        }
    }
}

const QMetaObject Client::View::SettingsView::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Client__View__SettingsView.data,
      qt_meta_data_Client__View__SettingsView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Client::View::SettingsView::metaObject() const
{
    return d_ptr->metaObject ? d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Client::View::SettingsView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Client__View__SettingsView.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Client::View::SettingsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
