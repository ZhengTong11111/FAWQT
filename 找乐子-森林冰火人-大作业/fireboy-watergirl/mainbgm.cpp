#include "mainbgm.h"

MainBgm::MainBgm(QObject *parent) : QObject(parent)
{
    playlist = new QMediaPlaylist();
    player = new QMediaPlayer();
    player->setPlaylist(playlist);
}

void MainBgm::addBgmFiles() {
    playlist->addMedia(QUrl("qrc:/MenuMusic.mp3"));

    // 添加所有的BGM文件
}

void MainBgm::setLooping() {
    playlist->setPlaybackMode(QMediaPlaylist::Loop); // 设置循环播放模式
}

void MainBgm::play() {
    player->play(); // 开始播放
}

void MainBgm::stop() {
    player->stop(); // 停止播放
}
