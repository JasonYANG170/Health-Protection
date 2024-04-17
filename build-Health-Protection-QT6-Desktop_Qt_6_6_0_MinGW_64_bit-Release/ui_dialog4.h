/********************************************************************************
** Form generated from reading UI file 'dialog4.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG4_H
#define UI_DIALOG4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog4
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QTextEdit *textEdit;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QTextEdit *textEdit_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_5;

    void setupUi(QDialog *Dialog4)
    {
        if (Dialog4->objectName().isEmpty())
            Dialog4->setObjectName("Dialog4");
        Dialog4->resize(400, 300);
        verticalLayout = new QVBoxLayout(Dialog4);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(Dialog4);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));

        horizontalLayout->addWidget(label);

        textEdit = new QTextEdit(Dialog4);
        textEdit->setObjectName("textEdit");
        textEdit->setMaximumSize(QSize(16777215, 40));

        horizontalLayout->addWidget(textEdit);

        label_2 = new QLabel(Dialog4);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(Dialog4);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));

        horizontalLayout_2->addWidget(label_3);

        textEdit_2 = new QTextEdit(Dialog4);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_2->addWidget(textEdit_2);

        label_4 = new QLabel(Dialog4);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));

        horizontalLayout_2->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");

        verticalLayout->addLayout(horizontalLayout_3);

        checkBox_2 = new QCheckBox(Dialog4);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setMinimumSize(QSize(0, 60));
        checkBox_2->setStyleSheet(QString::fromUtf8("QCheckBox{background-color: rgb(255, 255, 0);border:2px groove gray;border-radius:30px;padding:2px 4px;border-style: outset;font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";}\n"
"QCheckBox:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"QCheckBox:pressed{background-color:rgb(204, 228, 247);border-style: inset;}\n"
""));

        verticalLayout->addWidget(checkBox_2);

        checkBox = new QCheckBox(Dialog4);
        checkBox->setObjectName("checkBox");
        checkBox->setMinimumSize(QSize(0, 60));
        checkBox->setStyleSheet(QString::fromUtf8("QCheckBox{background-color: rgb(255, 255, 0);border:2px groove gray;border-radius:30px;padding:2px 4px;border-style: outset;font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";}\n"
"QCheckBox:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"QCheckBox:pressed{background-color:rgb(204, 228, 247);border-style: inset;}\n"
""));

        verticalLayout->addWidget(checkBox);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");

        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(Dialog4);

        QMetaObject::connectSlotsByName(Dialog4);
    } // setupUi

    void retranslateUi(QDialog *Dialog4)
    {
        Dialog4->setWindowTitle(QCoreApplication::translate("Dialog4", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog4", "\345\260\206\345\234\250", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog4", "\347\202\271\345\274\200\345\220\257\346\267\261\350\211\262\346\250\241\345\274\217", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog4", "\345\260\206\345\234\250", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog4", "\347\202\271\345\205\263\351\227\255\346\267\261\350\211\262\346\250\241\345\274\217", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Dialog4", "\345\274\200\345\220\257\345\256\232\346\227\266", nullptr));
        checkBox->setText(QCoreApplication::translate("Dialog4", "\345\274\200\345\220\257\346\267\261\350\211\262\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog4: public Ui_Dialog4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG4_H
