#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class client
{
public:
    client();
    client(QString,QString,QString,QString,int,QString);

    QString get_cin();
    QString get_tel();
    int get_age();
    QString get_nom();
    QString get_prenom();
    bool ajouter();
    void supprimer(QString);
    bool modifier();
QSqlQueryModel * chercher(QString);
    QSqlQueryModel * afficher();
    QSqlQueryModel * tri(int);
private:
    QString nom,prenom,cin,tel,email;
    int age;
};

#endif // CLIENT_H
