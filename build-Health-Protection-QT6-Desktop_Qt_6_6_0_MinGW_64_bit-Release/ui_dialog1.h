/********************************************************************************
** Form generated from reading UI file 'dialog1.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG1_H
#define UI_DIALOG1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog1
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *textEdit;
    QLabel *label_2;
    QTextEdit *textEdit_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Dialog1)
    {
        if (Dialog1->objectName().isEmpty())
            Dialog1->setObjectName("Dialog1");
        Dialog1->resize(407, 291);
        verticalLayout = new QVBoxLayout(Dialog1);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(Dialog1);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));

        verticalLayout->addWidget(label);

        textEdit = new QTextEdit(Dialog1);
        textEdit->setObjectName("textEdit");
        textEdit->setMinimumSize(QSize(0, 40));
        textEdit->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(textEdit);

        label_2 = new QLabel(Dialog1);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));

        verticalLayout->addWidget(label_2);

        textEdit_2 = new QTextEdit(Dialog1);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(textEdit_2);

        verticalSpacer = new QSpacerItem(0, 30, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_2 = new QPushButton(Dialog1);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(0, 40));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(255, 255, 0);border:2px groove gray;border-radius:20px;padding:2px 4px;border-style: outset;font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";}\n"
"QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}\n"
""));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(Dialog1);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 40));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(255, 255, 0);border:2px groove gray;border-radius:20px;padding:2px 4px;border-style: outset;font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";}\n"
"QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}\n"
""));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        pushButton_3 = new QPushButton(Dialog1);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(0, 40));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(255, 255, 0);border:2px groove gray;border-radius:20px;padding:2px 4px;border-style: outset;font: 10pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";}\n"
"QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}\n"
""));

        verticalLayout->addWidget(pushButton_3);


        retranslateUi(Dialog1);

        QMetaObject::connectSlotsByName(Dialog1);
    } // setupUi

    void retranslateUi(QDialog *Dialog1)
    {
        Dialog1->setWindowTitle(QCoreApplication::translate("Dialog1", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog1", "\350\257\267\350\276\223\345\205\245\346\240\207\351\242\230\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog1", "\350\257\267\350\276\223\345\205\245\345\206\205\345\256\271\357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog1", "\344\277\235\345\255\230", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog1", "\351\242\204\350\247\210", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Dialog1", "\350\201\224\347\275\221\350\216\267\345\217\226\357\274\210BETA\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog1: public Ui_Dialog1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG1_H
