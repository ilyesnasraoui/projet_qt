#include "employee.h"
#include <QDebug>
Employee::Employee()
{
id=0;
nom="";
prenom="";
age=0;
id_dep=0;
cin="";
numtel="";
email="";
salaire=0;
adresse="";
}
Employee::Employee(int id,QString nom,QString prenom,int id_dep,int age,QString cin,QString numtel,QString email, int salaire, QString adresse)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->id_dep=id_dep;
  this->age=age;
  this->cin=cin;
  this->numtel=numtel;
   this->email=email;
    this->salaire=salaire;
    this->adresse=adresse;
}
QString Employee::get_nom(){return  nom;}
QString Employee::get_prenom(){return prenom;}
int Employee::get_id(){return  id;}
int Employee::get_iddep(){return  id_dep;}
int Employee::get_age(){return  age;}
QString Employee::get_cin(){return  cin;}
QString Employee::get_numtel(){return  numtel;}
QString Employee::get_email(){return  email;}
int Employee::get_salaire(){return  salaire;}
QString Employee::get_adresse(){return  adresse;}

bool Employee::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO employee (ID, ID_DEP, CIN, AGE, NUM_TEL, NOM, PRENOM, EMAIL, SALAIRE, ADRESSE) "
                    "VALUES (:id,:id_dep,:cin,:age,:numtel,:nom,:prenom,:email,:salaire,:adresse)");
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":id", id);
query.bindValue(":id_dep", id_dep);
query.bindValue(":cin", cin);
query.bindValue(":age", age);
query.bindValue(":numtel", numtel);
query.bindValue(":email", email);
query.bindValue(":salaire", salaire);
query.bindValue(":adresse", adresse);
return    query.exec();
}

QSqlQueryModel * Employee::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select ID,NOM, PRENOM, AGE,CIN,ID_DEP,  EMAIL, SALAIRE, ADRESSE, NUM_TEL from employee");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_DEP"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("NUM_TEL"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("EMAIL"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("SALAIRE"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("ADRESSE"));
    return model;
}

bool Employee::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from employee where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Employee::modifier(int id)
{
    QSqlQuery query;
   QString res= QString::number(id);
   query.prepare("INSERT INTO employee (ID, ID_DEP, CIN, AGE, NUM_TEL, NOM, PRENOM, EMAIL, SALAIRE, ADRESSE) "
                       "VALUES (:id,:id_dep,:cin,:age,:numtel,:nom,:prenom,:email,:salaire,:adresse)");
   query.bindValue(":nom", nom);
   query.bindValue(":prenom", prenom);
   query.bindValue(":id", id);
   query.bindValue(":id_dep", id_dep);
   query.bindValue(":cin", cin);
   query.bindValue(":age", age);
   query.bindValue(":numtel", numtel);
   query.bindValue(":email", email);
   query.bindValue(":salaire", salaire);
   query.bindValue(":adresse", adresse);

    return  query.exec();
}
QSqlQueryModel *Employee::afficher_personnel_trier()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select ID,NOM, PRENOM, AGE,CIN,ID_DEP,  EMAIL, SALAIRE, ADRESSE, NUM_TEL from employee ORDER BY ID");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_DEP"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("NUM_TEL"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("SALAIRE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("ADRESSE"));
    return model;
}

QSqlQueryModel *Employee::rechercher_personnel(const QString &id)
{
    QSqlQueryModel *model=new QSqlQueryModel();
   model->setQuery("select ID,NOM, PRENOM, AGE,CIN,ID_DEP,  EMAIL, SALAIRE, ADRESSE, NUM_TEL from employee where(ID LIKE '"+id+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_DEP"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("NUM_TEL"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("SALAIRE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("ADRESSE"));

    return model;
}


QSqlQueryModel * Employee::setcombobbb3()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select id from DEP ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    return model ;

}




