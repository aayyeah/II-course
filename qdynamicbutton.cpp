#include "qdynamicbutton.h"
#include "src/Generator.h"

qdynamicline::qdynamicline(QWidget *parent) : QLineEdit (parent)
{
    ResID++;
    lineID = ResID;
}

qdynamicline::~qdynamicline(){

}

int qdynamicline::getID(){
    return lineID;
}

int qdynamicline::ResID = 0;


qdynamiccombobox::qdynamiccombobox(QWidget *parent) : QComboBox (parent){
    ResID++;
    lineID = ResID;
    this->addItem("Возрастающая",up);
    this->addItem("Убывающая",down);
    this->addItem("Одинаковые элементы",same);
    this->addItem("Случайные элементы",def);
    this->addItem("Частично-упорядоченная",part);

}

qdynamiccombobox::~qdynamiccombobox(){}

int qdynamiccombobox::getID(){
    return lineID;
}

int qdynamiccombobox::ResID = 0;
