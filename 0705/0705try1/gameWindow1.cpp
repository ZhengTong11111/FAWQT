#include "gameWindow1.h"
#include "loseWindow.h"

#include <QTimer>
#include <QPainter>
#include <QDebug>
#include <cmath>

gameWindow1::gameWindow1(QWidget* parent) :
    QWidget(parent)
{
    //窗口大小
    setFixedSize(800, 600);

    //屏障坐标
    floorBarrier.clear();
    floorBarrier.push_back(QRect(0, 580, 800, 45));

    ceilingBarrier.clear();
    ceilingBarrier.push_back(QRect(0,0,800,20));

    rightBarrier.clear();
    rightBarrier.push_back(QRect(750, 0, 50, 600));

    leftBarrier.clear();
    leftBarrier.push_back(QRect(0, 0, 50, 600));

    //火池
    allFirePool.push_back(QRect(400, 580, poolWidth, poolHeight));

    //冰池
    allIcePool.push_back(QRect(500, 580, poolWidth, poolHeight));

    //绿池
    allGreenPool.push_back(QRect(400, 400, poolWidth, poolHeight));


    //

    //运行过程
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &gameWindow1::timeout);

    //主要角色
    fireman = new Man(200, 300);
    icegirl = new Man(300, 300);

    //开始游戏
    timer->start(Man::updateTime);




}

gameWindow1::~gameWindow1() {
    delete timer;
    delete fireman;
    delete icegirl;
}

void gameWindow1::loseThisGame() {
    timer->stop();
    loseWindow* lw = new loseWindow(this);
    lw->show();
}

bool gameWindow1::inPool(QRect man, QRect pool) {
    double midManX = (double)(man.left() + man.right()) / 2;
    //在池子上
    if(abs(man.bottom() - pool.top()) < 8) {
        //半个身子进入了池子
        if(midManX > pool.left() and midManX < pool.right()) {
            return true;
        }
    }
    return false;
}

void gameWindow1::paintEvent (QPaintEvent *event) {
    QPainter painter(this);

    QPixmap pixBg;

    pixBg.load(":/picture_for_game1/picture_for_begin_and_game/background_first.png");
    painter.drawPixmap(0,0,800,600,pixBg);

    QPixmap pixFireman;

    pixFireman.load(":/picture_for_game/picture_for_begin_and_game/fireboy_static.png");
    painter.drawPixmap(fireman->curX, fireman->curY, Man::manWidth, Man::manHeight, pixFireman);

    QPixmap pixIcegirl;

    pixIcegirl.load(":/picture_for_game/picture_for_begin_and_game/icegirl_static.png");
    painter.drawPixmap(icegirl->curX, icegirl->curY, Man::manWidth, Man::manHeight, pixIcegirl);

    QPixmap firePool;
    firePool.load(":/props/picture_for_begin_and_game/firepool.png");
    for (QRect thisPool : allFirePool) {
        painter.drawPixmap(thisPool.left(), thisPool.top(), thisPool.width(), thisPool.height(), firePool);
        //qDebug() << thisPool.top() << " " << thisPool.left() << "\n";
    }

    QPixmap icePool;
    icePool.load(":/props/picture_for_begin_and_game/icepool.png");
    for (QRect thisPool : allIcePool) {
        painter.drawPixmap(thisPool.left(), thisPool.top(), thisPool.width(), thisPool.height(), icePool);
    }

    QPixmap greenPool;
    greenPool.load(":/props/picture_for_begin_and_game/greenpool.png");
    for (QRect thisPool : allGreenPool) {
        painter.drawPixmap(thisPool.left(), thisPool.top(), thisPool.width(), thisPool.height(), greenPool);
    }


}

