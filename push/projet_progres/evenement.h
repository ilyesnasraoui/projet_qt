#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>


class evenement
{
public:
    evenement();
    evenement(int,QString,QString,QString);
    int get_IdE();
    QString get_Desc();
    QString get_TypeEvent();
    QString get_Date_event();
    bool ajouterE();
    QSqlQueryModel * afficherE();
    bool supprimerE(int);
    bool modifierE(evenement e);
    QSqlQueryModel*rechercherE(QString event);
    QSqlQueryModel *triE(int);
    QSqlQueryModel *countE();
    int devis(int,int);
    int nbpersonne;

private:
    int idE;
    QString desc;
    QString date_event;
    QString typeEvent;

};

#endif // EVENEMENT_H
