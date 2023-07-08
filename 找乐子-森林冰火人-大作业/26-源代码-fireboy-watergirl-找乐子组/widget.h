#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QPointF>
#include <QPainter>
#include <QImage>
#include <QImageReader>
#include <QDialog>
#include <iostream>
#include <QtCore/QPropertyAnimation>

#include "settingbeginning.h"
#include "mainbgm.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE



class Widget : public QWidget
{
    Q_OBJECT
public:
    MainBgm* mainBgm;
    bool music_on_or_off;
    bool volumn_on_or_off;
    bool musicOnOrOff();
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
private slots:
    void on_start_Button_clicked();

private slots:
    void on_setting_Button_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
