#include "widget.h"
#include "ui_widget.h"
#include "gameWindow1.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent),
     ui(new Ui::Widget)
{
    ui->setupUi(this);

    mainBgm=new MainBgm();
    mainBgm->addBgmFiles(); // 添加BGM文件
    mainBgm->setLooping(); // 设置循环播放模式
    mainBgm->play();
    music_on_or_off=true;
    volumn_on_or_off=true;

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_start_Button_clicked()
{
    this->close();
    gameWindow1* gw1=new gameWindow1(nullptr,music_on_or_off,volumn_on_or_off);
    gw1->show();
    mainBgm->stop();
}

void Widget::on_setting_Button_clicked()
{

    settingBeginning *setting = new settingBeginning(this);
    setting->setWindowFlags(Qt::FramelessWindowHint);

    setting->show();
    connect(setting,&settingBeginning::music_on,[=](){
        mainBgm->play();
        this->music_on_or_off=true;
    });
    connect(setting,&settingBeginning::music_off,[=](){
        mainBgm->stop();
        this->music_on_or_off=false;
    });
    connect(setting,&settingBeginning::volumn_on,[=](){
        this->volumn_on_or_off=true;
    });
    connect(setting,&settingBeginning::volumn_off,[=](){
        this->volumn_on_or_off=false;
    });
}

bool Widget::musicOnOrOff(){
    return this->music_on_or_off;
};
