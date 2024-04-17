
#include "mainwindow.h"

#include <QApplication>
#include <QSettings>
#include <QLabel>
#include <QMessageBox>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Health-Protection-QT6_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    QSettings *reg = new QSettings("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);

    //判断 value 是否为空，不为空则输出
    // if(reg->value("键名 001") != "")
    // {
    int chooese=reg->value("startmini").toInt();
    //neirong=reg->value("Content").toString();
    // }

    //删除 QSettings
    delete reg;
    if(chooese==1){

    }else{
    w.show();
    }

    return a.exec();
}
