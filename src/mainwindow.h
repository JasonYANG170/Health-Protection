#include "dialog1x.h"
#include "ui_dialog1x.h"
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSystemTrayIcon *trayIcon;
    public slots:

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();
    void stTrayIconActive(QSystemTrayIcon::ActivationReason acReason);


private:
    Ui::MainWindow *ui;

    int id1; //定时器1的唯一标示
    int id2; //定时器2的唯一标示
    bool print_lock;
    bool stop_flag;
};

#endif // MAINWINDOW_H
