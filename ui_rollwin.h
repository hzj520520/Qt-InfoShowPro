/********************************************************************************
** Form generated from reading UI file 'rollwin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROLLWIN_H
#define UI_ROLLWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RollWin
{
public:

    void setupUi(QWidget *RollWin)
    {
        if (RollWin->objectName().isEmpty())
            RollWin->setObjectName(QStringLiteral("RollWin"));
        RollWin->resize(800, 80);

        retranslateUi(RollWin);

        QMetaObject::connectSlotsByName(RollWin);
    } // setupUi

    void retranslateUi(QWidget *RollWin)
    {
        RollWin->setWindowTitle(QApplication::translate("RollWin", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class RollWin: public Ui_RollWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROLLWIN_H
