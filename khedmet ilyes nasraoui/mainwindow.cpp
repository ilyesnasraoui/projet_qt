#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "voiture.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>

QT_CHARTS_USE_NAMESPACE



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView2->setModel(tmpvoiture.afficher());
    ui->tableView->setModel(tmpcategorie.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}



//********************************************************************************************
void MainWindow::on_ajouter_clicked()
{
    int idv = ui->lineEdit_idv->text().toInt();
    QString marque= ui->lineEdit_marque->text();
    QString matricule= ui->lineEdit_matricule->text();
    int idcategorie=ui->lineEdit_idcategorie->text().toInt();
    int nbplaces=ui->lineEdit_nbplaces->text().toInt();
    int anciennete=ui->lineEdit_anciennete->text().toInt();
    QString couleur=ui->lineEdit_couleur->text();
    int kilometrage=ui->lineEdit_kilometrage->text().toInt();
    QString carburant=ui->lineEdit_carburant->text();
    int prixparjour=ui->lineEdit_prixparjour->text().toInt();
    QString etat=ui->combo->currentText();
  voiture e(idv,marque,matricule,idcategorie,nbplaces,anciennete,couleur,kilometrage,carburant,prixparjour,etat);
//debut controle saisie
  int verif=0;

    if ((idv<0)||(idv>100))
     verif=1; int err=0;
    if ((verif==1))
        {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                       QObject::tr("identifier du voiture dit etre entre 1 et 100 "
                                   ), QMessageBox::Cancel);
        err++ ;
     }
    //-----------------------------------------------------------//
    verif=0;

      if ((idcategorie<0)||(idcategorie>5))
       verif=1;
      if ((verif==1))
          {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                         QObject::tr("identifier du caategorie doit etre entre 0 et 5  "
                                     ), QMessageBox::Cancel);
          err++ ;
       }
      //-----------------------------------------------------------//
      verif=0;

        if ((nbplaces<2)||(nbplaces>9))
         verif=1;
        if (verif==1)
            {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                           QObject::tr("nombre de places du voiture doit etre entre 2 et 9"
                                       ), QMessageBox::Cancel);
            err++ ;
         }
     verif=0;
     for(int i=0;i<marque.length();i++)
         if (((marque[i]<"a")||(marque[i]>"z"))&&((marque[i]<"A")||(marque[i]>"Z"))&&(marque[i]!=" ")&&((marque[i]<"0")||(marque[i]>"9")))
             verif=1;

    if ((verif==1)||(marque.length()>20)||(marque[0]==" ")||(marque[marque.length()]==" "))
       { {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                       QObject::tr("La marque doit  etre une chaine de caractere "
                                   ), QMessageBox::Cancel); }
    err++ ;
    }
    //-----------------------------------------------------------//
    verif=0;
    for(int i=0;i<couleur.length();i++)
        if (((couleur[i]<"a")||(couleur[i]>"z"))&&((couleur[i]<"A")||(couleur[i]>"Z"))&&(couleur[i]!=" "))
            verif=1;

   if ((verif==1)||(couleur.length()>20)||(couleur[0]==" ")||(couleur[couleur.length()]==" "))
      { {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                      QObject::tr("couleur doit etre une chaine de caractere "
                                  ), QMessageBox::Cancel); }
   err++ ;
   }
   //-----------------------------------------------------------//
   verif=0;

       if ((carburant != "essence")&&(carburant != "gasoil")&&(carburant != "gaz"))
           verif=1;

  if ((verif==1)||(marque.length()>20)||(marque[0]==" ")||(marque[marque.length()]==" "))
     { {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                     QObject::tr("carburant doit etre essence ou gasoil ou gaz"
                                 ), QMessageBox::Cancel); }
  err++ ;
  }
  //-----------------------------------------------------------//

    verif=0;
    if ((prixparjour<40)||(prixparjour>250))
     verif=1;
    if ((verif==1))
        {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                       QObject::tr("le prix par jour et entre 40 dt et 250 dt "
                                   ), QMessageBox::Cancel);
        err++ ;
     }
   //-----------------------------------------------------------//
      if (err==0)
        { bool test=e.ajouter();
          if(test)
        {ui->tableView2->setModel(tmpvoiture.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter un voiture"),
                          QObject::tr("voiture ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

        }
          else
              QMessageBox::critical(nullptr, QObject::tr("Ajouter un voiture"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        }
    //-----------------------------------------------------------//
//fin controle saisie
    ui->tableView2->setModel(tmpvoiture.afficher());//refresh
}

//********************************************************************************************

/*void MainWindow::on_ajouter_clicked()
{
    int idv = ui->lineEdit_idv->text().toInt();
    QString marque= ui->lineEdit_marque->text();
    QString matricule= ui->lineEdit_matricule->text();
    int idcategorie=ui->lineEdit_idcategorie->text().toInt();
    int nbplaces=ui->lineEdit_nbplaces->text().toInt();
    int anciennete=ui->lineEdit_anciennete->text().toInt();
    QString couleur=ui->lineEdit_couleur->text();
    int kilometrage=ui->lineEdit_kilometrage->text().toInt();
    QString carburant=ui->lineEdit_carburant->text();
    int prixparjour=ui->lineEdit_prixparjour->text().toInt();
    QString etat=ui->combo->currentText();
  voiture e(idv,marque,matricule,idcategorie,nbplaces,anciennete,couleur,kilometrage,carburant,prixparjour,etat);
  bool test=e.ajouter();
  if(test)
{ui->tableView2->setModel(tmpvoiture.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un voiture"),
                  QObject::tr("voiture ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un voiture"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}*/


void MainWindow::on_supprimer_clicked()
{
int id = ui->lineEdit_idv->text().toInt();
bool test=tmpvoiture.supprimer(id);
if(test)
{ui->tableView2->setModel(tmpvoiture.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer une voiture"),
                QObject::tr("voiture supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une voiture"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_modifier_clicked()
{
    int idv = ui->lineEdit_idv->text().toInt();
    QString marque= ui->lineEdit_marque->text();
    QString matricule= ui->lineEdit_matricule->text();
    int idcategorie=ui->lineEdit_idcategorie->text().toInt();
    int nbplaces=ui->lineEdit_nbplaces->text().toInt();
    int anciennete=ui->lineEdit_anciennete->text().toInt();
    QString couleur=ui->lineEdit_couleur->text();
    int kilometrage=ui->lineEdit_kilometrage->text().toInt();
    QString carburant=ui->lineEdit_carburant->text();
    int prixparjour=ui->lineEdit_prixparjour->text().toInt();
    QString etat=ui->combo->currentText();
    voiture e(idv,marque,matricule,idcategorie,nbplaces,anciennete,couleur,kilometrage,carburant,prixparjour,etat);
    bool test=e.modifier();
  if(test)
{ui->tableView2->setModel(tmpvoiture.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier une voiture"),
                  QObject::tr("voiture modifier.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un voiture"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);



}

void MainWindow::on_trie_clicked()
{


   ui->tableView2->setModel(tmpvoiture.trie());//refresh


}


// categorieee



void MainWindow::on_ajouter_categorie_clicked()
{
    int id = ui->lineEdit_idc->text().toInt();
    QString type= ui->lineEdit_type->text();
    int nbvoitures =ui->lineEdit_nbvoitures->text().toInt();

  categorie e(id,type,nbvoitures);
  bool test=e.ajouter();
  if(test)
{ui->tableView->setModel(tmpcategorie.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un categorie"),
                  QObject::tr("categorie ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un categorie"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_supprimer_categorie_clicked()
{
int id = ui->lineEdit_idc->text().toInt();
bool test=tmpcategorie.supprimer(id);
if(test)
{ui->tableView->setModel(tmpcategorie.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer une categorie"),
                QObject::tr("categorie supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une categorie"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_modifier_categorie_clicked()
{
    int id = ui->lineEdit_idc->text().toInt();
    QString type= ui->lineEdit_type->text();
    int nbvoitures=ui->lineEdit_nbvoitures->text().toInt();
    categorie e(id,type,nbvoitures);
    bool test=e.modifier();
  if(test)
{ui->tableView->setModel(tmpcategorie.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier une categorie"),
                  QObject::tr("categorie modifier.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un categorie"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);



}

void MainWindow::on_trie_categorie_clicked()
{


   ui->tableView->setModel(tmpcategorie.trie());//refresh


}



void MainWindow::on_recherche_clicked()
{

   QString x = ui->lineEdit_16->text();
   ui->tableView2->setModel(tmpvoiture.recherche(x));//refresh


}













void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    ui->lineEdit_idc->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toString());
    ui->lineEdit_type->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),1)).toString());
    ui->lineEdit_nbvoitures->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),2)).toString());
}

void MainWindow::on_tableView2_doubleClicked(const QModelIndex &index)
{
    ui->lineEdit_idv->setText(ui->tableView2->model()->data(ui->tableView2->model()->index(ui->tableView2->currentIndex().row(),0)).toString());
    ui->lineEdit_marque->setText(ui->tableView2->model()->data(ui->tableView2->model()->index(ui->tableView2->currentIndex().row(),1)).toString());
    ui->lineEdit_matricule->setText(ui->tableView2->model()->data(ui->tableView2->model()->index(ui->tableView2->currentIndex().row(),2)).toString());
    ui->lineEdit_idcategorie->setText(ui->tableView2->model()->data(ui->tableView2->model()->index(ui->tableView2->currentIndex().row(),3)).toString());
    ui->lineEdit_nbplaces->setText(ui->tableView2->model()->data(ui->tableView2->model()->index(ui->tableView2->currentIndex().row(),4)).toString());
    ui->lineEdit_anciennete->setText(ui->tableView2->model()->data(ui->tableView2->model()->index(ui->tableView2->currentIndex().row(),5)).toString());
    ui->lineEdit_couleur->setText(ui->tableView2->model()->data(ui->tableView2->model()->index(ui->tableView2->currentIndex().row(),6)).toString());
    ui->lineEdit_kilometrage->setText(ui->tableView2->model()->data(ui->tableView2->model()->index(ui->tableView2->currentIndex().row(),7)).toString());
    ui->lineEdit_carburant->setText(ui->tableView2->model()->data(ui->tableView2->model()->index(ui->tableView2->currentIndex().row(),8)).toString());
    ui->lineEdit_prixparjour->setText(ui->tableView2->model()->data(ui->tableView2->model()->index(ui->tableView2->currentIndex().row(),9)).toString());
    ui->lineEdit->setText(ui->tableView2->model()->data(ui->tableView2->model()->index(ui->tableView2->currentIndex().row(),0)).toString());
}



void MainWindow::on_pushButton_3_clicked()
{
   QString num1 = ui->lineEdit->text();
    int num = ui->lineEdit->text().toInt();

    QSqlQuery query1;
   QString idv="";
   QString matricule="";
    QString marque="";
   QString   idcategorie="";
   QString   nbplaces="";
   QString   anciennete="";
   QString couleur="";
   QString   kilometrage="";
   QString  carburant="";
   QString  prixparjour="";
   QString  etat="";
    if(num1!=""){
    query1.prepare("select * from voiture where IDV=:idv");
   query1.bindValue(":idv", num);

    if (query1.exec())
    {

        while (query1.next()) {

             idv = query1.value(0).toString();
             matricule = query1.value(1).toString();
             marque = query1.value(2).toString();
             idcategorie = query1.value(3).toString();
             nbplaces= query1.value(4).toString();
             anciennete = query1.value(5).toString();
             couleur = query1.value(6).toString();
             kilometrage= query1.value(7).toString();
             carburant = query1.value(8).toString();
             prixparjour = query1.value(9).toString();
             etat = query1.value(10).toString();

        }
    }
          QPrinter printer(QPrinter::HighResolution);
              printer.setPageSize(QPrinter::A4);

             QPrintDialog *dialog = new QPrintDialog(&printer);
              if (dialog->exec() == QDialog::Accepted)
              {               QPainter painter (&printer);
                              painter.begin(&printer);
                              QFont f;
                               f.setPointSize(20);
                               f.setBold(true);
                               painter.setFont(f);
                               painter.drawText(100, 500, " la fiche du voiture,num°:");
                               painter.drawText(2000, 520, idv);
                               f.setPointSize(15);
                               f.setBold(true);
                               painter.setFont(f);
                               painter.drawText(100, 1000, "maruqe :");
                               painter.drawText(1000, 1000, marque);
                               painter.drawText(100, 1200, "matricule :");
                               painter.drawText(1200, 1200, matricule);
                               painter.drawText(100, 1400, "id categorie :");
                               painter.drawText(1500, 1400, idcategorie);
                               painter.drawText(100, 1600, "nbplaces :");
                               painter.drawText(1500, 1600, nbplaces);
                               painter.drawText(100, 1800, "annciennete :");
                               painter.drawText(1500, 1800, anciennete);
                               painter.drawText(100, 2000, "couleur :");
                               painter.drawText(1500, 2000, couleur);
                               painter.drawText(100, 2200, "kilometrage :");
                               painter.drawText(1500, 2200, kilometrage);
                               painter.drawText(100, 2400, "carburant :");
                               painter.drawText(1500, 2400, carburant);
                               painter.drawText(100, 2600, "prix par jour :");
                               painter.drawText(1500, 2600, prixparjour);

                              painter.end();

              }}
    else
        QMessageBox::critical(nullptr, QObject::tr("Imprimer une reservation"),
                    QObject::tr("Erreur !.\n"
                                "Veuillez selectionner une reservation à imprimer .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}









void MainWindow::on_stat_clicked()
{
    //![1]
        QBarSet *set0 = new QBarSet("Fiat palio");
        QBarSet *set1 = new QBarSet("Mercedes");
        QBarSet *set2 = new QBarSet("Fiat sienna");
        QBarSet *set3 = new QBarSet("citroen c5");
        QBarSet *set4 = new QBarSet("bmw serie 4");

        *set0 << 1 << 2 << 3 << 4 << 5 << 6;
        *set1 << 5 << 0 << 0 << 4 << 0 << 7;
        *set2 << 3 << 5 << 8 << 13 << 8 << 5;
        *set3 << 5 << 6 << 7 << 3 << 4 << 5;
        *set4 << 9 << 7 << 5 << 3 << 1 << 2;
    //![1]

    //![2]
        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);
        series->append(set4);

    //![2]

    //![3]
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Simple barchart example");
        chart->setAnimationOptions(QChart::SeriesAnimations);
    //![3]

    //![4]
        QStringList categories;
        categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axis, series);
    //![4]

    //![5]
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
    //![5]

    //![6]
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
    //![6]

    //![7]
        ch= new MainWindow (this);
        ch->setCentralWidget(chartView);
        ch->resize(420, 300);
        ch->show();
    //![7]
}
