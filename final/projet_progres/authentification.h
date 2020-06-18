#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class authentification;
}

class authentification : public QDialog
{
    Q_OBJECT

public:
    explicit authentification(QWidget *parent = nullptr);
    ~authentification();

private slots:
    void on_ajouterclient_3_clicked();

private:
    Ui::authentification *ui;
    MainWindow *wind;
};

#endif // AUTHENTIFICATION_H
