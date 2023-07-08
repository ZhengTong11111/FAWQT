#ifndef LOSEWINDOW_H
#define LOSEWINDOW_H

#endif // LOSEWINDOW_H

#include <QWidget>
#include <QPainter>

class loseWindow : public QWidget {
public:
    loseWindow(QWidget* parent);

    void paintEvent(QPaintEvent* event) override;

};
