#include "reclamation.h"


reclamation::reclamation()
{

}

reclamation::reclamation(int id, QString description, QString cinC, int idV, int cinE)
{
 this->id=id;
 this->description=description;
 this->cinC=cinC;
 this->idV=idV;
    this->cinE=cinE;
}

bool reclamation::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO reclamation (ID, DESCRIPTION, CINC,IDV,CINE) "
                        "VALUES (:id, :description, :cinC,:idV,:cinE)");
    query.bindValue(":id", id);
    query.bindValue(":description", description);
    query.bindValue(":cinC", cinC);
    query.bindValue(":idV", idV);
    query.bindValue(":cinE", cinE);
    return    query.exec();
}

QSqlQueryModel * reclamation::setcombobox()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select idc from contrat where REC='0'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idc"));
    return model ;

}

bool reclamation::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("Delete from reclamation where ID = :id ");
    query.bindValue(":id", id);
    return    query.exec();
}

bool reclamation::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE reclamation SET DESCRIPTION=:description, CINC=:cinC,IDV=:idV,CINE=:cinE "
                        "WHERE ID=:id");
    query.bindValue(":id", id);
    query.bindValue(":description", description);
    query.bindValue(":cinC", cinC);
    query.bindValue(":idV", idV);
    query.bindValue(":cinE", cinE);
    return    query.exec();
}

QSqlQueryModel *reclamation::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from RECLAMATION");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Description "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN C"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID V"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN E"));
    return model;
}

QSqlQueryModel *reclamation::recherche(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from RECLAMATION WHERE ID LIKE '%"+cls+"%' OR DESCRIPTION LIKE '%"+cls+"%' OR CINC LIKE '%"+cls+"%' OR IDV LIKE '%"+cls+"%' OR CINE LIKE '%"+cls+"%'"
);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Description "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN C"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID V"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN E"));
    return model;
}

QSqlQueryModel *reclamation::triez(QString cls)
{
        QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from RECLAMATION order by "+cls+" ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Description "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN C"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID V"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN E"));
        return model;
}

