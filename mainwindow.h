#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "kub.h"
#include <QOpenGLWindow>
#include <QMainWindow>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    kub *kubb;
};

#endif // MAINWINDOW_H
