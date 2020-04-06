#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouterP_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString typeVoiture= ui->typeV->text();
    int nbVoiture= ui->nbvoiture->value();
    int pourc= ui->pourc->value();
    QString dateDebut=ui->dateEdit_debut->date().toString("dd/MM/yyyy");
     QString dateFin=ui->dateEdit_fin->date().toString("dd/MM/yyyy");

  promotion p(id,nbVoiture, typeVoiture,pourc,dateDebut,dateFin);
  bool test=p.ajouterP();
  if(test)
    {ui->tabpromotion->setModel(tmppromotion.afficherP());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une promotion"),
                  QObject::tr("promotion ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une promotion"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_idS->text().toInt();
bool test=tmppromotion.supprimerP(id);
if(test)
{ui->tabpromotion->setModel(tmppromotion.afficherP());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un promotion"),
                QObject::tr("promotion supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un promotion"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pb_modifierP_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString typeVoiture= ui->typeV->text();
    int nbVoiture= ui->nbvoiture->value();
    int pourc= ui->pourc->value();
    QString dateDebut=ui->dateEdit_debut->date().toString("dd/MM/yyyy");
     QString dateFin=ui->dateEdit_fin->date().toString("dd/MM/yyyy");

 promotion p(id,nbVoiture, typeVoiture,pourc,dateDebut,dateFin);

 bool test=p.modifierP(p);

 if (test)
 { ui->tabpromotion->setModel(tmppromotion.afficherP());//refresh
 QMessageBox::information(nullptr, QObject::tr("promotion un client"),
                   QObject::tr(" promotion modifié .\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}
}


void MainWindow::on_pb_ajouterE_clicked()
{
    int idE = ui->lineEdit_idE->text().toInt();
    QString typeEvent= ui->comboBoxE->currentText();
    QString desc= ui->description->text();
    QString date_event=ui->dateEdit_event->date().toString("dd/MM/yyyy");

  evenement e(idE,typeEvent, desc, date_event);
    bool test=e.ajouterE();
    if(test)
      {ui->tabevenement->setModel(tmpevenement.afficherE());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un evenement"),
                    QObject::tr("promotion ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un evenement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimerE_clicked()
{
int idE = ui->lineEdit_idES->text().toInt();
bool test=tmpevenement.supprimerE(idE);
if(test)
{ui->tabevenement->setModel(tmpevenement.afficherE());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un evenement"),
                QObject::tr("evenement supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un evenement"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_modifierE_clicked()
{
    int idE = ui->lineEdit_idE->text().toInt();
    QString typeEvent= ui->comboBoxE->currentText();
    QString desc= ui->description->text();
    QString date_event=ui->dateEdit_event->date().toString("dd/MM/yyyy");

 evenement e(idE,typeEvent, desc, date_event);

 bool test=e.modifierE(e);

 if (test)
 { ui->tabevenement->setModel(tmpevenement.afficherE());//refresh
 QMessageBox::information(nullptr, QObject::tr("modifier un evenement"),
                   QObject::tr(" evenement modifié .\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}
}

