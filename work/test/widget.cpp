#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    TTime=new QTimer();//信号槽（信号 和对应的函数关联起来）
    //定时器有一个timeout信号
    //关联了时间
    connect(TTime,SIGNAL(Timeout()),this,SLOT(Timeout()));
    //加入冰娃火娃

}

Widget::~Widget()
{
    delete ui;
}
//TTime->start(100)//启动定时器，每100ms超时一次
void Widget::keyPress(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_Up:
        my_fire_move=D_UP;
        break;
    case Qt::Key_Left:
        if(my_fire_move!=D_RIGHT){
            my_fire_move=D_LEFT;
        }
        break;
    case Qt::Key_Right:
        if(my_fire_move!=D_LEFT){
            my_fire_move=D_RIGHT;
        }
        break;
    case Qt::Key_W:
        my_ice_move=D_UP;
        break;
    case Qt::Key_A:
        if(my_ice_move!=D_RIGHT){
            my_ice_move=D_LEFT;
        }
        break;
    case Qt::Key_D:
        if(my_ice_move!=D_LEFT){
            my_ice_move=D_RIGHT;
        }
        break;
    case Qt::Key_Space:
        if(start_game==true){
            start_game=false;
            TTime->stop();
        }
        else{
            start_game=true;
            TTime->start();
        }
    default:
        break;
    }
}

void Widget::Timeout(){
    switch(my_fire_move){
    case D_UP:
        //在顶部加一个火娃
        fire_upadd();
        fire_delete_last();
        update();
        break;
    case D_RIGHT:
        fire_rightadd();
        update();
        break;
    case D_LEFT:
        fire_leftadd();
        update();
        break;
    default:
        break;
    }

    switch(my_ice_move){
    case D_UP:
        break;
    case D_RIGHT:
        break;
    case D_LEFT:
        break;
    default:
        break;
    }

}
//->x轴
//|y轴
/*void Widget::fire_upadd(){//火娃向上蹦
    QPointF fire_lefttop;
    QPointF fire_rightdown;//左上右下的位置定住
    fire_lefttop= QPointF(fireboy[0].x(),fireboy[0].y()+height);//新的火娃的左上角就是原火娃的y+高度，x不变
    fire_rightdown=fireboy[0].topRight();//新的火娃的右下角就是 原火娃右上角
    fireboy.insert(0,QRectF(fire_lefttop,fire_rightdown));
}
void Widget::fire_delete_last(){
    fireboy.removeLast();
}
void Widget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QImageReader reader;
    QImage image;
    reader.setDecideFormatFromContent(true);
    reader.setScaledSize(QSize(width,height));
    reader.setFileName("D:\\qt\\work\\background_wall.jpg");
    if(reader.canRead()){
        if(!reader.read(&image)){
            QImageReader::ImageReaderError error=reader.error();
            QString strError =reader.errorString();
            std::cout<<"last error:"<<strError.toStdString().c_str()<<std::endl;
            return;
        }
    }
    painter.drawPixmap(0,0,width,height,QPixmap::fromImage(image));
    //background image

}

*/
