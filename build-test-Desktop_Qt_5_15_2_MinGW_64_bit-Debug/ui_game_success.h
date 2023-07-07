/********************************************************************************
** Form generated from reading UI file 'game_success.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_SUCCESS_H
#define UI_GAME_SUCCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_game_success
{
public:
    QPushButton *backButton;

    void setupUi(QDialog *game_success)
    {
        if (game_success->objectName().isEmpty())
            game_success->setObjectName(QString::fromUtf8("game_success"));
        game_success->resize(400, 300);
        game_success->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/game_success.png);"));
        backButton = new QPushButton(game_success);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(120, 220, 171, 31));
        QPalette palette;
        QBrush brush(QColor(248, 224, 61, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        backButton->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Gabriola"));
        font.setPointSize(30);
        backButton->setFont(font);
        backButton->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/total_transparent.png);"));

        retranslateUi(game_success);

        QMetaObject::connectSlotsByName(game_success);
    } // setupUi

    void retranslateUi(QDialog *game_success)
    {
        game_success->setWindowTitle(QCoreApplication::translate("game_success", "Dialog", nullptr));
        backButton->setText(QCoreApplication::translate("game_success", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game_success: public Ui_game_success {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_SUCCESS_H
