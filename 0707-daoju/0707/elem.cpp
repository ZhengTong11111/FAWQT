#include "elem.h"

double reward::rewardWidth = 20;
double reward::rewardHeight = 20;

double gameButton::buttonWidth1 = 36;
double gameButton::buttonHeight1 = 18;

double gameButton::buttonWidth2 = 36;
double gameButton::buttonHeight2 = 36;

double lift::liftWidth = 61;
double lift::liftHeight = 10;

reward::reward (QRect _pos, int _color) {
    pos = _pos;
    color = _color;
    gotten = false;
}

lift::lift (QRect _posNoPress, QRect _posPress, int _liftType) {
    posNoPress = _posNoPress;
    posPress = _posPress;
    liftType = _liftType;
    curpos = posNoPress;
    allButtonControllingThis.clear();
}

void lift::liftMoveVert () {
    state = LIFT_NOPRESS;
    bool havePress = false;
    for (gameButton* thisButton : allButtonControllingThis) {
        havePress = havePress or thisButton->clicked;
    }
    if (havePress) {
        state = LIFT_PRESS;
    }
    if (state == LIFT_PRESS)
    {
        if (curpos.top() < posPress.top()) {
            curpos.translate(0, 5);
        } else {
            curpos = posPress;
        }
    }
    if (state == LIFT_NOPRESS) {
        if (curpos.top()  > posNoPress.top()) {
            curpos.translate(0, -5);
        } else {
            curpos = posNoPress;
        }
    }
}

void lift::liftMoveHori () {
    state = LIFT_NOPRESS;
    bool havePress = false;
    for (gameButton* thisButton : allButtonControllingThis) {
        havePress = havePress or thisButton->clicked;
    }
    if (havePress) {
        state = LIFT_PRESS;
    }
    if (state == LIFT_PRESS)
    {
        if (curpos.left() < posPress.left()) {
            curpos.translate(5, 0);
        } else {
            curpos = posPress;
        }
    }
    if (state == LIFT_NOPRESS) {
        if (curpos.left() > posNoPress.left()) {
            curpos.translate(-5, 0);
        } else {
            curpos = posNoPress;
        }
    }
}

gameButton::gameButton(QRect _pos, int _type) {
    clicked = false;
    pos = _pos;
    type = _type;
}

/*liftButton::liftButton(QRect _pos, lift& _operLift) :
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
}*/
