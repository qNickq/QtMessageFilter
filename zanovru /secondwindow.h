#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QTableWidget>
#include <set>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = 0);
    ~SecondWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
    void createTable();

private:
    Ui::SecondWindow *ui;
    QString string;
    enum class MyTypes;
    std::set<MyTypes>FullSet;
    std::set<MyTypes>ChangedSet;
};

#endif // SECONDWINDOW_H
