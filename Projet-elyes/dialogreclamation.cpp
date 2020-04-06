#include "dialogreclamation.h"
#include "ui_dialogreclamation.h"

Dialogreclamation::Dialogreclamation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogreclamation)
{
    ui->setupUi(this);
}

Dialogreclamation::~Dialogreclamation()
{
    delete ui;
}
