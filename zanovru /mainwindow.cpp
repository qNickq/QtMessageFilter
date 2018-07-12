#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include <QString>
#include "secondwindow.h"

std::set<MyTypes>*FullSet = new std::set<MyTypes>;
std::set<MyTypes>*EditedSet = new std::set<MyTypes>;
std::string header;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    FullSet->insert(MyTypes::Error);
    FullSet->insert(MyTypes::Info);
    FullSet->insert(MyTypes::Warning);
    FullSet->insert(MyTypes::Message);
    FullSet->insert(MyTypes::Putin);
    EditedSet->insert(MyTypes::Info);
    EditedSet->insert(MyTypes::Putin);
    header = "My Table";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    SecondWindow *window = new SecondWindow;
    window->setData(header, *FullSet, *EditedSet);
    window->setModal(true);
    window->createTable();
    window->resize(window->sizeHint());
    window->show();
}


