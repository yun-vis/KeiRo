/****************************************************************************
** Meta object code from reading C++ file 'TreemapGraphicsView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../ResponsiveLens/ui/TreemapGraphicsView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TreemapGraphicsView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TreemapGraphicsView_t {
    QByteArrayData data[18];
    char stringdata0[270];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TreemapGraphicsView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TreemapGraphicsView_t qt_meta_stringdata_TreemapGraphicsView = {
    {
QT_MOC_LITERAL(0, 0, 19), // "TreemapGraphicsView"
QT_MOC_LITERAL(1, 20, 15), // "dataInitialized"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 11), // "dataChanged"
QT_MOC_LITERAL(4, 49, 21), // "sendSelectedNodesInfo"
QT_MOC_LITERAL(5, 71, 27), // "vector<pair<uint,QString> >"
QT_MOC_LITERAL(6, 99, 15), // "sendMaxIncrease"
QT_MOC_LITERAL(7, 115, 19), // "sendMaxSiblingRatio"
QT_MOC_LITERAL(8, 135, 12), // "recvFilePath"
QT_MOC_LITERAL(9, 148, 13), // "recvLayerFont"
QT_MOC_LITERAL(10, 162, 13), // "vector<QFont>"
QT_MOC_LITERAL(11, 176, 12), // "recvIncrease"
QT_MOC_LITERAL(12, 189, 13), // "increaseRatio"
QT_MOC_LITERAL(13, 203, 16), // "recvSiblingRatio"
QT_MOC_LITERAL(14, 220, 12), // "siblingRatio"
QT_MOC_LITERAL(15, 233, 11), // "recvMinSize"
QT_MOC_LITERAL(16, 245, 7), // "minSize"
QT_MOC_LITERAL(17, 253, 16) // "recvRButtonPress"

    },
    "TreemapGraphicsView\0dataInitialized\0"
    "\0dataChanged\0sendSelectedNodesInfo\0"
    "vector<pair<uint,QString> >\0sendMaxIncrease\0"
    "sendMaxSiblingRatio\0recvFilePath\0"
    "recvLayerFont\0vector<QFont>\0recvIncrease\0"
    "increaseRatio\0recvSiblingRatio\0"
    "siblingRatio\0recvMinSize\0minSize\0"
    "recvRButtonPress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TreemapGraphicsView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    2,   71,    2, 0x06 /* Public */,
       6,    1,   76,    2, 0x06 /* Public */,
       7,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   82,    2, 0x0a /* Public */,
       9,    1,   85,    2, 0x0a /* Public */,
      11,    1,   88,    2, 0x0a /* Public */,
      13,    1,   91,    2, 0x0a /* Public */,
      15,    1,   94,    2, 0x0a /* Public */,
      17,    0,   97,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Double,    2,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void,

       0        // eod
};

void TreemapGraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TreemapGraphicsView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dataInitialized(); break;
        case 1: _t->dataChanged(); break;
        case 2: _t->sendSelectedNodesInfo((*reinterpret_cast< vector<pair<uint,QString> >(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 3: _t->sendMaxIncrease((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->sendMaxSiblingRatio((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->recvFilePath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->recvLayerFont((*reinterpret_cast< vector<QFont>(*)>(_a[1]))); break;
        case 7: _t->recvIncrease((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->recvSiblingRatio((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->recvMinSize((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->recvRButtonPress(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TreemapGraphicsView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TreemapGraphicsView::dataInitialized)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TreemapGraphicsView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TreemapGraphicsView::dataChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TreemapGraphicsView::*)(vector<pair<unsigned int,QString> > , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TreemapGraphicsView::sendSelectedNodesInfo)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TreemapGraphicsView::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TreemapGraphicsView::sendMaxIncrease)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TreemapGraphicsView::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TreemapGraphicsView::sendMaxSiblingRatio)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TreemapGraphicsView::staticMetaObject = { {
    QMetaObject::SuperData::link<Ui::GraphicsView::staticMetaObject>(),
    qt_meta_stringdata_TreemapGraphicsView.data,
    qt_meta_data_TreemapGraphicsView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TreemapGraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TreemapGraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TreemapGraphicsView.stringdata0))
        return static_cast<void*>(this);
    return Ui::GraphicsView::qt_metacast(_clname);
}

int TreemapGraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Ui::GraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void TreemapGraphicsView::dataInitialized()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TreemapGraphicsView::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TreemapGraphicsView::sendSelectedNodesInfo(vector<pair<unsigned int,QString> > _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TreemapGraphicsView::sendMaxIncrease(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TreemapGraphicsView::sendMaxSiblingRatio(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
