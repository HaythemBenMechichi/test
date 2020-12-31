#ifndef RECOLTES_H
#define RECOLTES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class recoltes
{
public:
    recoltes();
    recoltes(int,QString,int,int);
    QString get_culture();
    int get_prix();
    int get_id();
    int get_masse();
    bool ajouter();
    QSqlQueryModel * afficher();
     QSqlQueryModel * afficher_id();
    bool supprimer (int);
    recoltes recherche(int);
    bool modifier(int,QString,int,int);
    QSqlQueryModel * trier_prix();
    QSqlQueryModel * trier_masse();
    QSqlQueryModel * rechercher(int);

private:
    QString culture;
    int id,prix,masse;
};

#endif // RECOLTES_H
