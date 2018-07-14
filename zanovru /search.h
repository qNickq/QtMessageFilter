#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include "mainwindow.h"
#include <QMessageBox>


namespace Ui {
class Search;
}

class Search : public QWidget
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = 0);
    ~Search();
    void setMap(std::map<int, TMessage*>&);
    std::map<int, TMessage*>& getMap();


private slots:
    void on_pushButton_next_clicked();

private:
    Ui::Search *ui;
    std::map<int, TMessage*> *msg;
};

#endif // SEARCH_H
