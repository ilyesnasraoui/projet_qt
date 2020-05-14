#include "promotion.h"
#include <QDebug>

promotion::promotion()
{
   id=0;
   nbVoiture=0;
   typeVoiture="";
   pourc=0;
}

promotion::promotion(int id,int nbVoiture,QString typevoiture,  int pourc , QString dateDebut , QString dateFin )
{
  this->id=id;
  this->nbVoiture=nbVoiture;
  this->pourc=pourc;
  this->typeVoiture=typevoiture;
  this->dateDebut=dateDebut;
  this->dateFin=dateFin;
}
int promotion::get_Nbvoiture(){return  nbVoiture;}
QString promotion::get_TypeVoiture(){return typeVoiture;}
int promotion::get_id(){return  id;}
int promotion::get_Pourc(){return  pourc;}
QString promotion::get_DateDebut(){return dateDebut;}
QString promotion::get_DateFin(){return dateFin;}

bool promotion::ajouterP()
{

QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO PROMOTION (ID, NBVOITURE, TYPEVOITURE ,POURC, DATED, DATEF)"
              "VALUES (:id, :nbVoiture, :typeVoiture,:pourc, :dateDebut, :dateFin )");
query.bindValue(":id", res);
query.bindValue(":nbVoiture", nbVoiture);
query.bindValue(":typeVoiture", typeVoiture);
query.bindValue(":pourc", pourc);
query.bindValue(":dateDebut", dateDebut);
query.bindValue(":dateFin", dateFin);

return    query.exec();
}

QSqlQueryModel * promotion::afficherP()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PROMOTION");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NBVOITURE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPEVOITURE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("POURC"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATED"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATEF"));
    return model;
}

bool promotion::supprimerP(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from PROMOTION where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool promotion::modifierP(promotion p)
{
    QSqlQuery query;

       query.prepare("UPDATE PROMOTION SET NBVOITURE =:nbVoiture , TYPEVOITURE =:typeVoiture , POURC =:pourc , DATED =:dateDebut , DATEF =:dateFin WHERE ID =:id ");
       query.bindValue(":id", p.get_id());
       query.bindValue(":nbVoiture", p.get_Nbvoiture());
       query.bindValue(":typeVoiture",p.get_TypeVoiture());
       query.bindValue(":pourc", p.get_Pourc());
       query.bindValue(":dateDebut", p.get_DateDebut());
       query.bindValue(":dateFin", p.get_DateFin());
    return query.exec();
}
QSqlQueryModel * promotion::rechercherP(QString  type)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PROMOTION where TYPEVOITURE = '"+type+"' ");

model->setHeaderData(1, Qt::Horizontal, QObject::tr("NBVOITURE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPEVOITURE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("POURC"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATED"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATEF"));
return model;
}

QSqlQueryModel *promotion::triP(int in)
{
    QSqlQuery query;
      QSqlQueryModel * model= new QSqlQueryModel();
       if (in==0)
       { query.prepare("select * from PROMOTION");}
       if (in==1)
     { query.prepare("select * from PROMOTION order by NBVOITURE ");}
     if (in==2)
  {    query.prepare("select * from PROMOTION order by TYPEVOITURE ");}
     if (in==3)
  {    query.prepare("select * from PROMOTION order by POURC ");}
     if (in==4)
  {    query.prepare("select * from PROMOTION order by DATED ");}
     if (in==5)
  {    query.prepare("select * from PROMOTION order by DATEF ");}

     query.exec();


  model->setQuery(query);
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("NBVOITURE"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPEVOITURE"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("POURC"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATED"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATEF"));


      return model;
}

