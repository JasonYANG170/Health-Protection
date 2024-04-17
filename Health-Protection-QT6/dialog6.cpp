#include "dialog6.h"
#include "ui_dialog6.h"

Dialog6::Dialog6(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog6)
{
    ui->setupUi(this);
}

Dialog6::~Dialog6()
{
    delete ui;
}
