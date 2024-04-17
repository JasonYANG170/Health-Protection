#ifndef DIALOG3_H
#define DIALOG3_H

#include <QDialog>

namespace Ui {
class Dialog3;
}

class Dialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog3(QWidget *parent = nullptr);
    ~Dialog3();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();



private:
    Ui::Dialog3 *ui;
    virtual void timerEvent(QTimerEvent *);
    int id1; //定时器1的唯一标示
    int id2; //定时器2的唯一标示
    bool print_lock;
    bool stop_flag;
};


#endif // DIALOG3_H
