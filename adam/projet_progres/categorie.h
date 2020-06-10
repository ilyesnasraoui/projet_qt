#ifndef CATEGORIE_H
#define CATEGORIE_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class categorie
{
public:
    categorie();
    categorie(int,QString,int);
    int get_id();
    QString get_type();
    int get_nbvoitures();

    bool ajouter();
       QSqlQueryModel * afficher();
       bool supprimer(int);
       bool modifier();
       QSqlQueryModel * trie ();
private:
       int id ,nbvoitures;
           QString type;

};


#endif // CATEGORIE_H
