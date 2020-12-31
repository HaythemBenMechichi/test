#include "plantes.h"
#include "recoltes.h"
#include "ui_plantes.h"
#include "plante.h"
#include <QMessageBox>

plantes::plantes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::plantes)
{
    ui->setupUi(this);
    plante p;
    recoltes x;
    ui->comboBox_3->setModel(p.affiche_id());
    ui->label_3->setText(ui->comboBox_3->currentText());
    ui->tableView_2->setModel(p.afficher());
    ui->tableView_3->setModel(x.afficher());
     ui->label->setText(ui->comboBox_4->currentText());
      ui->comboBox_4->setModel(x.afficher_id());
      ui->comboBox->addItem("trie par prix");
      ui->comboBox->addItem("trie par masse");

}

plantes::~plantes()
{
    delete ui;

}
void plantes::refresh(){

    plante p;
    ui->comboBox_3->setModel(p.affiche_id());
    ui->label_3->setText(ui->comboBox_3->currentText());
    ui->tableView_2->setModel(p.afficher());
    recoltes x;
    ui->comboBox_4->setModel(x.afficher_id());
    ui->label->setText(ui->comboBox_4->currentText());
    ui->tableView_3->setModel(x.afficher());


}

void plantes::on_pushButton_9_clicked()
{
    int id =ui->lineEdit_8->text().toInt();
        QString culture=ui->lineEdit_6->text();
        int masse=ui->lineEdit_7->text().toInt();


        int prix =ui->lineEdit_9->text().toInt();

        recoltes c(id,culture,masse,prix);
        bool test=c.ajouter();
        if(test)
        {ui->tableView_2->setModel(c.afficher());
        QMessageBox::information(nullptr,QObject::tr("Ajouter un plantes"),QObject::tr("plantes ajouter.\n"
                                                                                        "Click Cancel to exit."), QMessageBox::Cancel);}
        ui->lineEdit_8->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear();


        ui->lineEdit_9->clear();
        refresh();

}

void plantes::on_pushButton_10_clicked()
{
    recoltes c;
    ui->tableView_3->setModel(c.afficher());
}

/*void plantes::on_comboBox_4_activated(const QString &arg1)
{

}*/

void plantes::on_comboBox_3_activated(const QString &arg1)
{
ui->label_3->setText(arg1);

}

