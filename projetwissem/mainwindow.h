#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <client.h>
#include <categorie.h>
#include <voiture.h>
#include <QMainWindow>
#include<fidelite.h>

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

private:
    Ui::MainWindow *ui;
    fidelite tmpfid ;

    client tmpclient;
    voiture tmpvoiture;
        categorie tmpcategorie;
};

#endif // MAINWINDOW_H
