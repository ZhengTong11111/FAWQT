#ifndef MAN_H
#define MAN_H

#endif // MAN_H

#define MAN_RIGHT 1
#define MAN_STILL 0
#define MAN_LEFT -1

class Man {
public:
    static int updateTime;
    static int stepX;//水平方向步长
    static int timeX;//每次水平方向移动时间
    static int accY;//竖直方向加速度
    static int manHeight;
    static int manWidth;
    static int jumpSpeed;
    static int iniPreY;


    int curX;
    int curY;

    int dirX;
    int speedY;//纵向移动速度，以向下为正

    int cntMoveX;//向右运动还剩几次
    int remPreY;//向上跳的保护还剩几次


    Man(int iniX, int iniY);

    void manMove();//每时每刻刷新的时候移动自己
};

