#include "dialog1x.h"
#include "qstyle.h"
#include "ui_dialog1x.h"
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QIcon>
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
#include<QStyle>
#include <QDir>
#include <QProcess>
#include "mainwindow.h"
#include "qstyle.h"
#include "ui_mainwindow.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>


#include <QJsonDocument>
#include <QJsonObject>

#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include <QSettings>
#include <QLabel>
#include <QMessageBox>

Dialog1x::Dialog1x(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1x)
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
  //  QMenu * menu = new QMenu();

    //设置菜单项目
   // QAction *actionHide = new QAction(icon, "Hide", menu);

   // menu->addAction(actionHide);
  //  trayIcon->setContextMenu(menu);
    // 设置Action的响应
   // connect(actionHide, SIGNAL(triggered()), this, SLOT(stActionHide()));
    trayIcon->show();

    //托盘的消息提示
    ui->setupUi(this);
}

Dialog1x::~Dialog1x()
{
    delete ui;
}





void Dialog1x::on_radioButton_clicked()
{
           //  trayIcon->showMessage("提醒", "显示图片");
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("https://api.vvhan.com/api/weather");
    QNetworkRequest request(url);

    // Set unsafe SSL configuration
    QSslConfiguration config = request.sslConfiguration();
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(config);

    QNetworkReply *reply = manager->get(request);

    // Connect to the finished signal
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Read the JSON data
            QByteArray data = reply->readAll();

            // Display the JSON data in a message box

            QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(data).toUtf8());
            QJsonObject jsonObj = jsonDoc.object();



             QString info1 = jsonObj["city"].toString();

            //对象类型需要使用新的QJsonObject对象存放，然后使用新的QJsonObject获取其中值
            QJsonObject jObj2 = jsonDoc["info"].toObject();
            //获取jObj2中指定键的值（值对应的类型直接使用对应函数转）
            QString key1Val = jObj2["type"].toString();


            QString key1Val2 = jObj2["low"].toString();


            QString key1Val3 = jObj2["high"].toString();


            QString key1Val4 = jObj2["tip"].toString();

              QJsonObject jObj7 = jObj2["air"].toObject();
            QString key1Val5 = jObj7["aqi_name"].toString();
    //QMessageBox::information(this, "JSON Data", key1Val5);
             QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

             //设定值有修改，没有创建。
              reg->setValue("Chooese",1);
            reg->setValue("Title",key1Val4);
             reg->setValue("Content",info1+" "+key1Val+" "+key1Val3+" "+key1Val2+" 空气质量："+key1Val5);
             //用完删除 QSettings
            delete reg;
  trayIcon->showMessage(key1Val4, info1+" "+key1Val+" "+key1Val3+" "+key1Val2+" 空气质量："+key1Val5);
        } else {
            // Display an error message
            QMessageBox::warning(this, "Error", reply->errorString());
        }

        // Clean up
        reply->deleteLater();
        manager->deleteLater();
    });
}


void Dialog1x::on_radioButton_2_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("https://api.vvhan.com/api/en?type=sj");
    QNetworkRequest request(url);

    // Set unsafe SSL configuration
    QSslConfiguration config = request.sslConfiguration();
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(config);

    QNetworkReply *reply = manager->get(request);

    // Connect to the finished signal
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Read the JSON data
            QByteArray data = reply->readAll();

            // Display the JSON data in a message box

            QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(data).toUtf8());
            QJsonObject jsonObj = jsonDoc.object();

            QJsonObject jObj2 = jsonDoc["data"].toObject();
            QString key1Val = jObj2["zh"].toString();
            QString key1Val2 = jObj2["en"].toString();


    //QMessageBox::information(this, "JSON Data", key1Val5);
             QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

             //设定值有修改，没有创建。
            reg->setValue("Title",key1Val2);
             reg->setValue("Content",key1Val);
            reg->setValue("Chooese",2);
             //用完删除 QSettings
            delete reg;
  trayIcon->showMessage(key1Val2, key1Val);
        } else {
            // Display an error message
            QMessageBox::warning(this, "Error", reply->errorString());
        }

        // Clean up
        reply->deleteLater();
        manager->deleteLater();
    });
}


