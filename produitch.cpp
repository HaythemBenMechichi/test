#include "produitch.h"

chimie::chimie()
{
    nom="";
    marque="";
    id_ch=0;
    prix="";
    quantit="";
}

chimie::chimie(QString nom,QString marque,int id_ch,QString prix,QString  quantit)
{
    this->nom=nom;
    this->marque=marque;
    this->id_ch=id_ch;
    this->quantit=quantit;
    this->prix=prix;
}

QString chimie::get_nom(){return nom;}
QString chimie::get_marque(){return marque;}
int chimie::get_id_ch(){return id_ch;}
QString chimie::get_quantit(){return quantit;}
QString  chimie::get_prix(){return prix;}


bool chimie::ajouter()
{
    QSqlQuery query;


    query.prepare("INSERT INTO chimie (nom, marque, id_ch, prix, quantit) "
                          " VALUES (:nom, :marque, :id_ch, :prix, :quantit)" );

    query.addBindValue( nom);
    query.addBindValue( marque);
    query.addBindValue( id_ch);
   query.addBindValue( prix);
    query.addBindValue( quantit);
    return  query.exec();

}

QSqlQueryModel * chimie::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from chimie");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_CH"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("QUANTIT"));
    return model;
}

bool chimie::supprimer(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from chimie where id_ch = :id_ch");
    query.bindValue(":id_ch", res);
    return  query.exec();
}
QSqlQueryModel * chimie::afficher_id()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select id_ch from chimie");


    return model;
}
bool chimie::modifier(int idd)
{
    QSqlQuery query;
    query.prepare("update chimie set nom = ? , marque = ? , prix = ? , quantit = ? where id_ch = ?");

    query.addBindValue(nom);
    query.addBindValue(marque);
     query.addBindValue(prix);
     query.addBindValue(quantit);


   query.addBindValue(idd);


   return query.exec();

}

QSqlQueryModel * chimie::rechercher(int idd){
    QSqlQueryModel * model=new QSqlQueryModel();

    QString res=QString::number(idd);


    model->setQuery("select * from chimie where where id_ch LIKE '"+res+"%'  ");


            return  model;

}
QSqlQueryModel * chimie::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from chimie ORDER BY prix");

        return model;
}



