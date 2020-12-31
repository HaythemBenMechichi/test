#include "menu.h"
#include "plantes.h"
#include "client.h"
#include "ui_menu.h"
#include "dialog.h"
#include "prod.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked()
{
    Dialog d;
    d.exec();
}

void menu::on_pushButton_3_clicked()
{
    prod p;
    p.exec();
}

void menu::on_pushButton_5_clicked()
{
    plantes p;
   p.exec();

}

void menu::on_pushButton_2_clicked()
{
    client x;

    x.exec();
}
