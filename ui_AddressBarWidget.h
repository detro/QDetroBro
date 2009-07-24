/********************************************************************************
** Form generated from reading ui file 'AddressBarWidget.ui'
**
** Created: Fri 24. Jul 16:47:47 2009
**      by: Qt User Interface Compiler version 4.5.2-tower
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ADDRESSBARWIDGET_H
#define UI_ADDRESSBARWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>
#include "chasewidget.h"

QT_BEGIN_NAMESPACE

class Ui_AddressBarWidgetClass
{
public:
    QGridLayout *gridLayout;
    QPushButton *GoPushButton;
    QLineEdit *AddressLineEdit;
    QProgressBar *LoadingProgressBar;
    QPushButton *SlidePushButton;
    QSpacerItem *verticalSpacer;
    ChaseWidget *BusyLoadingChaseWidget;
    QPushButton *ReloadPushButton;

    void setupUi(QWidget *AddressBarWidgetClass)
    {
        if (AddressBarWidgetClass->objectName().isEmpty())
            AddressBarWidgetClass->setObjectName(QString::fromUtf8("AddressBarWidgetClass"));
        AddressBarWidgetClass->resize(296, 76);
        AddressBarWidgetClass->setAutoFillBackground(false);
        gridLayout = new QGridLayout(AddressBarWidgetClass);
        gridLayout->setSpacing(1);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 0);
        GoPushButton = new QPushButton(AddressBarWidgetClass);
        GoPushButton->setObjectName(QString::fromUtf8("GoPushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GoPushButton->sizePolicy().hasHeightForWidth());
        GoPushButton->setSizePolicy(sizePolicy);
        GoPushButton->setMinimumSize(QSize(40, 40));
        GoPushButton->setMaximumSize(QSize(40, 40));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/go.png"), QSize(), QIcon::Normal, QIcon::On);
        GoPushButton->setIcon(icon);
        GoPushButton->setIconSize(QSize(40, 40));
        GoPushButton->setFlat(false);

        gridLayout->addWidget(GoPushButton, 0, 7, 1, 1);

        AddressLineEdit = new QLineEdit(AddressBarWidgetClass);
        AddressLineEdit->setObjectName(QString::fromUtf8("AddressLineEdit"));
        AddressLineEdit->setMinimumSize(QSize(0, 40));
        AddressLineEdit->setMaximumSize(QSize(16777215, 40));
        AddressLineEdit->setFrame(true);

        gridLayout->addWidget(AddressLineEdit, 0, 3, 1, 4);

        LoadingProgressBar = new QProgressBar(AddressBarWidgetClass);
        LoadingProgressBar->setObjectName(QString::fromUtf8("LoadingProgressBar"));
        LoadingProgressBar->setMinimumSize(QSize(0, 20));
        LoadingProgressBar->setMaximumSize(QSize(16777215, 20));
        LoadingProgressBar->setValue(0);
        LoadingProgressBar->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        LoadingProgressBar->setTextVisible(false);
        LoadingProgressBar->setInvertedAppearance(false);

        gridLayout->addWidget(LoadingProgressBar, 1, 3, 1, 4);

        SlidePushButton = new QPushButton(AddressBarWidgetClass);
        SlidePushButton->setObjectName(QString::fromUtf8("SlidePushButton"));
        sizePolicy.setHeightForWidth(SlidePushButton->sizePolicy().hasHeightForWidth());
        SlidePushButton->setSizePolicy(sizePolicy);
        SlidePushButton->setMinimumSize(QSize(40, 32));
        SlidePushButton->setMaximumSize(QSize(40, 32));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/slide-vertical.png"), QSize(), QIcon::Normal, QIcon::On);
        SlidePushButton->setIcon(icon1);
        SlidePushButton->setIconSize(QSize(40, 32));
        SlidePushButton->setFlat(false);

        gridLayout->addWidget(SlidePushButton, 1, 7, 1, 1);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 7, 1, 1);

        BusyLoadingChaseWidget = new ChaseWidget(AddressBarWidgetClass);
        BusyLoadingChaseWidget->setObjectName(QString::fromUtf8("BusyLoadingChaseWidget"));
        BusyLoadingChaseWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(BusyLoadingChaseWidget->sizePolicy().hasHeightForWidth());
        BusyLoadingChaseWidget->setSizePolicy(sizePolicy);
        BusyLoadingChaseWidget->setMinimumSize(QSize(40, 32));
        BusyLoadingChaseWidget->setMaximumSize(QSize(40, 32));

        gridLayout->addWidget(BusyLoadingChaseWidget, 1, 2, 1, 1);

        ReloadPushButton = new QPushButton(AddressBarWidgetClass);
        ReloadPushButton->setObjectName(QString::fromUtf8("ReloadPushButton"));
        sizePolicy.setHeightForWidth(ReloadPushButton->sizePolicy().hasHeightForWidth());
        ReloadPushButton->setSizePolicy(sizePolicy);
        ReloadPushButton->setMinimumSize(QSize(40, 40));
        ReloadPushButton->setMaximumSize(QSize(40, 40));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/reload.png"), QSize(), QIcon::Normal, QIcon::On);
        ReloadPushButton->setIcon(icon2);
        ReloadPushButton->setIconSize(QSize(40, 40));
        ReloadPushButton->setFlat(false);

        gridLayout->addWidget(ReloadPushButton, 0, 2, 1, 1);


        retranslateUi(AddressBarWidgetClass);

        QMetaObject::connectSlotsByName(AddressBarWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *AddressBarWidgetClass)
    {
        AddressBarWidgetClass->setWindowTitle(QApplication::translate("AddressBarWidgetClass", "AddressBarWidget", 0, QApplication::UnicodeUTF8));
        GoPushButton->setText(QString());
        SlidePushButton->setText(QString());
        ReloadPushButton->setText(QString());
        Q_UNUSED(AddressBarWidgetClass);
    } // retranslateUi

};

namespace Ui {
    class AddressBarWidgetClass: public Ui_AddressBarWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRESSBARWIDGET_H
