#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <client.h>
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
    void on_tabWidget_currentChanged(int index);

    void on_commandLinkButton_clicked();

    void on_tabclient_activated(const QModelIndex &index);

    void on_tabclient_clicked(const QModelIndex &index);

    void on_commandLinkButton_3_clicked();

    void on_lineEditrecherche_textChanged(const QString &arg1);

    void on_commandLinkButton_2_clicked();

    void on_comboBox_currentIndexChanged(int index);


    void on_comboBox_activated(int index);

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
    client tmpclient;
};

#endif // MAINWINDOW_H
