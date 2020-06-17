#include "contrat.h"

contrat::contrat()
{

}

contrat::contrat(QString cinc,QDate datedebut,QDate datefin,int montant,int quotient,int idv)
{
 this->cinc=cinc;
 this->datedebut=datedebut;
 this->datefin=datefin;

    this->montant=montant;
    this->quotient=quotient;
    this->idv=idv;


}

bool contrat::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO contrat (CINC, DATEDEBUT, DATEFIN,MONTANT,QUOTIENT,IDV) "
                        "VALUES (:cinc, :datedebut, :datefin,:montant, :quotient, :idv)");
    query.bindValue(":cinc", cinc);
    query.bindValue(":datedebut", datedebut);
    query.bindValue(":datefin", datefin);
    query.bindValue(":montant", montant);
    query.bindValue(":quotient", quotient);
    query.bindValue(":idv", idv);

    return    query.exec();
}

bool contrat::supprimer(int idc)
{
    QSqlQuery query;
    query.prepare("Delete from CONTRAT where IDC = :idc ");
    query.bindValue(":idc", idc);
    return    query.exec();
}

bool contrat::modifier(int idc)
{
    QSqlQuery query;
    query.prepare("UPDATE CONTRAT SET CINC=:cinc, DATEDEBUT=:datedebut, DATEFIN=:datefin, MONTANT=:montant, QUOTIENT=:quotient, IDV=:idv "
                        "WHERE IDC=:idc");
    query.bindValue(":cinc", cinc);
    query.bindValue(":datedebut", datedebut);
    query.bindValue(":datefin", datefin);
    query.bindValue(":montant", montant);
    query.bindValue(":quotient", quotient);
    query.bindValue(":idv", idv);
    query.bindValue(":idc", idc);

    return    query.exec();
}

QSqlQueryModel *contrat::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CONTRAT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CINC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATEDEBUT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEFIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("IDC"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MONTANT"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("QUOTIENT"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("IDV"));

    return model;
}

QSqlQueryModel *contrat::recherche(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CONTRAT WHERE CINC LIKE '%"+cls+"%' OR DATEDEBUT LIKE '%"+cls+"%' OR DATEFIN LIKE '%"+cls+"%' OR IDC LIKE '%"+cls+"%' OR MONTANT LIKE '%"+cls+"%' OR QUOTIENT LIKE '%"+cls+"%' OR IDV LIKE '%"+cls+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CINC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATEDEBUT "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEFIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("IDC"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MONTANT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("QUOTIENT"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("IDV"));

    return model;
}

QSqlQueryModel * contrat::setcomboboxv()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select idv from VOITURE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idc"));
    return model ;

}


