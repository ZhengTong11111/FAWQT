#include "game_success.h"
#include "ui_game_success.h"

game_success::game_success(QWidget *parent,QWidget *main_widget) :
    QDialog(parent),
    ui(new Ui::game_success),main_table(main_widget)
{
    ui->setupUi(this);
}

game_success::~game_success()
{
    delete ui;
}

void game_success::showEvent(QShowEvent *event){
    // 设置对话框在父对象中的中心位置
    int left = 300;
    int top = 150;
    move(left, top);

    QDialog::showEvent(event);
}

void game_success::on_backButton_clicked()//童哥请在粘贴的时候在game over的时候加一句
/*
    game_success *success = new game_success(this,this);
    success->setWindowFlags(Qt::FramelessWindowHint);
    success->show();*/
{
    main_table->show();
    this->close();

}

