#ifndef SUSPEND_H
#define SUSPEND_H

#include <QDialog>

namespace Ui {
class suspend;
}

class suspend : public QDialog
{
    Q_OBJECT

public:
    explicit suspend(QWidget *parent = nullptr,QWidget *main_widget = nullptr);
    ~suspend();

private slots:
    void on_continue_2_clicked();

    void on_retry_clicked();

    void on_end_clicked();

private:
    Ui::suspend *ui;
    QWidget *main_table;
    void showEvent(QShowEvent *event) override;
};

#endif // SUSPEND_H
