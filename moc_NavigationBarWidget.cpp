/****************************************************************************
** Meta object code from reading C++ file 'NavigationBarWidget.h'
**
** Created: Fri 24. Jul 16:47:46 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2-tower)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "NavigationBarWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NavigationBarWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2-tower. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NavigationBarWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,
      35,   20,   20,   20, 0x05,
      49,   20,   20,   20, 0x05,
      66,   20,   20,   20, 0x05,
      88,   20,   20,   20, 0x05,
     112,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
     138,   20,   20,   20, 0x0a,
     146,   20,   20,   20, 0x0a,
     163,   20,   20,   20, 0x0a,
     182,   20,   20,   20, 0x08,
     195,   20,   20,   20, 0x08,
     204,   20,   20,   20, 0x08,
     214,   20,   20,   20, 0x08,
     226,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NavigationBarWidget[] = {
    "NavigationBarWidget\0\0backClicked()\0"
    "homeClicked()\0forwardClicked()\0"
    "zoomLevelChanged(int)\0slideToVisibleClicked()\0"
    "slideToInvisibleClicked()\0slide()\0"
    "slideToVisible()\0slideToInvisible()\0"
    "initialize()\0zoomIn()\0zoomOut()\0"
    "slideTick()\0propagateSlideClicked()\0"
};

const QMetaObject NavigationBarWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NavigationBarWidget,
      qt_meta_data_NavigationBarWidget, 0 }
};

const QMetaObject *NavigationBarWidget::metaObject() const
{
    return &staticMetaObject;
}

void *NavigationBarWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NavigationBarWidget))
        return static_cast<void*>(const_cast< NavigationBarWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int NavigationBarWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: backClicked(); break;
        case 1: homeClicked(); break;
        case 2: forwardClicked(); break;
        case 3: zoomLevelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: slideToVisibleClicked(); break;
        case 5: slideToInvisibleClicked(); break;
        case 6: slide(); break;
        case 7: slideToVisible(); break;
        case 8: slideToInvisible(); break;
        case 9: initialize(); break;
        case 10: zoomIn(); break;
        case 11: zoomOut(); break;
        case 12: slideTick(); break;
        case 13: propagateSlideClicked(); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void NavigationBarWidget::backClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void NavigationBarWidget::homeClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void NavigationBarWidget::forwardClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void NavigationBarWidget::zoomLevelChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void NavigationBarWidget::slideToVisibleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void NavigationBarWidget::slideToInvisibleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
