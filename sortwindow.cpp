#include "sortwindow.h"
#include "ui_sortwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include <string>
#include "testbarchart.h"
#include "src/Sorts.h"


sortwindow::sortwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sortwindow)
{
    ui->setupUi(this);
}

sortwindow::~sortwindow()
{
    delete ui;
}


void sortwindow::on_pushButton_clicked()
{
    QStringList filenames = QFileDialog::getOpenFileNames(this,tr("TXT files"),QDir::currentPath(),tr("Text files (*.txt);;All files (*.*)") );
    if(!filenames.isEmpty())
    {
        for (int i = 0;i<filenames.count();i++)
            ui->listWidget->addItem(filenames.at(i));
    }
}



void sortwindow::on_Sort_button_clicked()
{

    if (ui->listWidget->count() != 0){

    int names_counter = ui->listWidget->count();

    std::vector<QString> name_vector;
    std::vector<int> Q_swaps_vector;
    std::vector<int> I_swaps_vector;
    std::vector<int> Q_comparison_vector;
    std::vector<int> I_comparison_vector;
    std::vector<double> Q_time_vector;
    std::vector<double> I_time_vector;

    for (int i= 0; i < names_counter; i++){
        name_vector.push_back(ui->listWidget->item(i)->text());
    }

    QuickSorter QS;
    IntroSorter IS;
    for (int i=0; i<names_counter; i++){
        IS.SetFilePath(name_vector[i].toStdString());
        QS.SetFilePath(name_vector[i].toStdString());
        IS.LoadSequence();
        QS.LoadSequence();
        IS.Sort();
        QS.Sort();
        I_swaps_vector.push_back(IS.GetSwaps());
        Q_swaps_vector.push_back(QS.GetSwaps());
        I_comparison_vector.push_back(IS.GetComparisons());
        Q_comparison_vector.push_back(QS.GetComparisons());
        I_time_vector.push_back(IS.GetTime());
        Q_time_vector.push_back(QS.GetTime());

        if (ui->checkBox->isChecked()){
            IS.WriteSequenceToFile();
            QS.WriteSequenceToFile();
        }

        IS.Clear();
        QS.Clear();
    }


    testbarchart window;

    window.showChartInt("Перестановки",name_vector,Q_swaps_vector,I_swaps_vector);
    window.showChartInt("Сравнения",name_vector,Q_comparison_vector,I_comparison_vector);
    window.showChartDouble("Затраты по времени(сек)",name_vector,Q_time_vector,I_time_vector);
    this->close();

    }else{
        QMessageBox::warning(this,"Ошибка","Не выбрано ни одной последовательности для сортировки");
    }

}
