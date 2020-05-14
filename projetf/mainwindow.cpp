#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPrinter>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QMessageBox>
#include<smtp.h>

#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include"QSortFilterProxyModel"
QT_CHARTS_USE_NAMESPACE
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->data2->setModel(tmpcontrat.afficher());//refresh
     ui->tabclient->setModel(tmpclient.afficher());//refresh
     ui->dated->setDate(QDate::currentDate()); //teb3a wissem
     ui->datef->setDate(QDate::currentDate()); //teb3a wissem
     ui->cincontrat->setModel(tmpfid.setcombobox());//refresh
     ui->cinC->setModel(tmpfid.setcombobox());//refresh
     ui->data->setModel(tmpreclamation.afficher());

    ui->tabevenement->setModel(tmpevenement.afficherE());
    ui->tabpromotion->setModel(tmppromotion.afficherP());
     ui->tabfidelite->setModel(tmpfid.afficher());//refresh
     ui->cinf->setModel(tmpfid.setcombobox());//refresh
     ui->comboBox_2->setModel(tmpreclamation.setcombobox());//refresh


     QFile File("C:\\Users\\wissem\\Desktop\\project\\projet_qt\\projetwissem\\style.css");
      File.open(QFile::ReadOnly);
      QString StyleSheet = QLatin1String(File.readAll());
     this->setStyleSheet(StyleSheet);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->tabclient->setModel(tmpclient.afficher());//refresh

}



void MainWindow::on_tabclient_activated(const QModelIndex &index)
{

}

void MainWindow::on_tabclient_clicked(const QModelIndex &index)
{
    ui->lineEditcin->setText(ui->tabclient->model()->data(ui->tabclient->model()->index(ui->tabclient->currentIndex().row(),0)).toString());
    ui->lineEditnom->setText(ui->tabclient->model()->data(ui->tabclient->model()->index(ui->tabclient->currentIndex().row(),2)).toString());
    ui->lineEditprenom->setText(ui->tabclient->model()->data(ui->tabclient->model()->index(ui->tabclient->currentIndex().row(),1)).toString());
    ui->lineEdittel->setText(ui->tabclient->model()->data(ui->tabclient->model()->index(ui->tabclient->currentIndex().row(),4)).toString());
    ui->lineEditage->setText(ui->tabclient->model()->data(ui->tabclient->model()->index(ui->tabclient->currentIndex().row(),3)).toString());
    ui->lineEditemail->setText(ui->tabclient->model()->data(ui->tabclient->model()->index(ui->tabclient->currentIndex().row(),5)).toString());
    ui->lineEditcin->setDisabled(1);






}



void MainWindow::on_lineEditrecherche_textChanged(const QString &arg1)
{      QString prenom= ui->lineEditrecherche->text();

    ui->tabclient->setModel(tmpclient.chercher(prenom));//recherche
    ui->comboBox->setCurrentText("--");
}



void MainWindow::on_comboBox_currentIndexChanged(int index)
{

        ui->lineEditrecherche->setText("");
        ui->tabclient->setModel(tmpclient.tri(index));//refresh



}


void MainWindow::on_comboBox_activated(int index)
{

}

void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



//*************** khedmet ilyes

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







void MainWindow::on_voituree_clicked()
{
    ui->stackedWidget22->setCurrentIndex(0);
}

void MainWindow::on_categoriee_clicked()
{
    ui->stackedWidget22->setCurrentIndex(1);
}


void MainWindow::on_imprimerr_clicked()
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

}


