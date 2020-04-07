#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "promotion.h"
#include "evenement.h"
#include <QMainWindow>
#include<QMessageBox>

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
    void on_pb_ajouterP_clicked();
    void on_pb_ajouterE_clicked();
    void on_pb_modifierP_clicked();
    void on_pb_modifierE_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_supprimerE_clicked();
    void on_pb_rechercherE_clicked();
    void on_pb_rechercherP_clicked();
    void on_pb_triP_clicked();
    void on_pb_triE_clicked();
private:
    Ui::MainWindow *ui;
    promotion tmppromotion;
    evenement tmpevenement;
};
#endif // MAINWINDOW_H
