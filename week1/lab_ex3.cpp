#include <iostream>
using namespace std;
int main () {
    int a[]= {10,20,0,-5,9,7};
    int min = a[0];
    int max = a[0];
    int size = sizeof(a) /sizeof(a[0]);
    cout << "Array : ";
    for (int i = 0 ; i < size ; i ++){
        cout << " " << a[i];
        if ( a[i] < min){
            min = a[i];
        }
        if (a[i] > max){
            max = a[i];
        }
    }

    cout << "\nmin is" << min << endl;
    cout << "max is" << max << endl;
}