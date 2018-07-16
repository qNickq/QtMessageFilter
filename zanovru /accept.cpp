#include "accept.h"
#include "ui_accept.h"
#include "search.h"

Accept::Accept(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Accept)
{
    ui->setupUi(this);
}

Accept::~Accept()
{
    delete ui;
}



void Accept::on_pushButton_clicked()
{
    getIter() = getVector().begin();
}

void Accept::on_pushButton_2_clicked()
{
    hide();
}

void Accept::setData(std::vector<int>::iterator& iter, std::vector<int>& idx)
{
   it = &iter;
   idx2 = &idx;
}

std::vector<int>::iterator& Accept::getIter()
{
    return *it;
}

std::vector<int>& Accept::getVector()
{
    return *idx2;
}


