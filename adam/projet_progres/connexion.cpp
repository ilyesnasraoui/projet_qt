#include "connexion.h"

Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source_projet2A");
db.setUserName("ilyes");//inserer nom de l'utilisateurilyes
db.setPassword("0000");//inserer mot de passe de cet utilisateur0000
if (db.open())
    test=true;
return  test;
}
void Connexion::fermerConnexion()
{db.close();}
