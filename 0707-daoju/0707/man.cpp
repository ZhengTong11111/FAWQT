#include "man.h"


int Man::updateTime = 10;
double Man::accX_Press = 1;
double Man::accX_noPress = 10;
double Man::maxSpeedX = 5;
double Man::accY = 0.15;
double Man::manHeight = 40;
double Man::manWidth = 30;
double Man::jumpSpeed = -5;
int Man::iniPreY = 20;

Man::Man(double iniX, double iniY) {
    curX = iniX;
    curY = iniY;
    speedX = 0;
    speedY = 0;
    remPreY = 0;
    longPress_right = false;
    longPress_left = false;
    jumping = false;
    relaToButton_cur = 0;
    relaToButton_pre = 0;
}

int Man::pullButton() {
    double man_midX = curX + manWidth / 2;
    if (man_midX > switch_midX) {
        relaToButton_cur = AT_BUTTON_RIGHT;
    }
    if (man_midX < switch_midX) {
        relaToButton_cur = AT_BUTTON_LEFT;
    }
    int res;
    if(relaToButton_cur + relaToButton_pre == 0) {
        res = relaToButton_cur;
    } else {
        res = 0;
    }
    if(relaToButton_cur != 0)
        relaToButton_pre = relaToButton_cur;
    return res;
}
void Man::manMove() {
    //水平方向移动（看移动次数距离上次按下按键是否足够）
    if (longPress_right) {
        if (speedX <= maxSpeedX) {
            speedX += accX_Press;
        }
    } else if (longPress_left) {
        if (speedX >= -1 * maxSpeedX) {
            speedX -= accX_Press;
        }
    } else {
        if (speedX > 0) {
            speedX -= accX_noPress;
            if(speedX < 0)
                speedX = 0;
        } else if (speedX < 0) {
            speedX += accX_noPress;
            if(speedX > 0)
                speedX = 0;
        } else {
            speedX = 0;
        }
    }
    curX += speedX;

    curY = curY + speedY;
    speedY += accY;
}

QRect Man::posRect() {
    return QRect(curX, curY, manWidth, manHeight);
}
