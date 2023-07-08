#include "mytimer.h"

MyTimer::MyTimer()
{
    pic[0].load(":/Timer_Pic/0.png");
    pic[1].load(":/Timer_Pic/1.png");
    pic[2].load(":/Timer_Pic/2.png");
    pic[3].load(":/Timer_Pic/3.png");
    pic[4].load(":/Timer_Pic/4.png");
    pic[5].load(":/Timer_Pic/5.png");
    pic[6].load(":/Timer_Pic/6.png");
    pic[7].load(":/Timer_Pic/7.png");
    pic[8].load(":/Timer_Pic/8.png");
    pic[9].load(":/Timer_Pic/9.png");
    for(int i=0;i<10;i++){
        pic[i]=pic[i].scaled(30,30);
    }
}
