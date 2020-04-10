#ifndef ASSURANCES_H
#define ASSURANCES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class assurances
{
private:
    QString nom,type;
    int id;

public:
    assurances();
    assurances(int,QString,QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * rechercher(int);
    bool supprimer(int);
    QSqlQueryModel * tri_croissant(QString);
    QSqlQueryModel * tri_decroissant(QString);
    bool modifier(int,QString,QString);
    int statistiques();
//-----------------------------------------------------
    QString get_nom();
    int get_id();
    QString get_type();
//-----------------------------------------------------
    void set_nom(QString nom);
    void set_type(QString type);
    void set_id(int id);
};

#endif // ASSURANCES_H
