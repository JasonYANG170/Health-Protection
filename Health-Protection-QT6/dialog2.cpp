#include "dialog2.h"
#include "ui_dialog2.h"
#include <QSettings>
#include <QLabel>


#include <QSettings>



#include <QDir>
#include <QProcess>
Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_pushButton_clicked()
{
    QProcess p(0);
    p.start("cmd", QStringList()<<"/c"<<"shutdown -a");
    p.waitForStarted();
    p.waitForFinished();
    QString strTemp=QString::fromLocal8Bit(p.readAllStandardOutput());  //获得输出
}

void Dialog2::on_pushButton_2_clicked()
{
    double time=ui->textEdit->toPlainText().toDouble();
    time=time*60*60;
    QString b =  QString::number(time, 'f', 0);
    QProcess p(0);
    p.start("cmd", QStringList()<<"/c"<<"shutdown -s -t "+b);
    p.waitForStarted();
    p.waitForFinished();
    QString strTemp=QString::fromLocal8Bit(p.readAllStandardOutput());  //获得输出
    //    QMessageBox testMassage;
    //    testMassage.setText(strTemp);
    //    testMassage.exec();
}

