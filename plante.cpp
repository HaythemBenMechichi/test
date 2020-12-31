#include "plante.h"

plante::plante()
{
    id=0;
    culture="";
    typeA="";
    surface=0;

}

plante::plante(int id,QString culture,QString typeA,int surface)
{
    this->id=id;
    this->culture=culture;
    this->typeA=typeA;
    this->surface=surface;
}
int plante::get_id(){return id;}
QString plante::get_culture(){return culture;}
QString plante::get_typeA(){return typeA;}

int plante::get_surface(){return surface;}

bool plante::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO plantes VALUES (?,?,?,?)" );
      query.addBindValue( id);
query.addBindValue(culture);
    query.addBindValue( typeA);


    query.addBindValue(surface);
    return  query.exec();

}

QSqlQueryModel * plante::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from plantes");

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
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("culture "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("typeA"));
        return model;
}
QSqlQueryModel *  plante::rechercher(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString::number(id);
    model->setQuery("select * from plantes where (id LIKE '"+res+"%' ) ");


            return  model;


}
QSqlQueryModel *  plante::affiche_id()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString::number(id);
    model->setQuery("select id from plantes ");


            return  model;


}


