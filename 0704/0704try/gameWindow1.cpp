#include "gameWindow1.h"

#include <QTimer>
#include <QPainter>
#include <QDebug>


gameWindow1::gameWindow1(QWidget* parent) :
    QWidget(parent)
{
    //窗口大小
    setFixedSize(800, 600);

    //屏障坐标
    horiBarrier.clear();
    horiBarrier.push_back(QRect(0, 575, 800, 45));

    //运行过程
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &gameWindow1::timeout);
    longPress = false;

    //主要角色
    fireman = new Man(20,300);

    //开始游戏
    timer->start(Man::updateTime);




}

gameWindow1::~gameWindow1() {

}

void gameWindow1::paintEvent (QPaintEvent *event) {
    QPainter painter(this);

    QPixmap pixBg;

    pixBg.load(":/picture_for_game1/picture_for_begin_and_game/background_first.png");
    painter.drawPixmap(0,0,800,600,pixBg);

    QPixmap pixFireman;

    pixFireman.load(":/picture_for_game/picture_for_begin_and_game/fireboy_static.png");
    painter.drawPixmap(fireman->curX, fireman->curY, Man::manHeight, Man::manWidth, pixFireman);

}

void gameWindow1::timeout() {

    fireman->remPreY--;
    if (fireman->remPreY < 0)
        fireman->remPreY = 0;

    //检查有没有触及屏障，如果有，则对动作进行初始化
    for (QRect thisBarrier : horiBarrier) {
        if (thisBarrier.intersects(QRect(fireman->curX, fireman->curY, Man::manHeight, Man::manWidth))) {
            if (!(fireman->remPreY > 0))
                fireman->speedY = 0;
            fireman->curY = thisBarrier.top() - Man::manHeight;
            //qDebug() << thisBarrier.top() << "\n";
        }
    }

    //对横向移动进行操作
    if (!longPress) {
        fireman->remMoveX--;
    }
    if (fireman->remMoveX < 0) {
        fireman->remMoveX = 0;
    }

    fireman->manMove();

    update();
}



void gameWindow1::keyPressEvent(QKeyEvent *event) {
    switch(event->key())
    {
    case Qt::Key_Up:
        if (!event->isAutoRepeat()) {
            fireman->speedY = Man::jumpSpeed;
            fireman->remPreY = Man::iniPreY;
        }
        break;
    case Qt::Key_Left:
        fireman->dirX = MAN_LEFT;
        fireman->remMoveX = Man::timeX;
        longPress = true;
        qDebug() << "longPress\n";
        break;
    case Qt::Key_Right:
        fireman->dirX = MAN_RIGHT;
        fireman->remMoveX = Man::timeX;
        longPress = true;
        qDebug() << "longPress\n";
        break;
    }

}

void gameWindow1::keyReleaseEvent(QKeyEvent *event) {
    switch(event->key())
    {
    case Qt::Key_Left:
        longPress = false;
        qDebug() << "endPress\n";
        break;
    case Qt::Key_Right:
        longPress = false;
        qDebug() << "endPress\n";
        break;
    }
}
