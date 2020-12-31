#include "produitph.h"

physique::physique()
{
    nom="";
    marque="";
    id_phy=0;
    prix="";


}

physique::physique(int id_phy,QString nom,QString marque,QString prix,QString dispo)
{
    this->id_phy=id_phy;
    this->nom=nom;
    this->marque=marque;
    this->prix=prix;
    this->dispo=dispo;

}

QString physique::get_nom(){return nom;}
QString physique::get_marque(){return marque;}
int physique::get_id_phy(){return id_phy;}
QString physique::get_prix(){return prix;}
QString physique::get_dispo(){return dispo;}



bool physique::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id_phy);
    query.prepare("INSERT INTO physique (id_phy, nom, marque, prix, dispo) "
                          " VALUES (:id_phy, :nom, :marque, :prix, :dispo)" );

    query.bindValue(":id_phy", res);
    query.bindValue(":nom", nom);
    query.bindValue(":marque", marque);
    query.bindValue(":prix", prix);
    query.bindValue(":dispo", dispo);

    return  query.exec();

}

QSqlQueryModel * physique::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from physique");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PHY"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MARQUE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DISPO"));

    return model;
}
QSqlQueryModel * physique::afficher_id()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select id_phy from physique");


    return model;
}


bool physique::supprimer(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from physique where id_phy = :id_phy");
    query.bindValue(":id_phy", res);
    return  query.exec();
}

/*physique physique::recherche(int x)
{
    QSqlQuery query;
    QString res= QString::number(x);
    query.prepare("select * from fournisseur where cin = : res ");
    query.bindValue(":cin",res);
    QString nom=query.value(0).toString();
    QString prenom=query.value(1).toString();
    int cin=query.value(2).toInt();
    QString mail=query.value(3).toString();
    int numero=query.value(4).toInt();
    fournisseur f(nom,prenom,cin,mail,numero);
    return  f;


}*/
bool physique::modifier(int a){


    QSqlQuery query;
    query.prepare("update physique set nom = ? , marque = ? , prix = ? , dispo = ? where id_phy = ?");

    query.addBindValue(nom);
    query.addBindValue(marque);
     query.addBindValue(prix);
     query.addBindValue(dispo);


   query.addBindValue(a);


   return query.exec();

}


