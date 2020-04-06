#ifndef DIALOGRECLAMATION_H
#define DIALOGRECLAMATION_H

#include <QDialog>

namespace Ui {
class Dialogreclamation;
}

class Dialogreclamation : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogreclamation(QWidget *parent = nullptr);
    ~Dialogreclamation();

private:
    Ui::Dialogreclamation *ui;
};

#endif // DIALOGRECLAMATION_H
