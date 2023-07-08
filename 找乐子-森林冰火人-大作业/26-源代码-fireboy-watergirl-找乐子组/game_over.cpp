#include "game_over.h"
#include "ui_game_over.h"
#include "widget.h"

game_over::game_over(QWidget *parent/*,QWidget *main_widget*/) :
    QDialog(parent),
    ui(new Ui::game_over)//,main_table(main_widget)
{
    parentWindow = parent;
    ui->setupUi(this);
    QPalette palette = ui->back_to_begin->palette();
    palette.setColor(QPalette::ButtonText, Qt::yellow);
    ui->back_to_begin->setPalette(palette);
    ui->back_to_begin->setStyleSheet("border: 2px solid gray;");
}

void game_over::showEvent(QShowEvent *event){
    // 设置对话框在父对象中的中心位置
    int left = 300;
    int top = 150;
    move(left, top);

    QDialog::showEvent(event);
}

game_over::~game_over()
{
    delete ui;
}

void game_over::on_back_to_begin_clicked()//童哥请在粘贴的时候在game over的时候加一句
/*
    game_over *over = new game_over(this,this);
    over->setWindowFlags(Qt::FramelessWindowHint);
    over->show();*/
{
    main_table = new Widget();
    main_table->show();
    parentWindow->close();
    this->close();
}

