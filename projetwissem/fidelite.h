#include <QDate>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fidelite
{
public:
    fidelite();
    fidelite(QString,float,QDate,QDate);

    QString get_cin();
    float get_value();
    QDate get_DD();
    QDate get_DF();
    bool ajouter();
    void supprimer(QString);
    void setcombobox();
    bool modifier();
QSqlQueryModel * chercher(QString);
    QSqlQueryModel * afficher();
    QSqlQueryModel * tri(int);
private:
    QString cin;
    float value ;
    QDate dateD,dateF;

};
