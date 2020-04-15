#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "voiture.h"
#include "categorie.h"
#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    voiture tmpvoiture;
    categorie tmpcategorie;
};

#endif // MAINWINDOW_H
