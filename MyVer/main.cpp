#include "mainwindow.h"
#include "table.h"
#include <QApplication>
#include <set>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    w.show();

    return a.exec();
}
