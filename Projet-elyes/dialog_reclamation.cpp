#include "dialog_reclamation.h"
#include "ui_dialog_reclamation.h"
#include "reclamation.h"
#include "contrat.h"
#include <QMessageBox>

Dialog_Reclamation::Dialog_Reclamation(QWidget *parent) :
QDialog(parent),
ui(new Ui::Dialog_Reclamation)
{
    reclamation tmp;
    contrat tmp2;
    ui->setupUi(this);
    ui->data->setModel(tmp.afficher());
    ui->data->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->data2->setModel(tmp2.afficher());
    ui->data2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

Dialog_Reclamation::~Dialog_Reclamation()
{
    delete ui;
}

void Dialog_Reclamation::on_ajouter_clicked()
{
   reclamation tmp(ui->ID->text().toInt(),ui->DESC->text(),ui->CINC->text().toInt(),ui->IDV->text().toInt(),ui->CINE->text().toInt());
   if(tmp.ajouter())
   {
       ui->data->setModel(tmp.afficher());
       QMessageBox::information(nullptr, QObject::tr("Ajouter une reclamation"),
                         QObject::tr("reclamation ajouté.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
   }
   else
   {
       QMessageBox::information(nullptr, QObject::tr("Ajouter une reclamation"),
                         QObject::tr("error reclamation non ajouté.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
   }

}

void Dialog_Reclamation::on_supprimer_clicked()
{
    reclamation tmp;
    if(tmp.supprimer(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),0)).toInt()))
    {
        ui->data->setModel(tmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("supprimé une reclamation"),
                          QObject::tr("reclamation supprimé.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter une reclamation"),
                          QObject::tr("error reclamation non ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void Dialog_Reclamation::on_data_clicked(const QModelIndex &index)
{
    ui->ID->setText(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),0)).toString());
    ui->DESC->setText(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),1)).toString());
    ui->CINC->setText(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),2)).toString());
    ui->IDV->setText(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),3)).toString());
    ui->CINE->setText(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),4)).toString());

}

void Dialog_Reclamation::on_modifier_clicked()
{
    reclamation tmp(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),0)).toInt(),ui->DESC->text(),ui->CINC->text().toInt(),ui->IDV->text().toInt(),ui->CINE->text().toInt());
    if(tmp.modifier())
    {
        ui->data->setModel(tmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajouter une reclamation"),
                          QObject::tr("reclamation ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter une reclamation"),
                          QObject::tr("error reclamation non ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Dialog_Reclamation::on_search_textChanged(const QString &arg1)
{
    reclamation tmp;

    ui->data->setModel(tmp.recherche(ui->search->text()));
}

void Dialog_Reclamation::on_AJOUTERC_clicked()
{
    contrat tmp(ui->CINC_3->text().toInt(),ui->DATEDEBUT->date(),ui->DATEFIN->date(),ui->IDC->text().toInt(),ui->MONTANT->text().toInt(),ui->QUOTIENT->text().toInt(),ui->IDV_3->text().toInt(),ui->NUM->text().toInt());
    if(tmp.ajouter())
    {
        ui->data2->setModel(tmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajouter un contrat"),
                          QObject::tr("conntrat ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un contrat"),
                          QObject::tr("error contrat non ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Dialog_Reclamation::on_modifierc_clicked()
{
    contrat tmp(ui->CINC_3->text().toInt(),ui->DATEDEBUT->date(),ui->DATEFIN->date(),ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),3)).toInt(),ui->MONTANT->text().toInt(),ui->QUOTIENT->text().toInt(),ui->IDV_3->text().toInt(),ui->NUM->text().toInt());
    if(tmp.modifier())
    {
        ui->data2->setModel(tmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("modifier un contrat"),
                          QObject::tr("conntrat modifié.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("modifier un contrat"),
                          QObject::tr("error contrat non modifié.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Dialog_Reclamation::on_Supprimerc_clicked()
{
    contrat tmp;
    if(tmp.supprimer(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),3)).toInt()))
    {
        ui->data2->setModel(tmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("supprimé une reclamation"),
                          QObject::tr("reclamation supprimé.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter une reclamation"),
                          QObject::tr("error reclamation non ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
}



void Dialog_Reclamation::on_data2_clicked(const QModelIndex &index)
{

    ui->CINC_3->setText(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),0)).toString());
    ui->DATEDEBUT->setDate(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),1)).toDate());
    ui->DATEFIN->setDate(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),2)).toDate());
    ui->IDC->setText(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),3)).toString());
    ui->MONTANT->setText(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),4)).toString());
    ui->QUOTIENT->setText(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),5)).toString());
    ui->IDV_3->setText(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),6)).toString());
    ui->NUM->setText(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),7)).toString());


}

void Dialog_Reclamation::on_searchc_textChanged(const QString &arg1)
{
    contrat tmp;

    ui->data2->setModel(tmp.recherche(ui->searchc->text()));
}
