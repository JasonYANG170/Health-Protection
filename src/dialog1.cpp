#include "dialog1.h"
#include "ui_dialog1.h"
#include <QSettings>
#include <QLabel>
#include <QDir>
#include <QProcess>
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QIcon>
#include <QStyle>
#include <QAction>
#include "dialog1x.h"
#include "ui_dialog1x.h"
Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    QPixmap img(":/Win11.jpg");



    QIcon icon = QApplication::style()->standardIcon((QStyle::StandardPixmap)0);
    QIcon icon1 = QApplication::style()->standardIcon((QStyle::StandardPixmap)9);

    //设置通知栏的图标
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(icon);

    //设置通知栏的单击事件
   // connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(stTrayIconActive(QSystemTrayIcon::ActivationReason)));

    //设置通知栏的右键菜单
    //QMenu * menu = new QMenu();

    //设置菜单项目
   // QAction *actionHide = new QAction(icon, "Hide", menu);

    //menu->addAction(actionHide);
  //  trayIcon->setContextMenu(menu);
    // 设置Action的响应
    //connect(actionHide, SIGNAL(triggered()), this, SLOT(stActionHide()));
    trayIcon->show();

    //托盘的消息提示

    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}

#include <QSettings>
#include <QLabel>
#include <QMessageBox>
void Dialog1::stTrayIconActive(QSystemTrayIcon::ActivationReason acReason)
{
    switch (acReason)
    {
    case QSystemTrayIcon::Trigger:
    {
        showNormal();
        break;
    }
    default:
        ;
    }
}
void Dialog1::on_pushButton_clicked()
{

        QString neirong ;
QString biaoti ;

    //实例 QSettings
    //参数 1：如果没有按照章节 Qt01 进行，则注册表中没有 Qt01。
    QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

    //判断 value 是否为空，不为空则输出
   // if(reg->value("键名 001") != "")
   // {
        biaoti=reg->value("Title").toString();
        neirong=reg->value("Content").toString();
   // }

    //删除 QSettings
    delete reg;

    //菜单项--打开主面板
   // QIcon icon = QApplication::style()->standardIcon((QStyle::StandardPixmap)0);
     //   QIcon icon1 = QApplication::style()->standardIcon((QStyle::StandardPixmap)9);

        if(isVisible())
        {
            trayIcon->showMessage(biaoti, neirong);


        }
        else
        {
            trayIcon->showMessage("提醒", "显示图片");

        }
 // QMessageBox::information(this,"检测执行","操作已执行");

}

#include <QSettings>



#include <QDir>
#include <QProcess>
void Dialog1::on_pushButton_2_clicked()
{

    QString strText1=ui->textEdit->toPlainText();
     QString strText2=ui->textEdit_2->toPlainText();
    QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

    //设定值有修改，没有创建。
    reg->setValue("Title",strText1);
    reg->setValue("Content",strText2);
        reg->setValue("Chooese",12);
    //用完删除 QSettings
    delete reg;
}
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>


#include <QJsonDocument>
#include <QJsonObject>
#include <QEventLoop>
#include <QDebug>
#include <QtWidgets>

#include <QJsonDocument>
#include <QJsonObject>

#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>



void Dialog1::on_pushButton_3_clicked()
{
    Dialog1x d;
    d.exec();
}



