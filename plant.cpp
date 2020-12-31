#include "plant.h"

plante::plante()
{
    culture="";
    typeA="";
    id=0;
    surface=0;

}

plante::plante(int id,QString culture,QString typeA,int surface)
{
    this->culture=culture;
    this->typeA=typeA;
    this->id=id;
    this->surface=surface;
}
int plante::get_id(){return id;}
QString plante::get_culture(){return culture;}
QString plante::get_typeA(){return typeA;}

int plante::get_surface(){return surface;}

bool plante::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO plantes (culture, typeA, id,  surface) "
                          " VALUES (:culture, :typeA, :id,  :surface)" );
query.bindValue(":id", res);
    query.bindValue(":culture", culture);
    query.bindValue(":typeA", typeA);

    query.bindValue(":surface", surface);
    return  query.exec();

}

QSqlQueryModel * plante::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from plantes");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("culture"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("typeA"));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("surface"));
    return model;
}

bool plante::supprimer(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from plantes where id = :id");
    query.bindValue(":id", res);
    return  query.exec();
}

plante plante::recherche(int x)
{
    QSqlQuery query;
    QString res= QString::number(x);
    query.prepare("select * from plantes where id = : res ");
    query.bindValue(":id",res);
    QString culture=query.value(0).toString();
    QString typeA=query.value(1).toString();
    int id=query.value(2).toInt();

    int surface=query.value(4).toInt();
    plante f(id,culture,typeA,surface);
    return  f;

}

bool plante::modifier(int id,QString culture,QString typeA,int surface)
{
    QSqlQuery query;
    query.prepare("update plantes set  culture = ? , typeA = ? , surface = ? where id= ?");

    query.addBindValue(culture);
    query.addBindValue(typeA);
     query.addBindValue(surface);


   query.addBindValue(id);


   return query.exec();

}

QSqlQueryModel * plante::trier_surface()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from plantes ORDER BY surface");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("culture "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("typeA"));
        return model;
}
QSqlQueryModel *  plante::rechercher(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString::number(id);
    model->setQuery("select * from plantes where (id LIKE '"+res+"%' ) ");


            return  model;


}


