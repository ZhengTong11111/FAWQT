#include "newWindow1.h"

newWindow1::newWindow1(QWidget* parent):
    QWidget(parent)
{
    curx = 10;
    cury = 10;
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &newWindow1::timeout);
    timer->start(10);
}

newWindow1::~newWindow1()
{
}

void newWindow1::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QPixmap pix;
    pix.load(":/picture_for_game/picture_for_begin_and_game/fireboy_static.png");
    painter.drawPixmap(curx, cury, 100, 100, pix);

}

void newWindow1::timeout()
{
    qDebug() << "timeout\n";
    switch(curDir)
    {
    case UP:
        cury -= 5;
        break;
    case DOWN:
        cury += 5;
        break;
    case LEFT:
        curx -= 5;
        break;
    case RIGHT:
        curx += 5;
        break;
    }
    update();
}

void newWindow1::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Up:
        curDir = UP;
        break;
    case Qt::Key_Down:
        curDir = DOWN;
        break;
    case Qt::Key_Left:
        curDir = LEFT;
        break;
    case Qt::Key_Right:
        curDir = RIGHT;
        break;
    }
}
