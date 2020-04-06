#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "etudiant.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabetudiant->setModel(tmpetudiant.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
  Etudiant e(id,nom,prenom);
  bool test=e.ajouter();
  if(test)
{ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Etudiant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpetudiant.supprimer(id);
if(test)
{ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                QObject::tr("Etudiant supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked(bool checked)
{
    on_pb_supprimer_clicked();
}

void MainWindow::on_pb_modifier_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
    QString nom= ui->lineEdit_nom_3->text();
    QString prenom= ui->lineEdit_prenom_3->text();
  Etudiant e(id,nom,prenom);
  bool test=e.modifier();
  if(test)
{ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier un étudiant"),
                  QObject::tr("Etudiant Modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);}
}
