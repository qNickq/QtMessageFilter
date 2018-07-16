#ifndef ACCEPT_H
#define ACCEPT_H

#include <QWidget>

namespace Ui {
class Accept;
}

class Accept : public QWidget
{
    Q_OBJECT

public:
    explicit Accept(QWidget *parent = 0);
    ~Accept();
    std::vector<int>::iterator& getIter();
    std::vector<int>& getVector();
    void setData(std::vector<int>::iterator&, std::vector<int>&);

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Accept *ui;
    std::vector<int>::iterator *it;
    std::vector<int>* idx2;

};

#endif // ACCEPT_H
