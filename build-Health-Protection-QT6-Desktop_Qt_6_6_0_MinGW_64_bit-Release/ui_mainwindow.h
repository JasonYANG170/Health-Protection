/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(613, 480);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 60));
        label->setStyleSheet(QString::fromUtf8("font: 30pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));

        verticalLayout_4->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/Desktop/8eea737026dbeeae250de40cffd742b9.png);\n"
"border:2px groove gray;\n"
"border-radius:35px;\n"
"background-color: rgb(170, 255, 0);"));

        verticalLayout_2->addWidget(label_2);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMaximumSize(QSize(16777215, 70));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(255, 255, 0);border:2px groove gray;border-radius:30px;padding:2px 4px;border-style: outset;font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";}\n"
"QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}\n"
""));

        verticalLayout_2->addWidget(pushButton_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(16777215, 70));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(255, 255, 0);;border:2px groove gray;border-radius:35px;padding:2px 4px;border-style: outset;font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";}\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"));

        verticalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMaximumSize(QSize(16777215, 70));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{background-color:rgb(255, 170, 0); ;border:2px groove gray;border-radius:35px;padding:2px 4px;border-style: outset;font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";}\n"
"\n"
"\n"
"QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMaximumSize(QSize(16777215, 70));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(85, 255, 255);border:2px groove gray;border-radius:35px;padding:2px 4px;border-style: outset;font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";}\n"
"QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setMaximumSize(QSize(16777215, 70));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(0, 255, 127);border:2px groove gray;border-radius:35px;padding:2px 4px;border-style: outset;font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";}\n"
"\n"
"QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"));

        verticalLayout->addWidget(pushButton_5);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 613, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "YANG Health-Peotection", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Health-Protection-QT6\351\207\215\346\236\204\347\211\210</p></body></html>", nullptr));
        label_2->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\222\255\346\212\245", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\346\212\244\347\234\274\345\212\251\346\211\213", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\345\201\245\345\272\267\345\256\210\346\212\244", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\345\256\232\346\227\266\345\205\263\346\234\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
