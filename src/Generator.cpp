#include "Generator.h"


bool Generator::checkFile(string file_name) {
    ifstream file;
    file.open(file_name);
    if(!file) {
        file.close();
        return false;
    }
    file.close();
    return true;
}

void Generator::UPGenerator(int size){
    string type = "/up_";
    int number = 0;

    while (checkFile(filepath + type + to_string(size) + "_" + to_string(number) + ".txt")){
        number++;
    }

    out.open(filepath + type + to_string(size) + "_" + to_string(number) + ".txt");

    int t = 1;

    if (out.is_open()){
        while (size >0) {
            t = t + rand()%100;
            out << t << " ";
            size--;
        }
    }

    out.close();
}

void Generator::DOWNGenerator(int size){
    string type = "/down_";
    int number = 0;

    while (checkFile(filepath + type + to_string(size) + "_" + to_string(number) + ".txt")){
        number++;
    }

    out.open(filepath + type + to_string(size) + "_" + to_string(number) + ".txt");

    int t = size * 50;

    if (out.is_open()){
        while (size >0) {
            int t = t - rand()%100;
            out << t << " ";
            size--;
        }
    }

    out.close();
}

void Generator::DEFGenerator(int size){
    string type = "/def_";
    int number = 0;

    while (checkFile(filepath + type + to_string(size) + "_" + to_string(number) + ".txt")){
        number++;
    }

    out.open(filepath + type + to_string(size) + "_" + to_string(number) + ".txt");

    int k = size;

    if (out.is_open()){
        while (size >0) {
            out << rand()%k << " ";
            size--;
        }
    }

    out.close();
}

void Generator::SAMEGenerator(int size){
    string type = "/same_";
    int number = 0;

    while (checkFile(filepath + type + to_string(size) + "_" + to_string(number) + ".txt")){
        number++;
    }

    out.open(filepath + type + to_string(size) + "_" + to_string(number) + ".txt");

    int k = rand()%size;

    if (out.is_open()){
        while (size >0) {
            out << k << " ";
            size--;
        }
    }

    out.close();
}

void Generator::PARTGenerator(int size){
    string type = "/part_";
    int number = 0;

    while (checkFile(filepath + type + to_string(size) + "_" + to_string(number) + ".txt")){
        number++;
    }

    out.open(filepath + type + to_string(size) + "_" + to_string(number) + ".txt");

    if (out.is_open()){
        int k = size;
        int d = 0;
        bool flag = true;
        int r = 0;
        while (size > 0) {


            if (d <= 0) {
                d = rand() % 20 ;
                flag = !flag;
                r = rand()%k;
            }

            if (flag) {
                out << rand()%k << " ";
                size--;
                d--;
            }else{
                out << r << " ";
                size--;
                d--;
            }
        }
    }

    out.close();
}

void Generator::SetFilePath(string filepath){
    this->filepath = filepath;
}

void Generator::Generate(GenerType gt,int size){

    switch(gt){
        case up:
            UPGenerator(size);
            break;
        case down:
            DOWNGenerator(size);
            break;
        case def:
            DEFGenerator(size);
            break;
        case same:
            SAMEGenerator(size);
            break;
        case part:
            PARTGenerator(size);
            break;
    }
};



