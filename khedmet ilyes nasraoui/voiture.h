#ifndef VOITURE_H
#define VOITURE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class voiture
{
public:
    voiture();
    voiture(int,QString,QString,int,int,int,QString,int,QString,int,int);
    int get_idv();
    QString get_marque();
    QString get_matricule();
    int get_idcategorie();
    int get_nbplaces();
    int get_anciennete();
    QString get_couleur();
    int get_kilometrage();
    QString get_carburant();
    int get_prixparjour();
    int get_etat();
    bool ajouter();
       QSqlQueryModel * afficher();
       bool supprimer(int);
       bool modifier();
       QSqlQueryModel * trie ();
       QSqlQueryModel* recherche (QString);
private:
       int idv,idcategorie,nbplaces,anciennete,kilometrage,prixparjour,etat;
           QString marque,matricule,couleur,carburant;

};

#endif // VOITURE_H
