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

bool fidelite::modifier(QString id)
{
QSqlQuery queryp,queryn,querya,queryt,querye;


QString resa= QString::number(value);
if ( resa !=""){
queryp.prepare("UPDATE fidelite SET value = :value , dated = :dated , datef= :datef  WHERE id=:id ");
queryp.bindValue(":cin", cin);

queryp.bindValue(":value", value);
queryp.bindValue(":dated", dateD);
queryp.bindValue(":datef", dateF);
queryp.bindValue(":id", id);

queryp.exec();
}
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

QString fidelite::send(QString cin)
{    QSqlQuery query;

    QSqlQueryModel * model= new QSqlQueryModel();
      query.prepare("select email from client where cin=:cin");
      query.bindValue(":cin", cin);
       query.exec();
      model->setQuery(query);
       return (model->data(model->index(0,0)).toString()) ;

}


QSqlQueryModel * fidelite::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select id,cin,value,dated,datef from fidelite");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("valeur (Dt) "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateD"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("dateF"));



    return model;
}


QSqlQueryModel * fidelite::chercher(QString prn)
{    QSqlQuery query;

    QSqlQueryModel * model= new QSqlQueryModel();
     prn='%'+prn+'%';

    query.prepare("select id,cin,value,dated,datef from fidelite where (cin LIKE :prn)");
    query.bindValue(":prn", prn);

    query.exec();


model->setQuery(query);
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("valeur (Dt) "));
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

void fidelite::supprimer(QString id)
{
QSqlQuery query;



query.prepare("DELETE FROM fidelite WHERE id=:id ");
query.bindValue(":id", id);

 query.exec();
}

