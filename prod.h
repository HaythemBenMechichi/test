#ifndef PROD_H
#define PROD_H
#include "tableprinter.h"
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QDebug>

#include <QDialog>

namespace Ui {
class prod;
}

class prod : public QDialog
{
    Q_OBJECT

public:
    explicit prod(QWidget *parent = nullptr);
    ~prod();
    bool verifform1();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();


    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_2_clicked();
    void refresh();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    void on_pushButton_8_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_pushButton_7_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();
    void print2(QPrinter *printer);
    void print_two_tables2(QPrinter *printer);
    void uglyPrint2(QPrinter *printer);
    void print3(QPrinter *printer);
    void print_two_tables3(QPrinter *printer);
    void uglyPrint3(QPrinter *printer);

    void on_pushButton_14_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::prod *ui;
};

#endif // PROD_H
