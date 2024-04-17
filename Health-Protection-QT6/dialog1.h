#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include <QDialog>
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QIcon>
#include <QAction>

#include <QMessageBox>
namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = nullptr);
    ~Dialog1();
    QSystemTrayIcon *trayIcon;
    void on_pushButton_clicked();
private slots:

    void stTrayIconActive(QSystemTrayIcon::ActivationReason acReason);
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Dialog1 *ui;
};

#endif // DIALOG1_H
