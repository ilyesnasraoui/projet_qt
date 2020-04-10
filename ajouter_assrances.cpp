#include "ajouter_assrances.h"
#include "ui_ajouter_assrances.h"
#include "mainwindow.h"
#include <QString>
Ajouter_Assrances::Ajouter_Assrances(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajouter_Assrances)
{
    ui->setupUi(this);
}

Ajouter_Assrances::~Ajouter_Assrances()
{
    delete ui;
}

void Ajouter_Assrances::on_ajout_assurance_pb_clicked()
{
    int id = ui->ajout_id_assurance->text().toInt();
    QString nom= ui->ajout_nom_assurance->text();
    QString type= ui->ajout_type_assurance->text();
    assurances a(id,nom,type);
    bool test=a.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter une assurance"),
                                 QObject::tr("Assurance ajoutée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une assurance"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
