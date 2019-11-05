#ifndef QDYNAMICBUTTON_H
#define QDYNAMICBUTTON_H

#include <QPushButton>
#include <QLineEdit>
#include <QLine>
#include <QComboBox>

class qdynamicline : public QLineEdit
{
    Q_OBJECT
public:
    explicit qdynamicline(QWidget *parent = nullptr);
    ~qdynamicline();
    static int ResID;
    int getID();
public slots:

private:
    int lineID = 0;
};

class qdynamiccombobox : public QComboBox
{
    Q_OBJECT
public:
    explicit qdynamiccombobox(QWidget *parent = nullptr);
    ~qdynamiccombobox();
    static int ResID;
    int getID();
public slots:

private:
    int lineID = 0;
};

#endif // QDYNAMICBUTTON_H
