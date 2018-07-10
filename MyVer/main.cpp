#include "mainwindow.h"
#include <QApplication>
#include <set>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString * header = new QString("My table ee");

    std::set<QString>*set_all = new std::set<QString>();
    std::set<QString>*set_main = new std::set<QString>();

    set_all->insert("Error,Yes");
    set_all->insert("Information,Yes");
    set_all->insert("No");

    set_main->insert("No");

    MainWindow w;
    w.setData(*header,*set_all,*set_main);
    w.show();

    return a.exec();
}
