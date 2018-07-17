#include "search.h"
#include "ui_search.h"
#include "mainwindow.h"



std::vector<int>idx;
std::vector<int>::iterator it;
int ch;

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

void Search::setMap(std::map<int, TMessage*>& message)
{
    msg = &message;
}

std::map<int, TMessage*>& Search::getMap()
{
    return *msg;
}



void Search::on_pushButton_next_clicked()
{
    if( ch == 2 ) ++it;
    if(idx.size() == 0)
    {
        fillVector();
        it = idx.begin();
    }
    if(idx.size() > 0)
    {
        if(it != idx.end())
        {
           QMessageBox::information(this,"Title","Ключ №" + QString::number(*it++));

        }
        else
        {
           QMessageBox::StandardButton reply = QMessageBox::question(this, "Title", "Хотите начать поиск заново?",QMessageBox::Yes | QMessageBox::No);
           if(reply == QMessageBox::Yes)
           {
                it = idx.begin();
           }
        }
    }
    else
    {
        QMessageBox::critical(this, "Title", "Поиск не дал результатов!");
    }

    ch = 1;
}






void Search::on_pushButton_prev_clicked()
{
    if( ch == 1 ) --it;
    if(idx.size() == 0)
    {
        fillVector();
        it = idx.begin();
    }
    if(idx.size() > 0)
    {
        if(it != --idx.begin())
        {
           QMessageBox::information(this,"Title", "Ключ №" + QString::number(*it--));
        }
        else
        {
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Title", "Хотите начать поиск заново?",QMessageBox::Yes | QMessageBox::No);
            if(reply == QMessageBox::Yes)
            {
                 it = idx.begin();
            }
        }

    }
    else
    {
        QMessageBox::critical(this, "Title", "Поиск не дал результатов!");
    }


    ch = 2;
}


void Search::fillVector()
{
    if(ui->radioButton_num->isChecked())
    {
        idx.clear();
        it = idx.begin();
        for(int i = 0; i < 1000; ++i)
        {
            if((*msg)[i]->msgNum == (ui->lineEdit->text()).toInt())
            {
                idx.push_back(i);
            }
        }
    }

    if(ui->radioButton_time->isChecked())
    {
        idx.clear();
        it = idx.begin();
        for(int i = 0; i < 1000; ++i)
        {
           if((*msg)[i]->msgTime == (ui->lineEdit->text()).toDouble())
           {
               idx.push_back(i);
           }
        }
    }

    if(ui->radioButton_type->isChecked())
    {
        idx.clear();
        it = idx.begin();
        for(int i = 0; i < 1000; ++i)
        {
           if((*msg)[i]->msgType == (ui->lineEdit->text()).toInt())
           {
               idx.push_back(i);
           }
        }
    }

    if(ui->radioButton_text->isChecked())
    {
        idx.clear();
        it = idx.begin();
        for(int i = 0; i < 1000; ++i)
        {
           if((*msg)[i]->msgName == (ui->lineEdit->text()).toStdString())
           {
               idx.push_back(i);
           }
        }
    }
}

void Search::on_lineEdit_textChanged(const QString &arg1)
{
    idx.clear();
}
