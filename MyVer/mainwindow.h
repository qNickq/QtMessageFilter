#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <set>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void setData(QString& head, std::set<QString>& all, std::set<QString>& user);

    QString& getHeader();
    std::set<QString>& getAllSet();
    std::set<QString>& getUserSet();

    ~MainWindow();

private slots:
    void on_mainButton_clicked();

private:
    Ui::MainWindow *ui;
    QString *header;
    std::set<QString>*all_data;
    std::set<QString>*user_data;
};

#endif // MAINWINDOW_H
