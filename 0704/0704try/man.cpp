#include "man.h"


int Man::updateTime = 10;
int Man::stepX = 10;
int Man::timeX = 10;
int Man::accY = 1;
int Man::manHeight = 50;
int Man::manWidth = 50;
int Man::jumpSpeed = -20;
int Man::iniPreY = 5;

Man::Man(int iniX, int iniY) {
    curX = iniX;
    curY = iniY;
    dirX = MAN_STILL;
    speedY = 0;
    cntMoveX = Man::timeX;
    remPreY = 0;
}

void Man::manMove() {
    //水平方向移动（看移动次数距离上次按下按键是否足够）
    if(cntMoveX < updateTime) {
        cntMoveX++;
        if (dirX == MAN_RIGHT) {
            curX += stepX;
        } else if (dirX == MAN_LEFT) {
            curX -= stepX;
        }
    }

    curY = curY + speedY;
    speedY += accY;

}
