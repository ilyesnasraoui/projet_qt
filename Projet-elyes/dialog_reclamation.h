#ifndef DIALOG_RECLAMATION_H
#define DIALOG_RECLAMATION_H

#include <QDialog>

namespace Ui {
class Dialog_Reclamation;
}

class Dialog_Reclamation : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Reclamation(QWidget *parent = nullptr);
    ~Dialog_Reclamation();

private slots:
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_data_clicked(const QModelIndex &index);

    void on_modifier_clicked();

    void on_search_textChanged(const QString &arg1);

    void on_AJOUTERC_clicked();

    void on_modifierc_clicked();

    void on_Supprimerc_clicked();

    void on_data2_clicked(const QModelIndex &index);

    void on_searchc_textChanged(const QString &arg1);

private:
    Ui::Dialog_Reclamation *ui;
};

#endif // DIALOG_RECLAMATION_H
