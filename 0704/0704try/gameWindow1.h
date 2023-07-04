#ifndef GAMEWINDOW1_H
#define GAMEWINDOW1_H

#endif // GAMEWINDOW1_H

#include <QWidget>
#include "man.h"
#include <QList>
#include <QRect>
#include <QKeyEvent>

class gameWindow1 : public QWidget {
public:
    gameWindow1(QWidget* parent);
    ~gameWindow1();

    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

    QTimer *timer;

    Man* fireman;
    Man* icegirl;

    QList<QRect> horiBarrier;

public slots:
    void timeout();
};