void plantes::on_pushButton_8_clicked()
{
    int idp = ui->label_3->text().toInt();
    plante c;
    bool test=c.supprimer(idp);
    if(test)
    {ui->tableView_2->setModel(c.afficher());
        QMessageBox::information(nullptr,QObject::tr("Supprime une plante"),QObject::tr("plante supprimer.\n"
                                                                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    refresh();
}

void plantes::on_pushButton_5_clicked()
{
    int id =ui->lineEdit_4->text().toInt();
        QString culture=ui->lineEdit_2->text();
        QString typeA=ui->lineEdit_3->text();


        int surface =ui->lineEdit_5->text().toInt();

        plante c(id,culture,typeA,surface);
        bool test=c.ajouter();
        if(test)
        {ui->tableView_2->setModel(c.afficher());
        QMessageBox::information(nullptr,QObject::tr("Ajouter un plantes"),QObject::tr("plantes ajouter.\n"
                                                                                        "Click Cancel to exit."), QMessageBox::Cancel);}
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();


        ui->lineEdit_5->clear();
        refresh();


}

void plantes::on_comboBox_4_activated(const QString &arg1)
{
    ui->label->setText(arg1);
}

void plantes::on_pushButton_12_clicked()
{
    int idp = ui->label->text().toInt();
    recoltes c;
    bool test=c.supprimer(idp);
    if(test)
    {ui->tableView_3->setModel(c.afficher());
        QMessageBox::information(nullptr,QObject::tr("Supprime une plante"),QObject::tr("plante supprimer.\n"
                                                                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    refresh();

}

void plantes::on_tableView_2_activated(const QModelIndex &index)
{
    int a=ui->tableView_2->model()->data(index).toInt();
ui->label_4->setNum(a);
    QSqlQuery q;
    q.prepare("select * from plantes where id = ?;");
     q.addBindValue(a);
     if(q.exec()){
         while(q.next()){
              ui->lineEdit_4->setText(q.value(0).toString());
             ui->lineEdit_2->setText(q.value(1).toString());
             ui->lineEdit_3->setText(q.value(2).toString());

             ui->lineEdit_5->setText(q.value(3).toString());




         }
     }

}

void plantes::on_pushButton_7_clicked()
{
    int id = ui->label_4->text().toInt();
     QString culture= ui->lineEdit_2->text();
          QString typeA= ui->lineEdit_3->text();

          int surface= ui->lineEdit_5->text().toInt();
         plante f;
         bool test=f.modifier(id,culture,typeA,surface);
       if(test)
         {
            ui->tableView_2->setModel((f.afficher()));//refresh
            QMessageBox::information(nullptr, QObject::tr("Modifier une plante !"),
                              QObject::tr(" plante modifié ! \n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
         }

         else {

             QMessageBox::critical(nullptr, QObject::tr("Modifier une plante"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         }
}

void plantes::on_tableView_3_activated(const QModelIndex &index)
{
    int a=ui->tableView_3->model()->data(index).toInt();
ui->label_2->setNum(a);
    QSqlQuery q;
    q.prepare("select * from recoltes where id = ?;");
     q.addBindValue(a);
     if(q.exec()){
         while(q.next()){
             ui->lineEdit_8->setText(q.value(0).toString());
             ui->lineEdit_6->setText(q.value(1).toString());
             ui->lineEdit_7->setText(q.value(2).toString());

             ui->lineEdit_9->setText(q.value(3).toString());




         }
     }

}

void plantes::on_pushButton_11_clicked()
{
    int id = ui->label_2->text().toInt();
     QString culture= ui->lineEdit_6->text();
        int prix= ui->lineEdit_9->text().toInt();

          int masse= ui->lineEdit_7->text().toInt();
         recoltes f;
         bool test=f.modifier(id,culture,prix,masse);
       if(test)
         {
            ui->tableView_3->setModel((f.afficher()));//refresh
            QMessageBox::information(nullptr, QObject::tr("Modifier une recolte !"),
                              QObject::tr(" recolte modifié ! \n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
         }

         else {

             QMessageBox::critical(nullptr, QObject::tr("Modifier une recolte"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         }


}

void plantes::on_pushButton_13_clicked()
{
    recoltes f;
    int id = ui->lineEdit_10->text().toInt();
   ui->tableView_3->setModel(f.rechercher(id));
}

void plantes::on_pushButton_14_clicked()
{
    plante f;
    int id = ui->lineEdit_11->text().toInt();
   ui->tableView_2->setModel(f.rechercher(id));

}

void plantes::on_pushButton_6_clicked()
{
    plante p;


    ui->tableView_2->setModel(p.afficher());

}
void plantes::print(QPrinter *printer)  {

    // ------------------ simplest example --------------------------

    QPainter painter;
    if(!painter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    // print table
    TablePrinter tablePrinter(&painter, printer);
    QVector<int> columnStretch = QVector<int>() << 2 << 5  << 15;
    if(!tablePrinter.printTable(ui->tableView_2->model(), columnStretch)) {
        qDebug() << tablePrinter.lastError();
    }
    painter.end();
}


void plantes::print_two_tables(QPrinter *printer) {

    // ------------------ two tables example --------------------------

    QPainter painter;
    if(!painter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    // print table
    TablePrinter tablePrinter(&painter, printer);
    QVector<int> columnStretch = QVector<int>() << 2 << 2 << 5 << 15;
    if(!tablePrinter.printTable(ui->tableView_2->model(), columnStretch)) {
        qDebug() << tablePrinter.lastError();
    }
    // print second table
    painter.translate(0, 100);
    if(!tablePrinter.printTable(ui->tableView_2->model(), columnStretch)) {
        qDebug() << tablePrinter.lastError();
    }
    painter.end();
}

class PrintBorder : public PagePrepare
{
public:
    virtual void preparePage(QPainter *painter);
    static int pageNumber;
};

int PrintBorder::pageNumber = 0;

void PrintBorder::preparePage(QPainter *painter)
{ // print a border on each page
    QRect rec = painter->viewport();
    painter->setPen(QPen(QColor(0, 0, 0), 1));
    painter->drawRect(rec);
    painter->translate(10, painter->viewport().height() - 10);
    painter->drawText(0, 0, QString("Page %1").arg(pageNumber));
    pageNumber += 1;
}
void plantes::uglyPrint(QPrinter *printer) {

    // ---------------- death-to-designers example ------------------

    QPainter uglyPainter;
    if(!uglyPainter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    TablePrinter uglyTablePrinter(&uglyPainter, printer);
    QVector<int> colStretch = QVector<int>() << 5 << 5 << 5 << 10;
    uglyTablePrinter.setPen(QPen(QColor(0, 100, 255), 3, Qt::DotLine)); // pen for borders
    uglyTablePrinter.setHeaderColor(Qt::red);
    uglyTablePrinter.setContentColor(Qt::green);
    QFont font1; // font for headers
    font1.setBold(true);
    QFont font2; // font for content
    font2.setItalic(true);
    uglyTablePrinter.setHeadersFont(font1);
    uglyTablePrinter.setContentFont(font2);
    PrintBorder *printB = new PrintBorder;
    printB->pageNumber = 1;
    uglyTablePrinter.setPagePrepare(printB);
    QVector<QString> headers = QVector<QString>() << "ID" << "CULTURE" << "SURFACE"<< "TYPEA" ;
    uglyPainter.setPen(QPen(Qt::yellow));
    uglyPainter.drawText(uglyPainter.viewport().width()/2 - 40, 40, "TABLE plantes");
    uglyPainter.translate(0, 60); // start print point
    uglyTablePrinter.setCellMargin(10, 5, 5);
    uglyTablePrinter.setPageMargin(100, 40, 40);
    if(!uglyTablePrinter.printTable(ui->tableView_2->model(), colStretch, headers)) {
        qDebug() << uglyTablePrinter.lastError();
    }
    uglyPainter.end();
    delete printB;
}

void plantes::on_comboBox_activated(const QString &arg1)
{
    recoltes r;

    if(arg1=="trie par masse"){
        ui->tableView_3->setModel(r.trier_masse());
    }
    if(arg1=="trie par prix"){
        ui->tableView_3->setModel(r.trier_prix());
    }

}
void plantes::print1(QPrinter *printer)  {

    // ------------------ simplest example --------------------------

    QPainter painter;
    if(!painter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    // print table
    TablePrinter tablePrinter(&painter, printer);
    QVector<int> columnStretch = QVector<int>() << 2 << 5  << 15;
    if(!tablePrinter.printTable(ui->tableView_3->model(), columnStretch)) {
        qDebug() << tablePrinter.lastError();
    }
    painter.end();
}


void plantes::print_two_tables1(QPrinter *printer) {

    // ------------------ two tables example --------------------------

    QPainter painter;
    if(!painter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    // print table
    TablePrinter tablePrinter(&painter, printer);
    QVector<int> columnStretch = QVector<int>() << 2 << 2 << 5 << 15;
    if(!tablePrinter.printTable(ui->tableView_3->model(), columnStretch)) {
        qDebug() << tablePrinter.lastError();
    }
    // print second table
    painter.translate(0, 100);
    if(!tablePrinter.printTable(ui->tableView_3->model(), columnStretch)) {
        qDebug() << tablePrinter.lastError();
    }
    painter.end();
}

void plantes::uglyPrint1(QPrinter *printer) {

    // ---------------- death-to-designers example ------------------

    QPainter uglyPainter;
    if(!uglyPainter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    TablePrinter uglyTablePrinter(&uglyPainter, printer);
    QVector<int> colStretch = QVector<int>() << 5 << 5 << 5 << 10;
    uglyTablePrinter.setPen(QPen(QColor(0, 100, 255), 3, Qt::DotLine)); // pen for borders
    uglyTablePrinter.setHeaderColor(Qt::red);
    uglyTablePrinter.setContentColor(Qt::green);
    QFont font1; // font for headers
    font1.setBold(true);
    QFont font2; // font for content
    font2.setItalic(true);
    uglyTablePrinter.setHeadersFont(font1);
    uglyTablePrinter.setContentFont(font2);
    PrintBorder *printB = new PrintBorder;
    printB->pageNumber = 1;
    uglyTablePrinter.setPagePrepare(printB);
    QVector<QString> headers = QVector<QString>() << "ID" << "CULTURE" << "PRIX"<< "MASSE" ;
    uglyPainter.setPen(QPen(Qt::yellow));
    uglyPainter.drawText(uglyPainter.viewport().width()/2 - 40, 40, "TABLE recoltes");
    uglyPainter.translate(0, 60); // start print point
    uglyTablePrinter.setCellMargin(10, 5, 5);
    uglyTablePrinter.setPageMargin(100, 40, 40);
    if(!uglyTablePrinter.printTable(ui->tableView_3->model(), colStretch, headers)) {
        qDebug() << uglyTablePrinter.lastError();
    }
    uglyPainter.end();
    delete printB;
}




void plantes::on_pushButton_17_clicked()
{
    QPrintPreviewDialog dialog;
    connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(uglyPrint(QPrinter*)));
    dialog.exec();
}

void plantes::on_pushButton_16_clicked()
{
    QPrintPreviewDialog dialog;
    connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(uglyPrint1(QPrinter*)));
    dialog.exec();
}

void plantes::on_pushButton_15_clicked()
{
    plante p;

    bool test=true;
            if(test){

                   { ui->tableView_2->setModel(p.trier_surface());
                    QMessageBox::information(nullptr, QObject::tr("trier plantes"),
                                QObject::tr("plantes trier.\n"
                                            "Voulez-vous enregistrer les modifications ?"),
                                       QMessageBox::Save
                                       | QMessageBox::Cancel,
                                      QMessageBox::Save);
    }

                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("trier plantes"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
}
