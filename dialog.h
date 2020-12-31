#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();


private slots:
    void on_pushButton_clicked();
    void sendMail();
    void mailSent(QString);
     bool trouve(int);
bool verif_form();
bool verif_formdate();
void on_pushButton_2_clicked();

void on_comboBox_activated(const QString &arg1);

void on_pushButton_4_clicked();

void on_pushButton_3_clicked();

void on_pushButton_5_clicked();

void on_comboBox_2_activated(const QString &arg1);

void on_pushButton_6_clicked();



void on_tableView_activated(const QModelIndex &index);

void on_comboBox_3_activated(const QString &arg1);

void on_pushButton_8_clicked();
void refresh();
void delay();


void on_comboBox_3_activated(int index);

void on_tableView_2_activated(const QModelIndex &index);

void on_tableView_clicked(const QModelIndex &index);

void on_pushButton_7_clicked();



void on_pushButton_9_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
