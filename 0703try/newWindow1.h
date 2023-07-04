#ifndef NEWWINDOW1_H
#define NEWWINDOW1_H

#endif // NEWWINDOW1_H

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

class newWindow1 : public QWidget {
public:
    newWindow1(QWidget* parent);
    ~newWindow1();

    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    

    QTimer* timer;

    int curDir = RIGHT;
    int curx = 10, cury = 10;


public slots:
    void timeout();

};