void Dialog1x::on_radioButton_3_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("https://v1.jinrishici.com/shuqing/shanggan");
    QNetworkRequest request(url);

    // Set unsafe SSL configuration
    QSslConfiguration config = request.sslConfiguration();
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(config);

    QNetworkReply *reply = manager->get(request);

    // Connect to the finished signal
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Read the JSON data
            QByteArray data = reply->readAll();

            // Display the JSON data in a message box

            QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(data).toUtf8());
            QJsonObject jsonObj = jsonDoc.object();
            QString key1Val = jsonObj["content"].toString();
            QString key1Val2 = jsonObj["origin"].toString();
            QString key1Val3 = jsonObj["author"].toString();


            //QMessageBox::information(this, "JSON Data", key1Val5);
            QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);
 //QMessageBox::warning(this, "Error", key1Val);
            //设定值有修改，没有创建。
            reg->setValue("Title",key1Val);
            reg->setValue("Content",key1Val2+"  作者："+key1Val3);
reg->setValue("Chooese",3);
            //用完删除 QSettings
            delete reg;
    trayIcon->showMessage(key1Val, key1Val2+"  作者："+key1Val3);
        } else {
            // Display an error message
            QMessageBox::warning(this, "Error", reply->errorString());
        }

        // Clean up
        reply->deleteLater();
        manager->deleteLater();
    });

}


void Dialog1x::on_radioButton_4_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("https://api.vvhan.com/api/hotlist?type=baiduRD");
    QNetworkRequest request(url);

    // Set unsafe SSL configuration
    QSslConfiguration config = request.sslConfiguration();
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(config);

    QNetworkReply *reply = manager->get(request);

    // Connect to the finished signal
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Read the JSON data
            QByteArray data = reply->readAll();

            // Display the JSON data in a message box

            QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(data).toUtf8());
            QJsonObject jsonObj = jsonDoc.object();


            //组合对象第一层类型为数组，需要使用QJsonArray对象存放
            QJsonArray jArr2 = jsonObj["data"].toArray();
            //数组中存放的对象，使用QJsonObject接收
            QJsonObject jObj3 = jArr2.at(0).toObject();
            //获取对象中的指定键的值
            QString name = jObj3["title"].toString();
            QString name2 = jObj3["desc"].toString();

         //   QMessageBox::information(this, "JSON Data", name);
            QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

            //设定值有修改，没有创建。
            reg->setValue("Title",name);
            reg->setValue("Content",name2);
            reg->setValue("Chooese",4);
            //用完删除 QSettings
            delete reg;
    trayIcon->showMessage(name, name2);
        } else {
            // Display an error message
            QMessageBox::warning(this, "Error", reply->errorString());
        }

        // Clean up
        reply->deleteLater();
        manager->deleteLater();
    });
}

#include <QtMultimedia/QMediaPlayer>

#include <QtMultimedia>
#include <QUrl>
#include <QtCore/QCoreApplication>
#include <QtMultimedia/QMediaPlayer>
#include <QMediaPlayer>
void Dialog1x::on_radioButton_5_clicked()
{
 // 创建一个QMediaPlayer对象

    //QMediaPlayer *player = new QMediaPlayer;
    //播放进度的信号提示
  //  connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
   // player->setSource(QUrl("http://m701.music.126.net/20230506173759/4ee9e9e326dc2496679fc4bdc7887c3b/jdymusic/obj/wo3DlMOGwrbDjj7DisKw/17718433824/acca/41eb/8112/efa4dce840121844afcb957bcb2d4fd1.mp3"));
     //0~100音量范围,默认是100
    //player->play();

}



