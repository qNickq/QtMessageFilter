#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "table.h"

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

void MainWindow::setData(QString& head, std::set<QString>& all, std::set<QString>& user)
{
    header = &head;
    all_data = &all;
    user_data = &user;
}
QString &MainWindow::getHeader()
{
    return *header;
}
std::set<QString>& MainWindow::getAllSet()
{
    return *all_data;
}

std::set<QString>& MainWindow::getUserSet()
{
    return *user_data;
}

void MainWindow::on_mainButton_clicked()
{
    this->hide();
    Table * mainTable = new Table();
    mainTable->setTable(getHeader(),getAllSet(),getUserSet());
    mainTable->show();
}



