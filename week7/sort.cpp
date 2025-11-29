#include <iostream>
#include <fstream>
void swap(int *x , int *y){
    int backup;
    backup = *x;
    *x = *y;
    *y = backup;
}
void bubble_sort(int a[] , int size){
    //using bubble sort
    for(int i =0 ; i< size ; i++) {
        int status = 0;
        for(int k = 0 ; k < size-1 ; k++){
            if(a[k] > a[k+1]){
                swap(&a[k] , &a[k+1]);
                status=1;
            }
        }
        if(status == 0){
            break;
        }
    }
}
void display(int a[] , int size){
    for (int j=0 ; j < size ; j++){
        std::cout << a[j] << " ";
    }
    std::cout<<std::endl;


}
int main () {
    std::fstream f1;
    int a[] ={10 , -1 , 5 , 2 , 7 , 0 , 20 ,21 ,1 , 3 ,4, -2 ,-3};
    int size = sizeof(a) / sizeof(a[0]);
    bubble_sort(a , size);
     std::cout << "\n SORTED ARRAY : \n";
     display(a,size);
}