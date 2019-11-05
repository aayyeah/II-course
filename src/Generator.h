#ifndef FOR_KURSACH_GENERATOR_H
#define FOR_KURSACH_GENERATOR_H

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

typedef unsigned long int ulong;

enum GenerType {up,down,def,same,part};

class Generator{
private:
    std::ofstream out;
    string filepath;

    bool checkFile(string file_name);

    void UPGenerator(int size);

    void DOWNGenerator(int size);

    void DEFGenerator(int size);

    void SAMEGenerator(int size);

    void PARTGenerator(int size);

public:
    void SetFilePath(string filepath);

    void Generate(GenerType gt,int size);
};


#endif //FOR_KURSACH_GENERATOR_H
