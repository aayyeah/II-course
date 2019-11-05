#ifndef SORTWINDOW_H
#define SORTWINDOW_H

#include <QFileDialog>
#include <string>
#include <vector>
#include "QListWidget"


namespace Ui {
class sortwindow;
}

class sortwindow : public QDialog
{
    Q_OBJECT

public:
    explicit sortwindow(QWidget *parent = nullptr);
    ~sortwindow();

private slots:
    void on_pushButton_clicked();

    void on_Sort_button_clicked();

private:
    Ui::sortwindow *ui;
};

#endif // SORTWINDOW_H
