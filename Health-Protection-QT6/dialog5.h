#ifndef DIALOG5_H
#define DIALOG5_H

#include <QDialog>

namespace Ui {
class Dialog5;
}

class Dialog5 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog5(QWidget *parent = nullptr);
    ~Dialog5();

private slots:


    void on_checkBox_clicked(bool checked);



    void on_checkBox_2_clicked(bool checked);


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog5 *ui;
};

#endif // DIALOG5_H
