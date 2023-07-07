#ifndef GAMEWINDOW1_H
#define GAMEWINDOW1_H

#endif // GAMEWINDOW1_H

#include <QWidget>
#include <QList>
#include <QRect>
#include <QKeyEvent>

#include "man.h"
#include "elem.h"

const int poolWidth = 100;
const int poolHeight = 20;

const int stoneWidth = 30;
const int stoneHeight = 30;

class gameWindow1 : public QWidget {
public:
    gameWindow1(QWidget* parent);
    ~gameWindow1();

public:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    QTimer *timer;


    Man* fireman;
    Man* icegirl;

    QList<QRect> floorBarrier;
    QList<QRect> ceilingBarrier;
    QList<QRect> rightBarrier;
    QList<QRect> leftBarrier;

    QList<QRect> allFirePool;
    QList<QRect> allIcePool;
    QList<QRect> allGreenPool;

    QList<reward> allRewards;

    QList<lift> allLift;
    QList<gameButton*> allButton;

    door redDoor;
    door blueDoor;

    void loseThisGame();
    void winThisGame();

    bool inPool(QRect man, QRect pool);

public slots:
    void timeout();
};
