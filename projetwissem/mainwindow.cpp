#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include<smtp.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

     ui->tabclient->setModel(tmpclient.afficher());//refresh
     ui->dated->setDate(QDate::currentDate()); //teb3a wissem
     ui->datef->setDate(QDate::currentDate()); //teb3a wissem

     ui->tabfidelite->setModel(tmpfid.afficher());//refresh
     ui->cinf->setModel(tmpfid.setcombobox());//refresh
    //-------------------------------------------------------------------------
     QWidget::setWindowTitle ("Smart Rent Car");

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
     ui->calendarWidget->setHidden(true);

     ui->connecte_label->setHidden(true);
     ui->icon_green->setHidden(true);
     ui->user_ico->setHidden(true);
     ui->etat_label->setHidden(true);

     ui->user_ico->setIconSize(QSize(50,50));


     ui->opt_theme->setIconSize(QSize(30, 30));
     ui->opt_deconnexion->setHidden(true);

     ui->opt_deconnexion->setIconSize(QSize(30, 30));
     ui->opts->setIconSize(QSize(50, 50));

     QPixmap mail("C:/Users/adem/Desktop/template2/theme_sombre/mail_gris.png");
     ui->label->setPixmap(mail.scaled(130,120));

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

    //-------------------------------------------------------------------------
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
        {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                       QObject::tr("Num de Cin invalide il faut qu'il: \n-comporte seulement des chiffres \n -comporte exactement 8 chiffres "
                                   ), QMessageBox::Cancel);
        err++ ;
     }
    //-----------------------------------------------------------//
    verif=0;
     for (int i=0;i<tel.length();i++)
      if ((tel[i]<"0")||(tel[i]>"9"))
       verif=1;
      if ((verif==1)||(tel.length()!=8))
          {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                         QObject::tr("Num de Tel invalide il faut qu'il: \n-comporte seulement des chiffres \n -comporte exactement 8 chiffres "
                                     ), QMessageBox::Cancel);
          err++ ;
       }
      //-----------------------------------------------------------//
      verif=0;
       for (int i=0;i<agea.length();i++)
        if ((agea[i]<"0")||(agea[i]>"9"))
         verif=1;
        if (verif==1)
            {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                           QObject::tr("age invalide il faut qu'il: \n-comporte seulement des chiffres \n -soit positif "
                                       ), QMessageBox::Cancel);
            err++ ;
         }
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
      if (err==0)
        {bool test=cl.ajouter();
        if (!(test))
        {QMessageBox::critical(nullptr, QObject::tr("probleme d'ajout"),
                           QObject::tr("CIN deja existant \n"), QMessageBox::Cancel);}
        else
        {Smtp* smtp = new Smtp("testwissem11@gmail.com", "wissem123", "smtp.gmail.com", 465);

            connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
            QString corps="cher(e) "+nom+" "+prenom+" \n Bienvenue chez smart rent car \n merci pour votre inscription vous avez reçu ___dt comme solde de fidélité suite a votre inscription";

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
//--------------------------------------------------------------------------------------------------------
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
    ui->opt_theme->setText("Theme sombre: Activé");
    ui->pb_recherche_assurances->setIcon(QIcon(":/theme_sombre/search.png"));
    ui->clear->setIcon(QIcon(":/theme_sombre/clear.png"));
    ui->clear_2->setIcon(QIcon(":/theme_sombre/clear.png"));
    ui->pb_calendrier->setIcon(QIcon(":/theme_sombre/calendrier.png"));
    ui->tri_croissant_assurances->setIcon(QIcon(":/theme_sombre/fleche_bas.png"));
    ui->tri_decroissant_assurances->setIcon(QIcon(":/theme_sombre/fleche_haut.png"));

    ui->opt_deconnexion->setIcon(QIcon(":/theme_sombre/deconnexion_icon"));


    ui->opts_menu->setStyleSheet("background-color: #272a33;"
                                 "border-color: #272a33;"
                                 "border-style: solid ");

    ui->stackedWidget_2->setStyleSheet("background-color:black;");

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
    ui->label_19->setStyleSheet("	background-color: transparent;"
                                "color:white"
                                );
    ui->label_20->setStyleSheet("	background-color: transparent;"
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
    ui->opt_deconnexion->setStyleSheet(pb1);
    ui->pb_opt_mail->setStyleSheet(pb1);
    ui->pb_opt_stats->setStyleSheet(pb1);
    ui->pb_opt_assurances->setStyleSheet(pb1);
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
                                     "border-radius: 25% 10%");


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

    //-------------------------assureurs--------------------------
    ui->tabassureurs->setStyleSheet("QTableView QTableCornerButton::section {"
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
    ui->marge_haute_2->setStyleSheet("background-color: #2780e3;"
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
    ui->modifier_assurances->setStyleSheet(pb2);
    ui->supprimer_assurances->setStyleSheet(pb2);
    ui->ajouter_assurances->setStyleSheet(pb2);

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

    ui->label_19->setStyleSheet("	background-color: transparent;"
                                "color:black"
                                );
    ui->label_20->setStyleSheet("	background-color: transparent;"
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
    ui->opt_deconnexion->setStyleSheet(pb1);
    ui->pb_opt_mail->setStyleSheet(pb1);
    ui->pb_opt_stats->setStyleSheet(pb1);
    ui->pb_opt_assurances->setStyleSheet(pb1);

}
void MainWindow::notifications()
{
    mSystemTrayIcon=new QSystemTrayIcon(this);
    mSystemTrayIcon->setIcon(QIcon(":/smart_logo.png"));
    mSystemTrayIcon->setVisible(true);
    QSqlQuery query;
    query.prepare("select * from assurances where (sysdate > DATE_FIN)");

    if(query.exec())
    {
        while(query.next())
          {
            mSystemTrayIcon->showMessage(tr("Alerte!!"),tr("assurances expirée"));
          }
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

bool MainWindow::verifier_entier(QString x)
{
    int i=0;
    for(i=0;i<x.length()&&(x[i]<9 && x[i]>0);i++);
    if(x[i]<=9 && x[i]>=0)
        return true;
    else
       return false;
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
}

void MainWindow::on_pushButton_clicked()
{

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
    ui->tabassureurs->setModel(tmpassureurs.afficher());
}

void MainWindow::on_ajouter_assureurs_clicked()
{

    if(controle_de_saisie_assureurs())
       {
        assureurs a( ui->id_assureurs->text().toInt(),ui->tel_assureurs->text().toInt(),ui->nom_assureurs->text(),ui->mail_assureurs->text());
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
            ui->tel_assureurs->setText(qry.value(2).toString());
            ui->mail_assureurs->setText(qry.value(3).toString());
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
assureurs a(ui->id_assureurs->text().toInt(),ui->tel_assureurs->text().toInt(),ui->nom_assureurs->text(),ui->mail_assureurs->text());


        if (controle_de_saisie_assureurs())
        {
            annuler_messages_assureurs();
            if(existance_assureur(ui->id_assureurs->text().toInt()))
             {

              bool test=a.modifier(ui->id_assureurs->text().toInt(),ui->tel_assureurs->text().toInt(),ui->nom_assureurs->text(),ui->mail_assureurs->text());
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


void MainWindow::on_pb_calendrier_clicked()
{
    if(ui->calendarWidget->isVisible())
    {
        ui->calendarWidget->setHidden(true);
    }
    else
        ui->calendarWidget->setVisible(true);
}

void MainWindow::on_calendarWidget_activated(const QDate &date)
{
    ui->date_assurances->setDate(date);
}
