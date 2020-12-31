#ifndef PLANTE_H
#define PLANTE_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class plante
{
public:
    plante();
    plante(int,QString,QString,int);
    QString get_culture();
    QString get_typeA();
    int get_id();
    int get_surface();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer (int);

    plante recherche(int);

    bool modifier(int,QString,QString,int);
    QSqlQueryModel * trier_surface();
    QSqlQueryModel * rechercher(int);
    QSqlQueryModel * affiche_id();


private:
    QString culture,typeA;
    int id,surface;
};

#endif // PLANTES_H