void MainWindow::on_commandLinkButton_4_clicked()
{   QString email ;
    QString cin= ui->cinf->currentText();
    int valeur= ui->valeurfid->text().toInt();
    QDate dated= ui->dated->date();
    QDate datef= ui->datef->date();
client cl(cin,"","","",0,"");
    fidelite f(cin,valeur,dated,datef);
    f.ajouter();
   email=f.send(cin);
   Smtp* mtp = new Smtp("testwissem11@gmail.com", "wissem123", "smtp.gmail.com", 465);

               connect(mtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
            QString corps="Vous avez reçu "+ui->valeurfid->text()+"Dt comme solde de fidélité valable jusqu'a "+datef.toString("yyyy/MM/dd")+"\n merci pour votre confiance";
           mtp->sendMail("nachts554@gmail.com", email , "Solde fidélité" ,corps);
    ui->tabfidelite->setModel(tmpfid.afficher());//refresh
    ui->cinf->setModel(tmpfid.setcombobox());//refresh




}

void MainWindow::on_tabfidelite_clicked(const QModelIndex &index)
{
    ui->idfid->setText(ui->tabfidelite->model()->data(ui->tabfidelite->model()->index(ui->tabfidelite->currentIndex().row(),0)).toString());
    ui->cinf->setCurrentText(ui->tabfidelite->model()->data(ui->tabfidelite->model()->index(ui->tabfidelite->currentIndex().row(),1)).toString());
    ui->valeurfid->setText(ui->tabfidelite->model()->data(ui->tabfidelite->model()->index(ui->tabfidelite->currentIndex().row(),2)).toString());
    ui->dated->setDate(ui->tabfidelite->model()->data(ui->tabfidelite->model()->index(ui->tabfidelite->currentIndex().row(),3)).toDate());
    ui->datef->setDate(ui->tabfidelite->model()->data(ui->tabfidelite->model()->index(ui->tabfidelite->currentIndex().row(),4)).toDate());



}

void MainWindow::on_lineEditrecherchef_textChanged(const QString &arg1)
{
    QString cin= ui->lineEditrecherchef->text();

        ui->tabfidelite->setModel(tmpfid.chercher(cin));//recherche
        ui->comboBoxf->setCurrentText("--");
}

void MainWindow::on_commandLinkButton_5_clicked()
{
    fidelite f;
         QString id= ui->idfid->text();
         f.supprimer(id);
         ui->tabfidelite->setModel(tmpfid.afficher());//refresh
         ui->idfid->setText("");
         ui->valeurfid->setText("");
         ui->cinf->setCurrentIndex(0);
         ui->dated->setDate(QDate::currentDate());
         ui->datef->setDate(QDate::currentDate());

}

void MainWindow::on_supprimerclient_clicked()
{
    client cl;
        QString cin= ui->lineEditcin->text();
        cl.supprimer(cin);
        ui->tabclient->setModel(tmpclient.afficher());//refresh
       ui->lineEditcin->setText("");
       ui->lineEditnom->setText("");
       ui->lineEditprenom->setText("");
       ui->lineEdittel->setText("");
       ui->lineEditage->setText("");
       ui->lineEditemail->setText("");
       ui->lineEditcin->setEnabled(1);
}

void MainWindow::on_ajouterclient_clicked()
{
    QString cin= ui->lineEditcin->text();
    QString email= ui->lineEditemail->text();
    QString nom= ui->lineEditnom->text();
    QString prenom= ui->lineEditprenom->text();
    QString tel= ui->lineEdittel->text();
    int age = ui->lineEditage->text().toInt();
    QString agea = ui->lineEditage->text();

client cl(cin,nom,prenom,tel,age,email) ;
//debut controle saisie
  int verif=0;
   for (int i=0;i<cin.length();i++)
    if ((cin[i]<"0")||(cin[i]>"9"))
     verif=1; int err=0;
    if ((verif==1)||(cin.length()!=8))
        {
                       ui->labelcin->setText("Num de Cin invalide");

        err++ ;
     }
    else{
        ui->labelcin->setText("");

    }
    //-----------------------------------------------------------//
    verif=0;
     for (int i=0;i<tel.length();i++)
      if ((tel[i]<"0")||(tel[i]>"9"))
       verif=1;
      if ((verif==1)||(tel.length()!=8))
          {
                         ui->labeltel->setText("Num de Tel invalide ");

          err++ ;
       }
      else
      {
           ui->labeltel->setText("");
      }
      //-----------------------------------------------------------//
      verif=0;
       for (int i=0;i<agea.length();i++)
        if ((agea[i]<"0")||(agea[i]>"9"))
         verif=1;
        if ((verif==1)||(age<18))
            {
                           ui->labelage->setText("age invalide ");

            err++ ;
         }
        else {
            ui->labelage->setText("");

        }
            //-----------------------------------------------------------//
     verif=0;
     for(int i=0;i<nom.length();i++)
         if (((nom[i]<"a")||(nom[i]>"z"))&&((nom[i]<"A")||(nom[i]>"Z"))&&(nom[i]!=" "))
             verif=1;

    if ((verif==1)||(nom.length()<3)||(nom.length()>20)||(nom[0]==" ")||(nom[nom.length()]==" "))
       {
                       ui->labelprenom->setText("prenom invalide");
    err++ ;
    }
    else {
        ui->labelprenom->setText("");

    }
    //-----------------------------------------------------------//
    verif=0;
    for(int i=0;i<prenom.length();i++)
        if (((prenom[i]<"a")||(prenom[i]>"z"))&&((prenom[i]<"A")||(prenom[i]>"Z"))&&(prenom[i]!=" "))
            verif=1;

    if ((verif==1)||(prenom.length()<3)||(prenom.length()>20)||(prenom[0]==" ")||(prenom[prenom.length()]==" "))
       {
                       ui->labelnom->setText("nom invalide");
    err++ ;
    }
    else {
        ui->labelnom->setText("");

    }
   //-----------------------------------------------------------//
      if (err==0)
        {bool test=cl.ajouter();
        if (!(test))
        {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                           QObject::tr("CIN deja existant \n"), QMessageBox::Cancel);}
        else
        {Smtp* smtp = new Smtp("testwissem11@gmail.com", "wissem123", "smtp.gmail.com", 465);

            connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
            QString corps="cher(e) "+nom+" "+prenom+" \n Bienvenue chez smart rent car \n merci pour votre inscription";

        smtp->sendMail("nachts554@gmail.com", email , "Bienvenue chez SRC" ,corps);
        ui->lineEditcin->setText("");
        ui->lineEditnom->setText("");
        ui->lineEditprenom->setText("");
        ui->lineEdittel->setText("");
        ui->lineEditage->setText("");
        ui->lineEditemail->setText("");}
      }
    //-----------------------------------------------------------//
//fin controle saisie
    ui->tabclient->setModel(tmpclient.afficher());//refresh
}

