#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_adding.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    parser.readXml(ui->tableWidget);
}

MainWindow::~MainWindow()
{
    parser.createNewXml(ui->tableWidget);
    delete ui;
}

void MainWindow::addStringTable(QString Fio, QString Task, QString date)
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(Fio));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1, new QTableWidgetItem(date));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2, new QTableWidgetItem(Task));

}


void MainWindow::on_pushButtonAdd_clicked()
{
    Adding* newDialog = new Adding(this);
    newDialog->show();
}
