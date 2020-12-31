#ifndef OUVRIER_H
#define OUVRIER_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCore>
#include <QtGui>

class ouvrier
{
    QString nom,prenom,email;
    int cin,salaire,numtel;
public:
    ouvrier();
    ouvrier(int,QString,QString,QString,int,int);
    QString getnom();
    QString getprenom();
    QString getemail();
    int getcin();
    int getsalaire();
    int getnumtel();
    bool ajouter();
    QStandardItemModel* afficher(QObject* parent);
     QSqlQueryModel * afficher_cin();
    bool supprimer(int);
    bool modifier(int);



};

#endif // OUVRIER_H

