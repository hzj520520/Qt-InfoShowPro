/********************************************************************************
** Form generated from reading UI file 'picturewin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICTUREWIN_H
#define UI_PICTUREWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PictureWin
{
public:

    void setupUi(QWidget *PictureWin)
    {
        if (PictureWin->objectName().isEmpty())
            PictureWin->setObjectName(QStringLiteral("PictureWin"));
        PictureWin->resize(400, 300);

        retranslateUi(PictureWin);

        QMetaObject::connectSlotsByName(PictureWin);
    } // setupUi

    void retranslateUi(QWidget *PictureWin)
    {
        PictureWin->setWindowTitle(QApplication::translate("PictureWin", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class PictureWin: public Ui_PictureWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTUREWIN_H
