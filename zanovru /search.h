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
    void fillVector();
    std::vector<int>& getVector();


private slots:
    void on_pushButton_next_clicked();

    void on_pushButton_prev_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::Search *ui;
    std::map<int, TMessage*> *msg;
    std::vector<int>idx;
};

#endif // SEARCH_H
