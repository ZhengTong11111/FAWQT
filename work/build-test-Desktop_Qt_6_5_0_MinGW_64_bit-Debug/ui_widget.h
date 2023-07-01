#pragma once
/********************************************************************************
** Form generated from reading UI file ''
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *background_begin;
    QPushButton *start_Button;
    QPushButton *setting_Button;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1000, 600);
        background_begin = new QLabel(Widget);
        background_begin->setObjectName("background_begin");
        background_begin->setGeometry(QRect(0, 0, 1000, 600));
        background_begin->setMinimumSize(QSize(800, 600));
        background_begin->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/background_begin.png);"));
        start_Button = new QPushButton(Widget);
        start_Button->setObjectName("start_Button");
        start_Button->setGeometry(QRect(430, 480, 161, 61));
        start_Button->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/buttons_start.png);"));
        setting_Button = new QPushButton(Widget);
        setting_Button->setObjectName("pushButton");
        setting_Button->setGeometry(QRect(20, 540, 61, 61));
        setting_Button->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/button_setting.png);"));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        background_begin->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        start_Button->setText(QString());
        setting_Button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

