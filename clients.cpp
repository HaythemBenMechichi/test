#include "clients.h"

clients::clients()
{
    nom="";
    prenom="";
    cinn=0;
    mail="";
    numero=0;
    nombreA=0;
    sommeP=0;
}

clients::clients(QString nom,QString prenom,int cinn,QString mail,int numero,int nombreA,int sommeP)
{
    this->nom=nom;
    this->prenom=prenom;
    this->cinn=cinn;
    this->mail=mail;
    this->numero=numero;
    this->nombreA=nombreA;
    this->sommeP=sommeP;
}

QString clients::get_nom(){return nom;}
QString clients::get_prenom(){return prenom;}
int clients::get_cinn(){return cinn;}
QString clients::get_mail(){return mail;}
int clients::get_numero(){return numero;}
int clients::get_nombreA(){return nombreA;}
int clients::get_sommeP(){return sommeP;}

QSqlQuery  clients::rech(int id)
{
   QSqlQuery query;
   QString res= QString::number(id);
   query.prepare("select * from client where cin =:cin");
   query.bindValue(":cin", res);
   return  query;

}

QSqlQuery  clients::rechT(QString id)
{
   QSqlQuery query;
   QString res= QString(id);
   query.prepare("select * from client where nom =:nom or prenom =:prenom or cin =:cin or mail =:mail or numero =:numero or nombre_article =:nombre or somme_payer =:somme");
   query.bindValue(":nom", res);
   query.bindValue(":prenom", res);
   query.bindValue(":cin", res.toInt());
   query.bindValue(":mail", res);
   query.bindValue(":numero", res.toInt());
   query.bindValue(":nombre", res.toInt());
   query.bindValue(":somme", res.toInt());
   return  query;

}

bool clients::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(cinn);
    query.prepare("INSERT INTO client (nom, prenom, cin, mail, numero, nombre_article, somme_payer) "
                          " VALUES (:nom, :prenom, :cin, :mail, :numero, :nombre, :somme)" );

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":cin", res);
    query.bindValue(":mail", mail);
    query.bindValue(":numero", numero);
    query.bindValue(":nombre", nombreA);
    query.bindValue(":somme", sommeP);
    return  query.exec();

}

QSqlQueryModel * clients::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from client");

    return model;
}

QSqlQueryModel * clients::afficher_cin()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select cin from client");
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));



    return  model;

}

bool clients::supprimer(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from client where cin = :cin");
    query.bindValue(":cin", res);
    return  query.exec();
}

bool clients::modifier(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("update client set  nom = :nom, prenom = :prenom, cin = :cinn, mail = :mail, numero = :numero,nombre_article = :nombre, somme_payer = :somme  where cin = :cin");

    query.bindValue(":cin", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":cinn", cinn);
    query.bindValue(":mail", mail);
    query.bindValue(":numero", numero);
    query.bindValue(":nombre", nombreA);
    query.bindValue(":somme", sommeP);

    return  query.exec();

}
