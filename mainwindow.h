#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "assurances.h"
#include "assureurs.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_tri_croissant_clicked();

    void on_tri_decroissant_clicked();

    void on_boutton_rechercher_clicked();

    void on_assureurs_currentChanged(int index);

    void on_ajouter_pb_clicked();

    void on_supprimer_pb_clicked();

    void on_modifier_pb_clicked();

    void on_statistiques_clicked();

private:
    Ui::MainWindow *ui;
    assurances tmpassurances;
};
#endif // MAINWINDOW_H
