#include "gameWindow1.h"
#include "loseWindow.h"
#include "barriers.h"
#include "game_over.h"
#include "game_success.h"

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

    //石头
    QRect stonePos(120, 210 - stoneHeight, stoneWidth, stoneHeight);
    leftBarrier.push_back(stonePos);
    floorBarrier.push_back(stonePos);

    //火池
    allFirePool.push_back(QRect(370, 575, poolWidth, poolHeight));

    //冰池
    allIcePool.push_back(QRect(535, 575, poolWidth, poolHeight));

    //绿池
    allGreenPool.push_back(QRect(500, 445, poolWidth, poolHeight));

    //红奖励
    allRewards.push_back(reward(QRect(410, 550, reward::rewardWidth, reward::rewardHeight), RED_REWARD));

    //蓝奖励
    allRewards.push_back(reward(QRect(575, 550, reward::rewardWidth, reward::rewardHeight), BLUE_REWARD));

    //竖直电梯与其控制
    //按钮
    allButton.push_back(new gameButton(QRect(270, 279, gameButton::buttonWidth1, gameButton::buttonHeight1), 1));
    allButton.push_back(new gameButton(QRect(600, 192, gameButton::buttonWidth1, gameButton::buttonHeight1), 1));

    //电梯
    allLift.push_back(lift(QRect(718, 210, lift::liftWidth, lift::liftHeight),
                           QRect(717, 304, lift::liftWidth, lift::liftHeight),
                           LIFT_VERT));
    //电梯控制设置
    allLift[0].allButtonControllingThis.push_back(allButton[0]);
    allLift[0].allButtonControllingThis.push_back(allButton[1]);

    //水平电梯与其控制
    //按钮
    allButton.push_back(new gameButton(QRect(150, 376, gameButton::buttonWidth2, gameButton::buttonHeight2), 2));
    //电梯
    allLift.push_back(lift(QRect(17, 320, lift::liftWidth, lift::liftHeight),
                           QRect(78, 320, lift::liftWidth, lift::liftHeight),
                           LIFT_HORI));
    allLift[1].allButtonControllingThis.push_back((allButton[2]));

    //门
    redDoor = door(QRect(600, 101 - door::doorHeight, door::doorWidth, door::doorHeight));
    blueDoor = door(QRect(700, 101 - door::doorHeight, door::doorWidth, door::doorHeight));

    //计时器
    //冒号
    colon=new QLabel(this);
       //colon->setPixmap(QPixmap(":/Timer_Pic/colon.png").scaled(5,30));
    colon->setGeometry(380,0,5,30);
    //个位秒
    sec1=new MyTimer();
    sec1->setParent(this);
    sec1->setGeometry(415,0,30,30);
    //十位秒
    sec10=new MyTimer();
    sec10->setParent(this);
    sec10->setGeometry(385,0,30,30);
    //分钟
    minute=new MyTimer();
    minute->setParent(this);
    minute->setGeometry(350,0,30,30);
    //设置计时器
    tGame=new QTimer(this);
    connect(tGame,&QTimer::timeout,this,&gameWindow1::setTimer);
    t=0;
    tGame->start(1000);

    //运行过程
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &gameWindow1::timeout);

    //主要角色
    fireman = new Man(500, 21);
    icegirl = new Man(600, 21);

    //开始游戏
    timer->start(Man::updateTime);


}

gameWindow1::~gameWindow1() {
    delete timer;
    delete fireman;
    delete icegirl;
}

void gameWindow1::setTimer(){
    int tmpT=t;
    int tmpMin=tmpT/60;
    int tmpSec1=tmpT%10;
    int tmpSec10=(tmpT%60)/10;
    sec1->setPixmap(sec1->pic[tmpSec1]);
    sec10->setPixmap(sec10->pic[tmpSec10]);
    minute->setPixmap(minute->pic[tmpMin]);
    colon->setPixmap(QPixmap(":/Timer_Pic/colon.png").scaled(5,30));
    t++;
}
void gameWindow1::winThisGame() {
    timer->stop();
    tGame->stop();
    gs = new game_success(this);
    gs->setWindowFlags(Qt::FramelessWindowHint);
    gs->show();

    /*(gs, &game_success::backButtonClicked, parentWidget(), [=]() {
        gs->hide();
        parentWidget()->show();
        gs->close();
    });*/

}

