#include "widget.h"
#include "ui_widget.h"
#include "newWindow1.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),
     ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_start_Button_clicked()
{
    this->close();
    newWindow1* gw1=new newWindow1(nullptr);
    gw1->show();
}

