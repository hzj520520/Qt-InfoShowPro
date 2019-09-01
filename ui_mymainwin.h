/********************************************************************************
** Form generated from reading UI file 'mymainwin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMAINWIN_H
#define UI_MYMAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "picturewin.h"
#include "rollwin.h"
#include "videowin.h"
#include "weathwin.h"

QT_BEGIN_NAMESPACE

class Ui_MyMainWin
{
public:
    QWidget *centralWidget;
    WeathWin *weatherWidget;
    PictureWin *pictureWidget;
    VideoWin *videoWidget;
    RollWin *rollWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyMainWin)
    {
        if (MyMainWin->objectName().isEmpty())
            MyMainWin->setObjectName(QStringLiteral("MyMainWin"));
        MyMainWin->resize(800, 480);
#ifndef QT_NO_STATUSTIP
        MyMainWin->setStatusTip(QStringLiteral(""));
#endif // QT_NO_STATUSTIP
        MyMainWin->setStyleSheet(QLatin1String("\n"
"border-image: url(:/images/UI5.jpg);\n"
"\n"
"\n"
"QWidget#rollWidget{\n"
"background-color: rgb(85, 255, 127);\n"
"}\n"
"\n"
"QWidget#weatherWidget{\n"
"background-color: rgb(255, 170, 0);\n"
"}"));
        centralWidget = new QWidget(MyMainWin);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        weatherWidget = new WeathWin(centralWidget);
        weatherWidget->setObjectName(QStringLiteral("weatherWidget"));
        weatherWidget->setGeometry(QRect(500, 0, 300, 400));
        weatherWidget->setStyleSheet(QStringLiteral(""));
        pictureWidget = new PictureWin(centralWidget);
        pictureWidget->setObjectName(QStringLiteral("pictureWidget"));
        pictureWidget->setGeometry(QRect(0, 0, 500, 400));
        pictureWidget->setStyleSheet(QLatin1String("\n"
"background-color: rgb(0, 170, 255);"));
        videoWidget = new VideoWin(centralWidget);
        videoWidget->setObjectName(QStringLiteral("videoWidget"));
        videoWidget->setGeometry(QRect(0, 0, 500, 400));
        videoWidget->setStyleSheet(QLatin1String("\n"
"background-color: rgb(0, 170, 255);"));
        rollWidget = new RollWin(centralWidget);
        rollWidget->setObjectName(QStringLiteral("rollWidget"));
        rollWidget->setGeometry(QRect(0, 400, 800, 31));
        MyMainWin->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyMainWin);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        MyMainWin->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyMainWin);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyMainWin->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MyMainWin);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyMainWin->setStatusBar(statusBar);

        retranslateUi(MyMainWin);

        QMetaObject::connectSlotsByName(MyMainWin);
    } // setupUi

    void retranslateUi(QMainWindow *MyMainWin)
    {
        MyMainWin->setWindowTitle(QApplication::translate("MyMainWin", "MyMainWin", 0));
    } // retranslateUi

};

namespace Ui {
    class MyMainWin: public Ui_MyMainWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMAINWIN_H
