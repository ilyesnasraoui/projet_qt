#include "modifier_assurance.h"
#include "ui_modifier_assurance.h"
#include "mainwindow.h"
#include <QString>
modifier_assurance::modifier_assurance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier_assurance)
{
    ui->setupUi(this);
}

modifier_assurance::~modifier_assurance()
{
    delete ui;
}

void modifier_assurance::on_modifier_assurance_pb_clicked()
{
    int id = ui->modifier_id_assurance->text().toInt();
    QString nom= ui->modifier_nom_assurance->text();
    QString type=ui->modifier_type_assurance->text();

    assurances a(id,nom,type);
    a.modifier(id,nom,type) ;
    bool test=a.modifier(id,nom,type);
    if(test)
    {   QMessageBox::information(nullptr, QObject::tr("Modifier une assurance"),
                                 QObject::tr("Assurance modifiée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier une assurance"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
