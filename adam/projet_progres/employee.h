#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Employee
{public:
    Employee();
    Employee(int,QString,QString,int,int,QString,QString);
    QString get_nom();
    QString get_prenom();
    int get_id();
    QString get_numtel();
    QString get_cin();
    int get_iddep();
    int get_age();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_personnel_trier();
    QSqlQueryModel * rechercher_personnel(const QString &id);
    bool supprimer(int);
    bool modifier(int id);

private:
    QString nom;
    QString prenom;
    QString cin;
    QString numtel;
    int id,id_dep,age;
};

#endif // EMPLOYEE_H
