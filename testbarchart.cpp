#include "testbarchart.h"
#include "ui_testbarchart.h"
#include <QChart>
#include <QBarSeries>
#include <QBarSet>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

QT_CHARTS_USE_NAMESPACE

testbarchart::testbarchart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testbarchart)
{
    ui->setupUi(this);
}

testbarchart::~testbarchart()
{
    delete ui;
}

void testbarchart::showtestexample(){

    QBarSet *set0 = new QBarSet("Jane");
    QBarSet *set1 = new QBarSet("John");

    *set0 << 1 << 2 << 3 << 4 << 5 << 6;
    *set1 << 5 << 0 << 0 << 4 << 0 << 7;

    QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);

        QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setTitle("Simple barchart example");
            chart->setAnimationOptions(QChart::SeriesAnimations);

            QStringList categories;
                categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
                QBarCategoryAxis *axis = new QBarCategoryAxis();
                axis->append(categories);
                chart->createDefaultAxes();
                chart->setAxisX(axis, series);

                chart->legend()->setVisible(true);
                    chart->legend()->setAlignment(Qt::AlignBottom);

                    QChartView *chartView = new QChartView(chart);
                        chartView->setRenderHint(QPainter::Antialiasing);
                        chartView->show();


    //QWindow window;
    //QMainWindow window;
    //window.setCentralWidget(chartView);
    //window.resize(400, 300);
    //window.show();
}


void testbarchart::showChartInt(QString name ,std::vector<QString> name_vector,std::vector<int> Q_vector, std::vector<int> I_vector){

    QStringList names;
    QBarSet *setQ = new QBarSet("QuickSort");
    QBarSet *setI = new QBarSet("IntroSort");


    while (Q_vector.size() != 0){
        QString q = QString::number(Q_vector.back());
        QString i = QString::number(I_vector.back());

        QString full_name = name_vector.back();
        int stepper = full_name.length()-5;
        QString short_name = "";
        while (full_name[stepper] != "/"){
            short_name = full_name[stepper] + short_name;
            stepper--;
        }

        names << short_name + "<br>" "(" + q + "/" + i + ")";
        *setQ << Q_vector.back();
        *setI << I_vector.back();
        I_vector.pop_back();
        Q_vector.pop_back();
        name_vector.pop_back();
    }

    QBarSeries *series = new QBarSeries();
        series->append(setQ);
        series->append(setI);

    QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle(name);
        chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(names);
        chart->createDefaultAxes();
        chart->setAxisX(axis, series);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);

        chartView->resize(600,400);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->show();

}

void testbarchart::showChartDouble(QString name ,std::vector<QString> name_vector,std::vector<double> Q_vector, std::vector<double> I_vector){

    QStringList names;
    QBarSet *setQ = new QBarSet("QuickSort");
    QBarSet *setI = new QBarSet("IntroSort");



    while (Q_vector.size() != 0){
        QString q = QString::number(Q_vector.back());
        QString i = QString::number(I_vector.back());

        QString full_name = name_vector.back();
        int stepper = full_name.length()-5;
        QString short_name = "";
        while (full_name[stepper] != "/"){
            short_name = full_name[stepper] + short_name;
            stepper--;
        }

        names << short_name + "<br>" "(" + q + "/" + i + ")";
        *setQ << Q_vector.back();
        *setI << I_vector.back();
        I_vector.pop_back();
        Q_vector.pop_back();
        name_vector.pop_back();
    }

    QBarSeries *series = new QBarSeries();
        series->append(setQ);
        series->append(setI);

    QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle(name);
        chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(names);
        chart->createDefaultAxes();
        chart->setAxisX(axis, series);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);

        chartView->resize(600,400);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->show();

}

