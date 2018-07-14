#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QTableWidget>
#include <set>
#include "mainwindow.h"

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = 0);
    ~SecondWindow();
    void setData(std::string& , std::set<MyTypes>& , std::set<MyTypes>&);
    std::set<MyTypes>& getAll();
    std::string& getHeader();
    std::set<MyTypes>& getEdited();
    void createTable();
    QString getType(MyTypes);
    QString getDescription(MyTypes);


private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_accept_clicked();

private:
    Ui::SecondWindow *ui;
    std::string header1;
    std::set<MyTypes>*FullSet1;
    std::set<MyTypes>*EditedSet1;
};

#endif // SECONDWINDOW_H
