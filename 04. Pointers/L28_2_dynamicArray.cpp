// Dynamic Memory Allocation of variable and 1D array

#include<iostream>
using namespace std;

int getSum(int* arr, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }  
    return sum;
}

int main() {

    // size of variable in static & dynamic
    /*
    char ch = 'q';
    cout << sizeof(ch) << endl; // size of variable

    char* c = &ch;
    cout << sizeof(c) << endl;  // size of pointer
    */


    // taking input in array dynamically
    // /*
    int n;
    cin >> n;

    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "sum = " << getSum(arr, n) << endl;

    delete[] arr;
    // */


    // DO NOT USE
    /*
    // case 1
    while(true) {
        int i = 5;
    }

    // case 2 ---> DANGEROUS
    while(true) {
        int *ptr = new int;
    }
    */

    return 0;
}