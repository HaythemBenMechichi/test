#include "fournisseur.h"

fournisseur::fournisseur()
{
    nom="";
    prenom="";
    cinn=0;
    mail="";
    numero=0;

}

fournisseur::fournisseur(QString nom,QString prenom,int cinn,QString mail,int numero)
{
    this->nom=nom;
    this->prenom=prenom;
    this->cinn=cinn;
    this->mail=mail;
    this->numero=numero;
}

QString fournisseur::get_nom(){return nom;}
QString fournisseur::get_prenom(){return prenom;}
int fournisseur::get_cinn(){return cinn;}
QString fournisseur::get_mail(){return mail;}
int fournisseur::get_numero(){return numero;}

 QSqlQuery  fournisseur::rech(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("select * from fournisseur where cin =:cin");
    query.bindValue(":cin", res);
    return  query;
}

 QSqlQuery  fournisseur::rechT(QString id)
{
    QSqlQuery query;
    QString res= QString(id);
    query.prepare("select * from fournisseur where nom =:nom or prenom =:prenom or cin =:cin or mail =:mail or numero =:numero");
    query.bindValue(":nom", res);
    query.bindValue(":prenom", res);
    query.bindValue(":cin", res.toInt());
    query.bindValue(":mail", res);
    query.bindValue(":numero", res.toInt());
    return query;
}

bool fournisseur::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(cinn);
    query.prepare("INSERT INTO fournisseur (nom, prenom, cin, mail, numero) "
                          " VALUES (:nom, :prenom, :cin, :mail, :numero)" );

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":cin", res);
    query.bindValue(":mail", mail);
    query.bindValue(":numero", numero);
    return  query.exec();

}

QSqlQueryModel * fournisseur::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from fournisseur");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMERO"));
    return model;
}

QSqlQueryModel * fournisseur::afficher_cin(){
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select cin from fournisseur");
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));



    return  model;

}


bool fournisseur::supprimer(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from fournisseur where cin =:cin ");

    query.bindValue(":cin", res.toInt());

    return  query.exec();
}

bool fournisseur::modifier(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("update fournisseur set  nom = :nom, prenom = :prenom, cin = :cinn, mail = :mail, numero = :numero where cin = :cin");

    query.bindValue(":cin", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":cinn", cinn);
    query.bindValue(":mail", mail);
    query.bindValue(":numero", numero);

    return  query.exec();


}
