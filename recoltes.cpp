#include "recoltes.h"

recoltes::recoltes()
{
    culture="";
    masse=0;
    id=0;
    prix=0;

}

recoltes::recoltes(int id,QString culture,int masse,int prix)
{
    this->culture=culture;
    this->masse=masse;
    this->id=id;
    this->prix=prix;
}

QString recoltes::get_culture(){return culture;}
int recoltes::get_masse(){return masse;}
int recoltes::get_id(){return id;}
int recoltes::get_prix(){return prix;}

bool recoltes::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO recoltes (culture, masse, id,  prix) "
                          " VALUES (:culture, :masse, :id,  :prix)" );

    query.bindValue(":culture", culture);
    query.bindValue(":masse", masse);
    query.bindValue(":id", res);
    query.bindValue(":prix", prix);
    return  query.exec();

}

QSqlQueryModel * recoltes::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from recoltes");

    return model;
}

bool recoltes::supprimer(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from recoltes where id = :id");
    query.bindValue(":id", res);
    return  query.exec();
}



recoltes recoltes::recherche(int x)
{
    QSqlQuery query;
    QString res= QString::number(x);
    query.prepare("select * from recoltes where id = : res ");
    query.bindValue(":id",res);
    QString culture=query.value(0).toString();
    int masse=query.value(1).toInt();
    int id=query.value(2).toInt();

    int prix=query.value(4).toInt();
    recoltes f(id,culture,masse,prix);
    return  f;

}
bool recoltes::modifier(int id,QString culture,int prix,int masse)
{


    QSqlQuery query;
    query.prepare("update recoltes set  culture = ? , prix = ? , masse = ? where id= ?");

    query.addBindValue(culture);
    query.addBindValue(prix);
     query.addBindValue(masse);


   query.addBindValue(id);


   return query.exec();

}


QSqlQueryModel * recoltes::trier_prix()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from recoltes ORDER BY prix");

        return model;
}

QSqlQueryModel * recoltes::trier_masse()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from recoltes ORDER BY masse");

        return model;
}
QSqlQueryModel *  recoltes::rechercher(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString::number(id);
    model->setQuery("select * from recoltes where (id LIKE '"+res+"%' ) ");


            return  model;


}
QSqlQueryModel *  recoltes::afficher_id()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select id from recoltes");


            return  model;


}


