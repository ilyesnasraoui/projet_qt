#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
     ui->tabclient->setModel(tmpclient.afficher());//refresh
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->tabclient->setModel(tmpclient.afficher());//refresh

}

void MainWindow::on_commandLinkButton_clicked()
{
    QString cin= ui->lineEditcin->text();
    QString nom= ui->lineEditnom->text();
    QString prenom= ui->lineEditprenom->text();
    QString tel= ui->lineEdittel->text();
    int age = ui->lineEditage->text().toInt();
    QString agea = ui->lineEditage->text();

client cl(cin,nom,prenom,tel,age) ;
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
                           QObject::tr("CIN deja existant \n"), QMessageBox::Cancel);}}
    //-----------------------------------------------------------//
//fin controle saisie
    ui->tabclient->setModel(tmpclient.afficher());//refresh
}

void MainWindow::on_tabclient_activated(const QModelIndex &index)
{

}

void MainWindow::on_tabclient_clicked(const QModelIndex &index)
{
    ui->lineEditcin->setText(ui->tabclient->model()->data(ui->tabclient->model()->index(ui->tabclient->currentIndex().row(),0)).toString());
    ui->lineEditcins->setText(ui->tabclient->model()->data(ui->tabclient->model()->index(ui->tabclient->currentIndex().row(),0)).toString());
}

void MainWindow::on_commandLinkButton_3_clicked()
{
    QString cin= ui->lineEditcin->text();
    QString prenom= ui->lineEditnom->text();
    QString nom= ui->lineEditprenom->text();
    QString tel= ui->lineEdittel->text();
    int age = ui->lineEditage->text().toInt();
client cl(cin,nom,prenom,tel,age) ;



    bool test=cl.modifier();

    ui->tabclient->setModel(tmpclient.afficher());//refresh
}

void MainWindow::on_lineEditrecherche_textChanged(const QString &arg1)
{      QString prenom= ui->lineEditrecherche->text();

    ui->tabclient->setModel(tmpclient.chercher(prenom));//recherche
}

void MainWindow::on_commandLinkButton_2_clicked()
{ client cl;
     QString cin= ui->lineEditcins->text();
     cl.supprimer(cin);
     ui->tabclient->setModel(tmpclient.afficher());//refresh

}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{


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
