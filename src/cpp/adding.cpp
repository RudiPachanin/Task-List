#include "adding.h"
#include "ui_adding.h"


Adding::Adding(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adding)
{
    ui->setupUi(this);
}

Adding::~Adding()
{
    delete ui;
}

void Adding::on_buttonBox_accepted()
{

    QString Fio = ui->lineEditFIO->text();
    QString Task = ui->textEditTask->toPlainText();
    QString date = ui->dateTimeEdit->text();
    ((MainWindow*)this->parent())->addStringTable(Fio,Task,date);
    this->close();
}

