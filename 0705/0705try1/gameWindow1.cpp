#include "gameWindow1.h"
#include "loseWindow.h"
#include "barriers.h"

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
    for(int i=0;i<19;i++){
        floorBarrier.push_back(QRect(myFloor[i][1], myFloor[i][0], myFloor[i][2]-myFloor[i][1], 0));
    }

    ceilingBarrier.clear();
    for(int i=0;i<19;i++){
        ceilingBarrier.push_back(QRect(myCeiling[i][1], myCeiling[i][0], myCeiling[i][2]-myCeiling[i][1], 0));
    }

    rightBarrier.clear();
    for(int i=0;i<19;i++){
        rightBarrier.push_back(QRect(myRight[i][0], myRight[i][1], 0, myRight[i][2]-myRight[i][1]));
    }


    leftBarrier.clear();
    for(int i=0;i<19;i++){
        leftBarrier.push_back(QRect(myLeft[i][0], myLeft[i][1], 0, myLeft[i][2]-myLeft[i][1]));
    }


    //火池
    allFirePool.push_back(QRect(370, 575, poolWidth, poolHeight));

    //冰池
    allIcePool.push_back(QRect(535, 575, poolWidth, poolHeight));

    //绿池
    allGreenPool.push_back(QRect(500, 445, poolWidth, poolHeight));


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

    //障碍物指示
    painter.setPen(Qt::red);
    for (QRect thisBarrier : floorBarrier) {
        painter.drawRect(thisBarrier);
    }

    for (QRect thisBarrier : ceilingBarrier) {
        painter.drawRect(thisBarrier);
    }

    for (QRect thisBarrier : leftBarrier) {
        painter.drawRect(thisBarrier);
    }

    for (QRect thisBarrier : rightBarrier) {
        painter.drawRect(thisBarrier);
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
                if (!(thisman->remPreY > 0)) {
                    thisman->speedY = 0;
                    thisman->curY = thisBarrier.top() - Man::manHeight;
                    thisman->jumping = false;
                }
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
                thisman->speedX = 0;
                thisman->longPress_left = false;
                thisman->longPress_right = false;
                thisman->curX = thisBarrier.left() - thisman->manWidth - 1;
            }
        }

        for (QRect thisBarrier : leftBarrier) {
            if (thisBarrier.intersects(QRect(thisman->curX, thisman->curY, Man::manWidth, Man::manHeight))) {
                //停止向左移动
                thisman->speedX = 0;
                thisman->longPress_left = false;
                thisman->longPress_right = false;
                thisman->curX = thisBarrier.right() + 1;
            }
        }

        //对横向移动进行操作

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
        if (fireman->jumping)
            break;
        if (!event->isAutoRepeat()) {
            fireman->speedY = Man::jumpSpeed;
            fireman->remPreY = Man::iniPreY;
            fireman->jumping = true;
        }
        break;
    case Qt::Key_Left:
        fireman->longPress_left = true;
        fireman->longPress_right = false;
        //qDebug() << "longPress\n";
        break;
    case Qt::Key_Right:
        fireman->longPress_left = false;
        fireman->longPress_right = true;
        //qDebug() << "longPress\n";
        break;
    }

    //冰娃操作
    switch(event->key())
    {
    case Qt::Key_W:
        if (icegirl->jumping)
            break;
        if (!event->isAutoRepeat()) {
            icegirl->speedY = Man::jumpSpeed;
            icegirl->remPreY = Man::iniPreY;
            icegirl->jumping = true;
        }
        break;
    case Qt::Key_A:
        icegirl->longPress_left = true;
        icegirl->longPress_right = false;
        //qDebug() << "longPress\n";
        break;
    case Qt::Key_D:
        icegirl->longPress_left = false;
        icegirl->longPress_right = true;
        //qDebug() << "longPress\n";
        break;
    }
}

void gameWindow1::keyReleaseEvent(QKeyEvent *event) {
    switch(event->key())
    {
    case Qt::Key_Left:
        fireman->longPress_left = false;
        //qDebug() << "endPress\n";
        break;
    case Qt::Key_Right:
        fireman->longPress_right = false;
        //qDebug() << "endPress\n";
        break;
    }

    switch(event->key())
    {
    case Qt::Key_A:
        icegirl->longPress_left = false;
        //qDebug() << "endPress\n";
        break;
    case Qt::Key_D:
        icegirl->longPress_right = false;
        //qDebug() << "endPress\n";
        break;
    }
}
