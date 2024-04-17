/********************************************************************************
** Form generated from reading UI file 'dialog2.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG2_H
#define UI_DIALOG2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog2
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QTextEdit *textEdit;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog2)
    {
        if (Dialog2->objectName().isEmpty())
            Dialog2->setObjectName("Dialog2");
        Dialog2->resize(400, 227);
        verticalLayout = new QVBoxLayout(Dialog2);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(Dialog2);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 13pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));

        horizontalLayout->addWidget(label);

        textEdit = new QTextEdit(Dialog2);
        textEdit->setObjectName("textEdit");
        textEdit->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(textEdit);

        label_2 = new QLabel(Dialog2);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 13pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton = new QPushButton(Dialog2);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 60));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(255, 255, 0);border:2px groove gray;border-radius:20px;padding:2px 4px;border-style: outset;font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";}\n"
"QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}\n"
""));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(Dialog2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(0, 60));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(255, 255, 0);border:2px groove gray;border-radius:20px;padding:2px 4px;border-style: outset;font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";}\n"
"QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}\n"
""));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Dialog2);

        QMetaObject::connectSlotsByName(Dialog2);
    } // setupUi

    void retranslateUi(QDialog *Dialog2)
    {
        Dialog2->setWindowTitle(QCoreApplication::translate("Dialog2", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog2", "\345\260\206\344\274\232\345\234\250", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog2", "\345\210\206\351\222\237\345\220\216\345\205\263\351\227\255\350\256\241\347\256\227\346\234\272", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog2", "\345\205\263\351\227\255\345\256\232\346\227\266", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog2", "\350\256\276\347\275\256\345\256\232\346\227\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog2: public Ui_Dialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG2_H