void MainWindow::on_modifierclient_clicked()
{
    QString cin= ui->lineEditcin->text();
    QString prenom= ui->lineEditnom->text();
    QString nom= ui->lineEditprenom->text();
    QString tel= ui->lineEdittel->text();
    QString email= ui->lineEditemail->text();
    int age = ui->lineEditage->text().toInt();
    client cl(cin,nom,prenom,tel,age,email) ;



    bool test=cl.modifier();
    ui->lineEditcin->setText("");
    ui->lineEditnom->setText("");
    ui->lineEditprenom->setText("");
    ui->lineEdittel->setText("");
    ui->lineEditage->setText("");
    ui->lineEditemail->setText("");
    ui->lineEditcin->setEnabled(1);

    ui->tabclient->setModel(tmpclient.afficher());//refresh
}

void MainWindow::on_ajouterfid_clicked()
{    int err=0 ;
    QString email ;
        QString cin= ui->cinf->currentText();
        int valeur= ui->valeurfid->text().toInt();
        QDate dated= ui->dated->date();
        QDate datef= ui->datef->date();
        QDate te ;
    client cl(cin,"","","",0,"");
        fidelite f(cin,valeur,dated,datef);
        if ((valeur<0)||(ui->valeurfid->text()==""))
            {
                           ui->labelvaleur->setText("valeur invalide");

            err++ ;
         }
        else{
            ui->labelvaleur->setText("");

        }
         if ((dated< QDate::currentDate()))
             {
                            ui->labeldated->setText("date invalide");

             err++ ;
          }
         else{
             ui->labeldated->setText("");

         }
        if ((dated>=datef))
            {
                           ui->labeldatef->setText("date invalide");

            err++ ;
         }
        else{
            ui->labeldatef->setText("");

        }


        if(err==0)
        {
        f.ajouter();
       email=f.send(cin);
       Smtp* mtp = new Smtp("testwissem11@gmail.com", "wissem123", "smtp.gmail.com", 465);

                   connect(mtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
                QString corps="Vous avez reçu "+ui->valeurfid->text()+"Dt comme solde de fidélité valable jusqu'a "+datef.toString("yyyy/MM/dd")+"\n merci pour votre confiance";
               mtp->sendMail("nachts554@gmail.com", email , "Solde fidélité" ,corps);
        ui->tabfidelite->setModel(tmpfid.afficher());//refresh
        ui->cinf->setModel(tmpfid.setcombobox());//refresh
}
        }

void MainWindow::on_checkBox_clicked()
{

}

void MainWindow::on_AJOUTERC_2_clicked()
{QString cin= ui->cincontrat->currentText();
    contrat tmp(cin,ui->DATEDEBUT->date(),ui->DATEFIN->date(),ui->IDC->text().toInt(),ui->MONTANT->text().toInt(),ui->QUOTIENT->text().toInt(),ui->IDV_3->text().toInt(),ui->NUM->text().toInt());
    if(tmp.ajouter())
    {
        QSqlQueryModel * model22= new QSqlQueryModel();
            model22->setQuery("select * from CONTRAT where REC='0' ");
            ui->comboBox->clear();
            for(int c=0;c<model22->rowCount();c++)
                {
                    ui->comboBox->addItem(model22->data(model22->index(c,3)).toString());
                }

        ui->data2->setModel(tmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajouter un contrat"),
                          QObject::tr("contrat ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un contrat"),
                          QObject::tr("error contrat non ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->comboBox_2->setModel(tmpreclamation.setcombobox());//refresh
    ui->data2->setModel(tmpcontrat.afficher());//refresh
}

void MainWindow::on_modifierc_2_clicked()
{   QString cin= ui->cincontrat->currentText();
    contrat tmp(cin,ui->DATEDEBUT->date(),ui->DATEFIN->date(),ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),3)).toInt(),ui->MONTANT->text().toInt(),ui->QUOTIENT->text().toInt(),ui->IDV_3->text().toInt(),ui->NUM->text().toInt());
    if(tmp.modifier())
    {
        ui->data2->setModel(tmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("modifier un contrat"),
                          QObject::tr("contrat modifié.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("modifier un contrat"),
                          QObject::tr("error contrat non modifié.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->data2->setModel(tmpcontrat.afficher());//refresh
}

void MainWindow::on_data2_clicked(const QModelIndex &index)
{
    ui->cincontrat->setCurrentText(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),0)).toString());
    ui->DATEDEBUT->setDate(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),1)).toDate());
    ui->DATEFIN->setDate(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),2)).toDate());
    ui->IDC->setText(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),3)).toString());
    ui->MONTANT->setText(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),4)).toString());
    ui->QUOTIENT->setText(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),5)).toString());
    ui->IDV_3->setText(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),6)).toString());
    ui->NUM->setText(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),7)).toString());
}

