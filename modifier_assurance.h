#ifndef MODIFIER_ASSURANCE_H
#define MODIFIER_ASSURANCE_H
#include "assurances.h"
#include <QMessageBox>
#include "connexion.h"
#include <QDialog>
#include <QMainWindow>
namespace Ui {
class modifier_assurance;
}

class modifier_assurance : public QDialog
{
    Q_OBJECT

public:
    explicit modifier_assurance(QWidget *parent = nullptr);
    ~modifier_assurance();

private slots:
    void on_modifier_assurance_pb_clicked();

private:
    Ui::modifier_assurance *ui;
};

#endif // MODIFIER_ASSURANCE_H
