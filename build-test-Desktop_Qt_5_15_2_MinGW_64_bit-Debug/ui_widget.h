/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *background_begin;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *start_Button;
    QSpacerItem *verticalSpacer;
    QPushButton *setting_Button;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1000, 600);
        background_begin = new QLabel(Widget);
        background_begin->setObjectName(QString::fromUtf8("background_begin"));
        background_begin->setGeometry(QRect(0, 0, 1000, 600));
        background_begin->setMinimumSize(QSize(800, 600));
        background_begin->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/background_begin.png);"));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(430, 480, 163, 109));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        start_Button = new QPushButton(widget);
        start_Button->setObjectName(QString::fromUtf8("start_Button"));
        start_Button->setMinimumSize(QSize(161, 61));
        start_Button->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/buttons_start.png);"));

        verticalLayout->addWidget(start_Button);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        setting_Button = new QPushButton(Widget);
        setting_Button->setObjectName(QString::fromUtf8("setting_Button"));
        setting_Button->setGeometry(QRect(20, 540, 60, 60));
        setting_Button->setMinimumSize(QSize(60, 60));
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

#endif // UI_WIDGET_H
