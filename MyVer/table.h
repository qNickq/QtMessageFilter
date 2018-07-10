#ifndef TABLE_H
#define TABLE_H

#include <QDialog>
#include <set>
namespace Ui {
class Table;
}

class Table : public QDialog
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = 0);
    void setTable(QString&, std::set<QString>&, std::set<QString>&);
    ~Table();



private:
    Ui::Table *ui;
};

#endif // TABLE_H