void Dialog1x::on_radioButton_6_clicked()
{

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("https://api.vvhan.com/api/horoscope?type=aquarius&time=today");
    QNetworkRequest request(url);

    // Set unsafe SSL configuration
    QSslConfiguration config = request.sslConfiguration();
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(config);

    QNetworkReply *reply = manager->get(request);

    // Connect to the finished signal
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Read the JSON data
            QByteArray data = reply->readAll();

            // Display the JSON data in a message box

            QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(data).toUtf8());
            QJsonObject jsonObj = jsonDoc.object();

           QJsonObject jObj2 = jsonDoc["data"].toObject();
            QString key1Val = jObj2["title"].toString();
        QJsonObject jObj3 = jObj2["fortunetext"].toObject();

              QString key1Val2 = jObj3["all"].toString();
           // QMessageBox::information(this, "JSON Data", key1Val);
             //    QMessageBox::information(this, "JSON Data", key1Val2);
            QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

            //设定值有修改，没有创建。
            reg->setValue("Title",key1Val);
            reg->setValue("Content",key1Val2);
            reg->setValue("Chooese",6);
            //用完删除 QSettings
            delete reg;
    trayIcon->showMessage(key1Val, key1Val2);
        } else {
            // Display an error message
            QMessageBox::warning(this, "Error", reply->errorString());
        }

        // Clean up
        reply->deleteLater();
        manager->deleteLater();
    });
}


void Dialog1x::on_radioButton_7_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("https://api.vvhan.com/api/horoscope?type=pisces&time=today");
    QNetworkRequest request(url);

    // Set unsafe SSL configuration
    QSslConfiguration config = request.sslConfiguration();
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(config);

    QNetworkReply *reply = manager->get(request);

    // Connect to the finished signal
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Read the JSON data
            QByteArray data = reply->readAll();

            // Display the JSON data in a message box

            QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(data).toUtf8());
            QJsonObject jsonObj = jsonDoc.object();

            QJsonObject jObj2 = jsonDoc["data"].toObject();
            QString key1Val = jObj2["title"].toString();
            QJsonObject jObj3 = jObj2["fortunetext"].toObject();

            QString key1Val2 = jObj3["all"].toString();
            // QMessageBox::information(this, "JSON Data", key1Val);
            //    QMessageBox::information(this, "JSON Data", key1Val2);
            QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

            //设定值有修改，没有创建。
            reg->setValue("Title",key1Val);
            reg->setValue("Content",key1Val2);
            reg->setValue("Chooese",7);
            //用完删除 QSettings
            delete reg;
    trayIcon->showMessage(key1Val, key1Val2);
        } else {
            // Display an error message
            QMessageBox::warning(this, "Error", reply->errorString());
        }

        // Clean up
        reply->deleteLater();
        manager->deleteLater();
    });
}


void Dialog1x::on_radioButton_8_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("https://api.vvhan.com/api/horoscope?type=aries&time=today");
    QNetworkRequest request(url);

    // Set unsafe SSL configuration
    QSslConfiguration config = request.sslConfiguration();
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(config);

    QNetworkReply *reply = manager->get(request);

    // Connect to the finished signal
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Read the JSON data
            QByteArray data = reply->readAll();

            // Display the JSON data in a message box

            QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(data).toUtf8());
            QJsonObject jsonObj = jsonDoc.object();

            QJsonObject jObj2 = jsonDoc["data"].toObject();
            QString key1Val = jObj2["title"].toString();
            QJsonObject jObj3 = jObj2["fortunetext"].toObject();

            QString key1Val2 = jObj3["all"].toString();
            // QMessageBox::information(this, "JSON Data", key1Val);
            //    QMessageBox::information(this, "JSON Data", key1Val2);
            QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

            //设定值有修改，没有创建。
            reg->setValue("Title",key1Val);
            reg->setValue("Content",key1Val2);
            reg->setValue("Chooese",8);
            //用完删除 QSettings
            delete reg;
    trayIcon->showMessage(key1Val, key1Val2);
        } else {
            // Display an error message
            QMessageBox::warning(this, "Error", reply->errorString());
        }

        // Clean up
        reply->deleteLater();
        manager->deleteLater();
    });
}


