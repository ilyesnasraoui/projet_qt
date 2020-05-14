
#ifndef CONTRAT_H
#define CONTRAT_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

class contrat
{
public:
    contrat();
    contrat(QString cinc,QDate datedebut,QDate datefin,int idc,int montant,int quotient,int idv,int num);
    bool ajouter();
    bool supprimer(int id);
    bool modifier();
    QSqlQueryModel * afficher();
    QSqlQueryModel * recherche (QString cls);
private:
    QString cinc ;
    int idc,montant,quotient,idv,num;
    QDate datedebut,datefin;
};

#endif // CONTRAT_H
