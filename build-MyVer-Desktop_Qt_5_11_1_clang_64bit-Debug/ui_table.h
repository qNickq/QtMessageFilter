/********************************************************************************
** Form generated from reading UI file 'table.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_H
#define UI_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Table
{
public:
    QTableWidget *tableWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *clearCheck;
    QPushButton *allCheck;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Table)
    {
        if (Table->objectName().isEmpty())
            Table->setObjectName(QStringLiteral("Table"));
        Table->resize(407, 260);
        tableWidget = new QTableWidget(Table);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 391, 192));
        tableWidget->setLayoutDirection(Qt::LeftToRight);
        tableWidget->setAutoFillBackground(false);
        layoutWidget = new QWidget(Table);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 220, 391, 32));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        clearCheck = new QPushButton(layoutWidget);
        clearCheck->setObjectName(QStringLiteral("clearCheck"));

        horizontalLayout_2->addWidget(clearCheck);

        allCheck = new QPushButton(layoutWidget);
        allCheck->setObjectName(QStringLiteral("allCheck"));

        horizontalLayout_2->addWidget(allCheck);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        retranslateUi(Table);
        QObject::connect(buttonBox, SIGNAL(accepted()), Table, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Table, SLOT(reject()));

        QMetaObject::connectSlotsByName(Table);
    } // setupUi

    void retranslateUi(QDialog *Table)
    {
        Table->setWindowTitle(QApplication::translate("Table", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Table", "\320\242\320\224", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Table", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Table", "\320\244\320\276\321\200\320\274\321\203\320\273\321\217\321\200", nullptr));
        clearCheck->setText(QApplication::translate("Table", "\320\241\320\275\321\217\321\202\321\214 \320\262\321\201\320\265", nullptr));
        allCheck->setText(QApplication::translate("Table", "\320\227\320\260\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \320\262\321\201\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Table: public Ui_Table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_H
