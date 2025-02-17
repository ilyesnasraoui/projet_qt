#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPrinter>
#include <QPrinter>
#include <QPainter>
#include <QPdfWriter>
#include <QPrintDialog>
#include <QMessageBox>
#include<smtp.h>
#include <QPixmap>
#include <QMovie>
#include<QProcess>

#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include"QSortFilterProxyModel"

#include "assurances.h"
#include <QMessageBox>
#include "smtp.h"
#include <QSystemTrayIcon>
#include <QDebug>
#include <QThread>


QT_CHARTS_USE_NAMESPACE
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
ui->authentification->setCurrentIndex(1);
    QPixmap bg("C:/Users/adem/Desktop/projet_progres/bg.jpg");
    ui->bg->setPixmap(bg.scaled(1600,1600));

            QFile File("C:\\Users\\wissem\\Desktop\\clone\\project\\projet_qt\\projetwissem\\style.css");
             File.open(QFile::ReadOnly);
             QString StyleSheet = QLatin1String(File.readAll());
            this->setStyleSheet(StyleSheet);
             QMovie *movie =new QMovie("C:/Users/wissem/Desktop/project/projet_qt/adam/projet_progres/thenya.gif");
             QMovie *moviee =new QMovie("C:/Users/wissem/Desktop/project/projet_qt/adam/projet_progres/welcome.gif");
             movie->setScaledSize(QSize().scaled(1411,1411,Qt::KeepAspectRatio));
             moviee->setScaledSize(QSize().scaled(400,400,Qt::KeepAspectRatio));
              ui->label_25->setMovie(movie);
              ui->label_25->setMovie(movie);
              ui->gifcategorie->setMovie(movie);
              ui->gifemploye->setMovie(movie);
              ui->label_2->setMovie(moviee);
              ui->gifmarketing->setMovie(movie);
             movie->start();
             moviee->start();



    ui->tableView->setModel(tmpcategorie.afficher());
    ui->tableView2->setModel(tmpvoiture.afficher());
    ui->calendarWidget->setHidden(true);
    ui->data2->setModel(tmpcontrat.afficher());//refresh
     ui->tabclient->setModel(tmpclient.afficher());//refresh
     ui->tabemployee_2->setModel(tmpdep.afficher());//refresh
     ui->dated->setDate(QDate::currentDate()); //teb3a wissem
     ui->datef->setDate(QDate::currentDate()); //teb3a wissem
     ui->cincontrat->setModel(tmpfid.setcombobox());//refresh
     ui->cinC->setModel(tmpfid.setcombobox());//refresh
     ui->data->setModel(tmpreclamation.afficher());
    ui->tabemployee->setModel(tmpemployee.afficher());//refresh
    ui->tabevenement->setModel(tmpevenement.afficherE());
    ui->tabpromotion->setModel(tmppromotion.afficherP());
     ui->tabfidelite->setModel(tmpfid.afficher());//refresh
     ui->cinf->setModel(tmpfid.setcombobox());//refresh
     ui->comboBox_2->setModel(tmpreclamation.setcombobox());//refresh
     ui->combov->setModel(tmpcontrat.setcomboboxv());
     ui->combov_2->setModel(tmpcontrat.setcomboboxv());
     ui->comboemp_2->setModel(tmpreclamation.setcomboemp_2());//refresh

     ui->combobbb3->setModel(tmpemployee.setcombobbb3());



     QPixmap pix4("C:/Users/wissem/Desktop/project/projet_qt/adam/projet_progres/logo.png");
     int w3 = ui->logo->width();
     int h3 = ui->logo->height();
      ui->logo->setPixmap(pix4.scaled(w3,h3));


      QPixmap pix5("C:/Users/wissem/Desktop/project/projet_qt/adam/projet_progres/logo.png");
      int w4 = ui->logo1->width();
      int h4 = ui->logo1->height();
       ui->logo1->setPixmap(pix5.scaled(w4,h4));


       QPixmap pix6("C:/Users/wissem/Desktop/project/projet_qt/adam/projet_progres/logo.png");
       int w8 = ui->logo2->width();
       int h8 = ui->logo2->height();
        ui->logo2->setPixmap(pix6.scaled(w8,h8));

        QPixmap pix7("C:/Users/wissem/Desktop/project/projet_qt/adam/projet_progres/logo.png");
        int w6 = ui->logo3->width();
        int h6 = ui->logo3->height();
         ui->logo3->setPixmap(pix7.scaled(w6,h6));


         QPixmap pix8("C:/Users/wissem/Desktop/project/projet_qt/adam/projet_progres/logo.png");
         int w7 = ui->logo4->width();
         int h7 = ui->logo4->height();
          ui->logo4->setPixmap(pix8.scaled(w7,h7));





     QPixmap devise1("C:/Users/wissem/Desktop/project/projet_qt/adam/projet_progres/tunisia.png");
     int w5 = ui->logo->width();
     int h5 = ui->logo->height();


    if(ui->checkBox_2->isChecked())
    {
       QMovie *movie =new QMovie("C:/Users/wissem/Desktop/project/projet_qt/adam/projet_progres/audiz.gif");
       movie->setScaledSize(QSize().scaled(1611,1600,Qt::KeepAspectRatio));
        ui->label_25->setMovie(movie);
        ui->label_25->setMovie(movie);
       movie->start();
   }
    else
    {
        QMovie *movie =new QMovie("C:/Users/wissem/Desktop/project/projet_qt/adam/projet_progres/thenya.gif");
        movie->setScaledSize(QSize().scaled(1611,1611,Qt::KeepAspectRatio));
         ui->label_25->setMovie(movie);
         ui->label_25->setMovie(movie);
        movie->start();
    }


    /* QFile File("C:\\Users\\wissem\\Desktop\\project\\projet_qt\\projetwissem\\Fibers.qss");
      File.open(QFile::ReadOnly);
      QString StyleSheet = QLatin1String(File.readAll());
     this->setStyleSheet(StyleSheet);*/


      //----------------------------------------------------------------------------------
      ui->type_assurances->addItem("CHOSIR LE TYPE");
      ui->type_assurances->addItem("juridique");
      ui->type_assurances->addItem("Obligatoire");
      ui->type_assurances->addItem("tous risques");

      ui->liste_tri_assurances->addItem("TRIER PAR");
      ui->liste_tri_assurances->addItem("IDENTIFIANT");
      ui->liste_tri_assurances->addItem("NOM");
      ui->liste_tri_assurances->addItem("TYPE");

      ui->liste_tri_assureurs->addItem("TIRER PAR");
      ui->liste_tri_assureurs->addItem("IDENTIFIANT");
      ui->liste_tri_assureurs->addItem("NOM");
      ui->liste_tri_assureurs->addItem("EMAIL");

      theme=true;
      theme_normal();
      ui->opts_menu->setHidden(true);
      ui->opt_theme->setHidden(true);
      ui->opt_traduction->setHidden(true);
      ui->connecte_label->setHidden(true);
      ui->icon_green->setHidden(true);
      ui->user_ico->setHidden(true);
      ui->etat_label->setHidden(true);

      ui->user_ico->setIconSize(QSize(50,50));


      ui->opt_theme->setIconSize(QSize(30, 30));

      ui->opt_traduction->setIconSize(QSize(30, 30));
      ui->opt_deconnexion->setHidden(true);

      ui->opt_deconnexion->setIconSize(QSize(30, 30));
      ui->opts->setIconSize(QSize(50, 50));

      QPixmap mail("C:/Users/adem/Desktop/template2/theme_sombre/mail_gris.png");
      ui->label_77->setPixmap(mail.scaled(130,120));
      //------------------------------------------------
     /* QPixmap car_bgd("C:/Users/adem/Desktop/template2/car background.jpg");
      ui->label_2->setPixmap(car_bgd.scaled(1328,682));
  */
  ui->tabassurances->setShowGrid(false);
  ui->tabassurances->verticalHeader()->setVisible(false);
  ui->tabassurances->horizontalHeader()->setStretchLastSection(true);

  ui->tabassureurs->setShowGrid(false);
  ui->tabassureurs->verticalHeader()->setVisible(false);
  ui->tabassureurs->horizontalHeader()->setStretchLastSection(true);

  ui->liste_mail->setShowGrid(false);
  ui->liste_mail->verticalHeader()->setVisible(false);
  ui->liste_mail->horizontalHeader()->setStretchLastSection(true);

      //------------------------------------------------
      ui->clear->setToolTip("Cliquez ici pour vider les cases");

      QPixmap charte("C:/Users/adem/Desktop/template2/theme_sombre/stats_gris.png");
      ui->chartes->setPixmap(charte.scaled(50,40));

      QPixmap tables("C:/Users/adem/Desktop/template2/theme_sombre/table_gris.png");
      ui->tables->setPixmap(tables.scaled(50,40));
      ui->tables_2->setPixmap(tables.scaled(50,40));

      ui->tabassurances->setModel(tmpassurances.afficher());
      ui->tabassureurs->setModel(tmpassureurs.afficher());
      notifications();

      ui->liste_mail->setModel(tmpassureurs.liste_mail());

      ui->liste_mail->horizontalHeader()->setStretchLastSection(true);
      //ui->tabassureurs->setColumnWidth(2, this->width()/2);
      ui->tabassurances->horizontalHeader()->setStretchLastSection(true);
      ui->tabassureurs->horizontalHeader()->setStretchLastSection(true);

      ui->tabassureurs->horizontalHeader()->setStretchLastSection(true);
      ui->tabassureurs->horizontalHeader()->setStretchLastSection(true);

      ui->liste_mail->horizontalHeader()->setStretchLastSection(true);
      ui->liste_mail->horizontalHeader()->setStretchLastSection(true);

      //----------------------------------------------------------------------------------


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
    QString idcategorie=ui->combobox_33->currentText();
    QString nbplaces=ui->combobox_11->currentText();
    int anciennete=ui->lineEdit_anciennete->text().toInt();
    QString couleur=ui->lineEdit_couleur->text();
    int kilometrage=ui->lineEdit_kilometrage->text().toInt();
    QString carburant=ui->combobox_22->currentText();
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

      //-----------------------------------------------------------//

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
        ui->combov->setModel(tmpcontrat.setcomboboxv());//refresh elyes BO


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
    ui->combov->setModel(tmpcontrat.setcomboboxv());//refresh elyes BO


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
    QString idcategorie=ui->combobox_33->currentText();
    QString nbplaces=ui->combobox_11->currentText();
    int anciennete=ui->lineEdit_anciennete->text().toInt();
    QString couleur=ui->lineEdit_couleur->text();
    int kilometrage=ui->lineEdit_kilometrage->text().toInt();
    QString carburant=ui->combobox_22->currentText();
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
   QString num1 = ui->lineEdit_idv->text();
    int num = ui->lineEdit_idv->text().toInt();

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


//************************************** imprimer khadija


void MainWindow::on_imprimerrkhadija_clicked()
{
   QString num1 = ui->devis->text();


    QSqlQuery query1;
   QString nbp="";
   QString cnp="";
    QString csd="";
     QString   nbe="";
   QString   dev="";

    if(num1!=""){






             nbp = ui->nbpersonne->text();
             cnp = ui->nourriture->text();
             csd = ui->salle->text();
             nbe = ui->nbemployee->text();
             dev = ui->devis->text();




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
                               painter.drawText(1000, 500, " votre devis ");

                               f.setPointSize(15);
                               f.setBold(true);
                               painter.setFont(f);
                               painter.drawText(100, 1000, "le nombres de personnes est  :");
                               painter.drawText(2100, 1000, nbp);
                               painter.drawText(100, 1200, "le coup de nourriture par perssone est :");
                               painter.drawText(2600, 1200, cnp);
                               painter.drawText(100, 1400, "le nombres d émployées est :");
                               painter.drawText(2100, 1400, nbe);
                               painter.drawText(100, 1600, "votre de devis sa coute :");
                               painter.drawText(1630, 1600, dev);


                              painter.end();

              }}
    else
        QMessageBox::critical(nullptr, QObject::tr("Imprimer une reservation"),
                    QObject::tr("Erreur !.\n"
                                "Veuillez selectionner une reservation à imprimer .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}









//*************************************




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
    QString type= ui->combocate->currentText();
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
    QString type= ui->combocate->currentText();
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


void MainWindow::on_rechercheee_clicked()
{

   QString x = ui->lineEdittt_16->text();
   ui->tableView->setModel(tmpcategorie.recherchee(x));//refresh


}














void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    ui->lineEdit_idc->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toString());
    ui->combocate->setCurrentText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),1)).toString());
    ui->lineEdit_nbvoitures->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),2)).toString());
}

