#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "secondwindow.h"
#include "search.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
