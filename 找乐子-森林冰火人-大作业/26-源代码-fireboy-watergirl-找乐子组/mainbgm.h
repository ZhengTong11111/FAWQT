#ifndef MAINBGM_H
#define MAINBGM_H

#include <QObject>
#include <QMediaPlayer>
#include <QMediaPlaylist>

class MainBgm : public QObject
{
    Q_OBJECT
public:
    explicit MainBgm(QObject *parent = nullptr);
    void addBgmFiles();
    void setLooping();
    void play();
    void stop();

private:
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
};

#endif // MAINBGM_H
