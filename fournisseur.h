#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fournisseur
{
public:
    fournisseur();
    fournisseur(QString,QString,int,QString,int);
    QSqlQuery rech(int);
    QSqlQuery rechT(QString);
    QString get_nom();
    QString get_prenom();
    int get_cinn();
    QString get_mail();
    int get_numero();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_cin();
    bool supprimer (int);
    bool modifier (int);


private:
    QString nom,prenom,mail;
    int cinn,numero;
};

#endif // FOURNISSEUR_H
