#include <iostream>
#include <fstream>
#include<sstream>
using namespace std;
int main(){
    fstream f;
    f.open("mydata.csv" , ios::in);
    string line;
    while (!f.eof()){
        getline(f , line);
        stringstream s(line);
        string item;
        for (int i =1 ; i <=3 ; i++) {
            getline(s, item , " ");
            cout<<item << "\t";
        }


    }
    f.close();
}