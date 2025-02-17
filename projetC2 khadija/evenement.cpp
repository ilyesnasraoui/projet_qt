#include "evenement.h"

evenement::evenement()
{
   //date_event(1,1,2020);
   idE=0;
   typeEvent="";
   desc="";

}

evenement::evenement(int idE,QString typeEvent ,QString desc ,QString date_event)
{
    this->idE=idE;
    this->desc=desc;
    this->typeEvent=typeEvent;
    this->date_event=date_event;
}
QString evenement::get_TypeEvent(){return typeEvent;}
int evenement::get_IdE(){return  idE;}
QString evenement::get_Desc(){return desc;}
QString evenement::get_Date_event(){return date_event;}
bool evenement::ajouterE()
{

QSqlQuery query;
QString res= QString::number(idE);
query.prepare("INSERT INTO EVENEMENT (IDE, TYPEEVENT, DESCRIPTION, DATEE)"
              "VALUES (:idE,:typeEvent,:desc, :date_event)");
query.bindValue(":idE", res);
query.bindValue(":typeEvent", typeEvent);
query.bindValue(":desc", desc);
query.bindValue(":date_event", date_event);

return    query.exec();
}
QSqlQueryModel * evenement::afficherE()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EVENEMENT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPEEVENT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEE"));
    return model;
}
bool evenement::supprimerE(int idE)
{
QSqlQuery query;
QString res= QString::number(idE);
query.prepare("Delete from EVENEMENT where IDE = :idE ");
query.bindValue(":idE", res);
return    query.exec();
}

bool evenement::modifierE(evenement e)
{
    QSqlQuery query;

       query.prepare("UPDATE EVENEMENT SET TYPEEVENT =:typeEvent , DESCRIPTION =:desc , DATEE =:date_event WHERE IDE =:idE ");
       query.bindValue(":idE", e.get_IdE());
       query.bindValue(":typeEvent", e.get_TypeEvent());
       query.bindValue(":desc", e.get_Desc());
       query.bindValue(":date_event", e.get_Date_event());
    return query.exec();
}

QSqlQueryModel * evenement::rechercherE(QString event)
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EVENEMENT where DATEE = '"+event+"' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPEEVENT"));

return model;
}
QSqlQueryModel *evenement::triE()
{
QSqlQuery *q = new QSqlQuery();
QSqlQueryModel *model = new QSqlQueryModel();
q->prepare("SELECT * FROM EVENEMENT ORDER BY TYPEEVENT");
q->exec();
model->setQuery(*q);
return model;
}
