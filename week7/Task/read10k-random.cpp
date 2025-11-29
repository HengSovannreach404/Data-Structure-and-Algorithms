#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;


//Team members: IN UDDAM DARREN, Born Chansothearith,Heng SovannReach

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int Index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[Index]) {
                Index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[Index];
        arr[Index] = temp;
    }
}

bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}

int main() {
    const int SIZE = 10000;
    const int COLS = 10;
    int numbers[SIZE];

    srand(time(0));

    ofstream out("numbers.csv");
    if (!out) return 1;

    for (int i = 0; i < SIZE; i++) {
        int num = 10 + rand() % 991;
        out << num;
        if ((i + 1) % COLS == 0)
            out << "\n";
        else
            out << ",";
    }
    out.close();

    ifstream in("10K.csv");
    if (!in) return 1;

    char comma;
    for (int i = 0; i < SIZE; i++) {
        in >> numbers[i];
        if (i % COLS != COLS - 1) in >> comma;
    }
    in.close();

    int bubbleArr[SIZE];
    for (int i = 0; i < SIZE; i++) bubbleArr[i] = numbers[i];
    bubbleSort(bubbleArr, SIZE);

    int selectionArr[SIZE];
    for (int i = 0; i < SIZE; i++) selectionArr[i] = numbers[i];
    selectionSort(selectionArr, SIZE);


    return 0;
}