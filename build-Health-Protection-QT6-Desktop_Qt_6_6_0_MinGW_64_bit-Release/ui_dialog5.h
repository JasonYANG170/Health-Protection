/********************************************************************************
** Form generated from reading UI file 'dialog5.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG5_H
#define UI_DIALOG5_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog5
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog5)
    {
        if (Dialog5->objectName().isEmpty())
            Dialog5->setObjectName("Dialog5");
        Dialog5->resize(476, 341);
        verticalLayout = new QVBoxLayout(Dialog5);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(Dialog5);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 200));
        widget->setMaximumSize(QSize(16777215, 1000));
        widget->setStyleSheet(QString::fromUtf8("QWidget{background:rgb(170, 255, 255);border:2px groove gray;border-radius:30px;padding:2px 4px;border-style: outset;font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";}"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(200, 0));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/Desktop/39414350.jpg);"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 50));

        verticalLayout_2->addWidget(label_2);

        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));

        verticalLayout_2->addWidget(textBrowser);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);


        verticalLayout->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        checkBox_2 = new QCheckBox(Dialog5);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setMaximumSize(QSize(16777215, 60));
        checkBox_2->setStyleSheet(QString::fromUtf8("QCheckBox{background-color: rgb(255, 255, 0);border:2px groove gray;border-radius:30px;padding:2px 4px;border-style: outset;font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";}\n"
"QCheckBox:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"QCheckBox:pressed{background-color:rgb(204, 228, 247);border-style: inset;}\n"
""));

        horizontalLayout->addWidget(checkBox_2);

        checkBox = new QCheckBox(Dialog5);
        checkBox->setObjectName("checkBox");
        checkBox->setMinimumSize(QSize(0, 60));
        checkBox->setStyleSheet(QString::fromUtf8("QCheckBox{background-color: rgb(255, 255, 0);border:2px groove gray;border-radius:30px;padding:2px 4px;border-style: outset;font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";}\n"
"QCheckBox:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"QCheckBox:pressed{background-color:rgb(204, 228, 247);border-style: inset;}\n"
""));

        horizontalLayout->addWidget(checkBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton = new QPushButton(Dialog5);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 60));
        pushButton->setMaximumSize(QSize(16777215, 60));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(255, 255, 0);;border:2px groove gray;border-radius:30px;padding:2px 4px;border-style: outset;font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";}\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(Dialog5);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(0, 60));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(255, 255, 0);;border:2px groove gray;border-radius:30px;padding:2px 4px;border-style: outset;font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";}\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Dialog5);

        QMetaObject::connectSlotsByName(Dialog5);
    } // setupUi

    void retranslateUi(QDialog *Dialog5)
    {
        Dialog5->setWindowTitle(QCoreApplication::translate("Dialog5", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("Dialog5", "Health-Protection\345\201\245\345\272\267\345\256\210\346\212\244", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Dialog5", "\350\207\252\345\212\250\346\234\200\345\260\217\345\214\226", nullptr));
        checkBox->setText(QCoreApplication::translate("Dialog5", "\345\274\200\346\234\272\350\207\252\345\220\257\345\212\250", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog5", "\346\233\264\346\226\260\350\267\263\350\275\254", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog5", "\346\215\220\350\265\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog5: public Ui_Dialog5 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG5_H
