#ifndef MYSOUNDEFFECT_H
#define MYSOUNDEFFECT_H

#include <QObject>
#include <QMap>
#include <QMediaPlayer>

class MySoundEffect : public QObject
{
    Q_OBJECT
public:
    explicit MySoundEffect(QObject *parent = nullptr);

    void addSoundEffect(const QString &id, const QString &soundFile);
    void play(const QString &id);
    void setVolume(const QString &id, int volume);
    void muteAll();

private:
    QMap<QString, QMediaPlayer *> m_soundEffects;
};

#endif // MYSOUNDEFFECT_H
