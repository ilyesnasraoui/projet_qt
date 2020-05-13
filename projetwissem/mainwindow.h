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
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
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


        void on_ajouter_categorie_clicked();
        void on_supprimer_categorie_clicked();
        void on_modifier_categorie_clicked();
        void on_trie_categorie_clicked();
        void on_recherche_clicked();
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

private:
    Ui::MainWindow *ui;
    fidelite tmpfid ;
   contrat tmpcontrat ;
   reclamation tmpreclamation;
    client tmpclient;
    voiture tmpvoiture;
        categorie tmpcategorie;
        promotion tmppromotion;
        evenement tmpevenement;
        MainWindow *ch;
};

#endif // MAINWINDOW_H
