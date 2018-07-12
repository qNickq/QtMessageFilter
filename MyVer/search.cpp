#include "search.h"
#include "ui_search.h"
#include "mainwindow.h"

Search::Search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);

}

Search::~Search()
{
    delete ui;
}

void Search::setData(std::map<int, TMessage*>& mesg)
{
    msg = &mesg;

}

std::map<int, TMessage*>& Search::getMap()
{
    return *msg;
}
