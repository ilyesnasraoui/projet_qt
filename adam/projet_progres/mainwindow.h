#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <client.h>
#include <categorie.h>
#include <voiture.h>
#include <QMainWindow>
#include<fidelite.h>
#include "reclamation.h"
#include "contrat.h"
#include "promotion.h"
#include "evenement.h"
#include "employee.h"
#include "departement.h"
//---------------------------------
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QMainWindow>
#include <QDateTime>
#include "assurances.h"
#include "smtp.h"
#include "assureurs.h"
#include <QDialog>
#include <QMessageBox>
#include <QTimer>
#include <QtWidgets/QMainWindow>

#include <QtCharts/QChartView>

#include <QtCharts/QBarSeries>

#include <QtCharts/QBarSet>

#include <QtCharts/QLegend>

#include <QtCharts/QBarCategoryAxis>

#include <QtCharts/QHorizontalStackedBarSeries>

#include <QtCharts/QLineSeries>

#include <QtCharts/QCategoryAxis>

#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE



//---------------------------------

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class QSystemTrayIcon;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //-----------------------------------------------------------
    void theme_normal();

    void theme_sombre();

    void notifications();

    void on_tri_croissant_assurances_clicked();

    void on_tri_decroissant_assurances_clicked();

    void on_pb_recherche_assurances_clicked();

    void on_tabassurances_activated(const QModelIndex &index);

    void on_modifier_assurances_clicked();

    void on_ajouter_assurances_clicked();

    void on_supprimer_assurances_clicked();

    bool controle_de_saisie();

    void annuler_messages();

    bool existance_assurance(int);

    void on_clear_clicked();


    void on_barre_recherche_assurances_textChanged(const QString &arg1);



    void on_opts_clicked();

    void on_opt_theme_clicked();


    void on_pushButton_clicked();


    void on_pb_opt_assureurs_clicked();

    void on_pb_opt_assurances_clicked();


    void on_clear_2_clicked();

    void on_ajouter_assureurs_clicked();

    void on_supprimer_assureurs_clicked();

    void on_modifier_assureurs_clicked();

    void annuler_messages_assureurs();

    bool controle_de_saisie_assureurs();

    void on_barre_recherche_assureurs_textChanged(const QString &arg1);

    void on_pb_recherche_assureurs_clicked();

    void on_tri_croissant_assureurs_clicked();

    void on_tri_decroissant_assureurs_clicked();

    bool existance_assureur(int );

    void on_tabassureurs_activated(const QModelIndex &index);

    void on_pb_opt_stats_clicked();

    void on_pb_opt_mail_clicked();

    void on_envoyer_mail_clicked();

    bool verif_number(QString);
    bool verif_mail(QString);

    void on_barre_recherche_assureurs_mails_textChanged(const QString &arg1);

    void on_liste_mail_activated(const QModelIndex &index);

    //-----------------------------------------------------------
    void on_tabWidget_currentChanged(int index);


    void on_tabclient_activated(const QModelIndex &index);

    void on_tabclient_clicked(const QModelIndex &index);


    void on_lineEditrecherche_textChanged(const QString &arg1);


    void on_comboBox_currentIndexChanged(int index);


    void on_comboBox_activated(int index);

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();
    void on_ajouter_clicked();
        void on_supprimer_clicked();
        void on_modifier_clicked();
        void on_trie_clicked();
        void on_stat_clicked();
        void on_voituree_clicked();
        void on_categoriee_clicked();

        void on_imprimerr_clicked();

        void on_imprimerrilyes_clicked();
        void on_ajouter_categorie_clicked();
        void on_supprimer_categorie_clicked();
        void on_modifier_categorie_clicked();
        void on_trie_categorie_clicked();
        void on_recherche_clicked();
        void on_rechercheee_clicked();
        void on_tableView_doubleClicked(const QModelIndex &index);
        void on_tableView2_doubleClicked(const QModelIndex &index);

        void on_commandLinkButton_4_clicked();

        void on_tabfidelite_clicked(const QModelIndex &index);

        void on_lineEditrecherchef_textChanged(const QString &arg1);

        void on_commandLinkButton_5_clicked();

        void on_supprimerclient_clicked();

        void on_ajouterclient_clicked();

        void on_modifierclient_clicked();

        void on_ajouterfid_clicked();

        void on_checkBox_clicked();

        void on_AJOUTERC_2_clicked();

        void on_modifierc_2_clicked();

        void on_data2_clicked(const QModelIndex &index);

        void on_Supprimerc_2_clicked();

        void on_pushButton_12_clicked();

        void on_searchc_textChanged(const QString &arg1);

        void on_pushButton_13_clicked();

        void on_ajouter_2_clicked();

        void on_pushButton_14_clicked();

        void on_pushButton_15_clicked();

        void on_pb_ajouterE_clicked();

        void on_pb_modifierE_clicked();

        void on_pb_supprimerE_clicked();

        void on_comboBoxE_2_currentIndexChanged(int index);

        void on_pb_rechercherE_clicked();

        void on_pb_count_clicked();

        void on_pb_ajouterP_clicked();

        void on_pb_supprimer_clicked();

        void on_pb_modifierP_clicked();

        void on_comboBoxP_currentIndexChanged(int index);

        void on_pb_rechercherP_clicked();

        void on_tabpromotion_clicked(const QModelIndex &index);

        void on_supprimerfid_clicked();

        void on_statsclient_clicked();

        void on_supprimer_2_clicked();

        void on_modifier_2_clicked();

        void on_data_clicked(const QModelIndex &index);

        void on_tribox_currentTextChanged(const QString &arg1);

        void on_search_textChanged(const QString &arg1);

        void on_pushButton_2_clicked();

        void on_modifierfid_clicked();

        void on_checkBox_stateChanged(int arg1);

        void on_checkBox_2_clicked();

        void on_checkBox_3_clicked();

        void on_pushButton_16_clicked();

        void on_pushButton_17_clicked();

        void on_pb_ajouterr_clicked();

        void on_pb_supprimerr_clicked();

        void on_pb_modifierr_clicked();

        void on_pb_stat_emp_clicked();

        void on_pb_trierr_clicked();

        void on_pb_recherchee_clicked();

        void on_pb_ajouterr_2_clicked();

        void on_pb_modifierr_2_clicked();

        void on_pb_supprimerr_2_clicked();

        void on_pb_recherchee_2_clicked();

        void on_pb_trierr_2_clicked();

        void on_checkBox_4_clicked();

        void on_checkBox_4_stateChanged(int arg1);

        void on_pb_calendrier_clicked();

        void on_calendarWidget_clicked(const QDate &date);
        void on_pb_devis_clicked();

        void on_data2_doubleClicked(const QModelIndex &index);

        void on_tabemployee_2_clicked(const QModelIndex &index);

        void on_tabemployee_clicked(const QModelIndex &index);

        void on_checkBox_2_stateChanged(int arg1);

        void on_pushButton_3_clicked();



        void on_checkBox_5_clicked();
        void on_checkBox_6_clicked();
        void on_checkBox_7_clicked();
        void on_checkBox_8_clicked();



private:
//--------------------------------------
        QTimer *timer;
        assurances tmpassurances;
        assureurs tmpassureurs;
        QSystemTrayIcon *mSystemTrayIcon;
        bool theme;
//---------------------------------------
    Ui::MainWindow *ui;
    fidelite tmpfid ;
   contrat tmpcontrat ;
   reclamation tmpreclamation;
    client tmpclient;
    voiture tmpvoiture;
        categorie tmpcategorie;
        promotion tmppromotion;
        evenement tmpevenement;
        Employee tmpemployee ;
        departement tmpdep ;
        MainWindow *ch;
};

#endif // MAINWINDOW_H
