// pointers & functions

#include<iostream>
using namespace std;

void print(int *p) {
    cout << *p << endl;
}

void addressUpdate(int *p) {
    ++p;
}

void valueUpdate(int *p) {
    ++*p;
}

int getSum(int *arr, int n) {   // int getSum(int arr[], int n) {
    cout << "in getSum() : " << sizeof(arr) << endl; // size of pointer *arr

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    /*
    int val = 5;

    int *p = &val;

    cout << "Printing val : ";
    print(p);

    cout << "Before : " << p << endl;
    addressUpdate(p);
    cout << "After  : " << p << endl;

    cout << "Before : " << *p << endl;
    valueUpdate(p);
    cout << "After  : " << *p << endl;
    */

    // /*
    int arr[5] = {1,2,3,4,5};

    cout << "in main()   : " << sizeof(arr) << endl;

    cout << getSum(arr, 5) << endl;
    cout << getSum(arr+3, 2) << endl;
    // */
    
    return 0;
}