#ifndef ADMIN_H
#define ADMIN_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class admin
{
public:
    admin();
    admin(int,QString);
    bool authentification();
private:
    int id;
    QString mot_de_passe;
};

#endif // ADMIN_H
