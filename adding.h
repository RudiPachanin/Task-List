#ifndef ADDING_H
#define ADDING_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Adding;
}

class Adding : public QDialog
{
    Q_OBJECT

public:
    explicit Adding(QWidget *parent = nullptr);
    ~Adding();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Adding *ui;
};

#endif // ADDING_H
