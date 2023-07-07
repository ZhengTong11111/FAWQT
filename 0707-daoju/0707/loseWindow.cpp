#include "loseWindow.h"

loseWindow::loseWindow(QWidget* parent) :
    QWidget(parent)
{
    //窗口大小
    setFixedSize(800, 600);


}

void loseWindow::paintEvent(QPaintEvent* event) {
    QPainter p(this);
    //边框黑色不透明 （因为设置了窗体无边框，这行代码可能没有效果）
    p.setPen(QColor(0, 255, 0, 255));
    p.setBrush(QColor(255, 0, 0, 150));//填充红色半透明
    p.drawRect(this->rect());//绘制半透明矩形，覆盖整个窗体
    //QWidget::paintEvent(event);
}
