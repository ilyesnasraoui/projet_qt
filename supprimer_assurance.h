#ifndef SUPPRIMER_ASSURANCE_H
#define SUPPRIMER_ASSURANCE_H
#include <QMainWindow>
#include <QDialog>
#include "assurances.h"
#include <QMessageBox>
#include "connexion.h"

namespace Ui {
class supprimer_assurance;
}

class supprimer_assurance : public QDialog
{
    Q_OBJECT

public:
    explicit supprimer_assurance(QWidget *parent = nullptr);
    ~supprimer_assurance();

private slots:
    void on_pb_confirmer_supp_clicked();

private:
    Ui::supprimer_assurance *ui;
    assurances tmpassurances;
};

#endif // SUPPRIMER_ASSURANCE_H
