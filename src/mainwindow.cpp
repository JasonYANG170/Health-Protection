#include "dialog1x.h"
#include "ui_dialog1x.h"
#include "mainwindow.h"
#include "qstyle.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QIcon>
#include "dialog1.h"
#include "ui_dialog1.h"
#include <QAction>
#include <windows.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <tlhelp32.h>
#include <QSettings>
#include <QMessageBox>
#include <QTime>
QString ves="V8.5";
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QPixmap img(":/Win11.jpg");




     QIcon icon = QApplication::style()->standardIcon((QStyle::StandardPixmap)0);
    QIcon icon1 = QApplication::style()->standardIcon((QStyle::StandardPixmap)9);

    //设置通知栏的图标
     trayIcon = new QSystemTrayIcon(this);
     trayIcon->setIcon(icon);

    //设置通知栏的单击事件
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(stTrayIconActive(QSystemTrayIcon::ActivationReason)));

    //设置通知栏的右键菜单
    QMenu * menu = new QMenu();

    //设置菜单项目
    QAction *actionHide = new QAction("Hide", menu);

    menu->addAction(actionHide);
    trayIcon->setContextMenu(menu);
    // 设置Action的响应
    connect(actionHide, SIGNAL(triggered()), this, SLOT(stActionHide()));
    trayIcon->show();
    QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

    //判断 value 是否为空，不为空则输出
    // if(reg->value("键名 001") != "")
    // {

    Dialog1x *aa = new Dialog1x;
     Dialog1 *bb = new Dialog1;
    int Chooese=reg->value("Chooese").toInt();
    switch (Chooese) {
    case 1:
         aa->on_radioButton_clicked();
        break;
    case 2:
        aa->on_radioButton_2_clicked();
        break;
    case 3:
  aa->on_radioButton_3_clicked();
        break;
    case 4:
 aa->on_radioButton_4_clicked();
        break;
    case 5:
 aa->on_radioButton_5_clicked();
        break;
    case 6:
          aa->on_radioButton_6_clicked();
        break;
    case 7:
         aa->on_radioButton_7_clicked();
        break;
    case 8:
         aa->on_radioButton_8_clicked();
        break;
    case 9:
        aa->on_radioButton_9_clicked();
        break;
    case 10:
        aa->on_radioButton_10_clicked();
        break;
    case 11:
        aa->on_radioButton_11_clicked();
        break;
    case 12:
        bb->on_pushButton_clicked();
        break;
    case 13:
        aa->on_radioButton_13_clicked();
        break;
    case 14:
        aa->on_radioButton_14_clicked();
        break;
    case 15:
         aa->on_radioButton_15_clicked();
        break;
    case 16:
        aa->on_radioButton_16_clicked();
        break;
    case 17:
        aa->on_radioButton_17_clicked();
        break;
    case 18:
         //p.on_radioButton_19_clicked()
        break;
    case 19:
         aa->on_radioButton_19_clicked();
        break;
    default:
        break;
    }

    //删除 QSettings

    //托盘的消息提示


    int NightON;
    int NightOFF;
    int AutoNight;
    //实例 QSettings
    //参数 1：如果没有按照章节 Qt01 进行，则注册表中没有 Qt01。


    //判断 value 是否为空，不为空则输出
    // if(reg->value("键名 001") != "")
    // {
    NightON=reg->value("NightON").toInt();
    NightOFF=reg->value("NightOFF").toInt();
     AutoNight=reg->value("AutoNight").toInt();
    // }
   delete reg;
    //删除 QSettings

     if(AutoNight==1){
        if (print_lock){
            return;
        }

        //防止重复执行
        print_lock = true;

        //获取打印行数


        //循环打印
        while(true) {

             QTime time = QTime::currentTime();
             QString time1=time.toString("hh");
            int time2=time1.toInt();
            //将数据输出到文件中或是做一些其他操作...
            if(NightON==time2){
                QSettings *reg = new
                    QSettings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", QSettings::NativeFormat);

                //判断 value 是否为空，不为空则输出
                //if(reg->value("Start Page") != "")
                //{
                //IE 默认主页修改为：百度首页
                reg->setValue("AppsUseLightTheme",1);
                reg->setValue("SystemUsesLightTheme",1);
                //}

                //删除 QSettings
                delete reg;
            }
            if(NightOFF==time2){
                QSettings *reg = new
                    QSettings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", QSettings::NativeFormat);

                //判断 value 是否为空，不为空则输出
                //if(reg->value("Start Page") != "")
                //{
                //IE 默认主页修改为：百度首页
                reg->setValue("AppsUseLightTheme",0);
                reg->setValue("SystemUsesLightTheme",0);
                //}

                //删除 QSettings
                delete reg;
            }
            //更新进度值


            //停止
            if (AutoNight==0) {
                break;
            }

            //优先响应UI事件，防止卡死， 提升用户体验
            qApp->processEvents();
        }



        print_lock = false;
        stop_flag = false;

        // 在需要停止线程的地方，发送中断信号
        // thread->requestInterruption();

    }
     QNetworkAccessManager *manager2 = new QNetworkAccessManager(this);
     QUrl url2("https://api.vvhan.com/api/qqsc?key=969c8d1f86b653696f929406faa0bbc0");
     QNetworkRequest request2(url2);

     // Set unsafe SSL configuration
     QSslConfiguration config2 = request2.sslConfiguration();
     config2.setPeerVerifyMode(QSslSocket::VerifyNone);
     request2.setSslConfiguration(config2);

     QNetworkReply *reply2 = manager2->get(request2);

     // Connect to the finished signal
     connect(reply2, &QNetworkReply::finished, [=]() {

         if (reply2->error() == QNetworkReply::NoError) {
             // Read the JSON data
             QByteArray data2 = reply2->readAll();

             // Display the JSON data in a message box

             // QMessageBox::information(this, "JSON Data", QString(data));
             QJsonDocument jsonDoc2 = QJsonDocument::fromJson(QString(data2).toUtf8());
             QJsonObject jsonObj2 = jsonDoc2.object();

             // 获取数据
             QString info2 = jsonObj2["content"].toString();
             if(info2!=ves){
                 QMessageBox::warning(this, "Error", "已发布新版本\""+info2+"\"。\n点击\"设置\"下载最新版本。");
                // ui->pushButton_4->setText("发现新版本");
             }else{


               //  ui->pushButton_4->setText("暂无更新");
             }

         } else {
             // Display an error message

             QMessageBox::warning(this, "Error", reply2->errorString());

         }

         // Clean up
         reply2->deleteLater();
         manager2->deleteLater();

     }



             );

}

void MainWindow::stTrayIconActive(QSystemTrayIcon::ActivationReason acReason)
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
MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    Dialog1 d;
    d.exec();
}


void MainWindow::on_pushButton_5_clicked()
{
    Dialog2 d;
    d.exec();
}


void MainWindow::on_pushButton_4_clicked()
{
    Dialog3 d;
    d.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    Dialog4 d;
    d.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    Dialog5 d;
    d.exec();
}



