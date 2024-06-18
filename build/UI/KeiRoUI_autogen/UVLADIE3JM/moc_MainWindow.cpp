/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../UI/src/MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Ui__MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ui__MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ui__MainWindow_t qt_meta_stringdata_Ui__MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Ui::MainWindow"
QT_MOC_LITERAL(1, 15, 7), // "newFile"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "save"
QT_MOC_LITERAL(4, 29, 5), // "print"
QT_MOC_LITERAL(5, 35, 4), // "undo"
QT_MOC_LITERAL(6, 40, 5), // "about"
QT_MOC_LITERAL(7, 46, 13), // "_initAllDocks"
QT_MOC_LITERAL(8, 60, 12), // "_initSetting"
QT_MOC_LITERAL(9, 73, 7), // "setting"
QT_MOC_LITERAL(10, 81, 16), // "_initInteraction"
QT_MOC_LITERAL(11, 98, 11), // "interaction"
QT_MOC_LITERAL(12, 110, 14), // "_updateSetting"
QT_MOC_LITERAL(13, 125, 18), // "_updateInteraction"
QT_MOC_LITERAL(14, 144, 15), // "_updateAllDocks"
QT_MOC_LITERAL(15, 160, 9) // "exportPNG"

    },
    "Ui::MainWindow\0newFile\0\0save\0print\0"
    "undo\0about\0_initAllDocks\0_initSetting\0"
    "setting\0_initInteraction\0interaction\0"
    "_updateSetting\0_updateInteraction\0"
    "_updateAllDocks\0exportPNG"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ui__MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    1,   80,    2, 0x08 /* Private */,
      10,    1,   83,    2, 0x08 /* Private */,
      12,    1,   86,    2, 0x08 /* Private */,
      13,    1,   89,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Ui::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newFile(); break;
        case 1: _t->save(); break;
        case 2: _t->print(); break;
        case 3: _t->undo(); break;
        case 4: _t->about(); break;
        case 5: _t->_initAllDocks(); break;
        case 6: _t->_initSetting((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->_initInteraction((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->_updateSetting((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->_updateInteraction((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->_updateAllDocks(); break;
        case 11: _t->exportPNG(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Ui::MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Ui__MainWindow.data,
    qt_meta_data_Ui__MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Ui::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ui::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Ui__MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Ui::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
