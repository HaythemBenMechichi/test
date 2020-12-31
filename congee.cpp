#include "congee.h"



congee::congee()
{
cin=0;

}
congee::congee(int a,QDate d,QDate e)
{
cin=a;
date_d=d;
date_e=e;


}
int congee::getcin(){

    return cin;
}
QDate congee::getdate_d(){

return date_d;
}
QDate congee::getdate_e(){

    return date_e;
}
bool congee::ajouter(){

    QSqlQuery query;
    query.prepare("insert into conges values(?,?,?,id.nextval);");
    query.addBindValue(cin);
    query.addBindValue(date_d);
    query.addBindValue(date_e);


   return query.exec();
}
QStandardItemModel * congee::afficher(QObject* parent){

    QSqlQuery q;
    q.prepare("select * from conges;");
     int i=0;
     if(q.exec()){
         while(q.next()){
             for(int col=0; col<4 ; col++){
                 QString a=q.value(col).toString();

             }



             i++;
         }
     }

      QStandardItemModel* model =new QStandardItemModel(i,4,parent);
  // QSqlQueryModel *model1=new QSqlQueryModel();

    //QStandardItemModel* model =new QStandardItemModel(4,2,this);

    q.prepare("select * from conges");
     i=0;
     if(q.exec()){
         while(q.next()){
             for(int col=0; col<4 ; col++){
                 if(col==2 or col==1){
                     QDate a=q.value(col).toDate();
                     QModelIndex index=model->index(i,col,QModelIndex());
                     model->setData(index,a);
                 }
                 else
                 {
                 QString a=q.value(col).toString();
                 QModelIndex index=model->index(i,col,QModelIndex());
                 model->setData(index,a);
                 }
             }



             i++;
         }
     }


   return model;



}
bool congee::supprimer(int a){

    QSqlQuery query;
    query.prepare("delete from conges where id = ?");
    query.addBindValue(a);


   return query.exec();

}
bool congee::modifier(int a){


    QSqlQuery query;
    query.prepare("update conges set cin = ? , date_d = ? , date_e = ?  where id = ?");

    query.addBindValue(cin);
    query.addBindValue(date_d);
     query.addBindValue(date_e);


   query.addBindValue(a);


   return query.exec();

}

QSqlQueryModel * congee::afficher_cin(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select id from conges;" );

    return  model;

}




