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
