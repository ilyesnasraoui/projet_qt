#ifndef VOITURE_H
#define VOITURE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class voiture
{
public:
    voiture();
    voiture(int,QString,QString,QString,QString,int,QString,int,QString,int,QString);
    int get_idv();
    QString get_marque();
    QString get_matricule();
    QString get_idcategorie();
    QString get_nbplaces();
    int get_anciennete();
    QString get_couleur();
    int get_kilometrage();
    QString get_carburant();
    int get_prixparjour();
    QString get_etat();
    bool ajouter();
       QSqlQueryModel * afficher();
       bool supprimer(int);
       bool modifier();
       QSqlQueryModel * trie ();
       QSqlQueryModel* recherche (QString);
private:
       int idv,anciennete,kilometrage,prixparjour;
           QString marque,matricule,couleur,carburant,etat,idcategorie,nbplaces;

};


#endif // VOITURE_H
