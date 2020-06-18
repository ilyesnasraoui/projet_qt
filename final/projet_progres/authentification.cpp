#include "authentification.h"
#include "ui_authentification.h"
#include "mainwindow.h"
#include "assurances.h"

authentification::authentification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authentification)
{
    ui->setupUi(this);
}

authentification::~authentification()
{
    delete ui;
}

void authentification::on_ajouterclient_3_clicked()
{

}
