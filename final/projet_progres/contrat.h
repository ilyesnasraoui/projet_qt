
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
    contrat(QString cinc,QDate datedebut,QDate datefin,int montant,int quotient,int idv);
    bool ajouter();
    bool supprimer(int id);
    bool modifier(int id);
    QSqlQueryModel * afficher();
    QSqlQueryModel * recherche (QString cls);
    QSqlQueryModel * setcomboboxv();

private:
    QString cinc ;
    int montant,quotient,idv;
    QDate datedebut,datefin;
};

#endif // CONTRAT_H
