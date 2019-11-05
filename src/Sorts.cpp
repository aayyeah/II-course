#include "Sorts.h"
#include <time.h>
#include <math.h>


using namespace std;

int Sorter::MedianOf3(vector<int> &A, int low, int high){
    int mid = (low + high) / 2;
    comparisons++;
    if(A[mid] < A[low]) {
        swap(A[low], A[mid]);
        swaps++;
    }
    comparisons++;
    if(A[high] < A[low]){
        swap(A[high],A[low]);
        swaps++;
    }
    comparisons++;
    if(A[mid] < A[high]){
        swap(A[high],A[mid]);
        swaps++;
    }
    swap(A[high],A[mid]);
    swaps++;
    return A[high];
}

int Sorter::Partition(vector<int> &A, int low, int high){
    int pivot = MedianOf3(A,low,high);
    int i = low;
    for (int j = low; j<high; j++){
        comparisons++;
        if (A[j] <= pivot){
            swap(A[i],A[j]);
            swaps++;
            i++;
        }
    }
    swap(A[i], A[high]);
    swaps++;
    return i;
}

void Sorter::Quicksort(vector<int> &A, int low, int high){
    if (low<high){
        int p = Partition(A,low,high);
        Quicksort(A,low,p-1);
        Quicksort(A,p+1, high);
    }
}


void Sorter::WriteSequenceToFile(){
    string new_path;
    new_path = this->filepath;

    int i = new_path.length();

    while (new_path[i] != '.')
        i--;

    string tst = "";
    for (int k = 0; k<i;k++)
        tst = tst + new_path[k];


    new_path = tst + "_sorted.txt";

    std::ofstream out;

    out.open(new_path);

    if (out.is_open()){
        for (int i=0; i<=actualsize;i++)
            out << sequence[i] << " ";
    }

    out.close();

}

void Sorter::Clear(){
    this->sequence.clear();
    this->actualsize = 0;
    this->comparisons = 0;
    this->swaps = 0;
    this->filepath = "";
    this->seconds = 0;
}


void Sorter::SetFilePath(string filepath){
    this->filepath = filepath;
}

int Sorter::LoadSequence(){

    ifstream file;
    file.open(filepath);

    if (file) {
        actualsize = -1;
        int part;
        while (file>>part , !file.eof()) {
            //file >> part;
            sequence.push_back(part);
            actualsize++;
        }

        file.close();
        return 0;
    }
    return 1;
}

int Sorter::GetComparisons(){
    return comparisons;
}

int Sorter::GetSwaps(){
    return swaps;
}

double Sorter::GetTime(){
    return seconds;
}

void QuickSorter::Sort(){
    clock_t start = clock();
    Quicksort(sequence,0,actualsize);
    clock_t end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
}

void IntroSorter::IntroSort(vector<int> &A, int maxdepth, int left, int right){
    if (left < right) {
        int n = right - left + 1;
        int p = Partition(A, left, right);
        if (n <= 1) {
            return;
        } else if (maxdepth == 0) {
            heapsort(A, left, right);
        } else {
            IntroSort(A, maxdepth - 1, left, p-1);
            IntroSort(A, maxdepth - 1, p + 1, right);
        }
    }
}

void IntroSorter::heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    this->comparisons++;
    if (l < n && arr[l] > arr[largest])
        largest = l;

    this->comparisons++;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    this->comparisons++;
    if (largest != i)
    {
        this->swaps++;
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void IntroSorter::hSort(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        this->swaps++;
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void IntroSorter::heapsort(vector<int> &A,int left,int right){
    vector<int> B;
    B.clear();
    int low = left;
    int high = right;
    for (int i=left;i<=right;i++)
        B.push_back(A[i]);


    hSort(B,high-low+1);


    for (int i=high;i>=low;i--){
        A[i] = B.back();
        B.pop_back();
    }
}

void IntroSorter::Sort(){

    clock_t start = clock();
    int maxdepth = log10(actualsize)*2; // !
    IntroSort(sequence,maxdepth,0,actualsize);
    clock_t end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;

}

IntroSorter::IntroSorter(){
    this->Clear();
}

QuickSorter::QuickSorter(){
    this->Clear();
}
