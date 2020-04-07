#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"
#include "departement.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabemployee->setModel(tmpemployee.afficher());
ui->tabemployee_2->setModel(tmpdep.afficher());
/*ui->tableView->setModel(tmpemployee.afficher_personnel_trier());*/
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
    int id_dep = ui->lineEdit_id_dep->text().toInt();
    int age = ui->lineEdit_age->text().toInt();
    int cin = ui->lineEdit_cin->text().toInt();
    int numtel = ui->lineEdit_numtel->text().toInt();

  Employee e(id,nom,prenom,id_dep,age,cin,numtel);
  bool test=e.ajouter();
  if(test)
{ui->tabemployee->setModel(tmpemployee.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un employee"),
                  QObject::tr("employee ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un emp"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpemployee.supprimer(id);
if(test)
{ui->tabemployee->setModel(tmpemployee.afficher());//refresh
    /*ui->tableView->setModel(tmpemployee.afficher_personnel_trier());*/
    QMessageBox::information(nullptr, QObject::tr("Supprimer un employee"),
                QObject::tr("Employee supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_pb_modifier_clicked()
{
    int id = ui->lineEdit_id_5->text().toInt();
    QString nom= ui->lineEdit_nom_3->text();
    QString prenom= ui->lineEdit_prenom_3->text();
    int id_dep = ui->lineEdit_id_dep_3->text().toInt();
    int age = ui->lineEdit_age_3->text().toInt();
    int cin = ui->lineEdit_cin_3->text().toInt();
    int numtel = ui->lineEdit_numtel_3->text().toInt();
    Employee e(id,nom,prenom,id_dep,age,cin,numtel);
  bool test=e.modifier(id);
  if(test)
{ui->tabemployee->setModel(tmpemployee.afficher());
/* ui->tableView->setModel(tmpemployee.afficher_personnel_trier())*/;//refresh
QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur"),
                  QObject::tr("modifier ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un fournisseur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pb_recherche_clicked()
{
    QString id = ui->lineEdit_id_6->text();
    ui->tableView_2->setModel(tmpemployee.rechercher_personnel(id));
    }


void MainWindow::on_pushButton_2_clicked()
{
    ui->tabemployee->setModel(tmpemployee.afficher_personnel_trier());

}
//departement
void MainWindow::on_pb_ajouter_2_clicked()
{
        int departement_id = ui->lineEdit_id_3->text().toInt();
        QString departement_name= ui->lineEdit_noom->text();
        int manager_id = ui->lineEdit_manager->text().toInt();
        int num_membre = ui->lineEdit_location->text().toInt();

      departement d(departement_id,departement_name,manager_id,num_membre);
      bool test=d.ajouter();
      if(test)
    {ui->tabemployee_2->setModel(tmpdep.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un departement"),
                      QObject::tr("departement ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un emp"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


    }

void MainWindow::on_pb_supprimer_2_clicked()
{
    int id = ui->lineEdit_id_4->text().toInt();
    bool test=tmpdep.supprimer(id);
    if(test)
    {ui->tabemployee_2->setModel(tmpdep.afficher());//refresh
        /*ui->tableView->setModel(tmpemployee.afficher_personnel_trier());*/
        QMessageBox::information(nullptr, QObject::tr("Supprimer un departement"),
                    QObject::tr("Departement supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un departement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_modifier_2_clicked()
{
    int departement_id = ui->lineEdit_id_8->text().toInt();
    QString departement_name= ui->lineEdit_age_4->text();
    int manager_id = ui->lineEdit_nom_4->text().toInt();
    int num_membre = ui->lineEdit_numtel_4->text().toInt();
    departement d(departement_id,departement_name,manager_id,num_membre);
    bool test=d.modifier(departement_id);
  if(test)
{ui->tabemployee_2->setModel(tmpdep.afficher());
/* ui->tableView->setModel(tmpemployee.afficher_personnel_trier())*/;//refresh
QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur"),
                  QObject::tr("modifier ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un fournisseur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_recherche_2_clicked()
{
    QString id = ui->lineEdit_id_7->text();
    ui->tableView_3->setModel(tmpdep.rechercher_personnel(id));
    ui->tabemployee_2->setModel(tmpdep.afficher());
}
