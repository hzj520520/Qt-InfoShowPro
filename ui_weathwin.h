/********************************************************************************
** Form generated from reading UI file 'weathwin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHWIN_H
#define UI_WEATHWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeathWin
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *weekLabel;
    QLabel *ymdLabel;
    QLabel *weatherpicLabel;
    QLabel *weathertextLabel;
    QLabel *lowLabel;
    QLabel *highLabel;
    QLabel *fxLabel;
    QLabel *flLabel;
    QLabel *noticeLabel;

    void setupUi(QWidget *WeathWin)
    {
        if (WeathWin->objectName().isEmpty())
            WeathWin->setObjectName(QStringLiteral("WeathWin"));
        WeathWin->resize(400, 300);
        gridLayout = new QGridLayout(WeathWin);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        weekLabel = new QLabel(WeathWin);
        weekLabel->setObjectName(QStringLiteral("weekLabel"));
        weekLabel->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        weekLabel->setScaledContents(true);
        weekLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(weekLabel);

        ymdLabel = new QLabel(WeathWin);
        ymdLabel->setObjectName(QStringLiteral("ymdLabel"));
        ymdLabel->setScaledContents(true);
        ymdLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(ymdLabel);

        weatherpicLabel = new QLabel(WeathWin);
        weatherpicLabel->setObjectName(QStringLiteral("weatherpicLabel"));
        weatherpicLabel->setMinimumSize(QSize(0, 120));
        weatherpicLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(weatherpicLabel);

        weathertextLabel = new QLabel(WeathWin);
        weathertextLabel->setObjectName(QStringLiteral("weathertextLabel"));
        weathertextLabel->setScaledContents(true);
        weathertextLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(weathertextLabel);

        lowLabel = new QLabel(WeathWin);
        lowLabel->setObjectName(QStringLiteral("lowLabel"));
        lowLabel->setScaledContents(true);
        lowLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lowLabel);

        highLabel = new QLabel(WeathWin);
        highLabel->setObjectName(QStringLiteral("highLabel"));
        highLabel->setScaledContents(true);
        highLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(highLabel);

        fxLabel = new QLabel(WeathWin);
        fxLabel->setObjectName(QStringLiteral("fxLabel"));
        fxLabel->setScaledContents(true);
        fxLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(fxLabel);

        flLabel = new QLabel(WeathWin);
        flLabel->setObjectName(QStringLiteral("flLabel"));
        flLabel->setScaledContents(true);
        flLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(flLabel);

        noticeLabel = new QLabel(WeathWin);
        noticeLabel->setObjectName(QStringLiteral("noticeLabel"));
        noticeLabel->setScaledContents(true);
        noticeLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(noticeLabel);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(WeathWin);

        QMetaObject::connectSlotsByName(WeathWin);
    } // setupUi

    void retranslateUi(QWidget *WeathWin)
    {
        WeathWin->setWindowTitle(QApplication::translate("WeathWin", "Form", 0));
        weekLabel->setText(QApplication::translate("WeathWin", "\346\230\237\346\234\237\344\270\200", 0));
        ymdLabel->setText(QApplication::translate("WeathWin", "07\346\234\21008\346\227\245", 0));
        weatherpicLabel->setText(QApplication::translate("WeathWin", "\345\244\251\346\260\224\345\233\276\347\211\207", 0));
        weathertextLabel->setText(QApplication::translate("WeathWin", "\345\244\251\346\260\224\346\217\217\350\277\260", 0));
        lowLabel->setText(QApplication::translate("WeathWin", "\346\234\200\344\275\216\346\270\251\345\272\246", 0));
        highLabel->setText(QApplication::translate("WeathWin", "\346\234\200\351\253\230\346\270\251\345\272\246", 0));
        fxLabel->setText(QApplication::translate("WeathWin", "\346\227\240\346\214\201\347\273\255\351\243\216\345\220\221", 0));
        flLabel->setText(QApplication::translate("WeathWin", "\351\243\216\345\212\233", 0));
        noticeLabel->setText(QApplication::translate("WeathWin", "notice", 0));
    } // retranslateUi

};

namespace Ui {
    class WeathWin: public Ui_WeathWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHWIN_H
