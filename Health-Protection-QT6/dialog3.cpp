#include "dialog3.h"
#include "ui_dialog3.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtWidgets/QWidget>

#include <QString>
#include <QUrl>
#include <qnetwork.h>

Dialog3::Dialog3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog3)
{
    ui->setupUi(this);
}

Dialog3::~Dialog3()
{
    delete ui;
}
#include <windows.h>
#include <tlhelp32.h>
#include <QProcess>
void ClearProcessByProcessName(const QString &strPrcessName)
{
    PROCESSENTRY32 pe32;
    pe32.dwSize=sizeof(pe32);
    HANDLE hProcessSnap=::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
    BOOL bMore=::Process32First(hProcessSnap,&pe32);
    while(bMore) {
        int len= WideCharToMultiByte(CP_ACP, 0, pe32.szExeFile, wcslen(pe32.szExeFile),
                                      NULL, 0, NULL, NULL);
        char* m_char = new char[len+1];
        WideCharToMultiByte(CP_ACP, 0, pe32.szExeFile, wcslen(pe32.szExeFile),
                            m_char, len, NULL, NULL);
        m_char[len]='\0';

        if(strcmp(strPrcessName.toStdString().c_str(), m_char) == 0) {
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pe32.th32ProcessID);
            if(hProcess != NULL) {
                TerminateProcess(hProcess, 0);
            }
        }

        bMore=::Process32Next(hProcessSnap,&pe32);

        delete[] m_char;
    }
}
QString apps;
void Dialog3::on_pushButton_clicked()
{
    QString app=ui->textEdit->toPlainText();
    apps=app;
    ClearProcessByProcessName(app);
}

#include <QSettings>
#include <QLabel>
#include <QMessageBox>
void Dialog3::on_pushButton_2_clicked()
{
   int app=ui->textEdit_2->toPlainText().toInt()*1000*60;
    id1 = startTimer(app);

}

void Dialog3::on_pushButton_3_clicked()
{
    if (print_lock){
        return;
    }

    //防止重复执行
    print_lock = true;

    //获取打印行数


    //循环打印
    while(true) {
        QString app=ui->textEdit->toPlainText();
        apps=app;
        ClearProcessByProcessName(app);
        //将数据输出到文件中或是做一些其他操作...

        //更新进度值


        //停止
        if (stop_flag) {
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

void Dialog3::on_pushButton_4_clicked()
{
    if (print_lock)
        stop_flag = true;
    else
        stop_flag = false;
}

void Dialog3::timerEvent(QTimerEvent * ev)
{
    if(ev->timerId() == id1)
    {
        QString app=ui->textEdit->toPlainText();
        ClearProcessByProcessName(app);
        killTimer(id1);
    }

    if(ev->timerId() == id2)
    {


    }

}
#include <QTimer> //定时器类
#include <QMouseEvent>
#include <QDebug>



