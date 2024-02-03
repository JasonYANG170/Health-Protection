#ifndef DIALOG6_H
#define DIALOG6_H

#include <QDialog>

namespace Ui {
class Dialog6;
}

class Dialog6 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog6(QWidget *parent = nullptr);
    ~Dialog6();

private:
    Ui::Dialog6 *ui;
};

#endif // DIALOG6_H
