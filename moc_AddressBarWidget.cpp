/****************************************************************************
** Meta object code from reading C++ file 'AddressBarWidget.h'
**
** Created: Mon 27. Jul 15:24:38 2009
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
      16,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      30,   17,   17,   17, 0x05,
      44,   17,   17,   17, 0x05,
      60,   17,   17,   17, 0x05,
      84,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
     110,   17,   17,   17, 0x0a,
     118,   17,   17,   17, 0x0a,
     135,   17,   17,   17, 0x0a,
     154,   17,   17,   17, 0x0a,
     184,  174,   17,   17, 0x0a,
     208,   17,   17,   17, 0x0a,
     229,   17,   17,   17, 0x08,
     242,   17,   17,   17, 0x08,
     254,   17,   17,   17, 0x08,
     278,   17,   17,   17, 0x08,
     290,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AddressBarWidget[] = {
    "AddressBarWidget\0\0goClicked()\0"
    "stopClicked()\0reloadClicked()\0"
    "slideToVisibleClicked()\0"
    "slideToInvisibleClicked()\0slide()\0"
    "slideToVisible()\0slideToInvisible()\0"
    "setLoadingStarted()\0aProgress\0"
    "setLoadingProgress(int)\0setLoadingFinished()\0"
    "initialize()\0slideTick()\0"
    "propagateSlideClicked()\0setGoIcon()\0"
    "setStopIcon()\0"
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
        case 1: stopClicked(); break;
        case 2: reloadClicked(); break;
        case 3: slideToVisibleClicked(); break;
        case 4: slideToInvisibleClicked(); break;
        case 5: slide(); break;
        case 6: slideToVisible(); break;
        case 7: slideToInvisible(); break;
        case 8: setLoadingStarted(); break;
        case 9: setLoadingProgress((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 10: setLoadingFinished(); break;
        case 11: initialize(); break;
        case 12: slideTick(); break;
        case 13: propagateSlideClicked(); break;
        case 14: setGoIcon(); break;
        case 15: setStopIcon(); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void AddressBarWidget::goClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void AddressBarWidget::stopClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void AddressBarWidget::reloadClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void AddressBarWidget::slideToVisibleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void AddressBarWidget::slideToInvisibleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
