#include "gamebgm.h"

GameBgm::GameBgm(QObject *parent) : QObject(parent)
{
    playlist = new QMediaPlaylist();
    player = new QMediaPlayer();
    player->setPlaylist(playlist);
}

void GameBgm::addBgmFiles() {
    playlist->addMedia(QUrl("qrc:/LevelMusic.mp3"));

    // 添加所有的BGM文件
}

void GameBgm::setLooping() {
    playlist->setPlaybackMode(QMediaPlaylist::Loop); // 设置循环播放模式
}

void GameBgm::play() {
    player->setVolume(50);
    player->play(); // 开始播放
}

void GameBgm::stop() {
    player->stop(); // 停止播放
}
