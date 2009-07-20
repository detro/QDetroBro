/********************************************************************************
** Form generated from reading ui file 'QDetroBro.ui'
**
** Created: Thu 9. Jul 17:40:25 2009
**      by: Qt User Interface Compiler version 4.5.2-tower
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_QDETROBRO_H
#define UI_QDETROBRO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_QDetroBroClass
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *ReloadButton;
    QLineEdit *AddressLineEdit;
    QPushButton *GoButton;
    QWebView *WebView;
    QLabel *label;
    QSlider *ZoomSlider;
    QLabel *label_2;
    QPushButton *BackButton;
    QPushButton *HomeButton;
    QPushButton *ForwardButton;
    QSpacerItem *horizontalSpacer;
    QProgressBar *ProgressBar;
    QLabel *LoadingLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QDetroBroClass)
    {
        if (QDetroBroClass->objectName().isEmpty())
            QDetroBroClass->setObjectName(QString::fromUtf8("QDetroBroClass"));
        QDetroBroClass->resize(374, 657);
        centralwidget = new QWidget(QDetroBroClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ReloadButton = new QPushButton(centralwidget);
        ReloadButton->setObjectName(QString::fromUtf8("ReloadButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ReloadButton->sizePolicy().hasHeightForWidth());
        ReloadButton->setSizePolicy(sizePolicy);
        ReloadButton->setMinimumSize(QSize(40, 30));
        ReloadButton->setMaximumSize(QSize(40, 30));
        QFont font;
        font.setPointSize(7);
        ReloadButton->setFont(font);

        gridLayout->addWidget(ReloadButton, 0, 0, 1, 1);

        AddressLineEdit = new QLineEdit(centralwidget);
        AddressLineEdit->setObjectName(QString::fromUtf8("AddressLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(AddressLineEdit->sizePolicy().hasHeightForWidth());
        AddressLineEdit->setSizePolicy(sizePolicy1);
        AddressLineEdit->setMinimumSize(QSize(120, 0));
        AddressLineEdit->setFont(font);

        gridLayout->addWidget(AddressLineEdit, 0, 1, 1, 4);

        GoButton = new QPushButton(centralwidget);
        GoButton->setObjectName(QString::fromUtf8("GoButton"));
        sizePolicy1.setHeightForWidth(GoButton->sizePolicy().hasHeightForWidth());
        GoButton->setSizePolicy(sizePolicy1);
        GoButton->setMinimumSize(QSize(60, 30));
        GoButton->setMaximumSize(QSize(60, 30));
        GoButton->setFont(font);

        gridLayout->addWidget(GoButton, 0, 5, 1, 1);

        WebView = new QWebView(centralwidget);
        WebView->setObjectName(QString::fromUtf8("WebView"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(WebView->sizePolicy().hasHeightForWidth());
        WebView->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(WebView, 1, 0, 1, 6);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        ZoomSlider = new QSlider(centralwidget);
        ZoomSlider->setObjectName(QString::fromUtf8("ZoomSlider"));
        sizePolicy1.setHeightForWidth(ZoomSlider->sizePolicy().hasHeightForWidth());
        ZoomSlider->setSizePolicy(sizePolicy1);
        ZoomSlider->setMinimumSize(QSize(30, 0));
        ZoomSlider->setMaximumSize(QSize(16000, 30));
        ZoomSlider->setFont(font);
        ZoomSlider->setMinimum(50);
        ZoomSlider->setMaximum(150);
        ZoomSlider->setSingleStep(20);
        ZoomSlider->setPageStep(20);
        ZoomSlider->setValue(100);
        ZoomSlider->setSliderPosition(100);
        ZoomSlider->setTracking(false);
        ZoomSlider->setOrientation(Qt::Horizontal);
        ZoomSlider->setTickPosition(QSlider::TicksBothSides);
        ZoomSlider->setTickInterval(20);

        gridLayout->addWidget(ZoomSlider, 2, 1, 1, 4);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(60, 0));
        label_2->setMaximumSize(QSize(60, 16777215));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 2, 5, 1, 1);

        BackButton = new QPushButton(centralwidget);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        sizePolicy.setHeightForWidth(BackButton->sizePolicy().hasHeightForWidth());
        BackButton->setSizePolicy(sizePolicy);
        BackButton->setMinimumSize(QSize(40, 30));
        BackButton->setMaximumSize(QSize(40, 30));
        BackButton->setFont(font);

        gridLayout->addWidget(BackButton, 3, 0, 1, 1);

        HomeButton = new QPushButton(centralwidget);
        HomeButton->setObjectName(QString::fromUtf8("HomeButton"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(HomeButton->sizePolicy().hasHeightForWidth());
        HomeButton->setSizePolicy(sizePolicy3);
        HomeButton->setMinimumSize(QSize(40, 30));
        HomeButton->setMaximumSize(QSize(40, 30));
        HomeButton->setFont(font);

        gridLayout->addWidget(HomeButton, 3, 1, 1, 1);

        ForwardButton = new QPushButton(centralwidget);
        ForwardButton->setObjectName(QString::fromUtf8("ForwardButton"));
        sizePolicy.setHeightForWidth(ForwardButton->sizePolicy().hasHeightForWidth());
        ForwardButton->setSizePolicy(sizePolicy);
        ForwardButton->setMinimumSize(QSize(40, 30));
        ForwardButton->setMaximumSize(QSize(40, 30));
        ForwardButton->setFont(font);

        gridLayout->addWidget(ForwardButton, 3, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 3, 1, 1);

        ProgressBar = new QProgressBar(centralwidget);
        ProgressBar->setObjectName(QString::fromUtf8("ProgressBar"));
        ProgressBar->setMinimumSize(QSize(130, 30));
        ProgressBar->setMaximumSize(QSize(16777215, 30));
        ProgressBar->setFont(font);
        ProgressBar->setValue(0);
        ProgressBar->setTextVisible(false);
        ProgressBar->setInvertedAppearance(false);

        gridLayout->addWidget(ProgressBar, 3, 4, 1, 1);

        LoadingLabel = new QLabel(centralwidget);
        LoadingLabel->setObjectName(QString::fromUtf8("LoadingLabel"));
        LoadingLabel->setEnabled(true);
        LoadingLabel->setMinimumSize(QSize(60, 0));
        LoadingLabel->setMaximumSize(QSize(60, 16777215));
        LoadingLabel->setFont(font);
        LoadingLabel->setScaledContents(false);
        LoadingLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LoadingLabel, 3, 5, 1, 1);

        QDetroBroClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QDetroBroClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 374, 21));
        QDetroBroClass->setMenuBar(menubar);
        statusbar = new QStatusBar(QDetroBroClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QDetroBroClass->setStatusBar(statusbar);

        retranslateUi(QDetroBroClass);

        QMetaObject::connectSlotsByName(QDetroBroClass);
    } // setupUi

    void retranslateUi(QMainWindow *QDetroBroClass)
    {
        QDetroBroClass->setWindowTitle(QApplication::translate("QDetroBroClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        ReloadButton->setText(QApplication::translate("QDetroBroClass", "R", 0, QApplication::UnicodeUTF8));
        GoButton->setText(QApplication::translate("QDetroBroClass", "Go", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QDetroBroClass", "50%", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QDetroBroClass", "150%", 0, QApplication::UnicodeUTF8));
        BackButton->setText(QApplication::translate("QDetroBroClass", "<", 0, QApplication::UnicodeUTF8));
        HomeButton->setText(QApplication::translate("QDetroBroClass", "H", 0, QApplication::UnicodeUTF8));
        ForwardButton->setText(QApplication::translate("QDetroBroClass", ">", 0, QApplication::UnicodeUTF8));
        LoadingLabel->setText(QApplication::translate("QDetroBroClass", "done", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(QDetroBroClass);
    } // retranslateUi

};

namespace Ui {
    class QDetroBroClass: public Ui_QDetroBroClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDETROBRO_H
