/********************************************************************************
** Form generated from reading UI file 'dialog3.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG3_H
#define UI_DIALOG3_H

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

class Ui_Dialog3
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *label;
    QTextEdit *textEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QTextEdit *textEdit_2;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *Dialog3)
    {
        if (Dialog3->objectName().isEmpty())
            Dialog3->setObjectName("Dialog3");
        Dialog3->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(Dialog3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        label = new QLabel(Dialog3);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));

        verticalLayout_2->addWidget(label);

        textEdit = new QTextEdit(Dialog3);
        textEdit->setObjectName("textEdit");
        textEdit->setMinimumSize(QSize(0, 0));
        textEdit->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(textEdit);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(Dialog3);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));

        horizontalLayout->addWidget(label_2);

        textEdit_2 = new QTextEdit(Dialog3);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(textEdit_2);

        label_3 = new QLabel(Dialog3);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));

        horizontalLayout->addWidget(label_3);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton = new QPushButton(Dialog3);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 40));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(255, 255, 0);border:2px groove gray;border-radius:20px;padding:2px 4px;border-style: outset;font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";}\n"
"QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}\n"
""));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(Dialog3);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(0, 40));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(255, 255, 0);border:2px groove gray;border-radius:20px;padding:2px 4px;border-style: outset;font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";}\n"
"QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}\n"
""));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButton_3 = new QPushButton(Dialog3);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(0, 40));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(255, 255, 0);border:2px groove gray;border-radius:20px;padding:2px 4px;border-style: outset;font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";}\n"
"QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}\n"
""));

        horizontalLayout_3->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(Dialog3);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(0, 40));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(255, 255, 0);border:2px groove gray;border-radius:20px;padding:2px 4px;border-style: outset;font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";}\n"
"QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}\n"
""));

        horizontalLayout_3->addWidget(pushButton_4);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(Dialog3);

        QMetaObject::connectSlotsByName(Dialog3);
    } // setupUi

    void retranslateUi(QDialog *Dialog3)
    {
        Dialog3->setWindowTitle(QCoreApplication::translate("Dialog3", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog3", "\350\257\267\350\276\223\345\205\245\351\231\220\345\256\232\346\227\266\351\225\277\347\232\204\345\272\224\347\224\250\347\250\213\345\272\217\345\220\215\347\247\260\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog3", "\345\260\206\345\234\250", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog3", "\345\210\206\351\222\237\345\220\216\345\205\263\351\227\255", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog3", "\347\253\213\345\215\263\345\205\263\351\227\255", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog3", "\345\273\266\346\227\266\345\205\263\351\227\255", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Dialog3", "\347\246\201\346\255\242\350\277\220\350\241\214", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Dialog3", "\345\205\201\350\256\270\350\277\220\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog3: public Ui_Dialog3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG3_H
