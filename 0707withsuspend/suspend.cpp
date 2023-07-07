#include "suspend.h"
#include "ui_suspend.h"

suspend::suspend(QWidget *parent,QWidget *main_widget) :
    QDialog(parent),
    ui(new Ui::suspend),main_table(main_widget)
{
    ui->setupUi(this);
}

suspend::~suspend()
{
    delete ui;
}

void suspend::on_continue_2_clicked()
{
    this->close();
}


void suspend::on_retry_clicked()
{
    this->close();//需要在合并代码的时候重启游戏界面
}

void suspend::on_end_clicked()
{
    main_table->show();
    this->close();
}
//童哥，在合并代码的时候需要在游戏界面增加一段代码，就是按下暂停键的时候的槽
/*
void 游戏界面的类名::on_按钮名称_clicked(){
    suspend *suspending = new suspend(this,this);
    suspend->setWindowFlags(Qt::FramelessWindowHint);

    suspend->show();
*/
void suspend::showEvent(QShowEvent *event){
    // 设置对话框在父对象中的中心位置
    int left = 300;
    int top = 150;
    move(left, top);

    QDialog::showEvent(event);
}
