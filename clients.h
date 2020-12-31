#ifndef CLIENTS_H
#define CLIENTS_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class clients
{
public:
    clients();
    clients(QString,QString,int,QString,int,int,int);
    QSqlQuery rech(int);
    QSqlQuery rechT(QString);
    QString get_nom();
    QString get_prenom();
    int get_cinn();
    QString get_mail();
    int get_numero();
    int get_nombreA();
    int get_sommeP();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_cin();
    bool supprimer (int);
    bool modifier (int);
private:
    QString nom,prenom,mail;
    int cinn,numero,nombreA,sommeP;
};

#endif // CLIENTS_H
