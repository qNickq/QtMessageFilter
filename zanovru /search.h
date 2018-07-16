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


private slots:
    void on_pushButton_next_clicked();

    void on_pushButton_prev_clicked();

//    void on_radioButton_num_clicked();

//    void on_radioButton_time_clicked();

//    void on_radioButton_type_clicked();

//    void on_radioButton_text_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::Search *ui;
    std::map<int, TMessage*> *msg;
};

#endif // SEARCH_H
