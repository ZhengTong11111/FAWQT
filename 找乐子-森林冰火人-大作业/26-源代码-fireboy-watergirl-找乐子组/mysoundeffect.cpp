#include "mysoundeffect.h"
#include <QMediaPlayer>

MySoundEffect::MySoundEffect(QObject *parent)
    : QObject(parent)
{
    addSoundEffect("platform", "qrc:/Platform.mp3");
    setVolume("platform", 100);
    addSoundEffect("diamond", "qrc:/Diamond.mp3");
    setVolume("diamond", 100);
    addSoundEffect("jump_wg", "qrc:/Jump_wg.mp3");
    setVolume("jump_wg", 100);
    addSoundEffect("jump_fb", "qrc:/Jump_fb.mp3");
    setVolume("jump_fb", 100);
    addSoundEffect("door", "qrc:/Door.mp3");
    setVolume("door", 100);
    addSoundEffect("death", "qrc:/Death.mp3");
    setVolume("death", 80);
}

void MySoundEffect::addSoundEffect(const QString &id, const QString &soundFile)
{
    QMediaPlayer *soundEffect = new QMediaPlayer(this);
    soundEffect->setMedia(QUrl(soundFile));
    m_soundEffects.insert(id, soundEffect);
}

void MySoundEffect::play(const QString &id)
{
    if (m_soundEffects.contains(id))
    {
        m_soundEffects[id]->play();
    }
}

void MySoundEffect::setVolume(const QString &id, int volume)
{
    if (m_soundEffects.contains(id))
    {
        m_soundEffects[id]->setVolume(volume);
    }
}

void MySoundEffect::muteAll()
{
    for (const QString &id : m_soundEffects.keys())
    {
        setVolume(id, 0);
    }
}
