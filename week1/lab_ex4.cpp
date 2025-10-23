#include<iostream>
using namespace std;
float sum_of_number(int n){
    return n*(n+1)/2;
}
float Sum_of_squares(int n){
    return n*(n+1)*(2*n+1)/6;
}
float Harmonic_number(int n){
    float sum = 0;
    for (int i = 1 ; i <n ; i++){
        sum += (float)1/i;
    
    }
    return sum; 
    
}
int main () {
    cout<<sum_of_number(10)<<endl;
    cout<<Sum_of_squares(7)<<endl;
    cout<<Harmonic_number(3)<<endl;
}
