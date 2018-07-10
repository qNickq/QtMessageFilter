#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->setVisible(false);
    SecondWindow window;
    window.setModal(true);
    window.exec();
}
