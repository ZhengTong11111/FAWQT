#ifndef MUSIC_H
#define MUSIC_H
#include <QString>
#include <QMediaPlayer>
#include <QMediaPlaylist>

class Music
{
    QMediaPlayer *musicg=new QMediaPlayer();
    QMediaPlaylist *backlist=new QMediaPlaylist();
    QString name;
public:
    Music();

    void setbhmusic();

    void beginbhmusic();
    void closebhmusic();


};

#endif // MUSIC_H
