#include <iostream>
using namespace std;
int main () {
    int array[3];
    int max =array[0];
    int sum = 0;
    for(int i = 0 ; i<3 ;i++){
        cout<<"input number: ";
        cin>>array[i];
    }
    for (int i = 0 ; i < 3 ; i++){
        sum += array[i];
    }
    float average =(float)sum / 3;
    cout <<"Average of array :"<< average << endl;
    cout <<"Array :";
    for (int i = 0 ; i <3 ; i++){
        cout<< array[i] << " " ;
    }
    for (int i = 0 ; i<3 ; i++){
        if (array[i] > max){
            max = array[i];
        }
    }
    cout <<"\nmax number is : "<< max <<endl;
    cout <<"array at position 3 is "<< array[2]<<endl;
    cout <<"Reverse Array :";
    for (int i=2 ; i>=0 ; i--){
        cout<<array[i]<<" ";
    }
}