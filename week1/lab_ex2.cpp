#include <iostream>
using namespace std;
int main () {
    int array[10];
    int even = 0;
    int numEven[0];
    for (int i = 0 ; i<10; i++){
        cout<<"input number: ";
        cin>>array[i];
    }
    cout <<"Array :";
    for(int i = 0 ; i<10 ; i++) {
         cout <<array[i]<<" " ;
    }
    cout <<"\nReverse Array :";
    for (int i=9 ; i>=0 ; i--){
        cout<<array[i]<<" ";
    }
    cout<<"\nEven Number :";
    for ( int i = 0 ; i <10 ; i++){
        if( array[i] % 2 == 0){
            even++;
            numEven[i] = array[i];
            cout<<numEven[i]<<" ";

        }
    }

    
}