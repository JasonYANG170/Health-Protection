#include "dialog5.h"
#include "ui_dialog5.h"
#include <QSettings>
#include <QLabel>


#include <QSettings>
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


#include <QDir>
#include <QProcess>
QString ves3="V8.5";
Dialog5::Dialog5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog5)
{
    ui->setupUi(this);
    QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

    //判断 value 是否为空，不为空则输出
    // if(reg->value("键名 001") != "")
    // {
    int chooese=reg->value("start").toInt();
    //neirong=reg->value("Content").toString();
    // }

    //删除 QSettings
    delete reg;
    if(chooese==1){
 ui->checkBox->setCheckState(Qt::Checked);
    }
    QSettings *reg2 = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

    //判断 value 是否为空，不为空则输出
    // if(reg->value("键名 001") != "")
    // {
    int chooese2=reg2->value("startmini").toInt();
    //neirong=reg->value("Content").toString();
    // }

    //删除 QSettings
    delete reg2;
    if(chooese2==1){
  ui->checkBox_2->setCheckState(Qt::Checked);
    }
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("https://api.vvhan.com/api/qqsc?key=55800ce777767fcd63f59beaf0eee9ff");
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

            // QMessageBox::information(this, "JSON Data", QString(data));
            QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(data).toUtf8());
            QJsonObject jsonObj = jsonDoc.object();

            // 获取数据
            QString info = jsonObj["content"].toString();

            ui->textBrowser->setPlainText("当前版本：V8.5\n\n公告：\n"+info);


        } else {
            // Display an error message

            QMessageBox::warning(this, "Error", reply->errorString());

        }

        // Clean up
        reply->deleteLater();
        manager->deleteLater();

    }



            );
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
            if(info2!=ves3){
              //  QMessageBox::warning(this, "Error", "已发布新版本\""+info2+"\"。\n点击右上角发现新版本按钮下载最新版本。");
                ui->pushButton->setText("发现新版本，点击跳转");
            }else{


                ui->pushButton->setText("暂无更新");
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

Dialog5::~Dialog5()
{
    delete ui;
}



void Dialog5::on_checkBox_clicked(bool checked)
{
    if(checked){

        QSettings* settings = new QSettings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
        auto application_name = QApplication::applicationName();
        auto path = settings->value(application_name).toString();
        QString appPath = QApplication::applicationFilePath();
        QString newPath = QDir::toNativeSeparators(appPath);
        if (path != newPath) {
            settings->setValue(application_name, newPath);
        }
        delete settings;

        QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

        //设定值有修改，没有创建。
        reg->setValue("start",1);
        //用完删除 QSettings
        delete reg;
    }else{
        QSettings* settings = new QSettings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
        auto application_name = QApplication::applicationName();
        settings->remove(application_name);


        delete settings;

        QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

        //设定值有修改，没有创建。
        reg->setValue("start",0);
        //用完删除 QSettings
        delete reg;
    }
}





void Dialog5::on_checkBox_2_clicked(bool checked)
{
    if(checked){
        QSettings* settings = new QSettings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
        auto application_name = QApplication::applicationName();
        settings->remove(application_name);


        delete settings;

        QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

        //设定值有修改，没有创建。
        reg->setValue("startmini",1);
        //用完删除 QSettings
        delete reg;
    }else{
        QSettings* settings = new QSettings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
        auto application_name = QApplication::applicationName();
        settings->remove(application_name);


        delete settings;

        QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

        //设定值有修改，没有创建。
        reg->setValue("startmini",0);
        //用完删除 QSettings
        delete reg;
    }
}



#include <QDesktopServices>
void Dialog5::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/JasonYANG170/Health-Protection/releases", QUrl::TolerantMode));
}
#include "dialog6.h"
#include "ui_dialog6.h"


void Dialog5::on_pushButton_2_clicked()
{
    Dialog6 d;
    d.exec();
}

