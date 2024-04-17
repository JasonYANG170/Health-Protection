/********************************************************************************
** Form generated from reading UI file 'dialog6.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG6_H
#define UI_DIALOG6_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog6
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog6)
    {
        if (Dialog6->objectName().isEmpty())
            Dialog6->setObjectName("Dialog6");
        Dialog6->resize(528, 270);
        verticalLayout = new QVBoxLayout(Dialog6);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_3 = new QLabel(Dialog6);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        label_2 = new QLabel(Dialog6);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/Desktop/a1bf4725bee712e6916866de02eb50f.jpg);"));

        horizontalLayout->addWidget(label_2);

        label = new QLabel(Dialog6);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/Desktop/6b73c9ae58aaad1b631e73f3dd357e9.jpg);"));

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(Dialog6);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialog6);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog6, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog6, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog6);
    } // setupUi

    void retranslateUi(QDialog *Dialog6)
    {
        Dialog6->setWindowTitle(QCoreApplication::translate("Dialog6", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog6", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">\345\274\200\345\217\221\347\225\231\350\250\200</span></p><p><span style=\" font-size:14pt;\">\346\202\250\347\232\204\346\215\220\350\265\240\346\230\257\346\210\221\346\234\200\345\244\247\347\232\204\345\212\250\345\212\233\357\274\214</span></p><p><span style=\" font-size:14pt;\">\346\204\237\350\260\242\346\224\257\346\214\201</span></p><p><span style=\" font-size:14pt; font-weight:700;\">palpay\346\215\220\350\265\240</span></p><p><span style=\" font-size:14pt;\">qw200477@163.com</span></p></body></html>", nullptr));
        label_2->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog6: public Ui_Dialog6 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG6_H
