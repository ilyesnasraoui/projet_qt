#include "categorie.h"
#include <QDebug>
categorie::categorie()
{
    id=0;
    type="";
    nbvoitures=0;
}
categorie::categorie(int id,QString type,int nbvoitures)
{
    this->id=id;
    this->type=type;
    this->nbvoitures=nbvoitures;


}


QString categorie::get_type(){return type;}
int categorie::get_id(){return id;}
int categorie::get_nbvoitures(){return  nbvoitures;}


bool categorie::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO categorie (ID,TYPE,NBVOITURES) "
                    "VALUES (:id, :type, :nbvoitures)");
query.bindValue(":id", res);
query.bindValue(":type", type);
query.bindValue(":nbvoitures", nbvoitures);

return    query.exec();
}
QSqlQueryModel * categorie::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from categorie order by id asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("idv"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nbvoitures"));

    return model;
}

bool categorie::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from categorie where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool categorie::modifier()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("UPDATE categorie SET type = :type ,nbvoitures = :nbvoitures WHERE ID = :id;");
query.bindValue(":id", res);
query.bindValue(":type", type);
query.bindValue(":nbvoitures", nbvoitures);

return    query.exec();
}


QSqlQueryModel * categorie::trie()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM categorie order by nbvoitures asc  ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nbvoitures"));

    return    model;
}


