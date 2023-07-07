/********************************************************************************
** Form generated from reading UI file 'settingbeginning.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGBEGINNING_H
#define UI_SETTINGBEGINNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_settingBeginning
{
public:
    QPushButton *music;
    QPushButton *volume;
    QPushButton *okButton;
    QSlider *horizontalSlider;
    QLabel *Volumelabel;

    void setupUi(QDialog *settingBeginning)
    {
        if (settingBeginning->objectName().isEmpty())
            settingBeginning->setObjectName(QString::fromUtf8("settingBeginning"));
        settingBeginning->resize(400, 300);
        settingBeginning->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/setting_beginning.png);"));
        music = new QPushButton(settingBeginning);
        music->setObjectName(QString::fromUtf8("music"));
        music->setGeometry(QRect(80, 80, 100, 100));
        music->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/total_transparent.png);"));
        volume = new QPushButton(settingBeginning);
        volume->setObjectName(QString::fromUtf8("volume"));
        volume->setGeometry(QRect(190, 60, 151, 131));
        volume->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/total_transparent.png);"));
        okButton = new QPushButton(settingBeginning);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(150, 190, 91, 31));
        QPalette palette;
        okButton->setPalette(palette);
        QFont font;
        font.setPointSize(12);
        okButton->setFont(font);
        okButton->setStyleSheet(QString::fromUtf8("border-image: url(:/picture_for_begin/picture_for_begin_and_game/button_background.png);"));
        horizontalSlider = new QSlider(settingBeginning);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(120, 50, 160, 16));
        horizontalSlider->setValue(30);
        horizontalSlider->setOrientation(Qt::Horizontal);
        Volumelabel = new QLabel(settingBeginning);
        Volumelabel->setObjectName(QString::fromUtf8("Volumelabel"));
        Volumelabel->setGeometry(QRect(160, 70, 81, 31));

        retranslateUi(settingBeginning);

        QMetaObject::connectSlotsByName(settingBeginning);
    } // setupUi

    void retranslateUi(QDialog *settingBeginning)
    {
        settingBeginning->setWindowTitle(QCoreApplication::translate("settingBeginning", "Dialog", nullptr));
        music->setText(QString());
        volume->setText(QString());
        okButton->setText(QCoreApplication::translate("settingBeginning", "OK", nullptr));
        Volumelabel->setText(QCoreApplication::translate("settingBeginning", "Volume", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settingBeginning: public Ui_settingBeginning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGBEGINNING_H
