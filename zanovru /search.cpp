#include "search.h"
#include "ui_search.h"

std::map<int, TMessage*> newmsg;

Search::Search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
    if(ui->radioButton_num->isChecked())
    {
        newmsg.clear();
        std::map<int, TMessage*>::iterator it = getMap().begin();
        for(; it != getMap().end(); ++it)
        {
           if(it->second->msgNum == (ui->lineEdit->text()).toInt())
           {
               newmsg.insert(it->first,it->second);
           }
        }
        std::map<int, TMessage*>::iterator iter = newmsg.begin();
     }
    if(ui->radioButton_time->isChecked())
    {
        newmsg.clear();
        std::map<int, TMessage*>::iterator it = getMap().begin();
        for(; it != getMap().end(); ++it)
        {
           if(it->second->msgTime == (ui->lineEdit->text()).toDouble())
           {
               newmsg.insert(it->first,it->second);
           }
        }
        std::map<int, TMessage*>::iterator iter = newmsg.begin();
     }
    if(ui->radioButton_type->isChecked())
    {
        newmsg.clear();
        std::map<int, TMessage*>::iterator it = getMap().begin();
        for(; it != getMap().end(); ++it)
        {
           if(it->second->msgType == (ui->lineEdit->text()).toInt())
           {
               newmsg.insert(it->first,it->second);
           }
        }
        std::map<int, TMessage*>::iterator iter = newmsg.begin();
     }
    if(ui->radioButton_num->isChecked())
    {
        newmsg.clear();
        std::map<int, TMessage*>::iterator it = getMap().begin();
        for(; it != getMap().end(); ++it)
        {
           if(it->second->msgNum == (ui->lineEdit->text()).toInt())
           {
               newmsg.insert(it->first,it->second);
           }
        }
        std::map<int, TMessage*>::iterator iter = newmsg.begin();
    }
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
    std::map<int, TMessage*>::iterator it;
    if(newmsg.size() > 0)
    {
       while(it != newmsg.end())
       {
           QMessageBox::information(this,"Title", QString::number(it->first));
       }
    }
    else
    {
        QMessageBox::critical(this, "Title", "Поиск не дал результатов!");
    }
    it++;
}



