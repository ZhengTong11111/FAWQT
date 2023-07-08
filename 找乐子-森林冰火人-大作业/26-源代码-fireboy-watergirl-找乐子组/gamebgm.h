#ifndef GAMEBGM_H
#define GAMEBGM_H

#include <QObject>
#include <QMediaPlayer>
#include <QMediaPlaylist>

class GameBgm : public QObject
{
    Q_OBJECT
public:
    explicit GameBgm(QObject *parent = nullptr);
    void addBgmFiles();
    void setLooping();
    void play();
    void stop();

private:
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
};

#endif // GAMEBGM_H
