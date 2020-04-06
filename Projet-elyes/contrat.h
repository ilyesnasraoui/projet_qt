
#ifndef CONTRAT_H
#define CONTRAT_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class contrat
{
public:
    contrat();
    contrat(int cinc,QDate datedebut,QDate datefin,int idc,int montant,int quotient,int idv,int num);
    bool ajouter();
    bool supprimer(int id);
    bool modifier();
    QSqlQueryModel * afficher();
    QSqlQueryModel * recherche (QString cls);
private:
    int cinc,idc,montant,quotient,idv,num;
    QDate datedebut,datefin;
};

#endif // CONTRAT_H
