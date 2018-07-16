#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <set>
#include <string>
#include <map>
#include <cstdlib>
#include <QTime>
#include <vector>

namespace Ui {
class MainWindow;
}

enum class MyTypes
{
  Error,
  Info,
  Warning,
  Message,
  Putin
};

struct TMessage
{
    int msgNum;
    double msgTime;
    int msgType;
    std::string msgName;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
