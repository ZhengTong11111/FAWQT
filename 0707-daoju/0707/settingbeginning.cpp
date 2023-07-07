#include "settingbeginning.h"
#include "ui_settingbeginning.h"

settingBeginning::settingBeginning(QWidget *parent) :
    QDialog(parent),is_the_musicfirst_pic(true),is_the_volumnfirst_pic(true),
    ui(new Ui::settingBeginning)
{
    ui->setupUi(this);
    //设置音乐图片
    if(is_the_musicfirst_pic==true){
        QPixmap music_on_image(":/picture_for_begin/picture_for_begin_and_game/button_music.png");
        ui->music->setIcon(QIcon(music_on_image));
        ui->music->setIconSize(QSize(151,131));
        ui->music->move(210,73);
    }
    else{
        QPixmap music_off_image(":/picture_for_begin/picture_for_begin_and_game/button_music_off.png");
        ui->music->setIcon(QIcon(music_off_image));
        ui->music->setIconSize(QSize(151,131));
        ui->music->move(210,73);
    }
    //设置音效图片
    if(is_the_volumnfirst_pic==true){
        QPixmap volumn_on_image(":/picture_for_begin/picture_for_begin_and_game/button_volumn.png");
        ui->volume->setIcon(QIcon(volumn_on_image));
        ui->volume->setIconSize(QSize(100,100));
        ui->volume->move(60,60);
    }
    else{
        QPixmap volumn_off_image(":/picture_for_begin/picture_for_begin_and_game/button_volumn_off.png");
        ui->volume->setIcon(QIcon(volumn_off_image));
        ui->volume->setIconSize(QSize(100,100));
        ui->volume->move(60,60);
    }

    setting_table_animation = new QPropertyAnimation(this,"geometry");
    setting_table_animation->setDuration(500);
    setting_table_animation->setEasingCurve(QEasingCurve::InOutQuad);
}
void settingBeginning::showEvent(QShowEvent *event){


    // 设置对话框在父对象中的中心位置
    int left = 300;
    int top = 150;
    move(left, top);

    QDialog::showEvent(event);
}
settingBeginning::~settingBeginning()
{
    delete ui;
}

void settingBeginning::on_okButton_clicked()
{
    close();
}


void settingBeginning::on_volume_clicked()
{
    if(is_volumn==true){
        //emit volumn_off();
        ui->volume->setIcon(QIcon(":/picture_for_begin/picture_for_begin_and_game/button_volumn_off.png"));
        is_volumn=false;
        is_the_volumnfirst_pic=false;
    }
    else if(is_volumn==false){
        //emit volumn_on();
        ui->volume->setIcon(QIcon(":/picture_for_begin/picture_for_begin_and_game/button_volumn.png"));
        is_volumn=true;
        is_the_volumnfirst_pic=true;
    }
}


void settingBeginning::on_music_clicked()
{
    if(is_music==true){
        //emit volumn_off();
        ui->music->setIcon(QIcon(":/picture_for_begin/picture_for_begin_and_game/button_music_off.png"));
        is_music=false;
        is_the_musicfirst_pic=false;
    }
    else if(is_music==false){
        //emit volumn_on();
        ui->music->setIcon(QIcon(":/picture_for_begin/picture_for_begin_and_game/button_music.png"));
        is_music=true;
        is_the_musicfirst_pic=true;
    }
}