void MainWindow::on_Supprimerc_2_clicked()
{
    contrat tmp;
    if(tmp.supprimer(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),3)).toInt()))
    {
        ui->data2->setModel(tmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("supprimé une contrat"),
                          QObject::tr("contrat supprimé.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("supprimé une contrat"),
                          QObject::tr("error contrat non supprimé.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
       ui->data2->setModel(tmpcontrat.afficher());//refresh
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_searchc_textChanged(const QString &arg1)
{


    ui->data2->setModel(tmpcontrat.recherche(ui->searchc->text()));
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_ajouter_2_clicked()
{
      QString cin= ui->cincontrat->currentText();
    reclamation tmp(ui->ID->text().toInt(),ui->DESC->text(),cin,ui->IDV->text().toInt(),ui->CINE->text().toInt());
    if(tmp.ajouter())
    {
        QSqlQuery query;
        QString bg=ui->comboBox_2->currentText();
        query.prepare("update CONTRAT set REC='1' where IDC= '"+bg+"' ");
        query.exec();
        QSqlQueryModel * model22= new QSqlQueryModel();
            model22->setQuery("select * from CONTRAT where REC='0' ");
             ui->comboBox_2->clear();
            for(int c=0;c<model22->rowCount();c++)
                {
                    ui->comboBox_2->addItem(model22->data(model22->index(c,3)).toString());
                }
            QSqlQueryModel *model=tmp.afficher();
             QSortFilterProxyModel *proxy=new QSortFilterProxyModel(this);
                    proxy->setDynamicSortFilter(true);
                    proxy->setSourceModel(model);
                    ui->data->setModel(proxy);
                    ui->data->setSortingEnabled(true);

       // ui->data->setModel(tmp.afficher());
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

void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidgetM->setCurrentIndex(0);

}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidgetM->setCurrentIndex(1);

}

void MainWindow::on_pb_ajouterE_clicked()
{
    int idE = ui->lineEdit_idE->text().toInt();
    QString typeEvent= ui->comboBoxE->currentText();
    QString desc= ui->description->text();
    QString date_event=ui->dateEdit_event->date().toString("dd/MM/yyyy");

  evenement e(idE,typeEvent, desc, date_event);


    int verif=0;

      if ((idE<0)||(idE>100000))
       verif=1; int err=0;
      if (verif==1)
          {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                         QObject::tr("id invalide il faut qu'il comporte 5 chiffre et qu'il soit positive "
                                     ), QMessageBox::Cancel);
          err++ ;
       }


    // ******************************************************************* //
   if (err==0)
           {bool test=e.ajouterE();
           if (!(test))
           {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                              QObject::tr("id existant \n"), QMessageBox::Cancel);}
           else
           {QMessageBox::critical(nullptr, QObject::tr("promotion ajouté"),
                                  QObject::tr("promotion ajouté\n"), QMessageBox::Cancel);
           }
               ui->tabevenement->setModel(tmpevenement.afficherE());
         }
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

void MainWindow::on_comboBoxE_2_currentIndexChanged(int index)
{
    ui->tabevenement ->setModel(tmpevenement.triE(index));
}

void MainWindow::on_pb_rechercherE_clicked()
{
    QString event= ui->dateEdit_Recherche->date().toString("dd/MM/yyyy");
       ui->tabevenement->setModel(tmpevenement.rechercherE(event));
}

void MainWindow::on_pb_count_clicked()
{
    ui->tableViewcount->setModel(tmpevenement.countE());

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

//controle de saisie
  int verif=0;

    if ((id<0)||(id>100000))
     verif=1; int err=0;
    if (verif==1)
        {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                       QObject::tr("id invalide il faut qu'il comporte 5 chiffre et qu'il soit positive "
                                   ), QMessageBox::Cancel);
        err++ ;
     }

 // ****************************************************************** //
    if (pourc == 0)
     verif=1;
    if (verif==1)
        {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                       QObject::tr("pourcentage est nul "
                                   ), QMessageBox::Cancel);
        err++ ;
     }
   // ****************************************************************** //

    QDate DateF = QDate::fromString(dateFin,"dd/MM/yyyy");
    QDate DateD = QDate::fromString(dateDebut,"dd/MM/yyyy");

    if ((DateD.year()>=DateF.year())&(DateD.month()>=DateF.month())&(DateD.day()>=DateF.day()))
          verif=1;
    if (verif==1)
        {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                   QObject::tr("la date de début est sup a a date de fin"
                               ), QMessageBox::Cancel);
        err++ ; }



  // ****************************************************************** //
    if (err==0)
           {bool test=p.ajouterP();
           if (!(test))
           {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                              QObject::tr("id existant \n"), QMessageBox::Cancel);}
           else
           {QMessageBox::critical(nullptr, QObject::tr("promotion ajouté"),
                                  QObject::tr("promotion ajouté\n"), QMessageBox::Cancel);
           }
               ui->tabpromotion->setModel(tmppromotion.afficherP());
         }
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

void MainWindow::on_comboBoxP_currentIndexChanged(int index)
{
    ui->tabpromotion ->setModel(tmppromotion.triP(index));
}

void MainWindow::on_pb_rechercherP_clicked()
{
    QString type = ui->lineEdit_RP->text();
    ui->tabpromotion->setModel(tmppromotion.rechercherP(type));
}

void MainWindow::on_tabpromotion_clicked(const QModelIndex &index)
{
    ui->lineEdit_id->setText(ui->tabpromotion->model()->data(ui->tabpromotion->model()->index(ui->tabpromotion->currentIndex().row(),0)).toString());
    ui->typeV->setText(ui->tabpromotion->model()->data(ui->tabpromotion->model()->index(ui->tabpromotion->currentIndex().row(),2)).toString());
    ui->nbvoiture->setValue(ui->tabpromotion->model()->data(ui->tabpromotion->model()->index(ui->tabpromotion->currentIndex().row(),1)).toInt());
    ui->pourc->setValue(ui->tabpromotion->model()->data(ui->tabpromotion->model()->index(ui->tabpromotion->currentIndex().row(),4)).toInt());
    ui->dateEdit_debut->setDate(ui->tabpromotion->model()->data(ui->tabpromotion->model()->index(ui->tabpromotion->currentIndex().row(),5)).toDate());
    ui->dateEdit_fin->setDate(ui->tabpromotion->model()->data(ui->tabpromotion->model()->index(ui->tabpromotion->currentIndex().row(),6)).toDate());
}

void MainWindow::on_supprimerfid_clicked()
{
    fidelite f;
         QString id= ui->idfid->text();
         f.supprimer(id);
         ui->tabfidelite->setModel(tmpfid.afficher());//refresh
         ui->idfid->setText("");
         ui->valeurfid->setText("");
         ui->cinf->setCurrentIndex(0);
         ui->dated->setDate(QDate::currentDate());
         ui->datef->setDate(QDate::currentDate());
}

void MainWindow::on_statsclient_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from client where age < 40 ");
        float age=model->rowCount();
        model->setQuery("select * from client where age between 40 and 60 ");
        float agee=model->rowCount();
        model->setQuery("select * from client where age>60 ");
        float ageee=model->rowCount();

        float total=age+agee+ageee;
        QString a=QString("moins de 40 "+QString::number((age*100)/total,'f',2)+"%" );
        QString b=QString("entre 40 et 60 "+QString::number((agee*100)/total,'f',2)+"%" );
        QString c=QString("+60ans "+QString::number((ageee*100)/total,'f',2)+"%" );
        QPieSeries *series = new QPieSeries();

        series->append(a,age);
        series->append(b,agee);
         series->append(c,ageee);
if (age!=0)
{QPieSlice *slice = series->slices().at(0);
 slice->setLabelVisible();
 slice->setPen(QPen());}
if ( agee!=0)
{
         // Add label, explode and define brush for 2nd slice
         QPieSlice *slice1 = series->slices().at(1);
         //slice1->setExploded();
         slice1->setLabelVisible();
}
if(ageee!=0)
{

         // Add labels to rest of slices
         QPieSlice *slice2 = series->slices().at(2);
         //slice1->setExploded();
         slice2->setLabelVisible();

}

        // Create the chart widget
        QChart *chart = new QChart();

        // Add data to chart with title and hide legend
        chart->addSeries(series);
        chart->setTitle("Pourcentage Par age:totale de "+ QString::number(total));
        chart->legend()->hide();


        // Used to display the chart
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(1000,500);
        chartView->show();
}

