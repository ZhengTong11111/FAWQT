#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QPointF>
#include <QPainter>
#include <QImage>
#include <QImageReader>
#include <iostream>
#include "fireboy.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
//按键处理
//使用定时器
//表示火娃和冰娃
enum direction{
    D_LEFT,D_RIGHT,D_UP
};


class Widget : public QWidget
{
    Q_OBJECT
protected://用于渲染
    void paintEvent(QPaintEvent *event);
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void keyPress(QKeyEvent *event);
    void fire_upadd();
    void fire_leftadd();
    void fire_rightadd();
    void fire_up_leftadd();
    void fire_up_rightadd();
    void fire_delete_last();
protected slots://是一个槽函数
    void Timeout();
private:
    Ui::Widget *ui;
    direction my_fire_move,my_ice_move;
    bool start_game=false;
    //定时器
    QTimer *TTime;
    //火娃
    QList <FireBoy> fireboy;
    QList <QRectF> icegirl;
    int height=600,width=800;//画布的大小
};
#endif // WIDGET_H
