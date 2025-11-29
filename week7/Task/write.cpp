#include <iostream>
#include<fstream>
#include <cstdlib> 
#include <ctime>
using namespace std;
int main (){
    fstream file;
    file.open("10K-number.csv", ios::out);
    srand(time(nullptr));
    int min = 10;
    int max = 1000;
    for (int a = 0 ; a < 10000 ; a++){
        int n = min + (rand() % (max - min + 1));
        file<< n << "\n";
    }
    
    file.close();
}