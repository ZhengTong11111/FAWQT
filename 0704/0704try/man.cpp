#include "man.h"


int Man::updateTime = 10;
double Man::stepX = 2;
int Man::timeX = 10;
double Man::accY = 0.1;
double Man::manHeight = 50;
double Man::manWidth = 50;
double Man::jumpSpeed = -5;
int Man::iniPreY = 5;

Man::Man(double iniX, double iniY) {
    curX = iniX;
    curY = iniY;
    dirX = MAN_STILL;
    speedY = 0;
    remMoveX = Man::timeX;
    remPreY = 0;
}

void Man::manMove() {
    //水平方向移动（看移动次数距离上次按下按键是否足够）
    if(remMoveX > 0) {
        //remMoveX--;
        if (dirX == MAN_RIGHT) {
            curX += stepX;
        } else if (dirX == MAN_LEFT) {
            curX -= stepX;
        }
    }
    //else
    //    remMoveX = 0;

    curY = curY + speedY;
    speedY += accY;

}
