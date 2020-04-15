#include "fidelite.h"

fidelite::fidelite()
{

}


fidelite::fidelite(QString cin,int valeur,QDate dated,QDate datef)
{
  this->cin=cin;
    this->value=valeur;
    this->dateF=datef;
    this->dateD=dated;
}



bool fidelite::ajouter()
{
QSqlQuery query;


//QString resa= QString::number(value);

query.prepare("INSERT INTO fidelite (cin,value,dated,datef) "
                    "VALUES (:cin,:value,:dated,:datef)");
query.bindValue(":cin", cin);
query.bindValue(":dated",dateD);
query.bindValue(":datef", dateF);
query.bindValue(":value", value);
return    query.exec();
}


QSqlQueryModel * fidelite::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select id,cin,value,dated,datef from fidelite");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("value "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateD"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("dateF"));



    return model;
}

QSqlQueryModel * fidelite::setcombobox()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select cin from client");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    return model ;

}
