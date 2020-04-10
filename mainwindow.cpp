#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ajouter_assrances.h"
#include "supprimer_assurance.h"
#include "modifier_assurance.h"
#include "statistiques.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tri->addItem("TRIER PAR");
    ui->tri->addItem("IDENTIFIANT");
    ui->tri->addItem("NOM");
    ui->tri->addItem("TYPE");
    ui->tabassurances->setModel(tmpassurances.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_tri_croissant_clicked()
{
    QString choix=ui->tri->currentText();
    ui->tabassurances->setModel(tmpassurances.tri_croissant(choix));
}

void MainWindow::on_tri_decroissant_clicked()
{
    QString choix=ui->tri->currentText();
    ui->tabassurances->setModel(tmpassurances.tri_decroissant(choix));
}

void MainWindow::on_boutton_rechercher_clicked()
{
    int id = ui->rechercher->text().toInt();
    ui->tabassurances->setModel(tmpassurances.rechercher(id));
}

void MainWindow::on_assureurs_currentChanged(int index)
{
     ui->tabassurances->setModel(tmpassurances.afficher());
}

void MainWindow::on_ajouter_pb_clicked()
{
    Ajouter_Assrances interface_ajout;
    interface_ajout.setModal(true);
    interface_ajout.exec();
    ui->tabassurances->setModel(tmpassurances.afficher());

}

void MainWindow::on_supprimer_pb_clicked()
{
    supprimer_assurance interface_supprimer;
    interface_supprimer.setModal(true);
    interface_supprimer.exec();
    ui->tabassurances->setModel(tmpassurances.afficher());

}

void MainWindow::on_modifier_pb_clicked()
{
    modifier_assurance interface_modifier;
    interface_modifier.setModal(true);
    interface_modifier.exec();
    ui->tabassurances->setModel(tmpassurances.afficher());
}

void MainWindow::on_statistiques_clicked()
{
    statistiques interface_statistiques;
    interface_statistiques.setModal(true);
    interface_statistiques.exec();
}
