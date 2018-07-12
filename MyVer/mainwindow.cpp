#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "table.h"
#include "search.h"

#include <QTime>

using namespace std;


QString header;

set<allTypes>*set_all = new set<allTypes>;
set<allTypes>*set_user = new set<allTypes>;

map<int, TMessage*> *messages = new map<int, TMessage*>;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    header = "My table!";
    set_all->insert(allTypes::Error);
    set_all->insert(allTypes::Info);
    set_all->insert(allTypes::no);
    set_all->insert(allTypes::A);
    set_all->insert(allTypes::B);


    set_user->insert(allTypes::Error);
    set_user->insert(allTypes::no);

    for (int i = 0 ; i < 10000; ++i)
    {
        TMessage *mes = new TMessage;
        mes->msgNum = rand() % 100 + 1;
        QTime currTime = QTime::currentTime();
        mes->msgTime =  currTime.hour()*60 + currTime.minute()*60 + currTime.second() + i ;
        mes->msgType = rand() % 5 + 1;
        mes->text = "Message = "+ std::to_string(i);
        (*messages)[i] = mes;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_mainButton_clicked()
{
    //this->hide();
    Table * mainTable = new Table();
    mainTable->setData(header,*set_all,*set_user);
    mainTable->setTable();
    mainTable->setModal(true);
    mainTable->show();
}


void MainWindow::on_pushButton_clicked()
{
    Search * search = new Search();
    search->setData(*messages);
    search->show();
}
