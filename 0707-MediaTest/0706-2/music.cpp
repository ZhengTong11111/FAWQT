#include "music.h"

#include <QMediaPlayer>
#include <QMediaPlaylist>
Music::Music()
{
    //主界面bgm的路径
    name="qrc:/music/LevelMusic.mp3";
}
//设置主界面bgm的播放
void Music::setbhmusic()
{
    backlist->setPlaybackMode(QMediaPlaylist::Loop);
    backlist->addMedia(QUrl(name));
    musicg->setPlaylist(backlist);
    musicg->play();
    musicg->setVolume(50);
}
//设置主界面bgm的打开
void Music::beginbhmusic()
{
    musicg->play();
}
//设置主界面bgm的关闭
void Music::closebhmusic()
{
    musicg->stop();
}
