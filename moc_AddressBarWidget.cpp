/****************************************************************************
** Meta object code from reading C++ file 'AddressBarWidget.h'
**
** Created: Fri 24. Jul 16:47:47 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2-tower)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "AddressBarWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddressBarWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2-tower. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddressBarWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      30,   17,   17,   17, 0x05,
      46,   17,   17,   17, 0x05,
      70,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      96,   17,   17,   17, 0x0a,
     104,   17,   17,   17, 0x0a,
     121,   17,   17,   17, 0x0a,
     140,   17,   17,   17, 0x0a,
     170,  160,   17,   17, 0x0a,
     194,   17,   17,   17, 0x0a,
     215,   17,   17,   17, 0x08,
     228,   17,   17,   17, 0x08,
     240,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AddressBarWidget[] = {
    "AddressBarWidget\0\0goClicked()\0"
    "reloadClicked()\0slideToVisibleClicked()\0"
    "slideToInvisibleClicked()\0slide()\0"
    "slideToVisible()\0slideToInvisible()\0"
    "setLoadingStarted()\0aProgress\0"
    "setLoadingProgress(int)\0setLoadingFinished()\0"
    "initialize()\0slideTick()\0"
    "propagateSlideClicked()\0"
};

const QMetaObject AddressBarWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AddressBarWidget,
      qt_meta_data_AddressBarWidget, 0 }
};

const QMetaObject *AddressBarWidget::metaObject() const
{
    return &staticMetaObject;
}

void *AddressBarWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddressBarWidget))
        return static_cast<void*>(const_cast< AddressBarWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int AddressBarWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: goClicked(); break;
        case 1: reloadClicked(); break;
        case 2: slideToVisibleClicked(); break;
        case 3: slideToInvisibleClicked(); break;
        case 4: slide(); break;
        case 5: slideToVisible(); break;
        case 6: slideToInvisible(); break;
        case 7: setLoadingStarted(); break;
        case 8: setLoadingProgress((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 9: setLoadingFinished(); break;
        case 10: initialize(); break;
        case 11: slideTick(); break;
        case 12: propagateSlideClicked(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void AddressBarWidget::goClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void AddressBarWidget::reloadClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void AddressBarWidget::slideToVisibleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void AddressBarWidget::slideToInvisibleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
