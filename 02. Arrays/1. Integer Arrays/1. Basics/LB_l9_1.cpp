// Array

#include<iostream>
using namespace std;

template <class T>
void printArray(T arr[], int size){
    cout<<"Printing Array!"<<endl;
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Printing Done!"<<endl;
}

int main(){

    // Integer Array
    // Method-1
    int arr[10];
    fill_n(arr, 10, 1);         // use in STL

    // Method-2
    // array<int, 10> a;
    // a.fill(1);

    printArray(arr, 10);

    cout<<"Size of array= "<<sizeof(arr)/sizeof(int)<<endl;


    cout<<endl;

    // Character Array
    char ch[10];
    std::fill_n(ch, 10, 'a');
    
    printArray(ch, 10);

    cout<<"Size of array= "<<sizeof(ch)/sizeof(char)<<endl;

    return 0;
}