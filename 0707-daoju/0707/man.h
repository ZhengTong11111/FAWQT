#ifndef MAN_H
#define MAN_H

#endif // MAN_H

#define MAN_RIGHT 1
#define MAN_STILL 0
#define MAN_LEFT -1

#define AT_BUTTON_LEFT -1
#define AT_BUTTON_RIGHT 1

#include <QRect>

const double switch_midX = 168;

class Man {
public:
    static int updateTime;
    static double accX_Press;//按键状态下加速度
    static double accX_noPress;//摩擦力状态下水平加速度
    static double maxSpeedX;//水平方向最大速度
    static double accY;//竖直方向加速度
    static double manHeight;
    static double manWidth;
    static double jumpSpeed;
    static int iniPreY;


    double curX;
    double curY;

    double speedX;//水平移动速度，以向右为正
    double speedY;//纵向移动速度，以向下为正

    int remPreY;//向上跳的保护还剩几次

    bool longPress_right;
    bool longPress_left;

    bool jumping;//在空中，停止按键操作


    Man(double iniX, double iniY);

    void manMove();//每时每刻刷新的时候移动自己

    QRect posRect();

    int relaToButton_cur;
    int relaToButton_pre;

    int pullButton();

    int getRewards;

};

