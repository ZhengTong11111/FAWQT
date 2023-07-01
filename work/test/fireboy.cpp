#include "fireboy.h"

FireBoy::FireBoy(QWidget *parent)
    : QWidget{parent}
{

}

void FireBoy::load_fireboy(){
    QPainter painter(this);
    QImageReader reader;
    QImage image;
    reader.setDecideFormatFromContent(true);
    reader.setScaledSize(QSize(fire_width,fire_height));
    reader.setFileName("D:\\qt\\work\\fireboy_static.png");
    if(reader.canRead()){
        if(!reader.read(&image)){
            QImageReader::ImageReaderError error=reader.error();
            QString strError =reader.errorString();
            std::cout<<"last error:"<<strError.toStdString().c_str()<<std::endl;
            return;
        }
    }
    painter.drawPixmap(0,0,fire_width,fire_height,QPixmap::fromImage(image));
}
