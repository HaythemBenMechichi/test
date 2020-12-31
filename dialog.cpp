#include "dialog.h"
#include "delegate.h"
#include "delegatedate.h"
#include "ouvrier.h"
#include "smtp.h"
#include "congee.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QRegExpValidator>
#define email_rx "^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$"
#define nom_rx "^([A-Za-z])+$"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ouvrier o;
    congee c;

     ui->comboBox->setModel(o.afficher_cin());
    ui->comboBox_2->setModel(o.afficher_cin());
    ui->comboBox_3->setModel(c.afficher_cin());
    connect(ui->pushButton_9, SIGNAL(clicked()),this, SLOT(sendMail()));
    ui->tableView->setModel(o.afficher(this));
 ui->tableView_2->setModel(c.afficher(this));
 ui->label_7->setNum(ui->comboBox_2->currentText().toInt());
 ui->label_9->setNum(ui->comboBox_3->currentText().toInt());
 ui->label_2->setNum(ui->comboBox->currentText().toInt());
 ui->lineEdit_2->setValidator( new QIntValidator(0, 99999999, this) );
 ui->lineEdit_7->setValidator( new QIntValidator(0, 99999999, this) );
 ui->lineEdit_2->setMaxLength(8);
 ui->lineEdit_7->setMaxLength(8);
 QRegExp email(email_rx),nom(nom_rx);
 QRegExpValidator *valid_e=new QRegExpValidator(email,this);
  QRegExpValidator *valid_n=new QRegExpValidator(nom,this);
 ui->lineEdit_5->setValidator(valid_e);
 ui->lineEdit_3->setValidator(valid_n);
 ui->lineEdit_4->setValidator(valid_n);
}
void Dialog::delay()
{
    QTime dieTime= QTime::currentTime().addSecs(10);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void Dialog::sendMail()
{
    Smtp* smtp = new Smtp(ui->lineEdit_9->text(), ui->lineEdit_10->text(), ui->lineEdit->text(), ui->lineEdit_8->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->lineEdit_9->text(), ui->lineEdit_13->text() , ui->lineEdit_11->text(),ui->lineEdit_12->text());
}
Dialog::~Dialog()
{
    delete ui;
}

bool Dialog::verif_form(){

     return (ui->lineEdit_2->text()!="" && ui->lineEdit_3->text()!="" && ui->lineEdit_4->text()!="" && ui->lineEdit_5->text()!="" && ui->lineEdit_6->text()!="" && ui->lineEdit_7->text()!="");
}
bool Dialog::verif_formdate(){

     return (ui->dateEdit->date()<ui->dateEdit_2->date());
}


void Dialog::on_pushButton_clicked()
{
    QRegularExpression email(email_rx);
    QRegularExpressionMatch match=email.match(ui->lineEdit_5->text());
    if(!match.hasMatch()){
        QMessageBox::critical(nullptr, QObject::tr("ajout insuccessful"),
                    QObject::tr("invalid email.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{

    if(verif_form()){
    int a= ui->lineEdit_2->text().toInt();
    QString b= ui->lineEdit_3->text();
    QString c= ui->lineEdit_4->text();
    QString d= ui->lineEdit_5->text();
    int e= ui->lineEdit_7->text().toInt();
    int f= ui->lineEdit_6->text().toInt();
    ouvrier o(a,b,c,d,e,f);
    if(o.ajouter()){

        QMessageBox::information(nullptr, QObject::tr("ajout successful"),
                    QObject::tr("ajout successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
         ui->tableView->setModel(o.afficher(this));
        refresh();




    }

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ajout unsuccessful"),
                    QObject::tr("champ vide.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }
    }


    //refresh();
}

void Dialog::on_pushButton_2_clicked()
{
    ouvrier o;
    ui->tableView->setModel(o.afficher(this));
     refresh();

}


void Dialog::on_comboBox_activated(const QString &arg1)
{
    ui->label_2->setText(arg1);
    /*int a=arg1.toInt();
    QSqlQuery q;
    q.prepare("select * from mycrud where cin = ?;");
     q.addBindValue(a);
     if(q.exec()){
         while(q.next()){
             ui->lineEdit_2->setText(q.value(0).toString());
             ui->lineEdit_3->setText(q.value(1).toString());
             ui->lineEdit_4->setText(q.value(2).toString());
             ui->lineEdit_5->setText(q.value(3).toString());
             ui->lineEdit_7->setText(q.value(4).toString());
             ui->lineEdit_6->setText(q.value(5).toString());
         }
     }*/
}


void Dialog::on_pushButton_4_clicked()
{
    int a=ui->label_2->text().toInt();
    ouvrier o;
    if(o.supprimer(a)){
        ui->tableView->setModel(o.afficher(this));

    }
    refresh();
}

void Dialog::on_pushButton_3_clicked()
{

   /* QRegularExpression email(email_rx);
    QRegularExpressionMatch match=email.match(ui->lineEdit_5->text());
    if(!match.hasMatch()){
        QMessageBox::critical(nullptr, QObject::tr("ajout insuccessful"),
                    QObject::tr("invalid email.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else {
    int a=ui->label_8->text().toInt();
     QString b= ui->lineEdit_3->text();
     QString c= ui->lineEdit_4->text();
     QString d= ui->lineEdit_5->text();
     int e= ui->lineEdit_7->text().toInt();
     int f= ui->lineEdit_6->text().toInt();
     ouvrier o(a,b,c,d,e,f);
     if(o.modifier(a)){
         ui->tableView->setModel(o.afficher(this));
         refresh();

     }
    }*/
    int col1=ui->label_13->text().toInt();
    QString a=ui->label_11->text();
    QString f=ui->label_12->text();
    /*int row =ui->label_14->text().toInt();
    QModelIndex b1=ui->tableView->model()->index(row,2,QModelIndex());
    QVariant prenom=b1.data(Qt::DisplayRole);
    QModelIndex b2=ui->tableView->model()->index(row,3,QModelIndex());
    QVariant email=b2.data(Qt::DisplayRole);
    QModelIndex b3=ui->tableView->model()->index(row,4,QModelIndex());
    QVariant num=b3.data(Qt::DisplayRole);
    QModelIndex b4=ui->tableView->model()->index(row,5,QModelIndex());
    QVariant salaire=b4.data(Qt::DisplayRole);
    ouvrier o(f.toInt(),a,prenom.toString(),email.toString(),num.toInt(),salaire.toInt());
    if(o.modifier(f.toInt())){
        QMessageBox::information(this, tr("ligne modifie"), tr(" modifie .\n"));

    }*/



    if(col1==1){
        QSqlQuery q;
        q.prepare("update mycrud set nom = ? where cin = ?;");
         q.addBindValue(a);
         q.addBindValue(f);
         if(q.exec()){
             QMessageBox::information(this, tr("ligne modifie"), tr("nom modifie .\n"));
         }

    }
   if(col1==2){
        QSqlQuery q;
        q.prepare("update mycrud set prenom = ? where cin = ?;");
         q.addBindValue(a);
         q.addBindValue(f);
         if(q.exec()){
             QMessageBox::information(this, tr("ligne modifie"), tr("prenom modifie .\n"));
         }

    }
    if(col1==3){
        QSqlQuery q;
        q.prepare("update mycrud set email = ? where cin = ?;");
         q.addBindValue(a);
         q.addBindValue(f);
         if(q.exec()){
             QMessageBox::information(this, tr("ligne modifie"), tr("email modifie .\n"));
         }

    }
    if(col1==4){
        QSqlQuery q;
        q.prepare("update mycrud set numtel = ? where cin = ?;");
         q.addBindValue(a);
         q.addBindValue(f);
         if(q.exec()){
             QMessageBox::information(this, tr("ligne modifie"), tr("numero de telephone modifie .\n"));
         }

    }
    if(col1==5){
        QSqlQuery q;
        q.prepare("update mycrud set salaire = ? where cin = ?;");
         q.addBindValue(a);
         q.addBindValue(f);
         if(q.exec()){
             QMessageBox::information(this, tr("ligne modifie"), tr("salaire modifie .\n"));
         }

    }
        refresh();

}

void Dialog::on_pushButton_5_clicked()
{
    int a= ui->label_7->text().toInt();
    QDate b= ui->dateEdit->date();
    QDate c= ui->dateEdit_2->date();


    congee con(a,b,c);
   if(verif_formdate()){
       if(con.ajouter()){

           QMessageBox::critical(nullptr, QObject::tr("ajout successful"),
                       QObject::tr("ajout successful.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
           refresh();

       }
   }


    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ajout unsuccessful"),
                    QObject::tr("verifier vos parametres .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }

}


void Dialog::on_comboBox_2_activated(const QString &arg1)
{
    ui->label_7->setText(arg1);
}

void Dialog::on_pushButton_6_clicked()
{
    congee c;
    ui->tableView_2->setModel(c.afficher(this));
     refresh();
}

/*void Dialog::on_comboBox_currentIndexChanged(int index)
{
    int a=index;
    QSqlQuery q;
    q.prepare("select * from mycrud where cin = ?;");
     q.addBindValue(a);
     if(q.exec()){
         while(q.next()){
             ui->lineEdit_2->setText(q.value(0).toString());
             ui->lineEdit_3->setText(q.value(1).toString());
             ui->lineEdit_4->setText(q.value(2).toString());
             ui->lineEdit_5->setText(q.value(3).toString());
             ui->lineEdit_7->setText(q.value(4).toString());
             ui->lineEdit_6->setText(q.value(5).toString());
         }
     }


}*/

void Dialog::on_tableView_activated(const QModelIndex &index)
{
    /*int a=ui->tableView->model()->data(index).toInt();
ui->label_8->setNum(a);
    QSqlQuery q;
    q.prepare("select * from mycrud where cin = ?;");
     q.addBindValue(a);
     if(q.exec()){
         while(q.next()){
             ui->lineEdit_2->setText(q.value(0).toString());
             ui->lineEdit_3->setText(q.value(1).toString());
             ui->lineEdit_4->setText(q.value(2).toString());
             ui->lineEdit_5->setText(q.value(3).toString());
             ui->lineEdit_7->setText(q.value(4).toString());
             ui->lineEdit_6->setText(q.value(5).toString());
         }
     }*/
    Delegate *d= new Delegate();
    QWidget * e=d->create(ui->tableView);
    d->set(e,index);
    QString a=d->setmodel(e,ui->tableView->model(),index);
    ui->label_11->setText(a);
int col=index.row();
int col1=index.column();
 QModelIndex b=ui->tableView->model()->index(col,0,QModelIndex());
 QVariant f=b.data(Qt::DisplayRole);
 ui->label_12->setText(f.toString());
 ui->label_13->setNum(col1);
 ui->label_14->setNum(col);


}

void Dialog::on_comboBox_3_activated(const QString &arg1)
{
    ui->label_9->setText(arg1);

}

void Dialog::on_pushButton_8_clicked()
{
    int a=ui->label_9->text().toInt();
    congee o;
    if(o.supprimer(a)){
        ui->tableView_2->setModel(o.afficher(this));
 refresh();
    }


}
void Dialog::refresh(){
    ouvrier o;
    congee c;
     ui->comboBox->setModel(o.afficher_cin());
    ui->comboBox_2->setModel(o.afficher_cin());
    ui->comboBox_3->setModel(c.afficher_cin());
    ui->tableView->setModel(o.afficher(this));
 ui->tableView_2->setModel(c.afficher(this));
 ui->label_7->setNum(ui->comboBox_2->currentText().toInt());
 ui->label_9->setNum(ui->comboBox_3->currentText().toInt());
 ui->label_2->setNum(ui->comboBox->currentText().toInt());

  }

void Dialog::on_tableView_2_activated(const QModelIndex &index)
{
    if(index.column()==1 or index.column()==2){
        delegatedate *d= new delegatedate();
     QWidget * e=d->createdate(ui->tableView_2);
     d->setdate(e,index);
     QDate a=d->setmodeldate(e,ui->tableView_2->model(),index);
     ui->label_10->setText(a.toString());
 int col=index.row();
 int col1=index.column();
  QModelIndex b=ui->tableView_2->model()->index(col,3,QModelIndex());
  QVariant f=b.data(Qt::DisplayRole);
  ui->label_15->setText(f.toString());
  if(col1==1){
     QVariant h=ui->tableView_2->model()->index(col,2,QModelIndex()).data(Qt::DisplayRole);
      if(a < h.toDate()){

      QSqlQuery q;
      q.prepare("update conges set date_d = ? where id = ?;");
       q.addBindValue(a);
       q.addBindValue(f);
       if(q.exec()){
           QMessageBox::information(this, tr("ligne modifie"), tr("date debut modifie .\n"));
       }
      }
      else{
          QMessageBox::critical(this, tr("error"), tr("la date debut doit etre moin que la date fin  .\n"));
      }

  }
  if(col1==2){
       QVariant h=ui->tableView_2->model()->index(col,1,QModelIndex()).data(Qt::DisplayRole);
       if(a > h.toDate()){
      QSqlQuery q;
      q.prepare("update conges set date_e = ? where id = ?;");
       q.addBindValue(a);
       q.addBindValue(f);
       if(q.exec()){
           QMessageBox::information(this, tr("ligne modifie"), tr("date fin modifie .\n"));
       }
       }
       else{
           QMessageBox::critical(this, tr("error"), tr("la date debut doit etre moin que la date fin  .\n"));
       }

  }
     refresh();
    }
    else if(index.column()==0){
        Delegate *d= new Delegate();
        QWidget * e=d->create(ui->tableView_2);
        d->set(e,index);
        int a=d->setmodel(e,ui->tableView_2->model(),index).toInt();
        ui->label_10->setNum(a);
    int col=index.row();

     QModelIndex b=ui->tableView_2->model()->index(col,3,QModelIndex());
     QVariant f=b.data(Qt::DisplayRole);
     ui->label_15->setText(f.toString());
     if(trouve(a)){
         QSqlQuery q;
         q.prepare("update conges set cin = ? where id = ?;");
          q.addBindValue(a);
          q.addBindValue(f);
          if(q.exec()){
              QMessageBox::information(this, tr("ligne modifie"), tr("cin modifie .\n"));
          }



     }
     else
     {
         QMessageBox::critical(this, tr("error"), tr("ce cin n'existe pas .\n"));

     }



    }

}
bool Dialog::trouve(int a){
    QSqlQuery q;
    q.prepare("select cin from mycrud;");

     if(q.exec()){
         while(q.next()){
             for(int col=0; col<4 ; col++){
                 if(q.value(col).toInt()==a)

                    return true;
             }




         }
     }
     return false;



}




void Dialog::on_pushButton_7_clicked()
{
    int a=ui->label_10->text().toInt();
    int d=ui->label_7->text().toInt();
    QDate b= ui->dateEdit->date();
    QDate c= ui->dateEdit_2->date();

    congee o(d,b,c);
    if(o.modifier(a)){
        ui->tableView_2->setModel(o.afficher(this));
        refresh();

    }
}
void Dialog::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::information( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}




void Dialog::on_pushButton_9_clicked()
{

    QLabel* label=new QLabel();
    label->setWindowFlag(Qt::FramelessWindowHint);
    label->setMask((new QPixmap("C:/Users/hp/Documents/splash/spec splashscreen/farm.gif"))->mask());
    QMovie* movie=new QMovie("C:/Users/hp/Documents/splash/spec splashscreen/farm.gif");

    label->setMovie(movie);
    movie->start();
    label->show();
   delay();
    movie->stop() ;
    label->close();
   mailSent("Message sent");
}
