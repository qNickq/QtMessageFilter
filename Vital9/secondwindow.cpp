#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QCheckBox>
#include <QAbstractItemView>


SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "чекбокс" << "тип" << "имя");
    for(int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->data(Qt::CheckStateRole);
        item->setCheckState(Qt::Checked);
        ui->tableWidget->setItem(i,0,item);
    }
    ui->tableWidget->resizeColumnsToContents();
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

