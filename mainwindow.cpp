#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "generationwindow.h"
#include "sortwindow.h"
#include <QGraphicsWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ToGeneration_clicked()
{
    generationwindow GWIN;
    GWIN.setModal(true);
    GWIN.exec();
}

void MainWindow::on_ToSort_clicked()
{
    sortwindow srt;
    srt.setModal(true);
    srt.exec();

}
