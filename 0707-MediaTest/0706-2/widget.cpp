#include "widget.h"
#include "ui_widget.h"
#include "gameWindow1.h"

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
    gameWindow1* gw1=new gameWindow1(nullptr);
    gw1->show();
}

void Widget::on_setting_Button_clicked()
{

    settingBeginning *setting = new settingBeginning(this);
    setting->setWindowFlags(Qt::FramelessWindowHint);

    setting->show();
}
