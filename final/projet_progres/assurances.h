#ifndef ASSURANCES_H
#define ASSURANCES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDateTime>
#include<QString>
class assurances
{
private:
    QString nom,type;
    int id,id_voiture,id_assureurs;
    QDate date_fin;

public:
    assurances();
    assurances(int,QString,QString,QDate,int,int);
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * rechercher(QString);
    bool supprimer(int);
    QSqlQueryModel * tri_croissant(QString);
    QSqlQueryModel * tri_decroissant(QString);
    bool modifier(int,QString,QString,QDate,int,int);
//-----------------------------------------------------
    QString get_nom();
    int get_id();
    QString get_type();
    QDate get_dateFin();
    int get_idVoiture();
    int get_idAssureurs();
//-----------------------------------------------------
    void set_nom(QString );
    void set_type(QString);
    void set_id(int id);
    void set_dateFin(QDate);
    void set_idVoiture(int);
    void set_idAssureurs(int);
    bool verifier_entier(QString );
    int calculer_type(QString);
    int comparer_date(QString,QString);
    QSqlQueryModel *ass_notif();
    int notifications();
    QSqlQueryModel * tab_assurances_activated();
};

#endif // ASSURANCES_H
