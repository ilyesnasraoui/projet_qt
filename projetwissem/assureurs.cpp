#include "assureurs.h"

assureurs::assureurs()
{
    id=0;
    nom="";
    email="";
    num_tel=0;
}
assureurs::assureurs(int id,int tel,QString nom, QString email)
{
    this->id=id;
    this->nom=nom;
    this->num_tel=tel;
    this->email=email;
}
QString assureurs::get_nom(){return  nom;}
int assureurs::get_id(){return  id;}
int assureurs::get_tel(){return  num_tel;}
QString assureurs::get_mail(){return  email;}
//------------------------------------------------------------------
void assureurs::set_id(int id){this->id=id;}
void assureurs::set_tel(int tel){this->num_tel=tel;}
void assureurs::set_nom(QString nom){this->nom=nom;}
void assureurs::set_mail(QString mail){this->email=mail;}
//------------------------------------------------------------------
bool assureurs::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
QString tel= QString::number(num_tel);

query.prepare("INSERT INTO assureurs (ID, NOM, NUM_TEL,EMAIL) "
                    "VALUES (:id, :nom, :tel, :mail)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":tel", tel);
query.bindValue(":mail", email);
    return    query.exec();
}
//-------------------------------------------------------------------
QSqlQueryModel * assureurs::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from assureurs");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_tel"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
return model;
}

QSqlQueryModel *assureurs::liste_mail()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select email from assureurs");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("email"));
    return model;

}
//-------------------------------------------------------------------
bool assureurs::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from assureurs where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
//---------------------------------------------------------------------
QSqlQueryModel * assureurs::rechercher(QString recherche) //rechercher
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    bool verif=verifier_entier(recherche);
    int rech_int=0;
    QString res;
    if(verif)
    {
        rech_int=recherche.toInt();
        res= QString::number(rech_int);
    }
    else res=recherche;
    res='%'+res+'%';
    query.prepare("select * from assureurs where (ID LIKE :num) or (nom LIKE :num) or (email LIKE :num) or (NUM_TEL LIKE :num) ");
query.bindValue(":num", res);
query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_tel"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));

return model;
}
//-------------------------------------------------------------------------
bool assureurs::verifier_entier(QString x)
{
    int i=0;
    for(i=0;i<x.length()&&(x[i]<9 && x[i]>0);i++);
    if(x[i]<=9 && x[i]>=0)
        return true;
    else
       return false;
}
//---------------------------------------------------------------------------
bool assureurs::modifier(int idd,int num_tel,QString name,QString email)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("update assureurs set NOM = :nom , EMAIL= :email , NUM_TEL = :num_tel where ID = :id");
query.bindValue(":id", res);
query.bindValue(":nom", name);
query.bindValue(":email",email);
query.bindValue(":num_tel", num_tel);
return    query.exec();
}
//---------------------------------------------------------------------------
QSqlQueryModel * assureurs::tri_croissant(QString choix)//hethi tri
{
    QSqlQueryModel * model= new QSqlQueryModel();

    if(choix=="NOM")
    model->setQuery("select * from assureurs order  by NOM asc");
    else if(choix=="EMAIL")
        model->setQuery("select * from assureurs order  by EMAIL asc");
    else if(choix=="IDENTIFIANT")
        model->setQuery("select * from assureurs order  by ID asc");
    else
        model->setQuery("select * from assureurs ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_tel"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));

    return model;

}
//----------------------------------------------------------------------
QSqlQueryModel * assureurs::tri_decroissant(QString choix)//hethi tri
{
    QSqlQueryModel * model= new QSqlQueryModel();

    if(choix=="NOM")
    model->setQuery("select * from assureurs order  by NOM desc");
    else if(choix=="EMAIL")
        model->setQuery("select * from assureurs order  by EMAIL desc");
    else if(choix=="IDENTIFIANT")
        model->setQuery("select * from assureurs order  by ID desc");
    else
        model->setQuery("select * from assureurs ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_tel"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));

    return model;
}
