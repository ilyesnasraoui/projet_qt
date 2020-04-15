#include "fidelite.h"

fidelite::fidelite()
{

}



bool fidelite::ajouter()
{
QSqlQuery query;


//QString resa= QString::number(value);

query.prepare("INSERT INTO fidelite (cin,value,dated,datef) "
                    "VALUES (:cin,:value,:dated,:datef)");
query.bindValue(":cin", cin);
query.bindValue(":dated",dateD);
query.bindValue(":tel", dateF);

query.bindValue(":value", value);
return    query.exec();
}


QSqlQueryModel * fidelite::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from fidelite");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("value "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateD"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateF"));


    return model;
}

void fidelite::setcombobox()
{  QSqlQuery query;

    query.prepare("select cin from fidelite");
    query.exec();
}
