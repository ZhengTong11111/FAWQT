#ifndef MAN_H
#define MAN_H

#endif // MAN_H

#define MAN_RIGHT 1
#define MAN_STILL 0
#define MAN_LEFT -1

class Man {
public:
    static int updateTime;
    static double stepX;//水平方向步长
    static int timeX;//每次水平方向移动时间
    static double accY;//竖直方向加速度
    static double manHeight;
    static double manWidth;
    static double jumpSpeed;
    static int iniPreY;


    double curX;
    double curY;

    int dirX;
    double speedY;//纵向移动速度，以向下为正

    int remMoveX;//向右运动还剩几次
    int remPreY;//向上跳的保护还剩几次


    Man(double iniX, double iniY);

    void manMove();//每时每刻刷新的时候移动自己
};

