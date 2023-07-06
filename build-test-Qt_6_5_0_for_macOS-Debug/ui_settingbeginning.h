/********************************************************************************
** Form generated from reading UI file 'settingbeginning.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGBEGINNING_H
#define UI_SETTINGBEGINNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_settingBeginning
{
public:
    QPushButton *music;
    QPushButton *volume;
    QPushButton *okButton;

    void setupUi(QDialog *settingBeginning)
    {
        if (settingBeginning->objectName().isEmpty())
            settingBeginning->setObjectName("settingBeginning");
        settingBeginning->resize(400, 300);
        settingBeginning->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/setting_beginning.png);"));
        music = new QPushButton(settingBeginning);
        music->setObjectName("music");
        music->setGeometry(QRect(80, 80, 100, 100));
        music->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/total_transparent.png);"));
        volume = new QPushButton(settingBeginning);
        volume->setObjectName("volume");
        volume->setGeometry(QRect(190, 60, 151, 131));
        volume->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/total_transparent.png);"));
        okButton = new QPushButton(settingBeginning);
        okButton->setObjectName("okButton");
        okButton->setGeometry(QRect(150, 190, 91, 31));
        QPalette palette;
        okButton->setPalette(palette);
        QFont font;
        font.setPointSize(12);
        okButton->setFont(font);
        okButton->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/button_background.png);"));

        retranslateUi(settingBeginning);

        QMetaObject::connectSlotsByName(settingBeginning);
    } // setupUi

    void retranslateUi(QDialog *settingBeginning)
    {
        settingBeginning->setWindowTitle(QCoreApplication::translate("settingBeginning", "Dialog", nullptr));
        music->setText(QString());
        volume->setText(QString());
        okButton->setText(QCoreApplication::translate("settingBeginning", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settingBeginning: public Ui_settingBeginning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGBEGINNING_H