void Dialog1x::on_radioButton_9_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("https://api.vvhan.com/api/horoscope?type=taurus&time=today");
    QNetworkRequest request(url);

    // Set unsafe SSL configuration
    QSslConfiguration config = request.sslConfiguration();
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(config);

    QNetworkReply *reply = manager->get(request);

    // Connect to the finished signal
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Read the JSON data
            QByteArray data = reply->readAll();

            // Display the JSON data in a message box

            QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(data).toUtf8());
            QJsonObject jsonObj = jsonDoc.object();

            QJsonObject jObj2 = jsonDoc["data"].toObject();
            QString key1Val = jObj2["title"].toString();
            QJsonObject jObj3 = jObj2["fortunetext"].toObject();

            QString key1Val2 = jObj3["all"].toString();
            // QMessageBox::information(this, "JSON Data", key1Val);
            //    QMessageBox::information(this, "JSON Data", key1Val2);
            QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

            //设定值有修改，没有创建。
            reg->setValue("Title",key1Val);
            reg->setValue("Content",key1Val2);
            reg->setValue("Chooese",9);
            //用完删除 QSettings
            delete reg;
    trayIcon->showMessage(key1Val, key1Val2);
        } else {
            // Display an error message
            QMessageBox::warning(this, "Error", reply->errorString());
        }

        // Clean up
        reply->deleteLater();
        manager->deleteLater();
    });
}


void Dialog1x::on_radioButton_10_clicked()
{

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("https://api.vvhan.com/api/horoscope?type=gemini&time=today");
    QNetworkRequest request(url);

    // Set unsafe SSL configuration
    QSslConfiguration config = request.sslConfiguration();
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(config);

    QNetworkReply *reply = manager->get(request);

    // Connect to the finished signal
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Read the JSON data
            QByteArray data = reply->readAll();

            // Display the JSON data in a message box

            QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(data).toUtf8());
            QJsonObject jsonObj = jsonDoc.object();

            QJsonObject jObj2 = jsonDoc["data"].toObject();
            QString key1Val = jObj2["title"].toString();
            QJsonObject jObj3 = jObj2["fortunetext"].toObject();

            QString key1Val2 = jObj3["all"].toString();
            // QMessageBox::information(this, "JSON Data", key1Val);
            //    QMessageBox::information(this, "JSON Data", key1Val2);
            QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

            //设定值有修改，没有创建。
            reg->setValue("Title",key1Val);
            reg->setValue("Content",key1Val2);
            reg->setValue("Chooese",10);
            //用完删除 QSettings
            delete reg;
    trayIcon->showMessage(key1Val, key1Val2);
        } else {
            // Display an error message
            QMessageBox::warning(this, "Error", reply->errorString());
        }

        // Clean up
        reply->deleteLater();
        manager->deleteLater();
    });
}


void Dialog1x::on_radioButton_11_clicked()
{

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("https://api.vvhan.com/api/horoscope?type=cancer&time=today");
    QNetworkRequest request(url);

    // Set unsafe SSL configuration
    QSslConfiguration config = request.sslConfiguration();
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(config);

    QNetworkReply *reply = manager->get(request);

    // Connect to the finished signal
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Read the JSON data
            QByteArray data = reply->readAll();

            // Display the JSON data in a message box

            QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(data).toUtf8());
            QJsonObject jsonObj = jsonDoc.object();

            QJsonObject jObj2 = jsonDoc["data"].toObject();
            QString key1Val = jObj2["title"].toString();
            QJsonObject jObj3 = jObj2["fortunetext"].toObject();

            QString key1Val2 = jObj3["all"].toString();
            // QMessageBox::information(this, "JSON Data", key1Val);
            //    QMessageBox::information(this, "JSON Data", key1Val2);
            QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

            //设定值有修改，没有创建。
            reg->setValue("Title",key1Val);
            reg->setValue("Content",key1Val2);
            reg->setValue("Chooese",11);
            //用完删除 QSettings
            delete reg;
    trayIcon->showMessage(key1Val, key1Val2);
        } else {
            // Display an error message
            QMessageBox::warning(this, "Error", reply->errorString());
        }

        // Clean up
        reply->deleteLater();
        manager->deleteLater();
    });
}


