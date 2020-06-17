#ifndef ASSUREURS_H
#define ASSUREURS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDateTime>
#include<QString>


class assureurs
{
private:
    int id,num_tel;
    QString nom,email,adresse;

public:
    assureurs();
    assureurs(int,int,QString,QString,QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * liste_mail();
    QSqlQueryModel * rechercher(QString);
    bool supprimer(int);
    QSqlQueryModel * tri_croissant(QString);
    QSqlQueryModel * tri_decroissant(QString);
    bool modifier(int,int,QString,QString,QString);
    bool verifier_entier(QString);
    QSqlQueryModel * rechercher_mail(QString);
//-------------------------------------------------------
    QString get_nom();
    int get_id();
    int get_tel();
    QString get_mail();
//-------------------------------------------------------
    void set_nom(QString);
    void set_id(int);
    void set_tel(int);
    void set_mail(QString);
};

#endif // ASSUREURS_H
