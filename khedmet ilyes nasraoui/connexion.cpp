#include "connexion.h"

connexion::connexion()
{

}
bool connexion::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("ilyes");//inserer nom de l'utilisateur
db.setPassword("0000");//inserer mot de passe de cet utilisateur
if (db.open())
    test=true;
return  test;
}
void connexion::fermerConnexion()
{db.close();}
