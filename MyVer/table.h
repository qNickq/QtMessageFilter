#ifndef TABLE_H
#define TABLE_H

#include <QDialog>
#include <set>
#include "mainwindow.h"

using namespace std;

namespace Ui {
class Table;
}


class Table : public QDialog
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = 0);

    ~Table();

private slots:

    void on_clearCheck_clicked();
    void on_allCheck_clicked();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

signals:
    void changeRowState();

private:
    Ui::Table *ui;

    QString header;
    set<allTypes>*all_data;
    set<allTypes>*user_data;

public :

    void setTable();
    void setData(QString&, set<allTypes>&, set<allTypes>&);

    QString getType(allTypes);

    QString &getHeader();
    set<allTypes>& getAllSet();
    set<allTypes>& getUserSet();

};

#endif // TABLE_H
