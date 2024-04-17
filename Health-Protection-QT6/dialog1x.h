#ifndef DIALOG1X_H
#define DIALOG1X_H

#include <QDialog>

#include <QMainWindow>

#include <QMainWindow>

#include <QDialog>
#include "dialog1.h"
#include "dialog2.h"
#include "dialog3.h"
#include "dialog4.h"
#include "dialog5.h"
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QIcon>
#include <QAction>

#include <QMessageBox>
#include <QDialog>
namespace Ui {
class Dialog1x;
}

class Dialog1x : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1x(QWidget *parent = nullptr);
    ~Dialog1x();
        QSystemTrayIcon *trayIcon;
public slots:

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_7_clicked();

    void on_radioButton_8_clicked();

    void on_radioButton_9_clicked();

    void on_radioButton_10_clicked();

    void on_radioButton_11_clicked();

    void on_radioButton_14_clicked();

    void on_radioButton_17_clicked();

    void on_radioButton_19_clicked();

    void on_radioButton_16_clicked();

    void on_radioButton_13_clicked();

    void on_radioButton_15_clicked();
       void stTrayIconActive(QSystemTrayIcon::ActivationReason acReason);
private slots:


private:
    Ui::Dialog1x *ui;
};

#endif // DIALOG1X_H
