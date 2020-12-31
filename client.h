#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>

namespace Ui {
class client;
}

class client : public QDialog
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    void refresh();
     void refresh_2();
    ~client();

private slots:
     void sendMail();
     void mailSent(QString);
    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_tableView_3_activated(const QModelIndex &index);

    void on_pushButton_11_clicked();

private:
    Ui::client *ui;
};

#endif // CLIENT_H
