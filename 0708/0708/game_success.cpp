#include "game_success.h"
#include "ui_game_success.h"
#include "widget.h"
#include <QString>

game_success::game_success(QWidget *parent/*,QWidget *main_widget*/, int _redReward, int _blueReward) :
    QDialog(parent),
    ui(new Ui::game_success)//,main_table(main_widget)
{
    ui->setupUi(this);
    parentWindow = parent;
    redReward = _redReward;
    blueReward = _blueReward;
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

void game_success::paintEvent (QPaintEvent* event) {
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Digital-7", 30));


    QString textRed = "";
    int tmpRed = redReward;
    if (tmpRed == 0)
        textRed = "0";
    else {
        while (tmpRed > 0) {
            QString tmpstr = "0";
            tmpstr[0] = (char)(tmpRed % 10 + '0');
            textRed = tmpstr + textRed;
        }
    }
    painter.drawText(170, 95 ,textRed);

    QString textBlue = "";
    int tmpBlue = blueReward;
    if (tmpBlue == 0)
        textBlue = "0";
    else {
        while (tmpBlue > 0) {
            QString tmpstr = "0";
            tmpstr[0] = (char)(tmpBlue % 10 + '0');
            textBlue = tmpstr + textBlue;
        }
    }
    painter.drawText(170, 140 ,textBlue);
}

void game_success::on_backButton_clicked()//童哥请在粘贴的时候在game over的时候加一句
/*
    game_success *success = new game_success(this,this);
    success->setWindowFlags(Qt::FramelessWindowHint);
    success->show();*/
{
    main_table = new Widget();
    main_table->show();
    parentWindow->close();
    this->close();
}

