/********************************************************************************
** Form generated from reading UI file 'videowin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOWIN_H
#define UI_VIDEOWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoWin
{
public:

    void setupUi(QWidget *VideoWin)
    {
        if (VideoWin->objectName().isEmpty())
            VideoWin->setObjectName(QStringLiteral("VideoWin"));
        VideoWin->resize(400, 300);

        retranslateUi(VideoWin);

        QMetaObject::connectSlotsByName(VideoWin);
    } // setupUi

    void retranslateUi(QWidget *VideoWin)
    {
        VideoWin->setWindowTitle(QApplication::translate("VideoWin", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class VideoWin: public Ui_VideoWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOWIN_H
