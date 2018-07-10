#include "table.h"
#include "ui_table.h"
#include"mainwindow.h"
#include <set>
#include <QCheckBox>

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

void Table::setTable(QString &header, std::set<QString>&all, std::set<QString>&main)
{
    ui->tableWidget->setRowCount(all.size());

    std::set<QString>::iterator it = all.begin();

    for (int i = 0; it!=all.end();++it,++i)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->data(Qt::CheckStateRole);
        if(main.count(*it)) item->setCheckState(Qt::Checked);
        else item->setCheckState(Qt::Unchecked);
        ui->tableWidget->setItem(i,0, item);

        ui->tableWidget->setItem(i,2, new QTableWidgetItem(*it));
        ui->tableWidget->resizeColumnsToContents();

    }
}





/*void Table::on_buttonBox_accepted()
{
    for(int i =0 ; i< ui->tableWidget->rowCount(); ++i)
    {
        QWidget *item = ui->tableWidget->cellWidget(i, 0);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(item->layout()->itemAt(0)->widget());

    }
}*/
