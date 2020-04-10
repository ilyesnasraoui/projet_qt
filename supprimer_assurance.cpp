#include "supprimer_assurance.h"
#include "ui_supprimer_assurance.h"
#include "mainwindow.h"
#include <QString>
supprimer_assurance::supprimer_assurance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimer_assurance)
{
    ui->setupUi(this);
}

supprimer_assurance::~supprimer_assurance()
{
    delete ui;
}

void supprimer_assurance::on_pb_confirmer_supp_clicked()
{
    int id = ui->supprimer->text().toInt();
    bool test=tmpassurances.supprimer(id);
    if(test)
    {   QMessageBox::information(nullptr, QObject::tr("Supprimer une assurance"),
                                 QObject::tr("Assurance supprimée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une assurance"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}