void MainWindow::on_tableView2_doubleClicked(const QModelIndex &index)
{
    ui->lineEdit_idv->setText(ui->tableView2->model()->data(ui->tableView2->model()->index(ui->tableView2->currentIndex().row(),0)).toString());
    ui->lineEdit_marque->setText(ui->tableView2->model()->data(ui->tableView2->model()->index(ui->tableView2->currentIndex().row(),1)).toString());
    ui->lineEdit_matricule->setText(ui->tableView2->model()->data(ui->tableView2->model()->index(ui->tableView2->currentIndex().row(),2)).toString());
    ui->combobox_33->setCurrentText(ui->tableView2->model()->data(ui->tableView2->model()->index(ui->tableView2->currentIndex().row(),3)).toString());
    ui->combobox_11->setCurrentText(ui->tableView2->model()->data(ui->tableView2->model()->index(ui->tableView2->currentIndex().row(),4)).toString());

    ui->lineEdit_anciennete->setText(ui->tableView2->model()->data(ui->tableView2->model()->index(ui->tableView2->currentIndex().row(),5)).toString());
    ui->lineEdit_couleur->setText(ui->tableView2->model()->data(ui->tableView2->model()->index(ui->tableView2->currentIndex().row(),6)).toString());
    ui->lineEdit_kilometrage->setText(ui->tableView2->model()->data(ui->tableView2->model()->index(ui->tableView2->currentIndex().row(),7)).toString());
    ui->combobox_22->setCurrentText(ui->tabemployee_2->model()->data(ui->tabemployee_2->model()->index(ui->tabemployee_2->currentIndex().row(),8)).toString());
    ui->lineEdit_prixparjour->setText(ui->tableView2->model()->data(ui->tableView2->model()->index(ui->tableView2->currentIndex().row(),9)).toString());
    ui->combo->setCurrentText(ui->tabemployee_2->model()->data(ui->tabemployee_2->model()->index(ui->tabemployee_2->currentIndex().row(),10)).toString());

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

        smtp->sendMail("testwissem11@gmail.com", email , "Bienvenue chez SRC" ,corps);
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
{
    QString cin= ui->cincontrat->currentText();
    int idv= ui->combov->currentText().toInt();

    contrat tmp(cin,ui->DATEDEBUT->date(),ui->DATEFIN->date(),ui->MONTANT->text().toInt(),ui->QUOTIENT->text().toInt(),idv);

    /**************************************/
    int err=0;
    QDate datedebut= ui->DATEDEBUT->date();
    QDate datefin= ui->DATEFIN->date();
    float montant= ui->MONTANT->text().toFloat();
    float quotient= ui->QUOTIENT->text().toFloat();
    if(montant<0)
    {
        err++;
        ui->csmontant->setText("Montant invalide");
        ui->MONTANT->setStyleSheet("background-color: red;");


    }
    else
    {
         ui->csmontant->setText("");
         }
    if(montant<0)
    {
        err++;
        ui->csquotient->setText("Quotient invalide");
    }
    if ((datedebut< QDate::currentDate()))
        {
                       ui->csdate->setText("date invalide");
        err++ ;
     }
    else{
        ui->csdate->setText("");

    }
   if ((datefin<=datedebut))
       {
                      ui->csdate2->setText("date invalide");

       err++ ;
    }
   else{
       ui->csdate2->setText("");

   }




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
{  QString cin= ui->cincontrat->currentText();
    int idv= ui->combov->currentText().toInt();

    contrat tmp(cin,ui->DATEDEBUT->date(),ui->DATEFIN->date(),ui->MONTANT->text().toInt(),ui->QUOTIENT->text().toInt(),idv);
    if(tmp.modifier( ui->lineEdit->text().toInt()))
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
{       ui->lineEdit->setText(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),3)).toString());

    ui->cincontrat->setCurrentText(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),0)).toString());
    ui->DATEDEBUT->setDate(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),1)).toDate());
    ui->DATEFIN->setDate(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),2)).toDate());
    ui->MONTANT->setText(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),4)).toString());
    ui->QUOTIENT->setText(ui->data2->model()->data(ui->data2->model()->index(ui->data2->currentIndex().row(),5)).toString());



}

