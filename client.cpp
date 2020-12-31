#include "client.h"
#include "clients.h"
#include "ui_client.h"
#include "clients.h"
#include "fournisseur.h"
#include <QMessageBox>
#include "smtp.h"
client::client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
    fournisseur f;
    ui->comboBox->setModel(f.afficher_cin());
      ui->label_11->setNum(ui->comboBox->currentText().toInt());
    ui->tableView->setModel(f.afficher());
    clients c;
    ui->comboBox_3->setModel(c.afficher_cin());
      ui->label_19->setNum(ui->comboBox_3->currentText().toInt());
    ui->tableView_3->setModel(c.afficher());
     connect(ui->pushButton_13, SIGNAL(clicked()),this, SLOT(sendMail()));
}

client::~client()
{
    delete ui;
}
void client::sendMail()
{
    Smtp* smtp = new Smtp(ui->lineEdit_9->text(), ui->lineEdit_10->text(), ui->lineEdit->text(), ui->lineEdit_8->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->lineEdit_9->text(), ui->lineEdit_20->text() , ui->lineEdit_11->text(),ui->lineEdit_12->text());
}
void client::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::information( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
void client::refresh()
{
    fournisseur f;
    ui->label_11->setNum(ui->comboBox->currentText().toInt());
    ui->comboBox->setModel(f.afficher_cin());
    ui->tableView->setModel(f.afficher());

}
void client::refresh_2(){


    clients c;
    ui->comboBox_3->setModel(c.afficher_cin());
      ui->label_19->setNum(ui->comboBox_3->currentText().toInt());
    ui->tableView_3->setModel(c.afficher());


}

void client::on_pushButton_clicked()
{
    int a= ui->lineEdit_2->text().toInt();
    QString b= ui->lineEdit_3->text();
    QString c= ui->lineEdit_4->text();
    QString d= ui->lineEdit_5->text();
    int e= ui->lineEdit_7->text().toInt();

    fournisseur o(b,c,a,d,e);
    if(o.ajouter()){

        QMessageBox::information(nullptr, QObject::tr("ajout successful"),
                    QObject::tr("ajout successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

        refresh();




    }

}

void client::on_comboBox_activated(const QString &arg1)
{
    ui->label_11->setNum(arg1.toInt());
}

void client::on_pushButton_4_clicked()
{
    int idp = ui->label_11->text().toInt();
    fournisseur c;
    bool test=c.supprimer(idp);
    if(test)
    {ui->tableView->setModel(c.afficher());
        QMessageBox::information(nullptr,QObject::tr("Supprime une plante"),QObject::tr("plante supprimer.\n"
                                                                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    refresh();
}

void client::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();
    ui->label_12->setText(val);
    fournisseur f;
    QSqlQuery query=f.rechT(val);
    if(query.exec())
    {
    while(query.next())
    {
        ui->lineEdit_3->setText(query.value(0).toString());
        ui->lineEdit_4->setText(query.value(1).toString());
        ui->lineEdit_2->setText(query.value(2).toString());
        ui->lineEdit_5->setText(query.value(3).toString());
        ui->lineEdit_7->setText(query.value(4).toString());


    }
}
}

void client::on_pushButton_3_clicked()
{
    int id = ui->label_12->text().toInt();
    QString nom=ui->lineEdit_3->text();
    QString prenom=ui->lineEdit_4->text();
    int cinn =ui->lineEdit_2->text().toInt();
    QString mail =ui->lineEdit_5->text();
    int numero =ui->lineEdit_7->text().toInt();

    fournisseur c(nom,prenom,cinn,mail,numero);
    bool test=c.modifier(id);
    if(test)
    {
    QMessageBox::information(nullptr,QObject::tr("modifier un client"),QObject::tr("client modifier.\n"
                                                                                    "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {
        QMessageBox::information(nullptr,QObject::tr("modifier un fournisseur"),QObject::tr("erreur modifier.\n"
                                                                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    refresh();
}

void client::on_pushButton_9_clicked()
{
    int a= ui->lineEdit_13->text().toInt();
    QString b= ui->lineEdit_14->text();
    QString c= ui->lineEdit_15->text();
    QString d= ui->lineEdit_16->text();
    int e= ui->lineEdit_17->text().toInt();
    int f= ui->lineEdit_18->text().toInt();
    int g = ui->lineEdit_19->text().toInt();

    clients o(b,c,a,d,e,f,g);
    if(o.ajouter()){

        QMessageBox::information(nullptr, QObject::tr("ajout successful"),
                    QObject::tr("ajout successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

        refresh_2();
    }

}

void client::on_pushButton_12_clicked()
{
    int idp = ui->label_19->text().toInt();
    clients c;
    bool test=c.supprimer(idp);
    if(test)
    {ui->tableView_3->setModel(c.afficher());
        QMessageBox::information(nullptr,QObject::tr("Supprime une plante"),QObject::tr("plante supprimer.\n"
                                                                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    refresh_2();

}

void client::on_tableView_3_activated(const QModelIndex &index)
{
    QString val = ui->tableView_3->model()->data(index).toString();
    ui->label_20->setText(val);
    clients f;
    QSqlQuery query=f.rechT(val);
    if(query.exec())
    {
    while(query.next())
    {
        ui->lineEdit_14->setText(query.value(0).toString());
        ui->lineEdit_15->setText(query.value(1).toString());
        ui->lineEdit_13->setText(query.value(2).toString());
        ui->lineEdit_16->setText(query.value(3).toString());
        ui->lineEdit_17->setText(query.value(4).toString());
        ui->lineEdit_18->setText(query.value(5).toString());
        ui->lineEdit_19->setText(query.value(6).toString());


    }
}

}

void client::on_pushButton_11_clicked()
{
    int id = ui->label_20->text().toInt();
    QString nom=ui->lineEdit_14->text();
    QString prenom=ui->lineEdit_15->text();
    int cinn =ui->lineEdit_13->text().toInt();
    QString mail =ui->lineEdit_16->text();
    int numero =ui->lineEdit_17->text().toInt();
    int a =ui->lineEdit_18->text().toInt();
    int b =ui->lineEdit_19->text().toInt();

    clients c(nom,prenom,cinn,mail,numero,a,b);
    bool test=c.modifier(id);
    if(test)
    {
    QMessageBox::information(nullptr,QObject::tr("modifier un client"),QObject::tr("client modifier.\n"
                                                                                    "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {
        QMessageBox::information(nullptr,QObject::tr("modifier un fournisseur"),QObject::tr("erreur modifier.\n"
                                                                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    refresh_2();

}
