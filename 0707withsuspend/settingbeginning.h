#ifndef SETTINGBEGINNING_H
#define SETTINGBEGINNING_H

#include <QDialog>
#include <QPropertyAnimation>
namespace Ui {
class settingBeginning;
}

class settingBeginning : public QDialog
{
    Q_OBJECT

public:
    explicit settingBeginning(QWidget *parent = nullptr);
    ~settingBeginning();

private slots:
    void on_okButton_clicked();
    void on_volume_clicked();

    void on_music_clicked();

signals:
    void volumn_on();
    void volumn_off();
    void music_on();
    void music_off();

private:
    bool is_the_musicfirst_pic,is_the_volumnfirst_pic;
    bool is_music=true,is_volumn=true;

    Ui::settingBeginning *ui;
    QPropertyAnimation *setting_table_animation;
    void showEvent(QShowEvent *event) override;
};

#endif // SETTINGBEGINNING_H