void MainWindow::on_supprimer_2_clicked()
{
    if(tmpreclamation.supprimer(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),0)).toInt()))
    {
        QSqlQueryModel *model=tmpreclamation.afficher();
         QSortFilterProxyModel *proxy=new QSortFilterProxyModel(this);
                proxy->setDynamicSortFilter(true);
                proxy->setSourceModel(model);
                ui->data->setModel(proxy);
                ui->data->setSortingEnabled(true);
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

void MainWindow::on_modifier_2_clicked()
{  QString cin= ui->cincontrat->currentText();
    reclamation tmp(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),0)).toInt(),ui->DESC->text(),cin,ui->IDV->text().toInt(),ui->CINE->text().toInt());
    if(tmp.modifier())
    {
        QSqlQueryModel *model=tmp.afficher();
         QSortFilterProxyModel *proxy=new QSortFilterProxyModel(this);
                proxy->setDynamicSortFilter(true);
                proxy->setSourceModel(model);
                ui->data->setModel(proxy);
                ui->data->setSortingEnabled(true);
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

void MainWindow::on_data_clicked(const QModelIndex &index)
{
    ui->ID->setText(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),0)).toString());
    ui->DESC->setText(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),1)).toString());
    ui->cinC->setCurrentText(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),2)).toString());
    ui->IDV->setText(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),3)).toString());
    ui->CINE->setText(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),4)).toString());

}

