#ifndef GAME_OVER_H
#define GAME_OVER_H

#include <QDialog>

namespace Ui {
class game_over;
}

class game_over : public QDialog
{
    Q_OBJECT

public:
    explicit game_over(QWidget *parent = nullptr);
    ~game_over();

public slots:
    void on_back_to_begin_clicked();

private:
    Ui::game_over *ui;
    void showEvent(QShowEvent *event) override;
};

#endif // GAME_OVER_H
