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
#include "gameWindow1.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


class Widget : public QWidget
{
    Q_OBJECT
public:
    gameWindow1* gw1;
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
