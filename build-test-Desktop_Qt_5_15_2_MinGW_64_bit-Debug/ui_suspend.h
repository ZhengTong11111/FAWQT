/********************************************************************************
** Form generated from reading UI file 'suspend.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUSPEND_H
#define UI_SUSPEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_suspend
{
public:
    QPushButton *retry;
    QPushButton *end;
    QPushButton *continue_2;

    void setupUi(QDialog *suspend)
    {
        if (suspend->objectName().isEmpty())
            suspend->setObjectName(QString::fromUtf8("suspend"));
        suspend->resize(400, 300);
        suspend->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_game/picture_for_begin_and_game/paused.png);"));
        retry = new QPushButton(suspend);
        retry->setObjectName(QString::fromUtf8("retry"));
        retry->setGeometry(QRect(70, 140, 91, 31));
        QPalette palette;
        QBrush brush(QColor(245, 217, 26, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        retry->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Gabriola"));
        font.setPointSize(20);
        retry->setFont(font);
        retry->setFocusPolicy(Qt::StrongFocus);
        retry->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/button_background.png);"));
        end = new QPushButton(suspend);
        end->setObjectName(QString::fromUtf8("end"));
        end->setGeometry(QRect(240, 140, 91, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        end->setPalette(palette1);
        end->setFont(font);
        end->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/button_background.png);"));
        continue_2 = new QPushButton(suspend);
        continue_2->setObjectName(QString::fromUtf8("continue_2"));
        continue_2->setGeometry(QRect(135, 210, 141, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        continue_2->setPalette(palette2);
        continue_2->setFont(font);
        continue_2->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/button_background.png);"));

        retranslateUi(suspend);

        QMetaObject::connectSlotsByName(suspend);
    } // setupUi

    void retranslateUi(QDialog *suspend)
    {
        suspend->setWindowTitle(QCoreApplication::translate("suspend", "Dialog", nullptr));
        retry->setText(QCoreApplication::translate("suspend", "RETRY", nullptr));
        end->setText(QCoreApplication::translate("suspend", "END", nullptr));
        continue_2->setText(QCoreApplication::translate("suspend", "CONTINUE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class suspend: public Ui_suspend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUSPEND_H
