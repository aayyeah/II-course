#ifndef TESTBARCHART_H
#define TESTBARCHART_H

#include <QDialog>


#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

namespace Ui {
class testbarchart;
}

class testbarchart : public QDialog
{
    Q_OBJECT

public:
    explicit testbarchart(QWidget *parent = nullptr);
    ~testbarchart();
    void showtestexample();
    void showChartInt(QString name,std::vector<QString> name_vector,std::vector<int> Q_vector, std::vector<int> I_vector);
    void showChartDouble(QString name ,std::vector<QString> name_vector,std::vector<double> Q_vector, std::vector<double> I_vector);


private:
    Ui::testbarchart *ui;
};



#endif // TESTBARCHART_H