void Dialog1x::on_radioButton_14_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("https://api.vvhan.com/api/horoscope?type=leo&time=today");
    QNetworkRequest request(url);

    // Set unsafe SSL configuration
    QSslConfiguration config = request.sslConfiguration();
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(config);

    QNetworkReply *reply = manager->get(request);

    // Connect to the finished signal
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Read the JSON data
            QByteArray data = reply->readAll();

            // Display the JSON data in a message box

            QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(data).toUtf8());
            QJsonObject jsonObj = jsonDoc.object();

            QJsonObject jObj2 = jsonDoc["data"].toObject();
            QString key1Val = jObj2["title"].toString();
            QJsonObject jObj3 = jObj2["fortunetext"].toObject();

            QString key1Val2 = jObj3["all"].toString();
            // QMessageBox::information(this, "JSON Data", key1Val);
            //    QMessageBox::information(this, "JSON Data", key1Val2);
            QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

            //设定值有修改，没有创建。
            reg->setValue("Title",key1Val);
            reg->setValue("Content",key1Val2);
            reg->setValue("Chooese",14);
            //用完删除 QSettings
            delete reg;
    trayIcon->showMessage(key1Val, key1Val2);
        } else {
            // Display an error message
            QMessageBox::warning(this, "Error", reply->errorString());
        }

        // Clean up
        reply->deleteLater();
        manager->deleteLater();
    });
}


void Dialog1x::on_radioButton_17_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("https://api.vvhan.com/api/horoscope?type=virgo&time=today");
    QNetworkRequest request(url);

    // Set unsafe SSL configuration
    QSslConfiguration config = request.sslConfiguration();
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(config);

    QNetworkReply *reply = manager->get(request);

    // Connect to the finished signal
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Read the JSON data
            QByteArray data = reply->readAll();

            // Display the JSON data in a message box

            QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(data).toUtf8());
            QJsonObject jsonObj = jsonDoc.object();

            QJsonObject jObj2 = jsonDoc["data"].toObject();
            QString key1Val = jObj2["title"].toString();
            QJsonObject jObj3 = jObj2["fortunetext"].toObject();

            QString key1Val2 = jObj3["all"].toString();
            // QMessageBox::information(this, "JSON Data", key1Val);
            //    QMessageBox::information(this, "JSON Data", key1Val2);
            QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

            //设定值有修改，没有创建。
            reg->setValue("Title",key1Val);
            reg->setValue("Content",key1Val2);
            reg->setValue("Chooese",17);
            //用完删除 QSettings
            delete reg;
    trayIcon->showMessage(key1Val, key1Val2);
        } else {
            // Display an error message
            QMessageBox::warning(this, "Error", reply->errorString());
        }

        // Clean up
        reply->deleteLater();
        manager->deleteLater();
    });
}


void Dialog1x::on_radioButton_19_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("https://api.vvhan.com/api/horoscope?type=libra&time=today");
    QNetworkRequest request(url);

    // Set unsafe SSL configuration
    QSslConfiguration config = request.sslConfiguration();
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(config);

    QNetworkReply *reply = manager->get(request);

    // Connect to the finished signal
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Read the JSON data
            QByteArray data = reply->readAll();

            // Display the JSON data in a message box

            QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(data).toUtf8());
            QJsonObject jsonObj = jsonDoc.object();

            QJsonObject jObj2 = jsonDoc["data"].toObject();
            QString key1Val = jObj2["title"].toString();
            QJsonObject jObj3 = jObj2["fortunetext"].toObject();

            QString key1Val2 = jObj3["all"].toString();
            // QMessageBox::information(this, "JSON Data", key1Val);
            //    QMessageBox::information(this, "JSON Data", key1Val2);
            QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

            //设定值有修改，没有创建。
            reg->setValue("Title",key1Val);
            reg->setValue("Content",key1Val2);
            reg->setValue("Chooese",19);
            //用完删除 QSettings
            delete reg;
    trayIcon->showMessage(key1Val, key1Val2);
        } else {
            // Display an error message
            QMessageBox::warning(this, "Error", reply->errorString());
        }

        // Clean up
        reply->deleteLater();
        manager->deleteLater();
    });
}


