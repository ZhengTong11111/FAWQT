#include "widget.h"
#include "ui_widget.h"


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
    hide();
    gw1=new gameWindow1(nullptr);
    gw1->show();


    //返回主界面
    connect(gw1->gs,&game_success::backButtonClicked,this,[=](){

        show();gw1->close();
    });


}

void Widget::on_setting_Button_clicked()
{

    settingBeginning *setting = new settingBeginning(this);
    setting->setWindowFlags(Qt::FramelessWindowHint);

    setting->show();
}
