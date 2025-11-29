#include <iostream>
#include <fstream>
using namespace std;
int main () {
    fstream f1;
    f1.open("mydata.csv", ios::out);
    f1<<"Lists of students\n";
    // for(int i = 0 ;i < 20 ; i++){
    //     f1<<i<< " , reach , 18\n ";
    //     cout<< i << " ";
    // }

    int id;
    string name;
    int age;
    f1<<"ID,Name,Age \n";
    for(int i =1 ; i <=3 ; i++){
        cin>>id;
        cin>>name;
        cin>>age;
        f1<<id<<","<<name<<","<<age<< "\n";
        
    }
    f1.close();
    cout<<"DONE!" ;
}