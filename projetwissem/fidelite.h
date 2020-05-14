#include <QDate>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fidelite
{
public:
    fidelite();
    fidelite(QString,int,QDate,QDate);

    QString get_cin();
    float get_value();
    QDate get_DD();
    QDate get_DF();
    bool ajouter();
    QString send(QString);
    void supprimer(QString);
    bool modifier(QString);
QSqlQueryModel * chercher(QString);
    QSqlQueryModel * afficher();
    QSqlQueryModel * setcombobox();

    QSqlQueryModel * tri(int);
private:
    QString cin;
    int value ;
    QDate dateD,dateF;

};
