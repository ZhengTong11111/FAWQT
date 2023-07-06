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
