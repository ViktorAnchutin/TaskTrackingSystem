/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TaskTrackingSystem/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[407];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 24), // "on_addUserButton_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 28), // "on_getAllUsersButton_clicked"
QT_MOC_LITERAL(4, 66, 24), // "on_addTaskButton_clicked"
QT_MOC_LITERAL(5, 91, 25), // "on_getTasksButton_clicked"
QT_MOC_LITERAL(6, 117, 15), // "updateTaskTable"
QT_MOC_LITERAL(7, 133, 27), // "on_deleteUserButton_clicked"
QT_MOC_LITERAL(8, 161, 36), // "on_searchConditionComboBox_ac..."
QT_MOC_LITERAL(9, 198, 4), // "arg1"
QT_MOC_LITERAL(10, 203, 27), // "on_deleteTaskButton_clicked"
QT_MOC_LITERAL(11, 231, 27), // "on_addProjectButton_clicked"
QT_MOC_LITERAL(12, 259, 31), // "on_getAllProjectsButton_clicked"
QT_MOC_LITERAL(13, 291, 30), // "on_deleteProjectButton_clicked"
QT_MOC_LITERAL(14, 322, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(15, 346, 37), // "on_tasksTableWidget_itemDoubl..."
QT_MOC_LITERAL(16, 384, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(17, 402, 4) // "item"

    },
    "MainWindow\0on_addUserButton_clicked\0"
    "\0on_getAllUsersButton_clicked\0"
    "on_addTaskButton_clicked\0"
    "on_getTasksButton_clicked\0updateTaskTable\0"
    "on_deleteUserButton_clicked\0"
    "on_searchConditionComboBox_activated\0"
    "arg1\0on_deleteTaskButton_clicked\0"
    "on_addProjectButton_clicked\0"
    "on_getAllProjectsButton_clicked\0"
    "on_deleteProjectButton_clicked\0"
    "on_actionOpen_triggered\0"
    "on_tasksTableWidget_itemDoubleClicked\0"
    "QTableWidgetItem*\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    1,   85,    2, 0x08 /* Private */,
      10,    0,   88,    2, 0x08 /* Private */,
      11,    0,   89,    2, 0x08 /* Private */,
      12,    0,   90,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    1,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_addUserButton_clicked(); break;
        case 1: _t->on_getAllUsersButton_clicked(); break;
        case 2: _t->on_addTaskButton_clicked(); break;
        case 3: _t->on_getTasksButton_clicked(); break;
        case 4: _t->updateTaskTable(); break;
        case 5: _t->on_deleteUserButton_clicked(); break;
        case 6: _t->on_searchConditionComboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_deleteTaskButton_clicked(); break;
        case 8: _t->on_addProjectButton_clicked(); break;
        case 9: _t->on_getAllProjectsButton_clicked(); break;
        case 10: _t->on_deleteProjectButton_clicked(); break;
        case 11: _t->on_actionOpen_triggered(); break;
        case 12: _t->on_tasksTableWidget_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
