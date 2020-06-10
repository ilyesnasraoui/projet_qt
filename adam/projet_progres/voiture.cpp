#include "voiture.h"
#include <QDebug>
voiture::voiture()
{
    idv=0;
    matricule="";
    marque="";
    idcategorie="";
    nbplaces="";
    anciennete=0;
    couleur="";
    kilometrage=0;
    carburant="";
    prixparjour=0;
    etat="";
}
voiture::voiture(int idv,QString marque,QString matricule,QString idcategorie,QString nbplaces,int anciennete,QString couleur,int kilometrage,QString carburant,int prixparjour,QString etat)
{
    this->idv=idv;
    this->marque=marque;
    this->matricule=matricule;
    this->idcategorie=idcategorie;
    this->nbplaces=nbplaces;
    this->anciennete=anciennete;
    this->carburant=carburant;
    this->kilometrage=kilometrage;
    this->couleur=couleur;
    this->prixparjour=prixparjour;
    this->etat=etat;

}

QString voiture::get_matricule(){return  matricule;}
QString voiture::get_marque(){return marque;}
QString voiture::get_couleur(){return  couleur;}
QString voiture::get_carburant(){return carburant;}
int voiture::get_idv(){return idv;}
QString voiture::get_idcategorie(){return  idcategorie;}
QString voiture::get_nbplaces(){return  nbplaces;}
int voiture::get_anciennete(){return  anciennete;}
int voiture::get_kilometrage(){return  kilometrage;}
int voiture::get_prixparjour(){return  prixparjour;}
QString voiture::get_etat(){return  etat;}

bool voiture::ajouter()
{
QSqlQuery query;
QString res= QString::number(idv);
query.prepare("INSERT INTO voiture (IDV,MARQUE,MATRICULE,IDCATEGORIE,NBPLACES,ANCIENNETE,COULEUR,KILOMETRAGE,CARBURANT,PRIXPARJOUR,ETAT) "
                    "VALUES (:idv, :marque, :matricule,:idcategorie, :nbplaces, :anciennete,:couleur,:kilometrage,:carburant, :prixparjour,:etat)");
query.bindValue(":idv", res);
query.bindValue(":marque", marque);
query.bindValue(":matricule", matricule);
query.bindValue(":idcategorie", idcategorie);
query.bindValue(":nbplaces", nbplaces);
query.bindValue(":anciennete", anciennete);
query.bindValue(":couleur", couleur);
query.bindValue(":kilometrage", kilometrage);
query.bindValue(":carburant", carburant);
query.bindValue(":prixparjour", prixparjour);
query.bindValue(":etat", etat);

return    query.exec();
}
QSqlQueryModel * voiture::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from voiture order by idv asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("idv"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("matricule"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("idcategorie"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbplaces"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("anciennete"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("couleur"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("kilometrage"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("carburant"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("prixparjour"));
model->setHeaderData(10, Qt::Horizontal, QObject::tr("etat"));

    return model;
}

bool voiture::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from voiture where IDV = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool voiture::modifier()
{
QSqlQuery query;
QString res= QString::number(idv);
query.prepare("UPDATE voiture SET marque = :marque ,matricule = :matricule, idcategorie = :idcategorie , nbplaces =:nbplaces ,anciennete =:anciennete ,couleur =:couleur , kilometrage =:kilometrage , carburant =:carburant , prixparjour =:prixparjour , etat =:etat WHERE IDV = :idv;");
query.bindValue(":idv", res);
query.bindValue(":marque", marque);
query.bindValue(":matricule", matricule);
query.bindValue(":idcategorie", idcategorie);
query.bindValue(":nbplaces", nbplaces);
query.bindValue(":anciennete", anciennete);
query.bindValue(":couleur", couleur);
query.bindValue(":kilometrage", kilometrage);
query.bindValue(":carburant", carburant);
query.bindValue(":prixparjour", prixparjour);
query.bindValue(":etat", etat);

return    query.exec();
}


QSqlQueryModel * voiture::trie()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM voiture order by prixparjour asc  ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idv"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("matricule"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("idcategorie"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbplaces"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("anciennete"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("couleur"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("kilometrage"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("carburant"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("prixparjour"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("etat"));
    return    model;
}

QSqlQueryModel* voiture:: recherche(QString x) {
    QString res= QString::number(idv);
QSqlQueryModel *model = new QSqlQueryModel() ;
model->setQuery( "SELECT * FROM voiture WHERE IDV LIKE '"+x+"%'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("idv"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("matricule"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("idcategorie"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbplaces"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("anciennete"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("couleur"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("kilometrage"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("carburant"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("prixparjour"));
model->setHeaderData(10, Qt::Horizontal, QObject::tr("etat"));
    return model ;
}
