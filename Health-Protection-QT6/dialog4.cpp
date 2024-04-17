#include "dialog4.h"
#include "ui_dialog4.h"
#include <QSettings>
Dialog4::Dialog4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog4)
{
    ui->setupUi(this);
    QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

    //判断 value 是否为空，不为空则输出
    // if(reg->value("键名 001") != "")
    // {
    int chooese=reg->value("AppsUseLightTheme").toInt();
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
    int chooese2=reg2->value("AutoNight").toInt();
    //neirong=reg->value("Content").toString();
    // }

    //删除 QSettings
    delete reg2;
    if(chooese2==1){
        ui->checkBox_2->setCheckState(Qt::Checked);
    }
}

Dialog4::~Dialog4()
{
    delete ui;
}
#include <windows.h>
#include <tlhelp32.h>
#include <QSettings>


#include <QTime>




void Dialog4::on_checkBox_clicked(bool checked)
{
    if(checked){
        //实例 QSettings
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
    }else{
        //实例 QSettings
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
}


void Dialog4::on_checkBox_2_clicked(bool checked)
{
    if(checked){
        // QTime time = QTime::currentTime();
        // QString time1=time.toString("hh");
        //int time2=time1.toInt();
        QString NightONstr=ui->textEdit->toPlainText();
        int NightON=NightONstr.toInt();
        QString NightOFFstr=ui->textEdit_2->toPlainText();
        int NightOFF=NightOFFstr.toInt();
        QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

        //设定值有修改，没有创建。
        reg->setValue("NightON",NightON);
        reg->setValue("NightOFF",NightOFF);
        reg->setValue("AutoNight",1);
        //用完删除 QSettings
        delete reg;
    }else{
        QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

        //设定值有修改，没有创建。
        reg->setValue("AutoNight",0);
        //用完删除 QSettings
        delete reg;
    }
}