void Dialog1x::on_radioButton_16_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("https://api.vvhan.com/api/horoscope?type=scorpio&time=today");
    QNetworkRequest request(url);

    // Set unsafe SSL configuration
    QSslConfiguration config = request.sslConfiguration();
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(config);

    QNetworkReply *reply = manager->get(request);

    // Connect to the finished signal
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Read the JSON data
            QByteArray data = reply->readAll();

            // Display the JSON data in a message box

            QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(data).toUtf8());
            QJsonObject jsonObj = jsonDoc.object();

            QJsonObject jObj2 = jsonDoc["data"].toObject();
            QString key1Val = jObj2["title"].toString();
            QJsonObject jObj3 = jObj2["fortunetext"].toObject();

            QString key1Val2 = jObj3["all"].toString();
            // QMessageBox::information(this, "JSON Data", key1Val);
            //    QMessageBox::information(this, "JSON Data", key1Val2);
            QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

            //设定值有修改，没有创建。
            reg->setValue("Title",key1Val);
            reg->setValue("Content",key1Val2);
            reg->setValue("Chooese",16);
            //用完删除 QSettings
            delete reg;
    trayIcon->showMessage(key1Val, key1Val2);
        } else {
            // Display an error message
            QMessageBox::warning(this, "Error", reply->errorString());
        }

        // Clean up
        reply->deleteLater();
        manager->deleteLater();
    });
}


void Dialog1x::on_radioButton_13_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("https://api.vvhan.com/api/horoscope?type=sagittarius&time=today");
    QNetworkRequest request(url);

    // Set unsafe SSL configuration
    QSslConfiguration config = request.sslConfiguration();
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(config);

    QNetworkReply *reply = manager->get(request);

    // Connect to the finished signal
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Read the JSON data
            QByteArray data = reply->readAll();

            // Display the JSON data in a message box

            QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(data).toUtf8());
            QJsonObject jsonObj = jsonDoc.object();

            QJsonObject jObj2 = jsonDoc["data"].toObject();
            QString key1Val = jObj2["title"].toString();
            QJsonObject jObj3 = jObj2["fortunetext"].toObject();

            QString key1Val2 = jObj3["all"].toString();
            // QMessageBox::information(this, "JSON Data", key1Val);
            //    QMessageBox::information(this, "JSON Data", key1Val2);
            QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

            //设定值有修改，没有创建。
            reg->setValue("Title",key1Val);
            reg->setValue("Content",key1Val2);
            reg->setValue("Chooese",13);
            //用完删除 QSettings
            delete reg;
    trayIcon->showMessage(key1Val, key1Val2);
        } else {
            // Display an error message
            QMessageBox::warning(this, "Error", reply->errorString());
        }

        // Clean up
        reply->deleteLater();
        manager->deleteLater();
    });
}
#include <QSystemTrayIcon>

void Dialog1x::on_radioButton_15_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("https://api.vvhan.com/api/horoscope?type=capricornus&time=today");
    QNetworkRequest request(url);

    // Set unsafe SSL configuration
    QSslConfiguration config = request.sslConfiguration();
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(config);

    QNetworkReply *reply = manager->get(request);

    // Connect to the finished signal
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Read the JSON data
            QByteArray data = reply->readAll();

            // Display the JSON data in a message box

            QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(data).toUtf8());
            QJsonObject jsonObj = jsonDoc.object();

            QJsonObject jObj2 = jsonDoc["data"].toObject();
            QString key1Val = jObj2["title"].toString();
            QJsonObject jObj3 = jObj2["fortunetext"].toObject();

            QString key1Val2 = jObj3["all"].toString();
            // QMessageBox::information(this, "JSON Data", key1Val);
            //    QMessageBox::information(this, "JSON Data", key1Val2);
            QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

            //设定值有修改，没有创建。
            reg->setValue("Title",key1Val);
            reg->setValue("Content",key1Val2);
            reg->setValue("Chooese",15);
            //用完删除 QSettings
            delete reg;
            QSettings *reg3 = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);
            QString Title=reg3->value("Title").toString();
            QString Content=reg3->value("Content").toString();
    trayIcon->showMessage(Title, Content);
            //neirong=reg->value("Content").toString();
            // }


            delete reg3;
        } else {
            // Display an error message
            QMessageBox::warning(this, "Error", reply->errorString());
        }

        // Clean up
        reply->deleteLater();
        manager->deleteLater();
    });
}


void Dialog1x::stTrayIconActive(QSystemTrayIcon::ActivationReason acReason)
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
