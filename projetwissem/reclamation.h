#ifndef RECLAMATION_H
#define RECLAMATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

class reclamation
{
public:
    reclamation();
    reclamation(int id,QString description,QString cinC,int idV,int cinE);
    bool ajouter();
    bool supprimer(int id);
    bool modifier();
    QSqlQueryModel * afficher();
    QSqlQueryModel * triez(QString cls);
    QSqlQueryModel * recherche (QString cls);
    QSqlQueryModel * setcombobox();

private:
    int id,idV,cinE;
    QString cinC,description;
};

#endif // RECLAMATION_H
