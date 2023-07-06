#ifndef ELEM_H
#define ELEM_H

#endif // ELEM_H

#define RED_REWARD 0
#define BLUE_REWARD 1

#define LIFT_DOWN 0
#define LIFT_UP 1

#include <QRect>

class reward {
public:
    QRect pos;
    int color;//奖励颜色
    bool gotten;

    reward(QRect _pos, int _color);

    static double rewardWidth;
    static double rewardHeight;
};

class lift {
public:
    bool state;
    QRect curpos;
    QRect uppos;
    QRect downpos;
    lift(QRect _uppos, QRect _downpos);
    void liftMove();
    static double liftWidth;
    static double liftHeight;
};

class gameButton {
public:
    bool clicked;//按钮是否正在被按下
    QRect pos;
    gameButton(QRect _pos);
    virtual void timeOper() = 0;
    static double buttonWidth;
    static double buttonHeight;
};

class liftButton : public gameButton{
public:
    lift& operLift;
    liftButton(QRect pos, lift& _operLift);
    void pressOper();
    void noPressOper();
    void timeOper();
};
