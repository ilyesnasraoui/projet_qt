#include "client.h"

client::client()
{

}

client::client(QString cin,QString nom ,QString prenom,QString tel,int age,QString email)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->email=email;

    this->tel=tel;
    this->age=age;
}


QString client::get_nom(){return  nom;}
QString client::get_prenom(){return prenom;}
QString client::get_cin(){return  cin;}
int client::get_age(){return  age;}
QString client::get_tel(){return  tel;}


bool client::ajouter()
{
QSqlQuery query;


QString resa= QString::number(age);

query.prepare("INSERT INTO client (cin,nom,prenom,age,tel,email) "
                    "VALUES (:cin,:prenom,:nom,:age,:tel,:email)");
query.bindValue(":cin", cin);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":tel", tel);
query.bindValue(":email", email);
query.bindValue(":age", resa);
return    query.exec();
}

void client::supprimer(QString cin)
{
QSqlQuery query;



query.prepare("DELETE FROM client WHERE cin=:cin ");
query.bindValue(":cin", cin);

 query.exec();
}

bool client::modifier()
{
QSqlQuery queryp,queryn,querya,queryt,querye;


QString resa= QString::number(age);
if ( prenom !=""){
queryp.prepare("UPDATE client SET PRENOM = :prenom WHERE cin=:cin ");
queryp.bindValue(":cin", cin);

queryp.bindValue(":prenom", prenom);

queryp.exec();
}
if ( nom !=""){
queryn.prepare("UPDATE client SET NOM = :nom WHERE cin=:cin ");
queryn.bindValue(":cin", cin);
queryn.bindValue(":nom", nom);

queryn.exec();
}

if ( email !=""){
querye.prepare("UPDATE client SET email = :email WHERE cin=:cin ");
querye.bindValue(":cin", cin);
querye.bindValue(":email", email);

querye.exec();
}
if ( tel !=""){
queryt.prepare("UPDATE client SET tel = :tel WHERE cin=:cin ");
queryt.bindValue(":cin", cin);
queryt.bindValue(":tel", tel);
queryt.exec();
}
if ( age != 0){
querya.prepare("UPDATE client SET age = :age WHERE cin=:cin ");
querya.bindValue(":cin", cin);
querya.bindValue(":age", resa);
querya.exec();
}
return   1;
}

QSqlQueryModel * client::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("tel"));


    return model;
}
QSqlQueryModel * client::chercher(QString prn)
{    QSqlQuery query;

    QSqlQueryModel * model= new QSqlQueryModel();
     prn='%'+prn+'%';

    query.prepare("select * from client where (prenom LIKE :prn) or (nom LIKE :prn) or (cin LIKE :prn) or (tel LIKE :prn) ");
    query.bindValue(":prn", prn);

    query.exec();


model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("tel"));


    return model;
}

QSqlQueryModel * client::tri(int in)
{    QSqlQuery query;
    QSqlQueryModel * model= new QSqlQueryModel();
     if (in==0)
     { query.prepare("select * from client");}
     if (in==1)
   { query.prepare("select * from client order by cin ");}
   if (in==2)
{    query.prepare("select * from client order by age ");}
   if (in==3)
{    query.prepare("select * from client order by nom ");}
   if (in==4)
{    query.prepare("select * from client order by prenom ");}
   if (in==5)
{    query.prepare("select * from client order by tel ");}

   query.exec();


model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("tel"));


    return model;
}