void MainWindow::on_Supprimerc_2_clicked()
{
    contrat tmp;
    if(tmp.supprimer( ui->lineEdit->text().toInt()))
    {
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
{        int idv= ui->combov_2->currentText().toInt();

      QString cin= ui->cincontrat->currentText();
    reclamation tmp(ui->ID->text().toInt(),ui->DESC->text(),cin,idv,ui->comboemp_2->currentText().toInt());
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
void MainWindow:: on_pb_devis_clicked()
{
    int coutnourriture=ui->nourriture->value();
    int nbemployee=ui->nbemployee->value();
    float coutsalle=ui->salle->text().toInt();
    int nbpersonne = ui->nbpersonne->text().toInt();
    float caldevis=(nbpersonne*coutnourriture)+coutsalle+(nbemployee*30);
    QString b = QString::number(caldevis);
    ui->devis->setText(b);


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
{  QString cin= ui->cinC->currentText();
    int idv= ui->combov_2->currentText().toInt();

    reclamation tmp(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),0)).toInt(),ui->DESC->text(),cin,idv,ui->comboemp_2->currentText().toInt());
    if(tmp.modifier())
    {
        QSqlQueryModel *model=tmp.afficher();
         QSortFilterProxyModel *proxy=new QSortFilterProxyModel(this);
                proxy->setDynamicSortFilter(true);
                proxy->setSourceModel(model);
                ui->data->setModel(proxy);
                ui->data->setSortingEnabled(true);
        QMessageBox::information(nullptr, QObject::tr("Ajouter une reclamation"),
                          QObject::tr("reclamation modifiée.\n"
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
    {               ui->checkBox_2->setChecked(true);
        ui->checkBox_3->setChecked(true);
        ui->checkBox_4->setChecked(true);

        QFile File("C:\\Users\\wissem\\Desktop\\clone\\project\\projet_qt\\projetwissem\\sombre.css");
         File.open(QFile::ReadOnly);
         QString StyleSheet = QLatin1String(File.readAll());
        this->setStyleSheet(StyleSheet);
         QMovie *movie =new QMovie("C:/Users/wissem/Desktop/project/projet_qt/adam/projet_progres/audiz.gif");
          QMovie *moviee =new QMovie("C:/Users/wissem/Desktop/project/projet_qt/adam/projet_progres/welcome.gif");
         movie->setScaledSize(QSize().scaled(1411,1411,Qt::KeepAspectRatio));
         moviee->setScaledSize(QSize().scaled(400,400,Qt::KeepAspectRatio));
          ui->label_25->setMovie(movie);
          ui->gifcategorie->setMovie(movie);
          ui->gifemploye->setMovie(movie);
          ui->gifmarketing->setMovie(movie);
          ui->label_25->setMovie(movie);
          ui->label_2->setMovie(moviee);
         movie->start();
         moviee->start();
    }
    else
    {   ui->checkBox_2->setChecked(false);
        ui->checkBox_3->setChecked(false);
        ui->checkBox_4->setChecked(false);

        QFile File("C:\\Users\\wissem\\Desktop\\clone\\project\\projet_qt\\projetwissem\\style.css");
         File.open(QFile::ReadOnly);
         QString StyleSheet = QLatin1String(File.readAll());
        this->setStyleSheet(StyleSheet);
         QMovie *movie =new QMovie("C:/Users/wissem/Desktop/project/projet_qt/adam/projet_progres/thenya.gif");
         QMovie *moviee =new QMovie("C:/Users/wissem/Desktop/project/projet_qt/adam/projet_progres/welcome.gif");
         movie->setScaledSize(QSize().scaled(1411,1411,Qt::KeepAspectRatio));
         moviee->setScaledSize(QSize().scaled(400,400,Qt::KeepAspectRatio));
          ui->label_25->setMovie(movie);
          ui->label_25->setMovie(movie);
          ui->gifcategorie->setMovie(movie);
          ui->gifemploye->setMovie(movie);
          ui->label_2->setMovie(moviee);
          ui->gifmarketing->setMovie(movie);
         movie->start();
         moviee->start();

    }
}

void MainWindow::on_checkBox_2_clicked()
{
    if (ui->checkBox_2->isChecked())
        { ui->checkBox_3->setChecked(true);
        ui->checkBox_4->setChecked(true);
        ui->checkBox->setChecked(true);
    }
        else
        {  ui->checkBox_3->setChecked(false);
        ui->checkBox_4->setChecked(false);
            ui->checkBox->setChecked(false);

        }
}

void MainWindow::on_checkBox_3_clicked()
{
    if (ui->checkBox_3->isChecked())
        { ui->checkBox_2->setChecked(true);
        ui->checkBox->setChecked(true);
        ui->checkBox_4->setChecked(true);
    }
        else
        {  ui->checkBox_2->setChecked(false);
        ui->checkBox_4->setChecked(false);
            ui->checkBox->setChecked(false);

        }
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(0);

}

void MainWindow::on_pushButton_17_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(1);

}

//-----------------------------------------------------------------------------------------------//


// traduction -------------------------------------------------------------------------------

void MainWindow::on_checkBox_5_clicked()
{
    if (ui->checkBox_5->isChecked())
        {
      // mariemmmm -----------------------------------

        ui->tabWidget->setTabText(0,"Home");
        ui->tabWidget->setTabText(1,"Category");
        ui->tabWidget->setTabText(2,"Customer");
        ui->tabWidget->setTabText(3,"Marketing");
        ui->tabWidget->setTabText(4,"Employee");
        ui->tabWidget->setTabText(5,"Insurance");



        ui->label_63->setText( tr("username"));
        ui->label_64->setText( tr("name"));
        ui->label_65->setText( tr("firstname"));
        ui->label_66->setText( tr("username dep"));
        ui->label_67->setText( tr("age"));
        ui->label_68->setText( tr("phone number"));
        ui->label_69->setText( tr("id card"));
        ui->label_88->setText( tr("E-mail"));
        ui->label_89->setText( tr("salary"));
        ui->label_90->setText( tr("addresse"));
        ui->label_104->setText( tr("employee management"));
        ui->label_62->setText( tr("username"));
        ui->label_70->setText( tr("username department"));
        ui->label_71->setText( tr("username manager"));
        ui->label_72->setText( tr("name"));
        ui->label_73->setText( tr("member number"));
        ui->label_74->setText( tr("username"));
        ui->pb_ajouterr->setText( tr("add"));
        ui->pb_modifierr->setText( tr("update"));
        ui->pb_supprimerr->setText( tr("delete"));
        ui->pb_recherchee->setText( tr("research"));
        ui->pb_ajouterr_2->setText( tr("add"));
        ui->pb_modifierr_2->setText( tr("update"));
        ui->pb_supprimerr_2->setText( tr("delete"));
        ui->pb_recherchee_2->setText( tr("research"));
        ui->checkBox_5->setText( tr("version français"));
        ui->pushButton_16->setText( tr("employee"));
        ui->pushButton_17->setText( tr("department"));
        ui->pb_trierr->setText( tr("sort"));
        ui->pb_trierr_2->setText( tr("sort"));
        ui->checkBox->setText( tr("dark mode"));
        ui->checkBox_2->setText( tr("dark mode"));
        ui->checkBox_3->setText( tr("dark mode"));
        ui->checkBox_4->setText( tr("dark mode"));
        ui->pb_stat_emp->setText( tr("statistics"));




    }

    else
    {
         // mariemmmm -----------------------------------

        ui->tabWidget->setTabText(0,"Accueil");
        ui->tabWidget->setTabText(1,"Categorie");
        ui->tabWidget->setTabText(2,"Client");
        ui->tabWidget->setTabText(3,"Marketing");
        ui->tabWidget->setTabText(4,"Employé");
        ui->tabWidget->setTabText(5,"Assurance");


        ui->label_63->setText( tr("identifiant"));
        ui->label_64->setText( tr("nom"));
        ui->label_65->setText( tr("prenom"));
        ui->label_66->setText( tr("id dep"));
        ui->label_67->setText( tr("age"));
        ui->label_68->setText( tr("num tel"));
        ui->label_69->setText( tr("cin"));
        ui->label_88->setText( tr("Email"));
        ui->label_89->setText( tr("salaire"));
        ui->label_90->setText( tr("adresse"));
        ui->label_104->setText( tr("gestion des employés"));
        ui->label_62->setText( tr("identifiant"));
        ui->label_70->setText( tr("id département"));
        ui->label_71->setText( tr("id directeur"));
        ui->label_72->setText( tr("nom"));
        ui->label_73->setText( tr("num membre"));
        ui->label_74->setText( tr("identifiant"));
        ui->pb_ajouterr->setText( tr("ajouter"));
        ui->pb_modifierr->setText( tr("modifier"));
        ui->pb_supprimerr->setText( tr("supprimer"));
        ui->pb_recherchee->setText( tr("recherche"));
        ui->pb_ajouterr_2->setText( tr("ajouter"));
        ui->pb_modifierr_2->setText( tr("modifier"));
        ui->pb_supprimerr_2->setText( tr("supprimer"));
        ui->pb_recherchee_2->setText( tr("recherche"));
        ui->checkBox_5->setText( tr("version Anglais"));
        ui->pushButton_16->setText( tr("employé"));
        ui->pushButton_17->setText( tr("département"));
        ui->pb_trierr->setText( tr("trier"));
        ui->pb_trierr_2->setText( tr("trier"));
        ui->checkBox->setText( tr("mode sombre"));
        ui->checkBox_2->setText( tr("mode sombre"));
        ui->checkBox_3->setText( tr("mode sombre"));
        ui->checkBox_4->setText( tr("mode sombre"));
        ui->pb_stat_emp->setText( tr("statistiques"));

    }

}

void MainWindow::on_checkBox_6_clicked()
{
    if (ui->checkBox_6->isChecked())
        {
      // ilyes nasraoui -----------------------------------

        ui->tabWidget->setTabText(0,"Home");
        ui->tabWidget->setTabText(1,"Category");
        ui->tabWidget->setTabText(2,"Customer");
        ui->tabWidget->setTabText(3,"Marketing");
        ui->tabWidget->setTabText(4,"Employee");
        ui->tabWidget->setTabText(5,"Insurance");




        ui->label_41->setText( tr("fuel"));
        ui->label_39->setText( tr("price per day"));
        ui->label->setText( tr("state"));
        ui->label_42->setText( tr("number of places"));
        ui->label_43->setText( tr("mileage"));
        ui->label_34->setText( tr("seniority"));
        ui->label_35->setText( tr("color"));
        ui->label_40->setText( tr("category username"));
        ui->label_44->setText( tr("registration number"));
        ui->label_36->setText( tr("car username"));
        ui->label_37->setText( tr("mark"));
        ui->label_45->setText( tr("cars numbers"));
        ui->label_46->setText( tr("username category"));
        ui->label_47->setText( tr("type"));
        ui->ajouter->setText( tr("add"));
        ui->modifier->setText( tr("update"));
        ui->supprimer->setText( tr("delete"));
        ui->recherche->setText( tr("research"));
        ui->imprimerr->setText( tr("print the sheet"));
        ui->imprimerrilyes->setText( tr("print a contract"));
        ui->ajouter_categorie->setText( tr("add"));
        ui->modifier_categorie->setText( tr("update"));
        ui->supprimer_categorie->setText( tr("delete"));
        ui->rechercheee->setText( tr("research"));
        ui->checkBox_6->setText( tr("version français"));
        ui->voituree->setText( tr("car"));
        ui->categoriee->setText( tr("category"));
        ui->trie->setText( tr("sort by price"));
        ui->trie_categorie->setText( tr("sort by number of cars"));
        ui->checkBox->setText( tr("dark mode"));
        ui->checkBox_2->setText( tr("dark mode"));
        ui->checkBox_3->setText( tr("dark mode"));
        ui->checkBox_4->setText( tr("dark mode"));
        ui->stat->setText( tr("statistics"));
        ui->label_102->setText( tr("cars management"));




    }

    else
    {
         // ilyes nasraoui  -----------------------------------


        ui->tabWidget->setTabText(0,"Accueil");
        ui->tabWidget->setTabText(1,"Categorie");
        ui->tabWidget->setTabText(2,"Client");
        ui->tabWidget->setTabText(3,"Marketing");
        ui->tabWidget->setTabText(4,"Employé");
        ui->tabWidget->setTabText(5,"Assurance");



        ui->label_41->setText( tr("carburant"));
        ui->label_39->setText( tr("prix par jour"));
        ui->label->setText( tr("etat"));
        ui->label_42->setText( tr("nombres de places"));
        ui->label_43->setText( tr("kilométrage"));
        ui->label_34->setText( tr("ancienneté"));
        ui->label_35->setText( tr("couleur"));
        ui->label_40->setText( tr("id categorie"));
        ui->label_44->setText( tr("matricule"));
        ui->label_36->setText( tr("id voiture"));
        ui->label_37->setText( tr("marque"));
        ui->label_45->setText( tr("nombres de voitures"));
        ui->label_46->setText( tr("id categorie"));
        ui->label_47->setText( tr("type"));
        ui->ajouter->setText( tr("ajouter"));
        ui->modifier->setText( tr("modifier"));
        ui->supprimer->setText( tr("supprimer"));
        ui->recherche->setText( tr("recherche"));
        ui->imprimerr->setText( tr("imprimer la fiche"));
        ui->imprimerrilyes->setText( tr("imprimer le contract"));
        ui->ajouter_categorie->setText( tr("ajouter"));
        ui->modifier_categorie->setText( tr("modifier"));
        ui->supprimer_categorie->setText( tr("supprimer"));
        ui->rechercheee->setText( tr("recherche"));
        ui->checkBox_6->setText( tr("version Anglais"));
        ui->voituree->setText( tr("voiture"));
        ui->categoriee->setText( tr("categorie"));
        ui->trie->setText( tr("trier selon prix"));
        ui->trie_categorie->setText( tr("trier selon nombres de voiture"));
        ui->checkBox->setText( tr("mode sombre"));
        ui->checkBox_2->setText( tr("mode sombre"));
        ui->checkBox_3->setText( tr("mode sombre"));
        ui->checkBox_4->setText( tr("mode sombre"));
        ui->stat->setText( tr("statistiques"));
        ui->label_102->setText( tr("gestions des voitures"));

    }

}
// traductionn  wissem w ilyes ben othmane


void MainWindow::on_checkBox_7_clicked()
{
    if (ui->checkBox_7->isChecked())
        {

        ui->tabWidget->setTabText(0,"Home");
        ui->tabWidget->setTabText(1,"Category");
        ui->tabWidget->setTabText(2,"Customer");
        ui->tabWidget->setTabText(3,"Marketing");
        ui->tabWidget->setTabText(4,"Employee");
        ui->tabWidget->setTabText(5,"Insurance");



        ui->ajouter_2->setText( tr("add"));
        ui->modifier_2->setText( tr("update"));
        ui->supprimer_2->setText( tr("delete"));
        ui->label_53->setText( tr("contract username"));
        ui->label_8->setText( tr("username car"));
        ui->label_4->setText( tr("customer id card "));
        ui->label_5->setText( tr("employee id card"));
        ui->label_3->setText( tr("description"));
        ui->label_59->setText( tr("sort by "));
        ui->label_61->setText( tr("research"));
        ui->AJOUTERC_2->setText( tr("add"));
        ui->modifierc_2->setText( tr("update"));
        ui->Supprimerc_2->setText( tr("delete"));
        ui->label_49->setText( tr("car username "));
        ui->label_48->setText( tr("quotient"));
        ui->label_50->setText( tr("amount"));
        ui->label_24->setText( tr("start date"));
        ui->label_51->setText( tr("end date"));
        ui->label_52->setText( tr("research"));
        ui->label_17->setText( tr("id card"));
        ui->label_33->setText( tr("id card"));
        ui->label_29->setText( tr("value"));
        ui->label_30->setText( tr("start date"));
        ui->label_31->setText( tr("end date"));
        ui->ajouterfid->setText( tr("add"));
        ui->modifierfid->setText( tr("update"));
        ui->supprimerfid->setText( tr("delete"));
        ui->label_32->setText( tr("sort by"));
        ui->label_14->setText( tr("research"));
        ui->pushButton_10->setText( tr("loyalty"));
        ui->pushButton_11->setText( tr("customer"));
        ui->pushButton_12->setText( tr("contract"));
        ui->pushButton_13->setText( tr("claim"));
        ui->statsclient->setText( tr("statistics"));
        ui->pushButton_2->setText( tr("statistics"));
        ui->label_23->setText( tr("sort by"));
        ui->label_7->setText( tr("research"));
        ui->label_18->setText( tr("id card"));
        ui->label_19->setText( tr("first name"));
        ui->label_20->setText( tr("name"));
        ui->label_21->setText( tr("phone number"));
        ui->label_22->setText( tr("age"));
        ui->label_27->setText( tr("E-mail"));
        ui->ajouterclient->setText( tr("add"));
        ui->modifierclient->setText( tr("update"));
        ui->supprimerclient->setText( tr("delete"));
        ui->imprimerrilyes->setText( tr("print a contract"));
        ui->checkBox_7->setText( tr("version français"));
        ui->checkBox->setText( tr("dark mode"));
        ui->checkBox_2->setText( tr("dark mode"));
        ui->checkBox_3->setText( tr("dark mode"));
        ui->checkBox_4->setText( tr("dark mode"));
        ui->label_101->setText( tr("client and contract management"));




    }

    else
    {

        ui->tabWidget->setTabText(0,"Accueil");
        ui->tabWidget->setTabText(1,"Categorie");
        ui->tabWidget->setTabText(2,"Client");
        ui->tabWidget->setTabText(3,"Marketing");
        ui->tabWidget->setTabText(4,"Employé");
        ui->tabWidget->setTabText(5,"Assurance");





        ui->pushButton_2->setText( tr("statistiques"));
        ui->label_53->setText( tr("id contrat"));
        ui->label_8->setText( tr("id voiture"));
        ui->label_4->setText( tr("id client "));
        ui->label_5->setText( tr("id employe"));
        ui->label_3->setText( tr("description"));
        ui->label_59->setText( tr("trier par "));
        ui->label_61->setText( tr("recherche"));
        ui->AJOUTERC_2->setText( tr("ajouter"));
        ui->modifierc_2->setText( tr("modifier"));
        ui->Supprimerc_2->setText( tr("supprimer"));
        ui->label_49->setText( tr("id voiture"));
       ui->label_48->setText( tr("quotient"));
       ui->label_50->setText( tr("montant"));
        ui->label_24->setText( tr("date deb "));
        ui->label_51->setText( tr("date fin "));
        ui->label_52->setText( tr("recherche"));
        ui->label_17->setText( tr("cin"));
        ui->label_33->setText( tr("cin"));
        ui->label_29->setText( tr("valeur"));
        ui->label_30->setText( tr("date deb "));
        ui->label_31->setText( tr("date fin "));
        ui->ajouterfid->setText( tr("ajouter"));
        ui->modifierfid->setText( tr("modifier"));
        ui->supprimerfid->setText( tr("supprimer"));
        ui->ajouter_2->setText( tr("ajouter"));
        ui->modifier_2->setText( tr("modifier"));
        ui->supprimer_2->setText( tr("supprimer"));
        ui->label_32->setText( tr("trier par"));
        ui->label_14->setText( tr("recherche"));
        ui->pushButton_10->setText( tr("fidélité"));
        ui->pushButton_11->setText( tr("client"));
        ui->pushButton_12->setText( tr("contrat"));
        ui->pushButton_13->setText( tr("réclamation"));
        ui->label_23->setText( tr("trier par"));
        ui->label_7->setText( tr("recherche"));
        ui->label_18->setText( tr("cin"));
        ui->label_19->setText( tr("prenom"));
        ui->label_20->setText( tr("nom"));
        ui->label_21->setText( tr("tel"));
        ui->label_22->setText( tr("age"));
        ui->label_27->setText( tr("email"));
        ui->ajouterclient->setText( tr("ajouter"));
        ui->modifierclient->setText( tr("modifier"));
        ui->supprimerclient->setText( tr("supprimer"));
        ui->imprimerrilyes->setText( tr("imprimer le contract"));
        ui->checkBox_7->setText( tr("version Anglais"));
        ui->checkBox->setText( tr("mode sombre"));
        ui->checkBox_2->setText( tr("mode sombre"));
        ui->checkBox_3->setText( tr("mode sombre"));
        ui->checkBox_4->setText( tr("mode sombre"));
        ui->statsclient->setText( tr("statistiques"));
        ui->label_101->setText( tr("gestions des clients et contrats"));

    }

}



//*************************************************************** khadijaaa


void MainWindow::on_checkBox_8_clicked()
{
    if (ui->checkBox_8->isChecked())
        {





        ui->tabWidget->setTabText(0,"Home");
        ui->tabWidget->setTabText(1,"Category");
        ui->tabWidget->setTabText(2,"Customer");
        ui->tabWidget->setTabText(3,"Marketing");
        ui->tabWidget->setTabText(4,"Employee");
        ui->tabWidget->setTabText(5,"Insurance");



        ui->typevoiture->setText( tr("type of car"));
        ui->nbvoiture_2->setText( tr("number of cars "));

        ui->imprimerrkhadija->setText( tr("print quote "));
        ui->pourcentage_2->setText( tr("percentage"));
        ui->DateDebut->setText( tr("start date"));
        ui->DAtefin->setText( tr("end date"));
        ui->ID_3->setText( tr("username"));
        ui->label_54->setText( tr("username"));
        ui->label_83->setText( tr("quote calculation for a showroom"));
        ui->label_84->setText( tr("number of persons"));
        ui->label_85->setText( tr("cost of the room in dinar "));
        ui->label_86->setText( tr("number of employees"));
        ui->label_87->setText( tr("cost of food / person"));
        ui->label_9->setText( tr("description"));
        ui->label_10->setText( tr("date of event "));
        ui->ID_2->setText( tr("username"));
        ui->label_9->setText( tr("description"));
        ui->label_10->setText( tr("date of event "));
        ui->label_11->setText( tr("type of event"));
        ui->pushButton_14->setText( tr("event"));
        ui->pushButton_15->setText( tr("promotion"));
        ui->label_13->setText( tr("username"));
        ui->pb_count->setText( tr("count"));
        ui->label_12->setText( tr("research per date"));
        ui->pb_rechercherE->setText( tr("research"));
        ui->pb_triE->setText( tr("sort by "));
        ui->pb_ajouterE->setText( tr("add"));
        ui->pb_modifierE->setText( tr("update"));
        ui->pb_supprimerE->setText( tr("delete"));
        ui->pb_rechercherP->setText( tr("research"));
        ui->pb_triP->setText( tr("sort by "));
        ui->pb_ajouterP->setText( tr("add"));
        ui->pb_modifierP->setText( tr("update"));
        ui->pb_supprimer->setText( tr("delete"));
        ui->checkBox_8->setText( tr("version français"));
        ui->checkBox->setText( tr("dark mode"));
        ui->checkBox_2->setText( tr("dark mode"));
        ui->checkBox_3->setText( tr("dark mode"));
        ui->checkBox_4->setText( tr("dark mode"));
        ui->label_103->setText( tr("promotion management"));




    }

    else
    {





        ui->tabWidget->setTabText(0,"Accueil");
        ui->tabWidget->setTabText(1,"Categorie");
        ui->tabWidget->setTabText(2,"Client");
        ui->tabWidget->setTabText(3,"Marketing");
        ui->tabWidget->setTabText(4,"Employé");
        ui->tabWidget->setTabText(5,"Assurance");




        ui->imprimerrkhadija->setText( tr("imprimer devis "));
        ui->typevoiture->setText( tr("type de voiture"));
        ui->nbvoiture_2->setText( tr("nombres de voitures "));
        ui->pourcentage_2->setText( tr("pourcentage"));
        ui->DateDebut->setText( tr("date debut "));
        ui->DAtefin->setText( tr("date fin"));
        ui->ID_3->setText( tr("id"));
        ui->label_54->setText( tr("id"));
        ui->label_83->setText( tr("calcul de devis pour un showroom"));
        ui->label_84->setText( tr("nombre de personnes"));
        ui->label_85->setText( tr("cout de la salle en dinar"));
        ui->label_86->setText( tr("nombre d'employés"));
        ui->label_87->setText( tr("cout nourriture/personne"));
        ui->ID_2->setText( tr("ID"));
        ui->label_9->setText( tr("description"));
        ui->label_10->setText( tr("date d 'évenement "));
        ui->label_11->setText( tr("type d évenement"));
        ui->pushButton_14->setText( tr("évenement"));
        ui->pushButton_15->setText( tr("promotion"));
        ui->label_13->setText( tr("id"));
        ui->pb_count->setText( tr("compter"));
        ui->label_12->setText( tr("recherche par date"));
        ui->pb_rechercherE->setText( tr("recherche"));
        ui->pb_triE->setText( tr("trier par "));
        ui->pb_ajouterE->setText( tr("ajouter"));
        ui->pb_modifierE->setText( tr("modifier"));
        ui->pb_supprimerE->setText( tr("supprimer"));
        ui->pb_rechercherP->setText( tr("recherche"));
        ui->pb_triP->setText( tr("trier par "));
        ui->pb_ajouterP->setText( tr("ajouter"));
        ui->pb_modifierP->setText( tr("modifier"));
        ui->pb_supprimer->setText( tr("supprimer"));
        ui->checkBox_8->setText( tr("version Anglais"));
        ui->checkBox->setText( tr("mode sombre"));
        ui->checkBox_2->setText( tr("mode sombre"));
        ui->checkBox_3->setText( tr("mode sombre"));
        ui->checkBox_4->setText( tr("mode sombre"));
        ui->label_103->setText( tr("gestions des promotions"));

    }

}












// fin traduction -----------------------------------------------------------------------








void MainWindow::on_pb_ajouterr_clicked()
{
    int id = ui->lineEdit_idi->text().toInt();
    QString nom= ui->lineEdit_nomm->text();
    QString prenom= ui->lineEdit_prenomm->text();
    int id_dep = ui->combobbb3->currentText().toInt();
    int age = ui->lineEdit_agee->text().toInt();
    QString cin = ui->lineEdit_cinn->text();
    QString numtel = ui->lineEdit_numtell->text();
    QString email = ui->lineEdit_email->text();
    int salaire = ui->lineEdit_salaire->text().toInt();
    QString adresse = ui->lineEdit_adresse->text();
  Employee e(id,nom,prenom,id_dep,age,cin,numtel,email,salaire,adresse);

  //debut controle saisie
  //cin
    int verif=0;
     for (int i=0;i<cin.length();i++)
      if ((cin[i]<"0")||(cin[i]>"9"))
       verif=1; int err=0;
      if ((verif==1)||(cin.length()!=8))
          {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                         QObject::tr("Num de Cin invalide il faut qu'il: \n-comporte seulement des chiffres \n -comporte exactement 8 chiffres "
                                     ), QMessageBox::Cancel);
          err++ ;
       }
      //-----------------------------------------------------------//
      //tel
      verif=0;
       for (int i=0;i<numtel.length();i++)
        if ((numtel[i]<"0")||(numtel[i]>"9"))
         verif=1;
        if ((verif==1)||(numtel.length()!=8))
            {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                           QObject::tr("Num de Tel invalide il faut qu'il: \n-comporte seulement des chiffres \n -comporte exactement 8 chiffres "
                                       ), QMessageBox::Cancel);
            err++ ;
         }
        //-----------------------------------------------------------//
        //nom
        verif=0;
        for(int i=0;i<nom.length();i++)
            if (((nom[i]<"a")||(nom[i]>"z"))&&((nom[i]<"A")||(nom[i]>"Z"))&&(nom[i]!=" "))
                verif=1;

       if ((verif==1)||(nom.length()<3)||(nom.length()>20)||(nom[0]==" ")||(nom[nom.length()]==" "))
          { {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                          QObject::tr("prenom invalide if faut qu'il: \n -comporte seulement des lettres alphabétiques ou des espaces \n-longueur comprise entre 3 et 20"
                                      ), QMessageBox::Cancel); }
       err++ ;
       }
       //-----------------------------------------------------------//
       verif=0;
       for(int i=0;i<prenom.length();i++)
           if (((prenom[i]<"a")||(prenom[i]>"z"))&&((prenom[i]<"A")||(prenom[i]>"Z"))&&(prenom[i]!=" "))
               verif=1;

      if ((verif==1)||(prenom.length()<3)||(prenom.length()>20)||(prenom[0]==" ")||(prenom[prenom.length()]==" "))
         { {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                         QObject::tr("nom invalide if faut qu'il: \n -comporte seulement des lettres alphabétiques ou des espaces \n-longueur comprise entre 3 et 20"
                                     ), QMessageBox::Cancel); }
      err++ ;
      }
      //-----------------------------------------------------------//
        verif=0;
        if(err==0)
        {
  bool test=e.ajouter();
  if(test)
{ ui->tabemployee->setModel(tmpemployee.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un employee"),
                  QObject::tr("employee ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
Smtp* smtp = new Smtp("testwissem11@gmail.com", "wissem123", "smtp.gmail.com", 465);

            connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
            QString corps="cher(e) "+nom+" "+prenom+" \n Bienvenue dans l'equipe de Smart Rent Car! ";

        smtp->sendMail("testwissem11@gmail.com", email , "" ,corps);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un emp"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

}

void MainWindow::on_pb_supprimerr_clicked()
{
    int id = ui->lineEdit_ids->text().toInt();
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

void MainWindow::on_pb_modifierr_clicked()
{
    int id = ui->lineEdit_idi->text().toInt();
    QString nom= ui->lineEdit_nomm->text();
    QString prenom= ui->lineEdit_prenomm->text();
    int id_dep = ui->combobbb3->currentText().toInt();
    int age = ui->lineEdit_agee->text().toInt();
    QString cin = ui->lineEdit_cinn->text();
    QString numtel = ui->lineEdit_numtell->text();
    QString email = ui->lineEdit_email->text();
    int salaire = ui->lineEdit_salaire->text().toInt();
    QString adresse = ui->lineEdit_adresse->text();
  Employee e(id,nom,prenom,id_dep,age,cin,numtel,email,salaire,adresse);

  bool test=e.modifier(id);
  if(test)
{
      ui->tabemployee->setModel(tmpemployee.afficher());
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

void MainWindow::on_pb_stat_emp_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from employee where age < 40 ");
        float age=model->rowCount();
        model->setQuery("select * from employee where age between 40 and 60 ");
        float agee=model->rowCount();
        model->setQuery("select * from employee where age>60 ");
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

void MainWindow::on_pb_trierr_clicked()
{
    ui->tabemployee->setModel(tmpemployee.afficher_personnel_trier());
}

void MainWindow::on_pb_recherchee_clicked()
{
    QString id = ui->lineEdit_idr->text();
    ui->tabemployee->setModel(tmpemployee.rechercher_personnel(id));
}

void MainWindow::on_pb_ajouterr_2_clicked()
{
    int departement_id = ui->lineEdit_idd_2->text().toInt();
    QString departement_name= ui->mariemm->currentText();
    int manager_id = ui->lineEdit_managerr->text().toInt();
    int num_membre = ui->lineEdit_num_membre->text().toInt();

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

void MainWindow::on_pb_modifierr_2_clicked()
{
    int departement_id = ui->lineEdit_idd_2->text().toInt();
    QString departement_name= ui->mariemm->currentText();
    int manager_id = ui->lineEdit_managerr->text().toInt();
    int num_membre = ui->lineEdit_num_membre->text().toInt();

    departement d(departement_id,departement_name,manager_id,num_membre);
    bool test=d.modifier(departement_id);
  if(test)
{ui->tabemployee_2->setModel(tmpdep.afficher());
// ui->tabemployee_2->setModel(tmpemployee.afficher_personnel_trier());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur"),
                  QObject::tr("modifier ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un fournisseur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimerr_2_clicked()
{
    int id = ui->lineEdits_2->text().toInt();
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

void MainWindow::on_pb_recherchee_2_clicked()
{
    QString id = ui->lineEditrecherchee_2->text();
    ui->tabemployee_2->setModel(tmpdep.rechercher_departement(id));
}

void MainWindow::on_pb_trierr_2_clicked()
{
    ui->tabemployee_2->setModel(tmpdep.afficher_departement_trier());
}

void MainWindow::on_checkBox_4_clicked()
{
    if (ui->checkBox_4->isChecked())
        { ui->checkBox_2->setChecked(true);
        ui->checkBox->setChecked(true);
        ui->checkBox_3->setChecked(true);
    }
        else
        {  ui->checkBox_2->setChecked(false);
        ui->checkBox_3->setChecked(false);
            ui->checkBox->setChecked(false);

        }
}

void MainWindow::on_checkBox_4_stateChanged(int arg1)
{

}
//--------------------------------------------------------------------------------------
void MainWindow::theme_sombre()
{


    ui->label_sp->setStyleSheet("color:white");
    ui->label_mdf->setStyleSheet("color:white");
    ui->label_aj->setStyleSheet("color:white");


    ui->label_spr_2->setStyleSheet("color:white");
    ui->label_mdf_2->setStyleSheet("color:white");
    ui->label_aj_2->setStyleSheet("color:white");


    ui->etat_label->setStyleSheet("color:white");
    ui->connecte_label->setStyleSheet("color:white");

    ui->opt_theme->setStyleSheet("color:black");
    ui->opt_traduction->setStyleSheet("color:black");

    ui->opt_theme->setText("Theme sombre: Activé");
    ui->pb_recherche_assurances->setIcon(QIcon(":/theme_sombre/search.png"));
    ui->clear->setIcon(QIcon(":/theme_sombre/clear.png"));
    ui->clear_2->setIcon(QIcon(":/theme_sombre/clear.png"));
    ui->pb_calendrier->setIcon(QIcon(":/theme_sombre/calendrier.png"));
    ui->tri_croissant_assurances->setIcon(QIcon(":/theme_sombre/fleche_bas.png"));
    ui->tri_decroissant_assurances->setIcon(QIcon(":/theme_sombre/fleche_haut.png"));

    ui->opt_deconnexion->setIcon(QIcon(":/theme_sombre/deconnexion_icon"));

    ui->marge_haute_3->setStyleSheet("background-color: #272a33;"
                                     "border-color: #272a33;"
                                     "padding: 5px;"
                                     "border-width: 3px;"
                                     "border-style: solid ;");

    ui->opts_menu->setStyleSheet("background-color: #272a33;"
                                 "border-color: #272a33;"
                                 "border-style: solid ");

    ui->stackedWidget_2->setStyleSheet("background-color:black;"
                                       "QLabel {"
                                       "qproperty-alignment: AlignCenter;"
                                       "}");

    ui->marge_gauche->setStyleSheet("background-color: #272a33;"
                                    "border-color: #272a33;"
                                    "padding: 5px;"
                                    "border-width: 3px;"
                                    "border-style: solid ");
   ui->liste_mail->setStyleSheet("QWidget"
                                 "{"
                                    "background-color: #272a33;"
                                    "color: #fffff8;"
                                 "}"
                                 "QHeaderView::section "
                                 "{"
                                    "background-color: #646464;"
                                    "padding: 4px;"
                                    "border: 1px solid #fffff8;"
                                    "font-size: 14pt;"
                                 "}"
                                 "QTableWidget "
                                 "{"
                                   "gridline-color: #fffff8;"
                                   "font-size: 12pt;"
                                 "}"
                                 "QTableWidget QTableCornerButton::section {"
                                 "background-color: #646464;"
                                 "border: 1px solid #fffff8;"
                                "}"
                            " QHeaderView::section {"
                                 "background-color: #646464;"
                                 "padding: 4px;"
                                 "font-size: 10pt;"
                                 "border-style: none;"
                                 "border-bottom: 1px solid #fffff8;"
                                 "border-right: 1px solid #fffff8;"

                             "}"
                             "QHeaderView::section:horizontal"
                             "{"
                                 "border-top: 1px solid #fffff8;"
                             "}"
                             "QHeaderView::section:vertical"
                             "{"
                                "border-left: 1px solid #fffff8;"
                             "height:100%;"
                             "}");
ui->marge_haute->setStyleSheet("background-color: #272a33;"
                               "border-color: #272a33;"
                               "padding: 5px;"
                               "border-width: 3px;"
                               "border-style: solid ;");
    ui->tabassurances->setStyleSheet("QWidget"
                                     "{"
                                        "background-color: #272a33;"
                                        "color: #fffff8;"
                                     "}"
                                     "QHeaderView::section "
                                     "{"
                                        "background-color: #646464;"
                                        "padding: 4px;"
                                        "border: 1px solid #fffff8;"
                                        "font-size: 14pt;"
                                     "}"
                                     "QTableWidget "
                                     "{"
                                       "gridline-color: #fffff8;"
                                       "font-size: 12pt;"
                                     "}"
                                     "QTableWidget QTableCornerButton::section {"
                                     "background-color: #646464;"
                                     "border: 1px solid #fffff8;"
                                    "}"
                                " QHeaderView::section {"
                                     "background-color: #646464;"
                                     "padding: 4px;"
                                     "font-size: 10pt;"
                                     "border-style: none;"
                                     "border-bottom: 1px solid #fffff8;"
                                     "border-right: 1px solid #fffff8;"
                                 "}"
                                 "QHeaderView::section:horizontal"
                                 "{"
                                     "border-top: 1px solid #fffff8;"
                                 "}"
                                 "QHeaderView::section:vertical"
                                 "{"
                                    "border-left: 1px solid #fffff8;"
                                 "height:100%;"
                                 "}");
    ui->marge_haute->setStyleSheet("background-color: #272a33;"
                                   "border-color: #272a33;"
                                   "padding: 5px;"
                                   "border-width: 3px;"
                                   "border-style: solid ;"
                                   );
    //-------------------assureurs--------------------------------------------------
    ui->marge_haute_2->setStyleSheet("background-color: #272a33;"
                                   "border-color: #272a33;"
                                   "padding: 5px;"
                                   "border-width: 3px;"
                                   "border-style: solid ;"
                                   );
    ui->tabassureurs->setStyleSheet("QWidget"
                                     "{"
                                        "background-color: #272a33;"
                                        "color: #fffff8;"
                                     "}"
                                     "QHeaderView::section "
                                     "{"
                                        "background-color: #646464;"
                                        "padding: 4px;"
                                        "border: 1px solid #fffff8;"
                                        "font-size: 14pt;"
                                     "}"
                                     "QTableWidget "
                                     "{"
                                       "gridline-color: #fffff8;"
                                       "font-size: 12pt;"
                                     "}"
                                     "QTableWidget QTableCornerButton::section {"
                                     "background-color: #646464;"
                                     "border: 1px solid #fffff8;"
                                    "}"
                                " QHeaderView::section {"
                                     "background-color: #646464;"
                                     "padding: 4px;"
                                     "font-size: 10pt;"
                                     "border-style: none;"
                                     "border-bottom: 1px solid #fffff8;"
                                     "border-right: 1px solid #fffff8;"
                                 "}"
                                 "QHeaderView::section:horizontal"
                                 "{"
                                     "border-top: 1px solid #fffff8;"
                                 "}"
                                 "QHeaderView::section:vertical"
                                 "{"
                                    "border-left: 1px solid #fffff8;"
                                 "height:100%;"
                                 "}");
    ui->barre_recherche_assureurs->setStyleSheet("QLineEdit"
                                                  "{"
                                                     "background-color: black;"
                                                     "color: white;"
                                                     "min-width: 80px;"
                                                     "border-style: solid;"
                                                     "border-width: 1px;"
                                                     "border-radius: 7px;"
                                                     "border-color: black"
                                                 "}");
    ui->barre_recherche_assureurs_mails->setStyleSheet("QLineEdit"
                                                  "{"
                                                     "background-color: black;"
                                                     "color: white;"
                                                     "min-width: 80px;"
                                                     "border-style: solid;"
                                                     "border-width: 1px;"
                                                     "border-radius: 7px;"
                                                     "border-color: black"
                                                 "}");
    ui->liste_tri_assureurs->setStyleSheet("background-color: black;"
                                            "color: white;"
                                            "min-width: 80px;"
                                            "border-style: solid;"
                                            "border-width: 1px;"
                                            "border-radius: 7px;"
                                            "border-color: black");
    //-------------------------------------------------------------------------------
    ui->logo_bg->setStyleSheet("background-color: #272a33;"
                               "border-color: #272a33;"
                               "padding: 5px;"
                               "border-width: 3px;"
                               "border-style: solid ;"
                               );

    ui->barre_recherche_assurances->setStyleSheet("QLineEdit"
                                                  "{"
                                                     "background-color: black;"
                                                     "color: white;"
                                                     "min-width: 80px;"
                                                     "border-style: solid;"
                                                     "border-width: 1px;"
                                                     "border-radius: 7px;"
                                                     "border-color: black"
                                                 "}");

    ui->liste_tri_assurances->setStyleSheet("background-color: black;"
                                            "color: white;"
                                            "min-width: 80px;"
                                            "border-style: solid;"
                                            "border-width: 1px;"
                                            "border-radius: 7px;"
                                            "border-color: black");

    QString pb2;
    pb2="QPushButton"
        "{"
"background-color: black;"
"color: #ffffff;"

"border-style: solid;"
"border-width: 1px;"
"border-radius: 7px;"
"border-color: #051a39;"
"padding: 5px;"

"}"


"QPushButton::hover"
"{"
"background-color: rgba(183, 134, 32, 20%);"
"border: 1px solid #b78620;"

"}"

"QPushButton::pressed"
"{"
"background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(74, 74, 74, 255),stop:1 rgba(49, 49, 49, 255));"
"border: 1px solid #b78620;"

"}"

"QPushButton::checked"
"{"
"background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(74, 74, 74, 255),stop:1 rgba(49, 49, 49, 255));"
"border: 1px solid #222;"
"}";
    ui->envoyer_mail->setStyleSheet(pb2);
    ui->modifier_assurances->setStyleSheet(pb2);
    ui->supprimer_assurances->setStyleSheet(pb2);
    ui->ajouter_assurances->setStyleSheet(pb2);
    ui->imprimer_assurances->setStyleSheet(pb2);
    ui->imprimer_assurances->setIcon(QIcon(":/theme_sombre/print_sombre.png"));
    ui->envoyer_mail->setStyleSheet(pb2);

    ui->modifier_assurances->setIcon(QIcon(":/theme_sombre/modifier.png"));
    ui->supprimer_assurances->setIcon(QIcon(":/theme_sombre/supprimer.png"));
    ui->ajouter_assurances->setIcon(QIcon(":/theme_sombre/ajouter.png"));

    ui->modifier_assureurs->setStyleSheet(pb2);
    ui->supprimer_assureurs->setStyleSheet(pb2);
    ui->ajouter_assureurs->setStyleSheet(pb2);

    ui->modifier_assureurs->setIcon(QIcon(":/theme_sombre/modifier.png"));
    ui->supprimer_assureurs->setIcon(QIcon(":/theme_sombre/supprimer.png"));
    ui->ajouter_assureurs->setIcon(QIcon(":/theme_sombre/ajouter.png"));




    ui->pb_recherche_assurances->setStyleSheet(pb2);
    ui->pb_recherche_mails->setStyleSheet(pb2);


    //-------------------------assureurs--------------------------
    ui->pb_recherche_assureurs->setStyleSheet(pb2);
    ui->clear_2->setStyleSheet(pb2);
    ui->tri_decroissant_assureurs->setStyleSheet(pb2);
    ui->tri_croissant_assureurs->setStyleSheet(pb2);
    //-------------------------------------------------------------


    ui->tri_decroissant_assurances->setStyleSheet(pb2);
    ui->tri_croissant_assurances->setStyleSheet(pb2);
        ui->clear->setStyleSheet(pb2);
        ui->pb_calendrier->setStyleSheet(pb2);

//-------------------------------------------------------------
        QString style_lineEdit;
        style_lineEdit="QLineEdit"
                       "{"
                          "background-color: #272a33;"
                          "color: white;"
                          "min-width: 80px;"
                          "border-style: solid;"
                          "border-width: 1px;"
                          "border-radius: 9px;"
                          "border-color: #e6e6e6"
                      "}";
    ui->id_assurances->setStyleSheet(style_lineEdit);
    ui->nom_assurances->setStyleSheet(style_lineEdit);
    ui->id_voiture->setStyleSheet(style_lineEdit);
    ui->id_assureur->setStyleSheet(style_lineEdit);
    ui->adresse_assureurs->setStyleSheet(style_lineEdit);

//----------assureurs---------------------------------------
    ui->id_assureurs->setStyleSheet(style_lineEdit);
    ui->nom_assureurs->setStyleSheet(style_lineEdit);
    ui->tel_assureurs->setStyleSheet(style_lineEdit);
    ui->mail_assureurs->setStyleSheet(style_lineEdit);
//------------------------------------------------------------


    ui->receiver_mail->setStyleSheet(style_lineEdit);
    ui->mail_contenu->setStyleSheet(style_lineEdit);

//-------------------------------------------------------------
    QString dte_type;
    dte_type="background-color: #272a33;"
             "color: white;"
             "border-width: 1px;"
             "border-radius: 9px;"
             "border-color: #e6e6e6;"
             "padding: 2px";

    ui->mail_contenu->setStyleSheet("QTextEdit{"
                                    "background-color: #272a33;"
                                    "color: white;"
                                    "}");

    ui->date_assurances->setStyleSheet(dte_type);
    ui->type_assurances->setStyleSheet(dte_type);
//--------------------------------------------------------------
    ui->label_id->setStyleSheet("	background-color: transparent;"
                                "color:white"
                                );
    ui->label_nom->setStyleSheet("	background-color: transparent;"
                                "color:white"
                                );
    ui->label_type->setStyleSheet("	background-color: transparent;"
                                "color:white"
                                );
    ui->label_dteFin->setStyleSheet("	background-color: transparent;"
                                "color:white"
                                );
    ui->label_idV->setStyleSheet("	background-color: transparent;"
                                "color:white"
                                );
    ui->label_idAss->setStyleSheet("	background-color: transparent;"
                                "color:white"
                                );
    ui->label_81->setStyleSheet("	background-color: transparent;"
                                "color:white"
                                );
    ui->label_80->setStyleSheet("	background-color: transparent;"
                                "color:white"
                                );

    //----------assureurs-----------------------------------------------
    ui->label_id_assureurs->setStyleSheet("	background-color: transparent;"
                                "color:white"
                                );
    ui->label_nom_assureur->setStyleSheet("	background-color: transparent;"
                                "color:white"
                                );

    ui->label_mail->setStyleSheet("	background-color: transparent;"
                                "color:white"
                                );
    ui->label_adresse_assureurs->setStyleSheet("background-color: transparent;"
                                "color:white"
                                );

    ui->label_num_tel->setStyleSheet("	background-color: transparent;"
                                "color:white"
                                );

    //------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
    QString pb1;
    pb1="QPushButton"
        "{background-color: transparent;"
        "border-color: #dee2e6;"
        "border-width: 0px;"
        "border-style: solid; "
        "color: white"
        "}"
        "QPushButton::hover"
          "{"
            "background-color: #191a1f;"
           "}";
    ui->pb_opt_assureurs->setStyleSheet(pb1);
    ui->opt_theme->setStyleSheet(pb1);
    ui->opt_traduction->setStyleSheet(pb1);
    ui->opt_traduction->setStyleSheet(pb1);

    ui->opt_deconnexion->setStyleSheet(pb1);
    ui->pb_opt_mail->setStyleSheet(pb1);
    ui->pb_opt_stats->setStyleSheet(pb1);
    ui->pb_opt_assurances->setStyleSheet(pb1);
    ui->pb_recherche_assureurs->setIcon(QIcon("C:/Users/adem/Desktop/template2/theme_sombre/search.png"));

}
void MainWindow::theme_normal()
{

    ui->label_sp->setStyleSheet("color:black");
    ui->label_mdf->setStyleSheet("color:black");
    ui->label_aj->setStyleSheet("color:black");

    ui->label_spr_2->setStyleSheet("color:black");
    ui->label_mdf_2->setStyleSheet("color:black");
    ui->label_aj_2->setStyleSheet("color:black");


    ui->opt_deconnexion->setIcon(QIcon(":/theme_normal/deconnexion_icon"));



    ui->etat_label->setStyleSheet("color:black");
    ui->connecte_label->setStyleSheet("color:black");


    ui->opt_theme->setStyleSheet("color:black");

    ui->opt_traduction->setStyleSheet("color:black");
    ui->opt_theme->setText("Theme sombre: Désctivé");

    ui->pb_recherche_assurances->setIcon(QIcon("C:/Users/adem/Desktop/template2/theme_normal/search.png"));
    ui->pb_recherche_assureurs->setIcon(QIcon("C:/Users/adem/Desktop/template2/theme_normal/search.png"));

    ui->clear->setIcon(QIcon(":/theme_normal/clear.png"));
    ui->clear_2->setIcon(QIcon(":/theme_normal/clear.png"));
    ui->pb_calendrier->setIcon(QIcon(":/theme_normal/calendrier.png"));
    ui->tri_croissant_assurances->setIcon(QIcon(":/theme_normal/fleche_bas.png"));
    ui->tri_croissant_assureurs->setIcon(QIcon(":/theme_normal/fleche_bas.png"));
    ui->tri_decroissant_assureurs->setIcon(QIcon(":/theme_normal/fleche_haut.png"));
    ui->tri_decroissant_assurances->setIcon(QIcon(":/theme_normal/fleche_haut.png"));




    ui->stackedWidget_2->setStyleSheet("background-color: #f2f2f2;"
                                     "border-radius: 24% 9%"
                                       "QLabel {"
                                       "qproperty-alignment: AlignCenter;"
                                       "}"
                                       );


    ui->opts_menu->setStyleSheet("background-color: white;"
                               "border-color: #dee2e6;"
                               "border-width: 1px;"
                               "border-style: solid ");


    ui->marge_gauche->setStyleSheet("background-color: white;"
                                    "border-color: #dee2e6;"
                                    "padding: 5px;"
                                    "border-width: 3px;"
                                    "border-style: solid ");

   ui->liste_mail->setStyleSheet("QTableView QTableCornerButton::section {"
                                 "background: red;"
                                 "border: 2px outset red;"
                             "}"
                                "QWidget"
                                 "{"
                                    "background-color: white;"
                                    "color: black;"

                                 "}"
                                 "QHeaderView::section "
                                 "{"
                                    "background-color: white;"
                                    "padding: 4px;"

                                    "font-size: 14pt;"
                                 "}"
                                 "QTableWidget "
                                 "{"
                                   "gridline-color: #fffff8;"
                                   "font-size: 12pt;"
                                 "}"
                                 "QTableWidget QTableCornerButton::section {"
                                 "background-color: white;"
                                "}"
                            " QHeaderView::section {"
                                 "background-color: white;"
                                 "padding: 4px;"
                                 "font-size: 10pt;"
                                 "border-style: none;"
                                 "border-bottom: 1px solid #fffff8;"
                                 "border-right: 1px solid #fffff8;"
                             "}"
                             "QHeaderView::section:horizontal"
                             "{"
                                 "border-top: 1px solid #fffff8;"
                             "}"
                             "QHeaderView::section:vertical"
                             "{"
                                "border-left: 1px solid #fffff8;"
                             "height:100%;"
                             "}"
                               );
    ui->tabassurances->setStyleSheet("QTableView QTableCornerButton::section {"
                                     "background: white;"
                                     "border: 2px outset white;"
                                 "}"
                                    "QWidget"
                                     "{"
                                        "background-color: white;"
                                        "color: black;"

                                     "}"
                                     "QHeaderView::section "
                                     "{"
                                     "border-bottom: 1px solid #D8D8D8;"
                                        "background-color: white;"
                                        "padding: 4px;"
                                        "color: #454952"
                                        "font-size: 14pt;"
                                     "}"
                                     "QTableWidget "
                                     "{"
                                        "border: black;"
                                        "text-align: center;"
                                       "gridline-color: #fffff8;"
                                       "font-size: 12pt;"
                                     "color:#6786ba"
                                     "}"
                                     "QTableWidget QTableCornerButton::section {"
                                     "background-color: white;"
                                    "}"
                                " QHeaderView::section {"
                                     "Alignment:center;"
                                     "background-color: white;"
                                     "padding: 4px;"
                                     "font-size: 10pt;"
                                     "border-style: none;"
                                     "border-bottom: 1px solid #fffff8;"
                                     "border-right: 1px solid #fffff8;"
                                 "}"
                                 "QHeaderView::section:horizontal"
                                 "{"
                                     "border-top: 1px solid #fffff8;"
                                 "}"
                                 "QHeaderView::section:vertical"
                                 "{"
                                    "border-left: 1px solid #fffff8;"
                                 "height:100%;"
                                 "}"
                                "QTableView"
                                "{"
                                " border: none;"
                                "}"
                                     );
    //------------------------------------------------------------------------
    QString a="QTableView QTableCornerButton::section {"
              "background: red;"
              "border: 2px outset red;"
          "}"
             "QWidget"
              "{"
                 "background-color: white;"
                 "color: black;"

              "}"
              "QHeaderView::section "
              "{"
                 "background-color: white;"
                 "padding: 4px;"

                 "font-size: 14pt;"
              "}"
              "QTableWidget "
              "{"
                "gridline-color: #fffff8;"
                "font-size: 12pt;"
              "}"
              "QTableWidget QTableCornerButton::section {"
              "background-color: white;"
             "}"
         " QHeaderView::section {"
              "background-color: white;"
              "padding: 4px;"
              "font-size: 10pt;"
              "border-style: none;"
              "border-bottom: 1px solid #fffff8;"
              "border-right: 1px solid #fffff8;"
          "}"
          "QHeaderView::section:horizontal"
          "{"
              "border-top: 1px solid #fffff8;"
          "}"
          "QHeaderView::section:vertical"
          "{"
             "border-left: 1px solid #fffff8;"
          "height:100%;"
          "}";
    //------------------------------------------------------------------------

    //-------------------------assureurs--------------------------
    ui->tabassureurs->setStyleSheet(a);
    ui->marge_haute_2->setStyleSheet("background-color: #2780e3;"
                                     "border-color: #2780e3;"
                                     "padding: 5px;"
                                     "border-width: 3px;"
                                     "border-style: solid ;"
                                     );
    ui->marge_haute_3->setStyleSheet("background-color: #2780e3;"
                                     "border-color: #2780e3;"
                                     "padding: 5px;"
                                     "border-width: 3px;"
                                     "border-style: solid ;"
                                     );
    ui->barre_recherche_assureurs->setStyleSheet("QLineEdit"
                                                  "{"
                                                     "background-color: white;"
                                                     "color: black;"
                                                     "min-width: 80px;"
                                                     "border-style: solid;"
                                                     "border-width: 1px;"
                                                     "border-radius: 7px;"
                                                     "border-color: black"
                                                 "}");
    ui->barre_recherche_assureurs_mails->setStyleSheet("QLineEdit"
                                                  "{"
                                                     "background-color: white;"
                                                     "color: black;"
                                                     "min-width: 80px;"
                                                     "border-style: solid;"
                                                     "border-width: 1px;"
                                                     "border-radius: 7px;"
                                                     "border-color: black"
                                                 "}");

    ui->liste_tri_assureurs->setStyleSheet("background-color: white;"
                                            "color: black;"
                                            "min-width: 80px;"
                                            "border-style: solid;"
                                            "border-width: 1px;"
                                            "border-radius: 7px;"
                                            "border-color: black");
    //-------------------------------------------------------------




    ui->marge_haute->setStyleSheet("background-color: #2780e3;"
                                   "border-color: #2780e3;"
                                   "padding: 5px;"
                                   "border-width: 3px;"
                                   "border-style: solid ;"
                                   );
    ui->logo_bg->setStyleSheet("background-color: #2780e3;"
                               "border-color: #2780e3;"
                               "padding: 5px;"
                               "border-width: 3px;"
                               "border-style: solid ;");

    ui->barre_recherche_assurances->setStyleSheet("QLineEdit"
                                                  "{"
                                                     "background-color: white;"
                                                     "color: black;"
                                                     "min-width: 80px;"
                                                     "border-style: solid;"
                                                     "border-width: 1px;"
                                                     "border-radius: 7px;"
                                                     "border-color: black"
                                                 "}");

    ui->liste_tri_assurances->setStyleSheet("background-color: white;"
                                            "color: black;"
                                            "min-width: 80px;"
                                            "border-style: solid;"
                                            "border-width: 1px;"
                                            "border-radius: 7px;"
                                            "border-color: black");

    QString pb2;
    pb2="QPushButton"
        "{"
"background-color: white;"
"color: black;"

"border-style: solid;"
"border-width: 1px;"
"border-radius: 7px;"
"border-color: #051a39;"
"padding: 5px;"

"}"
"QPushButton::flat"
"{"
"background-color: transparent;"
"border: none;"
"color: black;"
"}"
"QPushButton::disabled"
"{"
"background-color: #404040;"
"color: black;"
"border-color: #051a39;"

"}"


"QPushButton::hover"
"{"
"background-color: rgba(183, 134, 32, 20%);"
"border: 1px solid #b78620;"

"}"

"QPushButton::pressed"
"{"
"background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(74, 74, 74, 255),stop:1 rgba(49, 49, 49, 255));"
"border: 1px solid #b78620;"

"}"

"QPushButton::checked"
"{"
"background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(74, 74, 74, 255),stop:1 rgba(49, 49, 49, 255));"
"border: 1px solid #222;"
"}";
    ui->envoyer_mail->setStyleSheet(pb2);
    ui->pb_recherche_mails->setStyleSheet(pb2);
    ui->modifier_assurances->setStyleSheet(pb2);
    ui->supprimer_assurances->setStyleSheet(pb2);
    ui->ajouter_assurances->setStyleSheet(pb2);

    ui->imprimer_assurances->setIcon(QIcon("C:/Users/adem/Desktop/projet_progres/theme_normal/print1.png"));
    ui->imprimer_assurances->setStyleSheet(pb2);


    ui->envoyer_mail->setStyleSheet(pb2);

    ui->modifier_assurances->setIcon(QIcon(":/theme_normal/modifier.png"));
    ui->supprimer_assurances->setIcon(QIcon(":/theme_normal/supprimer.png"));
    ui->ajouter_assurances->setIcon(QIcon(":/theme_normal/ajouter.png"));


    ui->modifier_assureurs->setStyleSheet(pb2);
    ui->supprimer_assureurs->setStyleSheet(pb2);
    ui->ajouter_assureurs->setStyleSheet(pb2);

    ui->modifier_assureurs->setIcon(QIcon(":/theme_normal/modifier.png"));
    ui->supprimer_assureurs->setIcon(QIcon(":/theme_normal/supprimer.png"));
    ui->ajouter_assureurs->setIcon(QIcon(":/theme_normal/ajouter.png"));



    ui->pb_recherche_assurances->setStyleSheet(pb2);
    ui->tri_decroissant_assurances->setStyleSheet(pb2);
    ui->tri_croissant_assurances->setStyleSheet(pb2);
    ui->clear->setStyleSheet(pb2);
    ui->pb_calendrier->setStyleSheet(pb2);
    ui->modifier_assurances->setStyleSheet(pb2);
    ui->ajouter_assurances->setStyleSheet(pb2);
    ui->supprimer_assurances->setStyleSheet(pb2);

    //-------------------------assureurs--------------------------
    ui->pb_recherche_assureurs->setStyleSheet(pb2);
    ui->clear_2->setStyleSheet(pb2);
    ui->tri_decroissant_assureurs->setStyleSheet(pb2);
    ui->tri_croissant_assureurs->setStyleSheet(pb2);
    //-------------------------------------------------------------
    ui->label_id_assureurs->setStyleSheet("	background-color: transparent;"
                                "color:black"
                                );
    ui->label_nom_assureur->setStyleSheet("	background-color: transparent;"
                                "color:black"
                                );
    ui->label_mail->setStyleSheet("	background-color: transparent;"
                                "color:black"
                                );
    ui->label_num_tel->setStyleSheet("	background-color: transparent;"
                                "color:black"
                                );
    ui->label_adresse_assureurs->setStyleSheet("background-color: transparent;"
                                               "color:black");


//-------------------------------------------------------------
        QString style_lineEdit;
        style_lineEdit="QLineEdit"
                       "{"
                          "background-color: white;"
                          "color: black;"
                          "min-width: 80px;"
                          "border-style: solid;"
                          "border-width: 1px;"
                          "border-radius: 7px;"
                          "border-color: black"
                      "}";
    ui->id_assurances->setStyleSheet(style_lineEdit);
    ui->nom_assurances->setStyleSheet(style_lineEdit);
    ui->id_voiture->setStyleSheet(style_lineEdit);
    ui->id_assureur->setStyleSheet(style_lineEdit);


    ui->id_assureurs->setStyleSheet(style_lineEdit);
    ui->nom_assureurs->setStyleSheet(style_lineEdit);
    ui->tel_assureurs->setStyleSheet(style_lineEdit);
    ui->adresse_assureurs->setStyleSheet(style_lineEdit);
    ui->mail_assureurs->setStyleSheet(style_lineEdit);


    ui->receiver_mail->setStyleSheet(style_lineEdit);
    ui->mail_contenu->setStyleSheet(style_lineEdit);

//-------------------------------------------------------------
    QString dte_type;
    dte_type="background-color: white;"
             "color: black;"
             "min-width: 80px;"
             "border-style: solid;"
             "border-width: 1px;"
             "border-radius: 7px;"
             "border-color: black";

    ui->mail_contenu->setStyleSheet("QTextEdit{"
                                    "background-color: white;"
                                    "color: black;"
                                    "}");
    ui->date_assurances->setStyleSheet(dte_type);
    ui->type_assurances->setStyleSheet(dte_type);
//--------------------------------------------------------------
    ui->label_id->setStyleSheet("	background-color: transparent;"
                                "color:black"
                                );
    ui->label_nom->setStyleSheet("	background-color: transparent;"
                                "color:black"
                                );
    ui->label_type->setStyleSheet("	background-color: transparent;"
                                "color:black"
                                );
    ui->label_dteFin->setStyleSheet("	background-color: transparent;"
                                "color:black"
                                );
    ui->label_idV->setStyleSheet("	background-color: transparent;"
                                "color:black"
                                );
    ui->label_idAss->setStyleSheet("	background-color: transparent;"
                                "color:black"
                                );

    ui->label_80->setStyleSheet("	background-color: transparent;"
                                "color:black"
                                );
    ui->label_81->setStyleSheet("	background-color: transparent;"
                                "color:black"
                                );

    QString pb1;
    pb1="QPushButton"
        "{background-color: transparent;"
        "border-color: #dee2e6;"
        "border-width: 0px;"
        "border-style: solid; "
        "color: black"
        "}"
        "QPushButton::hover"
          "{"
            "background-color: #e9ecef;"
           "}";

    ui->pb_opt_assureurs->setStyleSheet(pb1);
    ui->opt_theme->setStyleSheet(pb1);
    ui->opt_traduction->setStyleSheet(pb1);
    ui->opt_deconnexion->setStyleSheet(pb1);
    ui->pb_opt_mail->setStyleSheet(pb1);
    ui->pb_opt_stats->setStyleSheet(pb1);
    ui->pb_opt_assurances->setStyleSheet(pb1);

}
void MainWindow::notifications()
{
    if(ui->authentification->currentIndex()==0)
    {
    mSystemTrayIcon=new QSystemTrayIcon(this);
    mSystemTrayIcon->setIcon(QIcon(":/smart_logo.png"));
    mSystemTrayIcon->setVisible(true);
        if(tmpassurances.notifications()>0)
            mSystemTrayIcon->showMessage(tr("Alerte!!"),tr("assurances expirée"));
    }
}
void MainWindow::on_tri_croissant_assurances_clicked()
{
    QString choix=ui->liste_tri_assurances->currentText();
    ui->tabassurances->setModel(tmpassurances.tri_croissant(choix));
}

void MainWindow::on_tri_decroissant_assurances_clicked()
{

    QString choix=ui->liste_tri_assurances->currentText();
    ui->tabassurances->setModel(tmpassurances.tri_decroissant(choix));
}

void MainWindow::on_pb_recherche_assurances_clicked()
{
    ui->tabassurances->setModel(tmpassurances.rechercher(ui->barre_recherche_assurances->text()));
}

void MainWindow::on_tabassurances_activated(const QModelIndex &index)
{
    QString val=ui->tabassurances->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from assurances where ID ='"+val+"' or NOM='"+val+"' or TYPE='"+val+"'  or ID_VOITURE='"+val+"' or ID_ASSUREUR='"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->id_assurances->setText(qry.value(0).toString());
            ui->nom_assurances->setText(qry.value(1).toString());
            ui->type_assurances->setCurrentText(qry.value(2).toString());
            ui->date_assurances->setDate(qry.value(3).toDate());
            ui->id_voiture->setText(qry.value(4).toString());
            ui->id_assureur->setText(qry.value(5).toString());
        }
    }
}

void MainWindow::on_modifier_assurances_clicked()
{
    int id = ui->id_assurances->text().toInt();
    QString nom= ui->nom_assurances->text();
    QString type=ui->type_assurances->currentText();
    int id_voiture = ui->id_voiture->text().toInt();
    int id_assureurs = ui->id_assureur->text().toInt();
    QDate date_fin=ui->date_assurances->date();
    assurances a(id,nom,type,date_fin,id_voiture,id_assureurs);


        if (controle_de_saisie())
        {
            annuler_messages();

            if(existance_assurance(id))
             {

              bool test=a.modifier(id,nom,type,date_fin,id_voiture,id_assureurs);
              if(test)
                QMessageBox::information(nullptr, QObject::tr("Modifier une assurance"),
                                 QObject::tr("Assurance modifiée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
              else
               QMessageBox::critical(nullptr, QObject::tr("modifier une assurance"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
             }
            else
                QMessageBox::critical(nullptr, QObject::tr("modifier une assurance"),
                               QObject::tr("Erreur !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

              ui->tabassurances->setModel(tmpassurances.afficher());

         }

}
//--------------------------------------------------------------------------------------------------
void MainWindow::on_ajouter_assurances_clicked()
{
    int id = ui->id_assurances->text().toInt();
    QString nom= ui->nom_assurances->text();
    QString type=ui->type_assurances->currentText();
    int id_voiture = ui->id_voiture->text().toInt();
    int id_assureurs = ui->id_assureur->text().toInt();
    QDate date_fin=ui->date_assurances->date();
assurances a(id,nom,type,date_fin,id_voiture,id_assureurs);

    if (controle_de_saisie())
    {
        annuler_messages();
      /*if(verif_number(ui->id_assurances->text()))
      {
          ui->msg_id_assurance->setText("");
      if(verif_number(ui->id_assureur->text()))
      {
          ui->msg_idAss_assurance->setText("");
      if(verif_number(ui->id_voiture->text()))
      {
         ui->msg_idV_assurance->setText("");


*/
        if(!existance_assurance(id))
        {

         bool test=a.ajouter();
         if(test)
          QMessageBox::information(nullptr, QObject::tr("Ajouter une assurance"),
                                 QObject::tr("Assurance ajoutée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

         else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter une assurance"),
                                QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else

         QMessageBox::critical(nullptr, QObject::tr("Ajouter une assurance"),
                                      QObject::tr("l'assurance existe deja"), QMessageBox::Cancel);

      /*}
      else ui->msg_idV_assurance->setText("<span style=\"color: red\">ce champs est numérique !</span>");
      }
      else ui->msg_idAss_assurance->setText("<span style=\"color: red\">ce champs est numérique !</span>");
      }
      else ui->msg_id_assurance->setText("<span style=\"color: red\">ce champs est numérique !</span>");
*/
      }

     ui->tabassurances->setModel(tmpassurances.afficher());
}
//--------------------------------------------------------------------------------------------------
void MainWindow::on_supprimer_assurances_clicked()
{
    int id = ui->id_assurances->text().toInt();

    if(controle_de_saisie())
    {
        if(existance_assurance(id))
        {
            bool test=tmpassurances.supprimer(id);
         if(test)
                 QMessageBox::information(nullptr, QObject::tr("Supprimer une assurance"),
                                 QObject::tr("Assurance supprimée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);


          else
               QMessageBox::critical(nullptr, QObject::tr("Supprimer une assurance"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

         ui->tabassurances->setModel(tmpassurances.afficher());
       }
       else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer une assurance"),
                           QObject::tr("L'assurance n'existe pas"), QMessageBox::Cancel);
    }
}

bool MainWindow::controle_de_saisie()
{
    int count=0;
    if(!verif_number(ui->id_assurances->text()))
    {
        ui->msg_id_assurance->setText("<span style=\"color: red\">ce champs est numérique !</span>");
        count++;
    }
    if(!verif_number(ui->id_assureur->text()))
    {
        ui->msg_idAss_assurance->setText("<span style=\"color: red\">ce champs est numérique !</span>");
        count++;
    }
    if(!verif_number(ui->id_voiture->text()))
    {
        ui->msg_idV_assurance->setText("<span style=\"color: red\">ce champs est numérique !</span>");
        count++;
    }

    if(ui->id_assurances->text()=="")
    {
        ui->msg_id_assurance->setText("<span style=\"color: red\">ce champs est obligatoire !</span>");
        count++;
    }
    if(ui->nom_assurances->text()=="")
    {
        ui->msg_nom_assurance->setText("<span style=\"color: red\">ce champs est obligatoire !</span>");
        count++;
    }
    if(ui->type_assurances->currentText()=="CHOSIR LE TYPE")
    {
        ui->msg_type_assurance->setText("<span style=\"color: red\">Veuillez choisir e type !</span>");
        count++;
    }
    if(ui->id_voiture->text()=="")
    {
        ui->msg_idV_assurance->setText("<span style=\"color: red\">ce champs est obligatoire !</span>");
        count++;
    }
    if(ui->id_assureur->text()=="")
    {
        ui->msg_idAss_assurance->setText("<span style=\"color: red\">ce champs est obligatoire !</span>");
        count++;
    }

    if(count!=0)
        return false;
    else
        return true;
}

void MainWindow::annuler_messages()
{
    ui->msg_id_assurance->setText("");
    ui->msg_type_assurance->setText("");
    ui->msg_nom_assurance->setText("");
    ui->msg_idV_assurance->setText("");
    ui->msg_idAss_assurance->setText("");
}

bool MainWindow::existance_assurance(int id)
{
    QSqlQuery verif;
    verif.prepare("Select * from assurances where ID = :id");
    verif.bindValue(":id",id);
    int count=0;
    if(verif.exec())
    {
        while(verif.next())
        count++;
    }
    if(count==0)
        return false;
    else
        return true;
}

void MainWindow::on_clear_clicked()
{
    ui->id_assurances->setText("");
    ui->nom_assurances->setText("");
    ui->type_assurances->currentText()="CHOISIR LE TYPE";
    ui->id_voiture->setText("");
    ui->id_assureur->setText("");
    ui->tabassurances->setModel(tmpassurances.afficher());
}


void MainWindow::on_barre_recherche_assurances_textChanged(const QString &arg1)
{
    QString prenom= ui->barre_recherche_assurances->text();
       ui->tabassurances->setModel(tmpassurances.rechercher(prenom));
       if(arg1=="")
           ui->tabassurances->setModel(tmpassurances.afficher());
}

void MainWindow::on_opts_clicked()
{
    if(ui->opts_menu->isVisible())
    {
        ui->opts_menu->setHidden(true);
        ui->opt_theme->setHidden(true);
        ui->opt_traduction->setHidden(true);

        ui->opt_deconnexion->setHidden(true);
        ui->connecte_label->setHidden(true);
        ui->icon_green->setHidden(true);
        ui->etat_label->setHidden(true);
        ui->user_ico->setHidden(true);
    }
        else
    {
        ui->opts_menu->setVisible(true);
        ui->opt_theme->setVisible(true);

        ui->opt_traduction->setVisible(true);

        ui->opt_deconnexion->setVisible(true);

        ui->connecte_label->setVisible(true);
        ui->icon_green->setVisible(true);
        ui->etat_label->setVisible(true);
        ui->user_ico->setVisible(true);
    }
}

void MainWindow::on_opt_theme_clicked()
{
    if(theme==true)
    {
        theme_normal();
        theme=false;
    }
    else
    {
        theme_sombre();
        theme=true;
    }
    if(ui->opt_traduction->text()=="  اللغة: العربية")
    {
        if(theme)
            ui->opt_theme->setText("المظهر الداكن: مفعّل");
        else
            ui->opt_theme->setText("مظهر معتم: تم إلغاء تنشيطه");
    }
    if(ui->opt_traduction->text()=="  Language : English")
    {
        if(theme)
            ui->opt_theme->setText("Dark mode: Activated");
        else
            ui->opt_theme->setText("Dark mode: Disabled");
    }


}

void MainWindow::on_pushButton_clicked()
{
    QProcess *process = new QProcess(this);
        QString file = "C:/Qt/Qt5.11.2/Examples/Qt-5.11.2/widgets/widgets/build-calculator-Desktop_Qt_5_11_2_MinGW_32bit-Debug/debug/calculator.exe";
        process->start(file);
}


void MainWindow::on_pb_opt_assureurs_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_pb_opt_assurances_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_clear_2_clicked()
{
    ui->id_assureurs->setText("");
    ui->nom_assureurs->setText("");
    ui->mail_assureurs->setText("");
    ui->tel_assureurs->setText("");
    ui->adresse_assureurs->setText("");
    annuler_messages_assureurs();
    ui->tabassureurs->setModel(tmpassureurs.afficher());

}

void MainWindow::on_ajouter_assureurs_clicked()
{

    if(controle_de_saisie_assureurs())
       {
        assureurs a( ui->id_assureurs->text().toInt(),ui->tel_assureurs->text().toInt(),ui->nom_assureurs->text(),ui->mail_assureurs->text(),ui->adresse_assureurs->text());
        annuler_messages_assureurs();
        //annuler
        if(!existance_assureur(ui->id_assureurs->text().toInt()))
         {
            bool test=a.ajouter();
            if(test)
          QMessageBox::information(nullptr, QObject::tr("Ajouter un assureurs"),
                                 QObject::tr("Assureur ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

         else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un assureur"),
                                QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else
         QMessageBox::critical(nullptr, QObject::tr("Ajouter un assureur"),
                                      QObject::tr("l'assureur existe deja"), QMessageBox::Cancel);
           ui->tabassureurs->setModel(tmpassureurs.afficher());
       }

}
void MainWindow::on_supprimer_assureurs_clicked()
{
    int id = ui->id_assureurs->text().toInt();
    if(controle_de_saisie_assureurs())
    {
        annuler_messages_assureurs();
        //annuler
        if(existance_assureur(id))
        {
            bool test=tmpassureurs.supprimer(id);
         if(test)
                 QMessageBox::information(nullptr, QObject::tr("Supprimer un assureur"),
                                 QObject::tr("Assureur supprimé."), QMessageBox::Cancel);


          else
               QMessageBox::critical(nullptr, QObject::tr("Supprimer un assureur"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

         ui->tabassureurs->setModel(tmpassureurs.afficher());
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un assureur"),
                           QObject::tr("L'assureur n'existe pas"), QMessageBox::Cancel);
    }
}
//--------------------------------------------------------------------------------------------------------
void MainWindow::on_tabassureurs_activated(const QModelIndex &index)
{
    QString val=ui->tabassureurs->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from assureurs where ID ='"+val+"' or NOM='"+val+"' or NUM_TEL='"+val+"'  or EMAIL='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->id_assureurs->setText(qry.value(0).toString());
            ui->nom_assureurs->setText(qry.value(1).toString());
            ui->tel_assureurs->setText(qry.value(3).toString());
            ui->mail_assureurs->setText(qry.value(2).toString());
            ui->adresse_assureurs->setText(qry.value(4).toString());

        }
    }
}
//--------------------------------------------------------------------------------------------------------
bool MainWindow::existance_assureur(int id)
{
    QSqlQuery verif;
    verif.prepare("Select * from assureurs where ID = :id");
    verif.bindValue(":id",id);
    int count=0;
    if(verif.exec())
    {
        while(verif.next())
        count++;
    }
    if(count==0)
        return false;
    else
        return true;
}
//--------------------------------------------------------------------------------------------------------

void MainWindow::on_modifier_assureurs_clicked()
{
assureurs a(ui->id_assureurs->text().toInt(),ui->tel_assureurs->text().toInt(),ui->nom_assureurs->text(),ui->mail_assureurs->text(),ui->adresse_assureurs->text());


        if (controle_de_saisie_assureurs())
        {
            annuler_messages_assureurs();
            if(existance_assureur(ui->id_assureurs->text().toInt()))
             {

              bool test=a.modifier(ui->id_assureurs->text().toInt(),ui->tel_assureurs->text().toInt(),ui->nom_assureurs->text(),ui->mail_assureurs->text(),ui->adresse_assureurs->text());
              if(test)
                QMessageBox::information(nullptr, QObject::tr("Modifier un assureur"),
                                 QObject::tr("Assureur modifié."), QMessageBox::Cancel);
              else
               QMessageBox::critical(nullptr, QObject::tr("modifier un assureur"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
             }
            else
                QMessageBox::critical(nullptr, QObject::tr("modifier un assureur"),
                               QObject::tr("l'assureur n'existe pas"), QMessageBox::Cancel);

            ui->tabassureurs->setModel(tmpassureurs.afficher());
         }
}
//--------------------------------------------------------------------------------------------------------
void MainWindow::on_tri_decroissant_assureurs_clicked()
{
    QString choix=ui->liste_tri_assureurs->currentText();
    ui->tabassureurs->setModel(tmpassureurs.tri_decroissant(choix));
}
//--------------------------------------------------------------------------------------------------------
void MainWindow::on_tri_croissant_assureurs_clicked()
{
    QString choix=ui->liste_tri_assureurs->currentText();
    ui->tabassureurs->setModel(tmpassureurs.tri_croissant(choix));
}
//--------------------------------------------------------------------------------------------------------
void MainWindow::on_pb_recherche_assureurs_clicked()
{
    ui->tabassureurs->setModel(tmpassureurs.rechercher(ui->barre_recherche_assureurs->text()));
}
void MainWindow::on_barre_recherche_assureurs_textChanged(const QString &arg1)
{
    QString prenom= ui->barre_recherche_assureurs->text();
       ui->tabassureurs->setModel(tmpassureurs.rechercher(prenom));
       if(arg1=="")
           ui->tabassureurs->setModel(tmpassureurs.afficher());
}
bool MainWindow::controle_de_saisie_assureurs()
{
    if(!verif_number(ui->id_assureurs->text()))
    {
        ui->msg_id_assureurs->setText("<span style=\"color: red\">Ce champ est numérique !</span>");
        return false;
    }
    if(!verif_number(ui->tel_assureurs->text()))
    {
        ui->msg_tel_assureurs->setText("<span style=\"color: red\">Ce champ est numérique !</span>");
        return false;
    }
    if(!verif_mail(ui->mail_assureurs->text()))
    {
        ui->msg_mail_assureurs->setText("<span style=\"color: red\">Veuillez entrer une adresse valide !</span>");
        return false;
    }
    if(ui->id_assureurs->text()=="")
    {
        ui->msg_id_assureurs->setText("<span style=\"color: red\">ce champs est obligatoire !</span>");
        return false;
    }
    if(ui->nom_assureurs->text()=="")
    {
        ui->msg_nom_assureurs->setText("<span style=\"color: red\">ce champs est obligatoire !</span>");
        return false;
    }
    if(ui->adresse_assureurs->text()=="")
    {
        ui->msg_local_assureurs->setText("<span style=\"color: red\">ce champs est obligatoire !</span>");
        return false;
    }
    if(ui->mail_assureurs->text()=="")
    {
        ui->msg_mail_assureurs->setText("<span style=\"color: red\">ce champs est obligatoire !</span>");
        return false;
    }
    if(ui->tel_assureurs->text()=="")
    {
        ui->msg_tel_assureurs->setText("<span style=\"color: red\">ce champs est obligatoire !</span>");
        return false;
    }

        return true;
}
void MainWindow::annuler_messages_assureurs()
{
    ui->msg_id_assureurs->setText("");

    ui->msg_mail_assureurs->setText("");

    ui->msg_nom_assureurs->setText("");

    ui->msg_tel_assureurs->setText("");

}


void MainWindow::on_pb_opt_stats_clicked()
{

    float tr=tmpassurances.calculer_type("tous risques");
    float o=tmpassurances.calculer_type("Obligatoire");
    float j=tmpassurances.calculer_type("juridique");

    QPieSeries *series = new QPieSeries();
    series->append("Tous risques",tr);
    series->append("Obligatoire",o);
    series->append("juridique",j);

    // Add label to 1st slice
    QPieSlice *slice0 = series->slices().at(0);
    slice0->setLabelVisible();

    // Add label, explode and define brush for 2nd slice
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setExploded();
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::darkGreen, 2));
    slice1->setBrush(Qt::blue);

    // Add labels to rest of slices
    QPieSlice *slice2 = series->slices().at(2);
    slice2->setLabelVisible();


    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and hide legend
    chart->addSeries(series);
    chart->setTitle("Nos assureurs");
    chart->legend()->hide();

    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(420, 300);
    chartView->show();
}

void MainWindow::on_pb_opt_mail_clicked()
{

    ui->stackedWidget_2->setCurrentIndex(2);

}

void MainWindow::on_envoyer_mail_clicked()
{
    QString email=ui->receiver_mail->text();
    Smtp* smtp = new Smtp("testwissem11@gmail.com", "wissem123", "smtp.gmail.com", 465);

                connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
                QString corps=ui->mail_contenu->toPlainText();

                smtp->sendMail("nachts554@gmail.com", email ,ui->mail_contenu->toPlainText(),corps);
}

bool MainWindow::verif_number(QString x)
{
    for(int i=0;i<x.length();i++)
     if(x[i]>"9" || x[i]<"0")
       return false;
    return true;

}

bool MainWindow::verif_mail(QString x)
{
    for(int i=0;i<x.length();i++)
     if(x[i]==" " || x[i]=="é" ||x[i]=="à" ||x[i]=="â" ||x[i]=="ç" ||x[i]=="è" ||x[i]=="ê" ||x[i]=="î" ||x[i]=="ô" ||x[i]=="ù" ||x[i]=="û")
         return false;
    int v=0;
    for(int i=0;i<x.length();i++)
     if(x[i]=="@")
          v++;
    if(v==1)
        return true;
   else return false;
}

void MainWindow::on_barre_recherche_assureurs_mails_textChanged(const QString &arg1)
{
    QString mail= ui->barre_recherche_assureurs_mails->text();
       ui->liste_mail->setModel(tmpassureurs.rechercher_mail(mail));
       if(arg1=="")
           ui->tabassureurs->setModel(tmpassureurs.liste_mail());

}

void MainWindow::on_liste_mail_activated(const QModelIndex &index)
{
    QString val=ui->liste_mail->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select email from assureurs where email ='"+val+"' ");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->receiver_mail->setText(qry.value(0).toString());
        }
    }
}



//--------------------------------------------------------------------------------------

void MainWindow::on_pb_calendrier_clicked()
{
    if(ui->calendarWidget->isVisible())
        ui->calendarWidget->setHidden(true);
    else
        ui->calendarWidget->setVisible(true);

}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    ui->date_assurances->setDate(date);
}

void MainWindow::on_data2_doubleClicked(const QModelIndex &index)
{

}
//************************************************
// khedmet ilyes
//***********************************************


void MainWindow::on_imprimerrilyes_clicked()
{
   QString num1 = ui->lineEdit->text();
    int num = ui->lineEdit->text().toInt();

    QSqlQuery query1;
   QString numcin="";
   QString datedeb="";
    QString datefin="";
   QString   montant="";
   QString   quotient="";
  QString   idv="";

    if(num1!=""){
    query1.prepare("select * from contrat where IDC=:numcin");
   query1.bindValue(":numcin", num);

    if (query1.exec())
    {

        while (query1.next()) {

             numcin = query1.value(0).toString();
             datedeb = query1.value(1).toString();
             datefin = query1.value(2).toString();
             montant = query1.value(3).toString();
             quotient= query1.value(4).toString();
             idv = query1.value(5).toString();



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
                               painter.drawText(900, 500, " contrat de location");


                               f.setPointSize(15);
                               f.setBold(true);
                               painter.setFont(f);
                               painter.drawText(100, 1000, "numero du cin :");
                               painter.drawText(1200, 1000, numcin);
                               painter.drawText(100, 1200, "date de debut contrat :");
                               painter.drawText(1550, 1200, datedeb);
                               painter.drawText(100, 1400, "date de fin contrat :");
                               painter.drawText(1500, 1400, datefin);
                               painter.drawText(100, 1600, "montant du contrat :");
                               painter.drawText(1500, 1600, montant);
                               painter.drawText(100, 1800, "prix du quotient :");
                               painter.drawText(1500, 1800, quotient);
                               painter.drawText(100, 2000, "id du voiture a louer :");
                               painter.drawText(1500, 2000, idv);

                              painter.end();

              }}
    else
        QMessageBox::critical(nullptr, QObject::tr("Imprimer une reservation"),
                    QObject::tr("Erreur !.\n"
                                "Veuillez selectionner une reservation à imprimer .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_tabemployee_2_clicked(const QModelIndex &index)
{
    ui->lineEdit_idd_2->setText(ui->tabemployee_2->model()->data(ui->tabemployee_2->model()->index(ui->tabemployee_2->currentIndex().row(),0)).toString());
    ui->lineEdit_managerr->setText(ui->tabemployee_2->model()->data(ui->tabemployee_2->model()->index(ui->tabemployee_2->currentIndex().row(),2)).toString());
    ui->lineEdits_2->setText(ui->tabemployee_2->model()->data(ui->tabemployee_2->model()->index(ui->tabemployee_2->currentIndex().row(),0)).toString());
    ui->mariemm->setCurrentText(ui->tabemployee_2->model()->data(ui->tabemployee_2->model()->index(ui->tabemployee_2->currentIndex().row(),1)).toString());
    ui->lineEdit_num_membre->setText(ui->tabemployee_2->model()->data(ui->tabemployee_2->model()->index(ui->tabemployee_2->currentIndex().row(),3)).toString());
}

void MainWindow::on_tabemployee_clicked(const QModelIndex &index)
{
    ui->lineEdit_ids->setText(ui->tabemployee->model()->data(ui->tabemployee->model()->index(ui->tabemployee->currentIndex().row(),0)).toString());
    ui->lineEdit_idi->setText(ui->tabemployee->model()->data(ui->tabemployee->model()->index(ui->tabemployee->currentIndex().row(),0)).toString());
    ui->lineEdit_nomm->setText(ui->tabemployee->model()->data(ui->tabemployee->model()->index(ui->tabemployee->currentIndex().row(),1)).toString());
    ui->lineEdit_prenomm->setText(ui->tabemployee->model()->data(ui->tabemployee->model()->index(ui->tabemployee->currentIndex().row(),2)).toString());
    ui->combobbb3->setCurrentText(ui->tabemployee->model()->data(ui->tabemployee->model()->index(ui->tabemployee->currentIndex().row(),5)).toString());
    ui->lineEdit_agee->setText(ui->tabemployee->model()->data(ui->tabemployee->model()->index(ui->tabemployee->currentIndex().row(),3)).toString());
    ui->lineEdit_numtell->setText(ui->tabemployee->model()->data(ui->tabemployee->model()->index(ui->tabemployee->currentIndex().row(),9)).toString());
    ui->lineEdit_cinn->setText(ui->tabemployee->model()->data(ui->tabemployee->model()->index(ui->tabemployee->currentIndex().row(),4)).toString());
    ui->lineEdit_email->setText(ui->tabemployee->model()->data(ui->tabemployee->model()->index(ui->tabemployee->currentIndex().row(),6)).toString());
   ui->lineEdit_salaire->setText(ui->tabemployee->model()->data(ui->tabemployee->model()->index(ui->tabemployee->currentIndex().row(),7)).toString());
    ui->lineEdit_adresse->setText(ui->tabemployee->model()->data(ui->tabemployee->model()->index(ui->tabemployee->currentIndex().row(),8)).toString());
}

void MainWindow::on_checkBox_2_stateChanged(int arg1)
{

}

void MainWindow::on_pushButton_3_clicked()
{
    QProcess *process = new QProcess(this);
        QString file = "C:/Users/wissem/Documents/build-convertisseur-Desktop_Qt_5_11_2_MinGW_32bit-Debug/debug/convertisseur.exe";
        process->start(file);
}

void MainWindow::on_opt_traduction_clicked()
{
    if(ui->opt_traduction->text()=="  Langue : francais")
    {

        ui->opt_traduction->setText("  Language : English");

        ui->label_81->setText("Enter the E-mail:");
        ui->label_80->setText("Content:");
        ui->envoyer_mail->setText("Send mail");
        ui->label_email->setText("E-mail");
        ui->label_statistiques->setText("Statistics");
        ui->label_assurance->setText("Insurance");
        ui->label_assurance_2->setText("Insurer");
        ui->barre_recherche_assureurs->setText("Search");
        ui->connecte_label->setText("Connected");
        if(theme)
            ui->opt_theme->setText("Dark mode: Activated");
        else
            ui->opt_theme->setText("Dark mode: Disabled");
        ui->opt_deconnexion->setText("Log out");


        ui->label_id->setText("Username");
        ui->label_nom->setText("Name");
        ui->label_type->setText("Type");
        ui->label_dteFin->setText("Deadline");
        ui->label_idV->setText("Car username");
        ui->label_idAss->setText("Insurer username");
        ui->label_mdf->setText("Modify");
        ui->label_sp->setText("Delete");
        ui->label_aj_2->setText("Add");



        ui->label_id_assureurs->setText("Username");
        ui->label_nom_assureur->setText("Name");
        ui->label_mail->setText("E-mail");
        ui->label_num_tel->setText("Phone");
        ui->label_adresse_assureurs->setText("Adress");
        ui->label_mdf_2->setText("Modify");
        ui->label_spr_2->setText("Delete");
        ui->label_aj_2->setText("Add");
        ui->label_options->setText("Options");
    }
    else if(ui->opt_traduction->text()=="  Language : English")
    {

        ui->label_81->setText("أدخل البريد الإلكتروني");
        ui->label_80->setText("المحتوى");
        ui->envoyer_mail->setText("إرسال البريد");

        ui->opt_traduction->setText("  اللغة: العربية");
        ui->label_statistiques->setText("الإحصاءات");
        ui->label_assurance->setText("تأمينات");
        ui->label_email->setText("إرسال بريدإلكتروني");
        ui->label_assurance_2->setText("شركة التأمين");
        ui->barre_recherche_assureurs->setText(" ...بحث");
        ui->connecte_label->setText("متصل");
        if(theme)
            ui->opt_theme->setText("المظهر الداكن: مفعّل");
        else
            ui->opt_theme->setText("مظهر معتم: تم إلغاء تنشيطه");
        ui->opt_deconnexion->setText("تسجيل الخروج");

        ui->label_id->setText("اسم المستخدم");
        ui->label_nom->setText("الاسم");
        ui->label_type->setText("نوع");
        ui->label_dteFin->setText("تاريخ الانتهاء");
        ui->label_idV->setText("معرف السيارة");
        ui->label_idAss->setText("معرف شركة التأمين");
        ui->label_mdf->setText("تعديل");
        ui->label_sp->setText("إزالة");
        ui->label_aj_2->setText("أضف");

        ui->label_id_assureurs->setText("اسم المستخدم");
        ui->label_nom_assureur->setText("الاسم");
        ui->label_mail->setText("البريد الإلكتروني");
        ui->label_num_tel->setText("الهاتف");
        ui->label_adresse_assureurs->setText("العنوان");
        ui->label_mdf_2->setText("تعديل");
        ui->label_spr_2->setText("إزالة");
        ui->label_aj_2->setText("أضف");
        ui->label_options->setText("خيارات");
    }
    else if(ui->opt_traduction->text()=="  اللغة: العربية")
    {
        ui->label_81->setText("Entrer l'E-mail:");
        ui->label_80->setText("Contenu:");
        ui->envoyer_mail->setText("Envoyer l'email");
        ui->opt_traduction->setText("  Langue : francais");
        ui->label_statistiques->setText("Statistiques");
        ui->label_assurance->setText("Assurances");
        ui->label_assurance_2->setText("Assureurs");
        ui->barre_recherche_assureurs->setText("Rechercher");
        ui->connecte_label->setText("Connecté");
        ui->label_email->setText("E-mail");
        if(theme)
            ui->opt_theme->setText("Theme sombre : Activé");
        else
            ui->opt_theme->setText("Theme sombre : Désactivé");
        ui->opt_deconnexion->setText("Se déconnecter");

        ui->label_id_assureurs->setText("Identifiant");
        ui->label_nom_assureur->setText("Nom");
        ui->label_mail->setText("E-mail");
        ui->label_num_tel->setText("Telephone");
        ui->label_adresse_assureurs->setText("Adresse");
        ui->label_mdf_2->setText("Modifier");
        ui->label_spr_2->setText("Supprimer");
        ui->label_aj_2->setText("Ajouter");
        ui->label_options->setText("Options");
    }

    ui->tabassureurs->setModel(tmpassureurs.afficher());
}

void MainWindow::on_imprimer_assurances_clicked()
{
    QDate date = QDate::currentDate();
    QString dte=date.toString("dd.MM.yyyy");
    QString html1="<!DOCTYPE html>"
                 "<html>"
                 "<head>"
                 "<style>"
                 "#customers {"
                  " font-family: 'Trebuchet MS', Arial, Helvetica, sans-serif;"
                   "border-collapse: collapse;"
                    "width: 100%;"
                 "}"

                 "#customers td, #customers th {"
                   "border: 1px solid #ddd;"
                   "padding: 8px;"
                 "}"

                 "#customers tr:nth-child(even){background-color: #f2f2f2;}"

                 "#customers tr:hover {background-color: #ddd;}"

                 "#customers th {"
                   "padding-top: 12px;"
                   "padding-bottom: 12px;"
                   "text-align: left;"
                   "background-color: #4CAF50;"
                   "color: white;"
                 "}"
                 "</style>"
                 "</head>"
                 "<body>"
                  "<div align=right>"
                     "Ariana,"+dte+""
                  "</div>"
                 "<div><h1 align='center'>La liste des assurances</h1></div>"
                 "<br/>"
                 "<table id='customers';margin-left:auto;margin-right:auto;>"
                   "<tr>"
                     "<th>Identifiant</th>"
                     "<th>Nom</th>"
                     "<th>Type</th>"
                     "<th>Date limite</th>"
                     "<th>ID Assureur</th>"
                     "<th>ID Voiture</th>"
                   "</tr>";

    QString html2="";
        QSqlQuery query;
        query.prepare("select * from assurances ");
       if (query.exec())
        {
            while (query.next())
            {
               html2=html2+"<tr>"
              "<td>"+query.value(0).toString()+"</td>"
              "<td>"+query.value(1).toString()+"</td>"
              "<td>"+query.value(2).toString()+"</td>"
              "<td>"+query.value(3).toString()+"</td>"
              "<td>"+query.value(4).toString()+"</td>"
              "<td>"+query.value(5).toString()+"</td>"
            "</tr>";
            }
        }

QString html3="</table>"
                 "</body>"
                 "</html> ";
QString html=html1+html2+html3;

    QTextDocument document;
    document.setHtml(html);

    QPrinter printer(QPrinter::HighResolution);

    //printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);

    QPrintDialog *dialog = new QPrintDialog(&printer);
    if (dialog->exec() == QDialog::Accepted)
    {
        document.print(&printer);
        QPainter painter (&printer);
        painter.begin(&printer);


    //printer.setOutputFileName("C:/Users/adem/Desktop/js-basics/aa.pdf");
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    //document.print(&printer);
    painter.end();

    }
}

void MainWindow::on_ajouterclient_3_clicked()
{
    if((ui->lineEditprenom_16->text()=="admin") && (ui->lineEditprenom_18->text()=="0000"))
        ui->authentification->setCurrentIndex(0);
    else
    {
        ui->label_114->setText("<span style=\"color: red\">ce champs est invalide !</span>");
        ui->label_115->setText("<span style=\"color: red\">ce champs est invalide !</span>");
    }

}

void MainWindow::on_opt_deconnexion_clicked()
{
    ui->authentification->setCurrentIndex(1);
}
