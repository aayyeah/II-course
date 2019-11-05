#ifndef FOR_KURSACH_SORTS_H
#define FOR_KURSACH_SORTS_H

#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <math.h>



using namespace std;

class Sorter{
public:
    int comparisons = 0; // сравнения
    int swaps = 0; // перестановки
    double seconds; // затраченные секунды
    string filepath;
    int actualsize;
    vector<int> sequence;

    int MedianOf3(vector<int> &A, int low, int high);

    int Partition(vector<int> &A, int low, int high);

    void Quicksort(vector<int> &A, int low, int high);

public:
    void Clear();

    void SetFilePath(string filepath);

    int LoadSequence();

    int GetComparisons();

    int GetSwaps();

    double GetTime();

    virtual void Sort() = 0;

    void WriteSequenceToFile();
};

class QuickSorter : public Sorter{
public:
    void Sort();

    QuickSorter();
};

class IntroSorter : public Sorter{
private:
    void IntroSort(vector<int> &A, int maxdepth, int left, int right);

    void heapify(vector<int> &arr, int n, int i);

    void hSort(vector<int> &arr, int n);

    void heapsort(vector<int> &A,int left,int right);

public:
    IntroSorter();

    void Sort();
};


#endif
