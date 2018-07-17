#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include <QString>
#include "secondwindow.h"
#include "search.h"


std::set<MyTypes>*FullSet = new std::set<MyTypes>;
std::set<MyTypes>*EditedSet = new std::set<MyTypes>;
std::string header;
std::map<int, TMessage*> *messages = new std::map<int, TMessage*>;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));
    FullSet->insert(MyTypes::Error);
    FullSet->insert(MyTypes::Info);
    FullSet->insert(MyTypes::Warning);
    FullSet->insert(MyTypes::Message);
    FullSet->insert(MyTypes::Help);
    EditedSet->insert(MyTypes::Info);
    EditedSet->insert(MyTypes::Help);
    header = "My Table";
    for(int i = 0; i < 1000; ++i)
    {
        TMessage *msg = new TMessage;
        QTime time = QTime::currentTime();
        msg->msgNum = rand() % 100;
        msg->msgType = rand() % 100;
        msg->msgTime = time.hour()*60*60 + time.minute()*60 + time.second() + i;
        msg->msgName = "Message=" + std::to_string(i);
        (*messages)[i] = msg;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    SecondWindow *window = new SecondWindow;
    window->setData(*FullSet, *EditedSet);
    window->setModal(true);
    window->setWindowTitle(QString::fromStdString(header));
    window->createTable();
    window->resize(window->sizeHint());
    window->show();
}





void MainWindow::on_pushButton_2_clicked()
{
    Search *wndw = new Search;
    wndw->setMap(*messages);
    wndw->show();
}
