/****************************************************************************
** Meta object code from reading C++ file 'MainView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Source/Client/View/MainView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Client__View__MainView_t {
    QByteArrayData data[23];
    char stringdata0[372];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Client__View__MainView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Client__View__MainView_t qt_meta_stringdata_Client__View__MainView = {
    {
QT_MOC_LITERAL(0, 0, 22), // "Client::View::MainView"
QT_MOC_LITERAL(1, 23, 16), // "ToolBarTriggered"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 8), // "QAction*"
QT_MOC_LITERAL(4, 50, 6), // "action"
QT_MOC_LITERAL(5, 57, 18), // "WorkflowTextEdited"
QT_MOC_LITERAL(6, 76, 4), // "text"
QT_MOC_LITERAL(7, 81, 19), // "WorkflowListChanged"
QT_MOC_LITERAL(8, 101, 5), // "index"
QT_MOC_LITERAL(9, 107, 20), // "WorkflowListAddClick"
QT_MOC_LITERAL(10, 128, 23), // "WorkflowListDeleteClick"
QT_MOC_LITERAL(11, 152, 32), // "FoldersTableItemSelectionChanged"
QT_MOC_LITERAL(12, 185, 20), // "FoldersTableAddClick"
QT_MOC_LITERAL(13, 206, 23), // "FoldersTableDeleteClick"
QT_MOC_LITERAL(14, 230, 27), // "FoldersTableLeftBrowseClick"
QT_MOC_LITERAL(15, 258, 28), // "FoldersTableRightBrowseClick"
QT_MOC_LITERAL(16, 287, 17), // "CompareSendObject"
QT_MOC_LITERAL(17, 305, 6), // "objOut"
QT_MOC_LITERAL(18, 312, 13), // "CompareFinish"
QT_MOC_LITERAL(19, 326, 11), // "SyncPercent"
QT_MOC_LITERAL(20, 338, 7), // "percent"
QT_MOC_LITERAL(21, 346, 14), // "SyncIndexApply"
QT_MOC_LITERAL(22, 361, 10) // "SyncFinish"

    },
    "Client::View::MainView\0ToolBarTriggered\0"
    "\0QAction*\0action\0WorkflowTextEdited\0"
    "text\0WorkflowListChanged\0index\0"
    "WorkflowListAddClick\0WorkflowListDeleteClick\0"
    "FoldersTableItemSelectionChanged\0"
    "FoldersTableAddClick\0FoldersTableDeleteClick\0"
    "FoldersTableLeftBrowseClick\0"
    "FoldersTableRightBrowseClick\0"
    "CompareSendObject\0objOut\0CompareFinish\0"
    "SyncPercent\0percent\0SyncIndexApply\0"
    "SyncFinish"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Client__View__MainView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x0a /* Public */,
       5,    1,   92,    2, 0x0a /* Public */,
       7,    1,   95,    2, 0x0a /* Public */,
       9,    0,   98,    2, 0x0a /* Public */,
      10,    0,   99,    2, 0x0a /* Public */,
      11,    0,  100,    2, 0x0a /* Public */,
      12,    0,  101,    2, 0x0a /* Public */,
      13,    0,  102,    2, 0x0a /* Public */,
      14,    0,  103,    2, 0x0a /* Public */,
      15,    0,  104,    2, 0x0a /* Public */,
      16,    1,  105,    2, 0x0a /* Public */,
      18,    0,  108,    2, 0x0a /* Public */,
      19,    1,  109,    2, 0x0a /* Public */,
      21,    1,  112,    2, 0x0a /* Public */,
      22,    0,  115,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::VoidStar,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

       0        // eod
};

void Client::View::MainView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainView *_t = static_cast<MainView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ToolBarTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 1: _t->WorkflowTextEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->WorkflowListChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->WorkflowListAddClick(); break;
        case 4: _t->WorkflowListDeleteClick(); break;
        case 5: _t->FoldersTableItemSelectionChanged(); break;
        case 6: _t->FoldersTableAddClick(); break;
        case 7: _t->FoldersTableDeleteClick(); break;
        case 8: _t->FoldersTableLeftBrowseClick(); break;
        case 9: _t->FoldersTableRightBrowseClick(); break;
        case 10: _t->CompareSendObject((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 11: _t->CompareFinish(); break;
        case 12: _t->SyncPercent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->SyncIndexApply((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->SyncFinish(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
}

const QMetaObject Client::View::MainView::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Client__View__MainView.data,
      qt_meta_data_Client__View__MainView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Client::View::MainView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Client::View::MainView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Client__View__MainView.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Client::View::MainView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
