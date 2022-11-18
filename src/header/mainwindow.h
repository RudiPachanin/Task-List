#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "adding.h"
#include "xmlparser.h"
#include "jsonparser.h"
#include "parser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Parser* parser = nullptr;

    void addStringTable(QString,QString,QString);
    Parser* getParser();

private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonDel_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
