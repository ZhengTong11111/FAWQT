#ifndef GAMEWINDOW1_H
#define GAMEWINDOW1_H

#endif // GAMEWINDOW1_H

#include <QWidget>
#include "man.h"
#include <QList>
#include <QRect>
#include <QKeyEvent>

const int poolWidth = 100;
const int poolHeight = 20;

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

    void loseThisGame();

    bool inPool(QRect man, QRect pool);



public slots:
    void timeout();
};