void MainWindow::on_tribox_currentTextChanged(const QString &arg1)
{
    QString cls=ui->tribox->currentText();
    reclamation tmp;
    ui->data->setModel(tmp.triez(cls));
}

void MainWindow::on_search_textChanged(const QString &arg1)
{
    reclamation tmp;

    QSqlQueryModel *model=tmp.recherche(ui->search->text());
     QSortFilterProxyModel *proxy=new QSortFilterProxyModel(this);
            proxy->setDynamicSortFilter(true);
            proxy->setSourceModel(model);
            ui->data->setModel(proxy);
            ui->data->setSortingEnabled(true);
}

void MainWindow::on_pushButton_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from CONTRAT where REC ='1' ");
        float nonsatisfe=model->rowCount();
        model->setQuery("select * from CONTRAT where REC ='0' ");
        float satisfe=model->rowCount();


        float total=satisfe+nonsatisfe;
        QString s=QString("Satisfe"+QString::number((satisfe*100)/total, 'f',2)+"%" );
        QString ns=QString("Non Satisfe "+QString::number((nonsatisfe*100)/total, 'f',2)+"%" );
        QPieSeries *series = new QPieSeries();

        series->append(s,satisfe);
        series->append(ns,nonsatisfe);

        // Add label to 1st slice
        QPieSlice *slice0 = series->slices().at(0);
        slice0->setLabelVisible();

        // Add label, explode and define brush for 2nd slice
        QPieSlice *slice1 = series->slices().at(1);
        //slice1->setExploded();
        slice1->setLabelVisible();
        slice1->setPen(QPen(Qt::darkGreen, 2));
        slice1->setBrush(Qt::green);

        // Add labels to rest of slices

        // Create the chart widget
        QChart *chart = new QChart();

        // Add data to chart with title and hide legend
        chart->addSeries(series);
        chart->setTitle("Pourcentage Par Service ");
        chart->legend()->hide();


        // Used to display the chart
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(800,500);
        chartView->show();
}

