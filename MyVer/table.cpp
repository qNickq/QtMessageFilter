#include "table.h"
#include "ui_table.h"
#include "mainwindow.h"

#include <set>
#include <QCheckBox>

using namespace std;

Table::Table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
}

Table::~Table()
{
    delete ui;
}

void Table::setData(QString &head, set<allTypes>& all, set<allTypes>& user)
{
    header = head;
    all_data = &all;
    user_data = &user;
}

QString Table::getType(allTypes t)
{

    switch (t)
    {
    case allTypes::Error : return "Error"; break;
    case allTypes::Info : return "Info"; break;
    case allTypes::no : return "no"; break;
    case allTypes::A: return "A"; break;
    case allTypes::B: return "B"; break;
    }
}

QString &Table::getHeader()
{
    return header;
}
set<allTypes>& Table::getAllSet()
{
    return *all_data;
}
set<allTypes>& Table::getUserSet()
{
    return *user_data;
}


void Table::setTable()
{
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setRowCount(getAllSet().size());
    ui->tableWidget->setWindowTitle(header);

    set<allTypes>::iterator it = getAllSet().begin();

    for (int i = 0; it != getAllSet().end(); ++it, ++i)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->data(Qt::CheckStateRole);

        if(getUserSet().count(*it)) item->setCheckState(Qt::Checked);
        else item->setCheckState(Qt::Unchecked);

        ui->tableWidget->setItem(i,0, item);

        QString type = getType(*it);
        QTableWidgetItem *str = new QTableWidgetItem();
        str->setText(type);

        //QTableWidgetItem *str = new QTableWidgetItem();


        ui->tableWidget->setItem(i,1,str);
        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget->verticalHeader()->hide();

    }

}





void Table::on_buttonBox_accepted()
{

    getUserSet().clear();
    set<allTypes>::iterator it = getAllSet().begin();

    for(int i =0 ; it!=getAllSet().end(); ++it, ++i)
    {
        if(ui->tableWidget->item(i,0)->checkState() == Qt::Checked)
        {
           getUserSet().insert(*it);
        }
        else getUserSet().erase(*it);
    }
    hide();
}

void Table::on_buttonBox_rejected()
{
    this->close();
}

void Table::on_clearCheck_clicked()
{
    for (int i = 0; i<ui->tableWidget->rowCount(); ++i)
    {
        ui->tableWidget->item(i,0)->setCheckState(Qt::Unchecked);
    }
    ui->tableWidget->repaint();
}

void Table::on_allCheck_clicked()
{
    for (int i = 0; i<ui->tableWidget->rowCount(); ++i)
    {
        ui->tableWidget->item(i,0)->setCheckState(Qt::Checked);
    }
    ui->tableWidget->repaint();
}