void gameWindow1::loseThisGame() {
    timer->stop();
    tGame->stop();
    /*loseWindow* lw = new loseWindow(this);
    lw->show();*/
    go = new game_over(this);
    go->setWindowFlags(Qt::FramelessWindowHint);
    go->show();
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

    //绘制奖励
    QPixmap redReward;
    QPixmap blueReward;

    redReward.load(":/props/picture_for_begin_and_game/reward_red.png");
    blueReward.load(":/props/picture_for_begin_and_game/reward_blue.png");
    for (reward thisReward : allRewards) {
        //这个奖励还没有被获取
        if (!thisReward.gotten) {
            //qDebug() << 1 << "\n";
            if (thisReward.color == RED_REWARD)
                painter.drawPixmap(thisReward.pos, redReward);
            else if (thisReward.color == BLUE_REWARD)
                painter.drawPixmap(thisReward.pos, blueReward);
        }
    }

    //绘制按钮
    QPixmap buttonPurple;
    buttonPurple.load(":/props/picture_for_begin_and_game/button_purple.png");
    for (gameButton* thisButton : allButton) {
        if (thisButton->type == 1) {
            painter.drawPixmap(thisButton->pos, buttonPurple);
        } else if (thisButton->type == 2) {
            if(!thisButton->clicked) {
                QPixmap switchClose;
                switchClose.load(":/props/picture_for_begin_and_game/buttons_switch_close.png");
                painter.drawPixmap(thisButton->pos, switchClose);
            } else if (thisButton->clicked) {
                QPixmap switchOpen;
                switchOpen.load(":/props/picture_for_begin_and_game/buttons_switch_open.png");
                painter.drawPixmap(thisButton->pos, switchOpen);
            }
        }
    }

    //绘制电梯
    QPixmap liftPurple;
    liftPurple.load(":/props/picture_for_begin_and_game/lift_purple.png");
    for (lift thisLift : allLift) {
        painter.drawPixmap(thisLift.curpos, liftPurple);
    }

    //绘制门
    QPixmap pRedDoorClose;
    QPixmap pRedDoorOpen;
    QPixmap pBlueDoorClose;
    QPixmap pBlueDoorOpen;
    pRedDoorClose.load(":/props/picture_for_begin_and_game/door_red_close.png");
    pRedDoorOpen.load(":/props/picture_for_begin_and_game/door_red_open.png");
    pBlueDoorClose.load(":/props/picture_for_begin_and_game/door_blue_close.png");
    pBlueDoorOpen.load(":/props/picture_for_begin_and_game/door_blue_open.png");
    if (redDoor.open) {
        painter.drawPixmap(redDoor.pos, pRedDoorOpen);
    } else {
        painter.drawPixmap(redDoor.pos, pRedDoorClose);
    }

    if (blueDoor.open) {
        painter.drawPixmap(blueDoor.pos, pBlueDoorOpen);
    } else {
        painter.drawPixmap(blueDoor.pos, pBlueDoorClose);
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

    //检查按钮是非被按下
    for (gameButton* ptrThisButton : allButton) {
        if (ptrThisButton->type == 1) {
            if (ptrThisButton->pos.intersects(fireman->posRect())
                or ptrThisButton->pos.intersects(icegirl->posRect())) { //按钮被按下
                ptrThisButton->clicked = true;
            } else { //按钮没被按下
                ptrThisButton->clicked = false;
            }
        } else if (ptrThisButton->type == 2) {
            if (ptrThisButton->pos.intersects(fireman->posRect())) { //按钮被按下
                int tmpres = fireman->pullButton();
                if(tmpres == AT_BUTTON_LEFT) {
                    ptrThisButton->clicked = true;
                } else if (tmpres == AT_BUTTON_RIGHT) {
                    ptrThisButton->clicked = false;
                }
                //qDebug() << "火娃：" << fireman->relaToButton_cur << "\n";

            }

            if (ptrThisButton->pos.intersects(icegirl->posRect())) { //按钮被按下
                int tmpres = icegirl->pullButton();
                if(tmpres == AT_BUTTON_LEFT) {
                    ptrThisButton->clicked = true;
                } else if (tmpres == AT_BUTTON_RIGHT) {
                    ptrThisButton->clicked = false;
                }
                //qDebug() << "冰娃：" << icegirl->relaToButton_cur << "\n";
            }
        }
        //ptrThisButton->timeOper();
    }

    //电梯操作
    for (lift& thisLift : allLift) {
        if (thisLift.liftType == LIFT_VERT)
            thisLift.liftMoveVert();
        if (thisLift.liftType == LIFT_HORI)
            thisLift.liftMoveHori();
        //qDebug() << QRect(thisLift.curpos.left(), thisLift.curpos.bottom(), lift::liftWidth, 0) << "\n";
        floorBarrier.push_back(QRect(thisLift.curpos.left(), thisLift.curpos.top(), lift::liftWidth, 0));
        ceilingBarrier.push_back(QRect(thisLift.curpos.left(), thisLift.curpos.bottom(), lift::liftWidth, 0));
    }

    //分别操作冰娃和火娃
    for (Man* thisman : twomen) {
        thisman->remPreY--;
        if (thisman->remPreY < 0)
            thisman->remPreY = 0;

        //检查有没有触及屏障，如果有，则对动作进行初始化

        //地面屏障
        for (QRect thisBarrier : floorBarrier) {
            if (thisBarrier.intersects(QRect(thisman->curX, thisman->curY, Man::manWidth / 2, Man::manHeight)) and
                thisBarrier.intersects(QRect(thisman->curX + Man::manWidth / 2, thisman->curY, Man::manWidth / 2, Man::manHeight))) {
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
            if (thisBarrier.intersects(QRect(thisman->curX, thisman->curY, Man::manWidth / 2, Man::manHeight)) and
                thisBarrier.intersects(QRect(thisman->curX + Man::manWidth / 2, thisman->curY, Man::manWidth / 2, Man::manHeight))) {

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
    //删除刚刚添加的电梯阻碍
    for (int i = 0; i < allLift.size(); i++) {
        floorBarrier.pop_back();
        ceilingBarrier.pop_back();
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

    //接收奖励检测
    for (reward& thisReward : allRewards) {
        if (!thisReward.gotten) {   //还没被接收，需要进行检测
            if (thisReward.color == RED_REWARD) {
                //红色奖励
                if (thisReward.pos.intersects(fireman->posRect())) {
                    thisReward.gotten = true;
                    fireman->getRewards++;
                }
            } else if (thisReward.color == BLUE_REWARD) {
                //蓝色奖励
                if (thisReward.pos.intersects(icegirl->posRect())) {
                    thisReward.gotten = true;
                    icegirl->getRewards++;
                }
            }
        }
    }

    //门检测
    if (redDoor.pos.intersects(fireman->posRect())) {
        redDoor.open = true;
    } else {
        redDoor.open = false;
    }

    if (blueDoor.pos.intersects(icegirl->posRect())) {
        blueDoor.open = true;
    } else {
        blueDoor.open = false;
    }

    update();

    if (blueDoor.open and redDoor.open) {
        winThisGame();
    }
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

