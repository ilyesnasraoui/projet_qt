#include "statistiques.h"
#include "ui_statistiques.h"

statistiques::statistiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiques)
{
    ui->setupUi(this);
    QPieSeries *series =new QPieSeries();
    int x=0,y=0;
    x=calculer_nom();
    y=calculer_type();
    series->append("C++",x);
    series->append("java",y);


    QChart *chart=new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques assurances");


    QChartView *chartview = new QChartView(chart);
    chartview->setParent(ui->horizontalFrame);
}

statistiques::~statistiques()
{
    delete ui;
}
int statistiques:: calculer_nom()
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM assurances where nom=star");
    query.next();
    int star_assurance_number;
    star_assurance_number= query.value(0).toInt();
    query.exec();
}
int statistiques::calculer_type()
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM assurances");
    query.next();
    int star_assurance_number;
    star_assurance_number= query.value(0).toInt();
    query.exec();

}
