#ifndef PLANTES_H
#define PLANTES_H
#include "tableprinter.h"
#include <QDialog>
#include <QMessageBox>


#include "tableprinter.h"
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>

namespace Ui {
class plantes;
}

class plantes : public QDialog
{
    Q_OBJECT

public:
    explicit plantes(QWidget *parent = nullptr);
    ~plantes();

private slots:
    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    //void on_comboBox_4_activated(const QString &arg1);

    void on_comboBox_3_activated(const QString &arg1);

    void on_pushButton_8_clicked();
    void refresh();

    void on_pushButton_5_clicked();

    void on_comboBox_4_activated(const QString &arg1);

    void on_pushButton_12_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_pushButton_7_clicked();

    void on_tableView_3_activated(const QModelIndex &index);

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_6_clicked();
    void print(QPrinter *printer);
    void print_two_tables(QPrinter *printer);
    void uglyPrint(QPrinter *printer);
    void print1(QPrinter *printer);
    void print_two_tables1(QPrinter *printer);
    void uglyPrint1(QPrinter *printer);

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_17_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_15_clicked();

private:
    Ui::plantes *ui;
};

#endif // PLANTES_H
