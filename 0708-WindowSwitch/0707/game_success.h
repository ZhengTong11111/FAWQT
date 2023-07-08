#ifndef GAME_SUCCESS_H
#define GAME_SUCCESS_H

#include <QDialog>
#include <QWidget>

namespace Ui {
class game_success;
}

class game_success : public QDialog
{
    Q_OBJECT

public:
    explicit game_success(QWidget *parent = nullptr);
    ~game_success();

    QWidget* parentWindow;

public slots:
    void on_backButton_clicked();

private:
    Ui::game_success *ui;
    void showEvent(QShowEvent *event) override;

signals:
    void backButtonClicked();
};

#endif // GAME_SUCCESS_H
