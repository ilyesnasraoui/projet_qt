#ifndef AJOUTER_ASSRANCES_H
#define AJOUTER_ASSRANCES_H
#include <QMainWindow>
#include <QDialog>
#include "assurances.h"
#include <QMessageBox>
#include "connexion.h"

namespace Ui {
class Ajouter_Assrances;
}

class Ajouter_Assrances : public QDialog
{
    Q_OBJECT

public:
    explicit Ajouter_Assrances(QWidget *parent = nullptr);
    ~Ajouter_Assrances();

private slots:
    void on_ajout_assurance_pb_clicked();

private:
    Ui::Ajouter_Assrances *ui;
};

#endif // AJOUTER_ASSRANCES_H
