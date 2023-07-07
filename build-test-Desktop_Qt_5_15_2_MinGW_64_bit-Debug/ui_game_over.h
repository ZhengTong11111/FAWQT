/********************************************************************************
** Form generated from reading UI file 'game_over.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_OVER_H
#define UI_GAME_OVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_game_over
{
public:
    QPushButton *back_to_begin;
    QLabel *game;
    QLabel *over;

    void setupUi(QDialog *game_over)
    {
        if (game_over->objectName().isEmpty())
            game_over->setObjectName(QString::fromUtf8("game_over"));
        game_over->resize(400, 300);
        game_over->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/setting_beginning.png);"));
        back_to_begin = new QPushButton(game_over);
        back_to_begin->setObjectName(QString::fromUtf8("back_to_begin"));
        back_to_begin->setGeometry(QRect(80, 170, 251, 31));
        QPalette palette;
        QBrush brush(QColor(239, 214, 27, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        back_to_begin->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Gabriola"));
        font.setPointSize(25);
        font.setBold(true);
        back_to_begin->setFont(font);
        back_to_begin->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/total_transparent.png);\n"
""));
        game = new QLabel(game_over);
        game->setObjectName(QString::fromUtf8("game"));
        game->setGeometry(QRect(60, 90, 151, 61));
        QPalette palette1;
        QBrush brush1(QColor(234, 220, 23, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        game->setPalette(palette1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Gabriola"));
        font1.setPointSize(40);
        game->setFont(font1);
        game->setLayoutDirection(Qt::LeftToRight);
        game->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/total_transparent.png);"));
        game->setAlignment(Qt::AlignCenter);
        over = new QLabel(game_over);
        over->setObjectName(QString::fromUtf8("over"));
        over->setGeometry(QRect(195, 85, 141, 51));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush2(QColor(244, 237, 23, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        over->setPalette(palette2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Gabriola"));
        font2.setPointSize(70);
        over->setFont(font2);
        over->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/total_transparent.png);"));

        retranslateUi(game_over);

        QMetaObject::connectSlotsByName(game_over);
    } // setupUi

    void retranslateUi(QDialog *game_over)
    {
        game_over->setWindowTitle(QCoreApplication::translate("game_over", "Dialog", nullptr));
        back_to_begin->setText(QCoreApplication::translate("game_over", "BACK TO BEGINNING", nullptr));
        game->setText(QCoreApplication::translate("game_over", "GAME", nullptr));
        over->setText(QCoreApplication::translate("game_over", "over", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game_over: public Ui_game_over {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_OVER_H
