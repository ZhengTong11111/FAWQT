#ifndef GAME_SUCCESS_H
#define GAME_SUCCESS_H

#include <QDialog>
#include <QWidget>
#include  <QPainter>

namespace Ui {
class game_success;
}

class game_success : public QDialog
{
    Q_OBJECT

public:
    int redReward, blueReward,successTime;

    explicit game_success(QWidget *parent = nullptr/*,QWidget *main_widget = nullptr*/, int _redReward = 0, int _blueReward = 0,int _successTime=0);
    ~game_success();

    QWidget* parentWindow;
    void paintEvent(QPaintEvent* event) override;


private slots:
    void on_backButton_clicked();

private:
    Ui::game_success *ui;
    QWidget *main_table;
    void showEvent(QShowEvent *event) override;
};

#endif // GAME_SUCCESS_H
