#ifndef PROMOTION_H
#define PROMOTION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>

class promotion
{
public:
    promotion();
    promotion(int ,int ,QString,int ,QString, QString);

    int get_id();
    int get_Pourc();
    int get_Nbvoiture();
    QString get_TypeVoiture();
    QString get_DateDebut();
    QString get_DateFin();
    bool ajouterP();
    bool modifierP(promotion p);
    QSqlQueryModel * afficherP();
    bool supprimerP(int);
    QSqlQueryModel*rechercherP(QString type);
    QSqlQueryModel *triP(int);

private :
    int id;
    int nbVoiture;
    int pourc;
    QString dateDebut;
    QString dateFin;
    QString typeVoiture;
};

#endif // PROMOTION_H

