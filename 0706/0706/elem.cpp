#include "elem.h"

double reward::rewardWidth = 20;
double reward::rewardHeight = 20;

double gameButton::buttonWidth = 15;
double gameButton::buttonHeight = 10;

double lift::liftWidth = 61;
double lift::liftHeight = 10;

reward::reward (QRect _pos, int _color) {
    pos = _pos;
    color = _color;
    gotten = false;
}

lift::lift (QRect _uppos, QRect _downpos) {
    uppos = _uppos;
    downpos = _downpos;
    curpos = uppos;
}
void lift::liftMove () {
    if (state == LIFT_DOWN)
    {
        if (curpos.top() < downpos.top()) {
            curpos.translate(0, 5);
        } else {
            curpos = downpos;
        }
    }
    if (state == LIFT_UP) {
        if (curpos.top()  > uppos.top()) {
            curpos.translate(0, -5);
        } else {
            curpos = uppos;
        }
    }
}

gameButton::gameButton(QRect _pos) {
    clicked = false;
    pos = _pos;
}

liftButton::liftButton(QRect _pos, lift& _operLift) :
    gameButton(_pos),
    operLift(_operLift) {}

void liftButton::pressOper() {
    operLift.state = LIFT_DOWN;
}

void liftButton::noPressOper() {
    operLift.state = LIFT_UP;
}

void liftButton::timeOper() {
    if (clicked) {
        pressOper();
    } else {
        noPressOper();
    }
}
