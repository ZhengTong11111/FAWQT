#include "newWindow1.h"

newWindow1::newWindow1(QWidget* parent):
    QWidget(parent)
{
    curx = 10;
    cury = 10;
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
    timer->start(1000);
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
        cury -= 10;
        break;
    case DOWN:
        cury += 10;
        break;
    case LEFT:
        curx -= 10;
        break;
    case RIGHT:
        curx += 10;
        break;
    }
    //update();
}
