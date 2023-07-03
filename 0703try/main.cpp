#include "widget.h"
#include "newWindow1.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget *w = new Widget(nullptr);
    w->show();
    return a.exec();
}
