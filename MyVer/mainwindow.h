#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <set>
#include <map>

using namespace std;

namespace Ui {
class MainWindow;
}

struct TMessage
{
    int msgNum;
    double msgTime;
    int msgType;
    string text;
};


enum class allTypes
{
    Error,
    Info,
    no,
    A,
    B
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void on_mainButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
