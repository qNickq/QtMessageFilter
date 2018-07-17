#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QCheckBox>
#include <QAbstractItemView>
#include <set>
#include "mainwindow.h"
#include <QMessageBox>


SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}


SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_pushButton_2_clicked()
{
    for(int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        ui->tableWidget->item(i,0)->setCheckState(Qt::Unchecked);
    }
    ui->tableWidget->repaint();
}

void SecondWindow::on_pushButton_clicked()
{
    for(int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        ui->tableWidget->item(i,0)->setCheckState(Qt::Checked);
    }
    ui->tableWidget->repaint();
}

void SecondWindow::createTable()
{
    ui->tableWidget->setRowCount(getAll().size());
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "№" << "Тип" << "Расшифровка");
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    std::set<MyTypes>::iterator it = getAll().begin();
    for(int i = 0; it != getAll().end(); i++, it++)
    {
        QString type = getType(*it);
        QTableWidgetItem *str = new QTableWidgetItem;
        str->setText(type);
        ui->tableWidget->setItem(i,1,str);
        QString desc = getDescription(*it);
        QTableWidgetItem *str1 = new QTableWidgetItem;
        str1->setText(desc);
        ui->tableWidget->setItem(i,2,str1);
        QTableWidgetItem *item = new QTableWidgetItem();
        item->data(Qt::CheckStateRole);
        if (getEdited().count(*it))
        {
           item->setCheckState(Qt::Checked);
        }
        else
        {
           item->setCheckState(Qt::Unchecked);
        }
        ui->tableWidget->setItem(i,0,item);
        ui->tableWidget->item(i,0)->setText(QString::number(i+1));
        ui->tableWidget->verticalHeader()->setVisible(false);
    }
    ui->tableWidget->resizeColumnsToContents();


}


void SecondWindow::on_pushButton_accept_clicked()
{
    std::set<MyTypes>::iterator it = getAll().begin();
    for(int i = 0; it != getAll().end(); i++, it++)
    {
        if(ui->tableWidget->item(i,0)->checkState() == Qt::Checked)
        {
            getEdited().insert(*it);
        }
        else
        {
            getEdited().erase(*it);
        }
    }
    hide();
}

void SecondWindow::setData(std::set<MyTypes>& all, std::set<MyTypes>& edited)
{
    FullSet1 = &all;
    EditedSet1 = &edited;
}

std::set<MyTypes>& SecondWindow::getAll()
{
    return *FullSet1;
}

std::set<MyTypes>& SecondWindow::getEdited()
{
    return *EditedSet1;
}
QString SecondWindow::getType(MyTypes type)
{
    switch(type)
    {
    case MyTypes::Error:
        return "Error";
        break;
    case MyTypes::Info:
        return "Info";
        break;
    case MyTypes::Warning:
        return "Warning";
        break;
    case MyTypes::Message:
        return "Message";
        break;
    case MyTypes::Help:
        return "Help";
        break;
    }
}

QString SecondWindow::getDescription(MyTypes type)
{
    switch(type)
    {
    case MyTypes::Error:
        return "This is error";
        break;
    case MyTypes::Info:
        return "This is info";
        break;
    case MyTypes::Warning:
        return "This is warning";
        break;
    case MyTypes::Message:
        return "This is message";
        break;
    case MyTypes::Help:
        return "This is help";
        break;
    }
}



