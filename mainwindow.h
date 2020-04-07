#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employee.h"
#include "departement.h"
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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_recherche_clicked();

    void on_pushButton_2_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pb_modifier_2_clicked();

    void on_pb_recherche_2_clicked();

private:
    Ui::MainWindow *ui;
    Employee tmpemployee;
    departement tmpdep;
};

#endif // MAINWINDOW_H
