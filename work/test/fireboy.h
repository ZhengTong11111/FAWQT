#ifndef FIREBOY_H
#define FIREBOY_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QPointF>
#include <QPainter>
#include <QImage>
#include <QImageReader>
#include <iostream>
class FireBoy : public QWidget
{
    Q_OBJECT
public:
    explicit FireBoy(QWidget *parent = nullptr);
private:
    int fire_height=80,fire_width=60;
protected:
    void load_fireboy();
signals:

};

#endif // FIREBOY_H
