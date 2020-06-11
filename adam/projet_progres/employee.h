#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Employee
{public:
    Employee();
    Employee(int,QString,QString,int,int,QString,QString,QString,int,QString);
    QString get_nom();
    QString get_prenom();
    int get_id();
    QString get_numtel();
    QString get_cin();
    int get_iddep();
    int get_age();
    bool ajouter();
    QString get_email();
    int get_salaire();
    QString get_adresse();

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
    QString email;
    int id,id_dep,age, salaire;
    QString adresse;
};

#endif // EMPLOYEE_H
