#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_adding.h"
#include "QModelIndex"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    parser = getParser();
    parser->read(ui->tableWidget);
}

MainWindow::~MainWindow()
{
    parser = getParser();
    parser->save(ui->tableWidget);
    delete ui;
}

void MainWindow::addStringTable(QString Fio, QString Task, QString date)
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(Fio));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1, new QTableWidgetItem(date));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2, new QTableWidgetItem(Task));

}

Parser *MainWindow::getParser()
{
    if (parser) {
        delete parser;
    }
    if (ui->radioButtonXml->isChecked()) {
        return new XmlParser();
    }
    return new JsonParser();
}


void MainWindow::on_pushButtonAdd_clicked()
{
    Adding* newDialog = new Adding(this);
    newDialog->show();
}

void MainWindow::on_pushButtonDel_clicked()
{
    QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();
    while (!selectedRows.empty()) {
        ui->tableWidget->removeRow(selectedRows[0].row());
        selectedRows = ui->tableWidget->selectionModel()->selectedRows();
    }
}

