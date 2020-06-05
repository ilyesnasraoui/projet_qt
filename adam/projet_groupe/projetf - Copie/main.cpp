#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
//-------------------------------------------
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include <QQmlApplicationEngine>
#include<QDebug>


#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>

#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>

#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
    QT_CHARTS_USE_NAMESPACE

//-------------------------------------------

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c;

    bool test=c.ouvrirConnexion();
    MainWindow w;
    if(test)
    {w.show();

}
else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    QQmlApplicationEngine engine;

            engine.load(QUrl(QStringLiteral("qrc:/map.qml")));
    return a.exec();
}
