/********************************************************************************
** Form generated from reading ui file 'NavigationBarWidget.ui'
**
** Created: Mon 27. Jul 11:29:26 2009
**      by: Qt User Interface Compiler version 4.5.2-tower
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_NAVIGATIONBARWIDGET_H
#define UI_NAVIGATIONBARWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NavigationBarWidgetClass
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *SlidePushButton;
    QPushButton *BackPushButton;
    QPushButton *HomePushButton;
    QPushButton *ForwardPushButton;
    QFrame *line;
    QPushButton *ZoomOutPushButton;
    QSlider *ZoomSlider;
    QPushButton *ZoomInPushButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *NavigationBarWidgetClass)
    {
        if (NavigationBarWidgetClass->objectName().isEmpty())
            NavigationBarWidgetClass->setObjectName(QString::fromUtf8("NavigationBarWidgetClass"));
        NavigationBarWidgetClass->resize(317, 76);
        gridLayout = new QGridLayout(NavigationBarWidgetClass);
        gridLayout->setSpacing(1);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 0, 2, 2);
        horizontalSpacer = new QSpacerItem(274, 29, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 6);

        SlidePushButton = new QPushButton(NavigationBarWidgetClass);
        SlidePushButton->setObjectName(QString::fromUtf8("SlidePushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SlidePushButton->sizePolicy().hasHeightForWidth());
        SlidePushButton->setSizePolicy(sizePolicy);
        SlidePushButton->setMinimumSize(QSize(40, 32));
        SlidePushButton->setMaximumSize(QSize(40, 32));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/slide-vertical.png"), QSize(), QIcon::Normal, QIcon::On);
        SlidePushButton->setIcon(icon);
        SlidePushButton->setIconSize(QSize(40, 32));
        SlidePushButton->setFlat(false);

        gridLayout->addWidget(SlidePushButton, 1, 6, 1, 1);

        BackPushButton = new QPushButton(NavigationBarWidgetClass);
        BackPushButton->setObjectName(QString::fromUtf8("BackPushButton"));
        sizePolicy.setHeightForWidth(BackPushButton->sizePolicy().hasHeightForWidth());
        BackPushButton->setSizePolicy(sizePolicy);
        BackPushButton->setMinimumSize(QSize(40, 40));
        BackPushButton->setMaximumSize(QSize(40, 40));
        BackPushButton->setAutoFillBackground(false);
        BackPushButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/back.png"), QSize(), QIcon::Normal, QIcon::On);
        BackPushButton->setIcon(icon1);
        BackPushButton->setIconSize(QSize(40, 40));

        gridLayout->addWidget(BackPushButton, 2, 0, 1, 1);

        HomePushButton = new QPushButton(NavigationBarWidgetClass);
        HomePushButton->setObjectName(QString::fromUtf8("HomePushButton"));
        sizePolicy.setHeightForWidth(HomePushButton->sizePolicy().hasHeightForWidth());
        HomePushButton->setSizePolicy(sizePolicy);
        HomePushButton->setMinimumSize(QSize(40, 40));
        HomePushButton->setMaximumSize(QSize(40, 40));
        HomePushButton->setAutoFillBackground(false);
        HomePushButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/home.png"), QSize(), QIcon::Normal, QIcon::On);
        HomePushButton->setIcon(icon2);
        HomePushButton->setIconSize(QSize(40, 40));

        gridLayout->addWidget(HomePushButton, 2, 1, 1, 1);

        ForwardPushButton = new QPushButton(NavigationBarWidgetClass);
        ForwardPushButton->setObjectName(QString::fromUtf8("ForwardPushButton"));
        sizePolicy.setHeightForWidth(ForwardPushButton->sizePolicy().hasHeightForWidth());
        ForwardPushButton->setSizePolicy(sizePolicy);
        ForwardPushButton->setMinimumSize(QSize(40, 40));
        ForwardPushButton->setMaximumSize(QSize(40, 40));
        ForwardPushButton->setAutoFillBackground(false);
        ForwardPushButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/forward.png"), QSize(), QIcon::Normal, QIcon::On);
        ForwardPushButton->setIcon(icon3);
        ForwardPushButton->setIconSize(QSize(40, 40));

        gridLayout->addWidget(ForwardPushButton, 2, 2, 1, 1);

        line = new QFrame(NavigationBarWidgetClass);
        line->setObjectName(QString::fromUtf8("line"));
        sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy);
        line->setMinimumSize(QSize(15, 40));
        line->setAutoFillBackground(false);
        line->setStyleSheet(QString::fromUtf8(""));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 2, 3, 1, 1);

        ZoomOutPushButton = new QPushButton(NavigationBarWidgetClass);
        ZoomOutPushButton->setObjectName(QString::fromUtf8("ZoomOutPushButton"));
        sizePolicy.setHeightForWidth(ZoomOutPushButton->sizePolicy().hasHeightForWidth());
        ZoomOutPushButton->setSizePolicy(sizePolicy);
        ZoomOutPushButton->setMinimumSize(QSize(40, 40));
        ZoomOutPushButton->setMaximumSize(QSize(40, 40));
        ZoomOutPushButton->setAutoFillBackground(false);
        ZoomOutPushButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/zoom-out.png"), QSize(), QIcon::Normal, QIcon::On);
        ZoomOutPushButton->setIcon(icon4);
        ZoomOutPushButton->setIconSize(QSize(40, 40));

        gridLayout->addWidget(ZoomOutPushButton, 2, 4, 1, 1);

        ZoomSlider = new QSlider(NavigationBarWidgetClass);
        ZoomSlider->setObjectName(QString::fromUtf8("ZoomSlider"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ZoomSlider->sizePolicy().hasHeightForWidth());
        ZoomSlider->setSizePolicy(sizePolicy1);
        ZoomSlider->setMinimumSize(QSize(0, 0));
        ZoomSlider->setAutoFillBackground(false);
        ZoomSlider->setStyleSheet(QString::fromUtf8(""));
        ZoomSlider->setMinimum(50);
        ZoomSlider->setMaximum(150);
        ZoomSlider->setSingleStep(25);
        ZoomSlider->setPageStep(25);
        ZoomSlider->setValue(100);
        ZoomSlider->setTracking(false);
        ZoomSlider->setOrientation(Qt::Horizontal);
        ZoomSlider->setInvertedAppearance(false);
        ZoomSlider->setInvertedControls(false);
        ZoomSlider->setTickPosition(QSlider::TicksBothSides);
        ZoomSlider->setTickInterval(25);

        gridLayout->addWidget(ZoomSlider, 2, 5, 1, 1);

        ZoomInPushButton = new QPushButton(NavigationBarWidgetClass);
        ZoomInPushButton->setObjectName(QString::fromUtf8("ZoomInPushButton"));
        sizePolicy.setHeightForWidth(ZoomInPushButton->sizePolicy().hasHeightForWidth());
        ZoomInPushButton->setSizePolicy(sizePolicy);
        ZoomInPushButton->setMinimumSize(QSize(40, 40));
        ZoomInPushButton->setMaximumSize(QSize(40, 40));
        ZoomInPushButton->setAutoFillBackground(false);
        ZoomInPushButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/zoom-in.png"), QSize(), QIcon::Normal, QIcon::On);
        ZoomInPushButton->setIcon(icon5);
        ZoomInPushButton->setIconSize(QSize(40, 40));

        gridLayout->addWidget(ZoomInPushButton, 2, 6, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 6, 1, 1);


        retranslateUi(NavigationBarWidgetClass);

        QMetaObject::connectSlotsByName(NavigationBarWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *NavigationBarWidgetClass)
    {
        NavigationBarWidgetClass->setWindowTitle(QApplication::translate("NavigationBarWidgetClass", "NavigationBarWidget", 0, QApplication::UnicodeUTF8));
        SlidePushButton->setText(QString());
        BackPushButton->setText(QString());
        HomePushButton->setText(QString());
        ForwardPushButton->setText(QString());
        ZoomOutPushButton->setText(QString());
        ZoomInPushButton->setText(QString());
        Q_UNUSED(NavigationBarWidgetClass);
    } // retranslateUi

};

namespace Ui {
    class NavigationBarWidgetClass: public Ui_NavigationBarWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIGATIONBARWIDGET_H
