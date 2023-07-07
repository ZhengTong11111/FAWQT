#ifndef ELEM_H
#define ELEM_H

#endif // ELEM_H

#define RED_REWARD 0
#define BLUE_REWARD 1

#define LIFT_PRESS 0
#define LIFT_NOPRESS 1

#include <QRect>
#include <QList>

class reward {
public:
    QRect pos;
    int color;//奖励颜色
    bool gotten;

    reward(QRect _pos, int _color);

    static double rewardWidth;
    static double rewardHeight;
};

class gameButton {
public:
    bool clicked;//按钮是否正在被按下
    QRect pos;
    gameButton(QRect _pos, int _type);
    //virtual void timeOper() = 0;
    static double buttonWidth1;
    static double buttonHeight1;
    static double buttonWidth2;
    static double buttonHeight2;
    int type;
};

#define LIFT_VERT 0
#define LIFT_HORI 1

class lift {
public:
    int liftType;
    bool state;
    QRect curpos;
    QRect posNoPress;
    QRect posPress;
    QList<gameButton*> allButtonControllingThis;
    lift (QRect _posNoPress, QRect _posPress, int _liftType);
    void liftMoveVert();
    void liftMoveHori();
    static double liftWidth;
    static double liftHeight;
};

class door {
public:
    static double doorWidth;
    static double doorHeight;
    bool open;
    QRect pos;
    door(QRect _pos);
    door();
};

/*class liftButton : public gameButton{
public:
    lift& operLift;
    liftButton(QRect pos, lift& _operLift);
    void pressOper();
    void noPressOper();
    void timeOper();
};*/
