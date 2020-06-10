#include "assurances.h"
#include <QMessageBox>
assurances::assurances()
{
    id=0;
    nom="";
    type="";
    id_assureurs=0;
    id_voiture=0;
}
//----------------------------------------------------------------
assurances::assurances(int id,QString nom, QString type,QDate date,int id_voiture,int id_assureurs)
{
    this->id=id;
    this->nom=nom;
    this->type=type;
    this->id_voiture=id_voiture;
    this->id_assureurs=id_assureurs;
    this->date_fin=date;
}
//-----------------------------------------------------------------
QString assurances::get_nom(){return  nom;}
QString assurances::get_type(){return type;}
int assurances::get_id(){return  id;}
int assurances::get_idVoiture(){return  id_voiture;}
int assurances::get_idAssureurs(){return id_assureurs;}
QDate assurances::get_dateFin(){return date_fin;}
//-----------------------------------------------------------------
void assurances::set_nom(QString nom){this->nom=nom;}
void assurances::set_type(QString type){this->type=type;}
void assurances::set_id(int id){this->id=id;}
void assurances::set_idVoiture(int id_voiture){this->id_voiture=id_voiture;}
void assurances::set_idAssureurs(int id_assureurs){this->id_assureurs=id_assureurs;}
void assurances::set_dateFin(QDate date_fin){this->date_fin=date_fin;}
//-----------------------------------------------------------------
bool assurances::ajouter()
{

QSqlQuery query;
QString res= QString::number(id);
QString id_v= QString::number(id_voiture);
QString id_ass= QString::number(id_assureurs);
query.prepare("INSERT INTO assurances (ID, NOM, TYPE, DATE_FIN, ID_VOITURE, ID_ASSUREUR) "
                    "VALUES (:id, :nom, :type, :date_fin, :id_voiture, :id_assureur)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":type", type);
query.bindValue(":id_voiture",id_v);
query.bindValue(":id_assureur",id_ass);
query.bindValue(":date_fin", date_fin);

    return    query.exec();

}
//------------------------------------------------------------------
QSqlQueryModel * assurances::rechercher(QString recherche) //rechercher
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
    query.prepare("select * from assurances where (ID LIKE :num) or (nom LIKE :num) or (type LIKE :num)");
query.bindValue(":num", res);
query.exec();
model->setQuery(query);

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_FIN"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_ASSUREUR"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_VOITURE"));
return model;
}
//------------------------------------------------------------------
QSqlQueryModel * assurances::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from assurances");
/*model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_FIN"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_ASSUREUR"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_VOITURE"));

*/
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
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_FIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_ASSUREUR"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_VOITURE"));

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
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_FIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_ASSUREUR"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_VOITURE"));

    return model;
}
bool assurances::modifier(int idd,QString name,QString typ,QDate date_fin,int id_voiture,int id_assureurs)
{
QSqlQuery query;
QString res= QString::number(idd);


query.prepare("update assurances set NOM = :nom , TYPE = :type , DATE_FIN = :date_fin , ID_VOITURE = :id_voiture , "
              "ID_ASSUREUR = :id_assureurs where ID = :id ");
query.bindValue(":id", res);
query.bindValue(":nom", name);
query.bindValue(":type",typ);
query.bindValue(":date_fin", date_fin);
query.bindValue(":id_voiture",id_voiture);
query.bindValue(":id_assureurs",id_assureurs);


return    query.exec();
}
bool assurances::verifier_entier(QString x)
{
    int i=0;
    for(i=0;i<x.length()&&(x[i]<9 && x[i]>0);i++);
    if(x[i]<=9 && x[i]>=0)
        return true;
    else
       return false;
}
int assurances::calculer_type(QString str)
{
    QSqlQuery verif;
    verif.prepare("Select * from assurances where TYPE = :type");
    verif.bindValue(":type",str);
    int count=0;
    if(verif.exec())
    {
        while(verif.next())
        count++;
    }
    return count;
}
QSqlQueryModel *assurances::ass_notif()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from assurances where (sysdate > DATE_FIN)");
    //query.bindValue("")
    query.exec();

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_FIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_ASSUREUR"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_VOITURE"));


    return model;
}

int assurances::notifications()
{
    int count=0;
    QSqlQuery query;
    query.prepare("select * from assurances where (sysdate > DATE_FIN)");
    if(query.exec())
    {
        while(query.next())
          count++;
    }
    return count;
}

QSqlQueryModel *assurances::tab_assurances_activated()
{

}
int assurances::comparer_date(QString d1,QString d2)
{
    QString dt1,dt2;
    int i;
    for(i=0;i<d1.length();i++)
        dt1[d1.length()-(i+1)]=d1[i];

    for(i=0;i<d2.length();i++)
        dt2[d2.length()-(i+1)]=d2[i];
    if(dt1>dt2)
        return 1;
    else if(dt1<dt2)
            return -1;
    else
        return 0;
}