void MainWindow::on_modifierfid_clicked()
{
    QString cin= ui->cinf->currentText();
    int valeur= ui->valeurfid->text().toInt();
    QDate dated= ui->dated->date();
    QDate datef= ui->datef->date();


  fidelite f(cin,valeur,dated,datef);

    bool test=f.modifier(ui->idfid->text());
    ui->tabfidelite->setModel(tmpfid.afficher());//refresh

}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (ui->checkBox->isChecked())
    {
        QFile File("C:\\Users\\wissem\\Desktop\\clone\\project\\projet_qt\\projetwissem\\sombre.css");
         File.open(QFile::ReadOnly);
         QString StyleSheet = QLatin1String(File.readAll());
        this->setStyleSheet(StyleSheet);
    }
    else
    {
        QFile File("C:\\Users\\wissem\\Desktop\\clone\\project\\projet_qt\\projetwissem\\style.css");
         File.open(QFile::ReadOnly);
         QString StyleSheet = QLatin1String(File.readAll());
        this->setStyleSheet(StyleSheet);

    }
}

void MainWindow::on_checkBox_2_clicked()
{
    if (ui->checkBox_2->isChecked())
        { ui->checkBox_3->setChecked(true);
        ui->checkBox->setChecked(true);
    }
        else
        {  ui->checkBox_3->setChecked(false);
            ui->checkBox->setChecked(false);

        }
}

void MainWindow::on_checkBox_3_clicked()
{
    if (ui->checkBox_3->isChecked())
        { ui->checkBox_2->setChecked(true);
        ui->checkBox->setChecked(true);
    }
        else
        {  ui->checkBox_2->setChecked(false);
            ui->checkBox->setChecked(false);

        }
}
