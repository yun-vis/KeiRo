/****************************************************************************
** Meta object code from reading C++ file 'LensSetting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../ResponsiveLens/ui/LensSetting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LensSetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LensSetting_t {
    QByteArrayData data[26];
    char stringdata0[472];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LensSetting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LensSetting_t qt_meta_stringdata_LensSetting = {
    {
QT_MOC_LITERAL(0, 0, 11), // "LensSetting"
QT_MOC_LITERAL(1, 12, 12), // "sendFilePath"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "filePath"
QT_MOC_LITERAL(4, 35, 13), // "sendLayerFont"
QT_MOC_LITERAL(5, 49, 13), // "vector<QFont>"
QT_MOC_LITERAL(6, 63, 5), // "fonts"
QT_MOC_LITERAL(7, 69, 12), // "sendIncrease"
QT_MOC_LITERAL(8, 82, 11), // "maxIncrease"
QT_MOC_LITERAL(9, 94, 16), // "sendSiblingRatio"
QT_MOC_LITERAL(10, 111, 12), // "siblingRatio"
QT_MOC_LITERAL(11, 124, 11), // "sendMinSize"
QT_MOC_LITERAL(12, 136, 7), // "minSize"
QT_MOC_LITERAL(13, 144, 14), // "pressedRButton"
QT_MOC_LITERAL(14, 159, 25), // "on_btn_BrowseData_clicked"
QT_MOC_LITERAL(15, 185, 25), // "on_le_Increase_textEdited"
QT_MOC_LITERAL(16, 211, 32), // "on_hSlider_Increase_valueChanged"
QT_MOC_LITERAL(17, 244, 29), // "on_le_SiblingRatio_textEdited"
QT_MOC_LITERAL(18, 274, 36), // "on_hSlider_SiblingRatio_value..."
QT_MOC_LITERAL(19, 311, 24), // "on_le_MinSize_textEdited"
QT_MOC_LITERAL(20, 336, 31), // "on_hSlider_MinSize_valueChanged"
QT_MOC_LITERAL(21, 368, 21), // "recvSelectedNodesInfo"
QT_MOC_LITERAL(22, 390, 27), // "vector<pair<uint,QString> >"
QT_MOC_LITERAL(23, 418, 15), // "recvMaxIncrease"
QT_MOC_LITERAL(24, 434, 19), // "recvMaxSiblingRatio"
QT_MOC_LITERAL(25, 454, 17) // "recvSpinBoxValues"

    },
    "LensSetting\0sendFilePath\0\0filePath\0"
    "sendLayerFont\0vector<QFont>\0fonts\0"
    "sendIncrease\0maxIncrease\0sendSiblingRatio\0"
    "siblingRatio\0sendMinSize\0minSize\0"
    "pressedRButton\0on_btn_BrowseData_clicked\0"
    "on_le_Increase_textEdited\0"
    "on_hSlider_Increase_valueChanged\0"
    "on_le_SiblingRatio_textEdited\0"
    "on_hSlider_SiblingRatio_valueChanged\0"
    "on_le_MinSize_textEdited\0"
    "on_hSlider_MinSize_valueChanged\0"
    "recvSelectedNodesInfo\0vector<pair<uint,QString> >\0"
    "recvMaxIncrease\0recvMaxSiblingRatio\0"
    "recvSpinBoxValues"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LensSetting[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    1,  102,    2, 0x06 /* Public */,
       7,    1,  105,    2, 0x06 /* Public */,
       9,    1,  108,    2, 0x06 /* Public */,
      11,    1,  111,    2, 0x06 /* Public */,
      13,    0,  114,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  115,    2, 0x08 /* Private */,
      15,    1,  116,    2, 0x08 /* Private */,
      16,    1,  119,    2, 0x08 /* Private */,
      17,    1,  122,    2, 0x08 /* Private */,
      18,    1,  125,    2, 0x08 /* Private */,
      19,    1,  128,    2, 0x08 /* Private */,
      20,    1,  131,    2, 0x08 /* Private */,
      21,    2,  134,    2, 0x0a /* Public */,
      23,    1,  139,    2, 0x0a /* Public */,
      24,    1,  142,    2, 0x0a /* Public */,
      25,    0,  145,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 22, QMetaType::Double,    2,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,

       0        // eod
};

void LensSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LensSetting *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendFilePath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendLayerFont((*reinterpret_cast< vector<QFont>(*)>(_a[1]))); break;
        case 2: _t->sendIncrease((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->sendSiblingRatio((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->sendMinSize((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->pressedRButton(); break;
        case 6: _t->on_btn_BrowseData_clicked(); break;
        case 7: _t->on_le_Increase_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_hSlider_Increase_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_le_SiblingRatio_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_hSlider_SiblingRatio_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_le_MinSize_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_hSlider_MinSize_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->recvSelectedNodesInfo((*reinterpret_cast< vector<pair<uint,QString> >(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 14: _t->recvMaxIncrease((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->recvMaxSiblingRatio((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->recvSpinBoxValues(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LensSetting::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LensSetting::sendFilePath)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LensSetting::*)(vector<QFont> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LensSetting::sendLayerFont)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LensSetting::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LensSetting::sendIncrease)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (LensSetting::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LensSetting::sendSiblingRatio)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (LensSetting::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LensSetting::sendMinSize)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (LensSetting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LensSetting::pressedRButton)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LensSetting::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_LensSetting.data,
    qt_meta_data_LensSetting,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LensSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LensSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LensSetting.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui_LensSetting"))
        return static_cast< Ui_LensSetting*>(this);
    return QWidget::qt_metacast(_clname);
}

int LensSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void LensSetting::sendFilePath(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LensSetting::sendLayerFont(vector<QFont> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LensSetting::sendIncrease(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LensSetting::sendSiblingRatio(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void LensSetting::sendMinSize(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void LensSetting::pressedRButton()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