void gameWindow1::timeout() {

    QList<Man*> twomen = {fireman, icegirl};

    //分别操作冰娃和火娃
    for (Man* thisman : twomen) {
        thisman->remPreY--;
        if (thisman->remPreY < 0)
            thisman->remPreY = 0;

        //检查有没有触及屏障，如果有，则对动作进行初始化

        //地面屏障
        for (QRect thisBarrier : floorBarrier) {
            if (thisBarrier.intersects(QRect(thisman->curX, thisman->curY, Man::manWidth, Man::manHeight))) {
                //正在向下移动

                //判断是否刚刚起跳
                if (!(thisman->remPreY > 0))
                    thisman->speedY = 0;
                thisman->curY = thisBarrier.top() - Man::manHeight;
                //qDebug() << thisBarrier.top() << "\n";
            }
        }

        //天花板屏障
        for (QRect thisBarrier : ceilingBarrier) {
            if (thisBarrier.intersects(QRect(thisman->curX, thisman->curY, Man::manWidth, Man::manHeight))) {

                thisman->speedY = 0;
                thisman->curY = thisBarrier.bottom() + 1;
            }
        }

        //处在右侧的屏障
        for (QRect thisBarrier : rightBarrier) {
            if (thisBarrier.intersects(QRect(thisman->curX, thisman->curY, Man::manWidth, Man::manHeight))) {
                //停止向右移动
                thisman->remMoveX = 0;
                thisman->curX = thisBarrier.left() - thisman->manWidth - 1;
            }
        }

        for (QRect thisBarrier : leftBarrier) {
            if (thisBarrier.intersects(QRect(thisman->curX, thisman->curY, Man::manWidth, Man::manHeight))) {
                //停止向左移动
                thisman->remMoveX = 0;
                thisman->curX = thisBarrier.right() + 1;
            }
        }

        //对横向移动进行操作
        if (!thisman->longPress) {
            thisman->remMoveX--;
        }
        if (thisman->remMoveX < 0) {
            thisman->remMoveX = 0;
        }

        thisman->manMove();
    }

    //进入池子检测
    for (QRect thisPool : allFirePool) {
        //火池会让冰娃失败
        if(inPool(QRect(icegirl->curX, icegirl->curY, Man::manWidth, Man::manHeight), thisPool)) {
            loseThisGame();
        }
    }

    for (QRect thisPool : allIcePool) {
        if(inPool(QRect(fireman->curX, fireman->curY, Man::manWidth, Man::manHeight), thisPool)) {
            loseThisGame();
        }
    }

    for (QRect thisPool : allGreenPool) {

        if(inPool(QRect(icegirl->curX, icegirl->curY, Man::manWidth, Man::manHeight), thisPool)) {
            loseThisGame();
        }

        if(inPool(QRect(fireman->curX, fireman->curY, Man::manWidth, Man::manHeight), thisPool)) {
            loseThisGame();
        }
    }

    update();
}



void gameWindow1::keyPressEvent(QKeyEvent *event) {

    //火娃操作
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
        fireman->longPress = true;
        //qDebug() << "longPress\n";
        break;
    case Qt::Key_Right:
        fireman->dirX = MAN_RIGHT;
        fireman->remMoveX = Man::timeX;
        fireman->longPress = true;
        //qDebug() << "longPress\n";
        break;
    }

    //冰娃操作
    switch(event->key())
    {
    case Qt::Key_W:
        if (!event->isAutoRepeat()) {
            icegirl->speedY = Man::jumpSpeed;
            icegirl->remPreY = Man::iniPreY;
        }
        break;
    case Qt::Key_A:
        icegirl->dirX = MAN_LEFT;
        icegirl->remMoveX = Man::timeX;
        icegirl->longPress = true;
        //qDebug() << "longPress\n";
        break;
    case Qt::Key_D:
        icegirl->dirX = MAN_RIGHT;
        icegirl->remMoveX = Man::timeX;
        icegirl->longPress = true;
        //qDebug() << "longPress\n";
        break;
    }
}

void gameWindow1::keyReleaseEvent(QKeyEvent *event) {
    switch(event->key())
    {
    case Qt::Key_Left:
        fireman->longPress = false;
        //qDebug() << "endPress\n";
        break;
    case Qt::Key_Right:
        fireman->longPress = false;
        //qDebug() << "endPress\n";
        break;
    }

    switch(event->key())
    {
    case Qt::Key_A:
        icegirl->longPress = false;
        //qDebug() << "endPress\n";
        break;
    case Qt::Key_D:
        icegirl->longPress = false;
        //qDebug() << "endPress\n";
        break;
    }
}
