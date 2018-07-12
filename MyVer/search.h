#ifndef SEARCH_H
#define SEARCH_H
#include <mainwindow.h>
#include <QWidget>

namespace Ui {
class Search;
}

class Search : public QWidget
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = 0);
    ~Search();

private:
    Ui::Search *ui;

    std::map<int, TMessage*> *msg;
public:
   std::map<int, TMessage*>& getMap();
   void setData(std::map<int, TMessage*>&);
};

#endif // SEARCH_H
