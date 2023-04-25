#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (kubb)
        delete kubb;
}

void MainWindow::on_pushButton_clicked()
{
    kubb=new kub();
    kubb->resize(600,600);
    kubb->show();
}
