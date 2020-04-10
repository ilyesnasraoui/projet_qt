#include "assurances.h"

assurances::assurances()
{
    id=0;
    nom="";
    type="";
}
//----------------------------------------------------------------
assurances::assurances(int id,QString nom, QString type)
{
    this->id=id;
    this->nom=nom;
    this->type=type;
}
//-----------------------------------------------------------------
QString assurances::get_nom(){return  nom;}
QString assurances::get_type(){return type;}
int assurances::get_id(){return  id;}
//-----------------------------------------------------------------
void assurances::set_nom(QString nom){this->nom=nom;};
void assurances::set_type(QString type){this->type=type;};
void assurances::set_id(int id){this->id=id;};
//-----------------------------------------------------------------
bool assurances::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO assurances (ID, NOM, TYPE) "
                    "VALUES (:id, :nom, :type)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":type", type);
int i=0;
i++;

return    query.exec();

}
//------------------------------------------------------------------
QSqlQueryModel * assurances::rechercher(int num ) //rechercher
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    QString res= QString::number(num);

query.prepare("select * from assurances where ID = :num");
query.bindValue(":num", res);
query.exec();
model->setQuery(query);

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    return model;
}


//------------------------------------------------------------------
QSqlQueryModel * assurances::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from assurances");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));

    return model;
}
//-------------------------------------------------------------------
bool assurances::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from assurances where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
//--------------------------------------------------------------------
QSqlQueryModel * assurances::tri_croissant(QString choix)//hethi tri
{
    QSqlQueryModel * model= new QSqlQueryModel();

    if(choix=="NOM")
    model->setQuery("select * from assurances order  by NOM asc");
    else if(choix=="IDENTIFIANT")
        model->setQuery("select * from assurances order  by ID asc");
    else if(choix=="TYPE")
        model->setQuery("select * from assurances order  by TYPE asc");
    else
        model->setQuery("select * from assurances ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));

    return model;
}
//----------------------------------------------------------------------
QSqlQueryModel * assurances::tri_decroissant(QString choix)//hethi tri
{
    QSqlQueryModel * model= new QSqlQueryModel();
    if(choix=="NOM")
    model->setQuery("select * from assurances order  by NOM desc");
    else if(choix=="IDENTIFIANT")
        model->setQuery("select * from assurances order  by ID desc");
    else if(choix=="TYPE")
        model->setQuery("select * from assurances order  by TYPE desc");
    else
        model->setQuery("select * from assurances ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));

    return model;
}
bool assurances::modifier(int idd,QString name,QString typ)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("update assurances set NOM = :nom , TYPE = :type where ID = :id ");
query.bindValue(":id", res);
query.bindValue(":nom", name);
query.bindValue(":type",typ);

return    query.exec();
}
int assurances::statistiques()
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM assurances");
    query.exec();
    query.next();
    int numberOfPages=0 ;
    numberOfPages=query.value(0).toInt();
    return numberOfPages;

}
