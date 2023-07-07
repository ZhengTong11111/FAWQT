#ifndef GAME_SUCCESS_H
#define GAME_SUCCESS_H

#include <QDialog>

namespace Ui {
class game_success;
}

class game_success : public QDialog
{
    Q_OBJECT

public:
    explicit game_success(QWidget *parent = nullptr,QWidget *main_widget = nullptr);
    ~game_success();

private slots:
    void on_backButton_clicked();

private:
    Ui::game_success *ui;
    QWidget *main_table;
    void showEvent(QShowEvent *event) override;
};

#endif // GAME_SUCCESS_H
