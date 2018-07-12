#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
//#include "secondwindow.h"
#include <set>
#include <string>

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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
