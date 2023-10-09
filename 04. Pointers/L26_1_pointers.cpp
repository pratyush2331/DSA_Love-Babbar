// understanding pointers - 2

#include<iostream>
using namespace std;

int main() {

    // /*
    int arr[10] = {10, 20, 30, 40};

    cout << " address of 1st memory block is " << arr << endl;
    cout << " address of 1st memory block is " << &arr[0] << endl;

    cout << " first element : " << *arr << endl;
    cout << "hi1 : " << *arr + 1 << endl;
    cout << "hi2 : " << *(arr + 1) << endl;

    int i = 3;
    cout << arr[i] << " = " << *(arr + i) << " = " << *(i + arr) << " = " << i[arr] << endl;
    // */

    /*
    int temp[10] = {1, 2};
    cout << sizeof(temp) << endl;  // size of temp[] array
    cout << sizeof(*temp) << endl; // size of int
    cout << sizeof(&temp) << endl; // size of address of temp
    cout << sizeof(&temp[0]) << endl; // size of address of temp
    cout << endl;

    int *ptr = temp;
    cout << sizeof(ptr) << endl;  // size of ptr (because ptr is storing address)
    cout << sizeof(*ptr) << endl; // size of int
    cout << sizeof(&ptr) << endl; // size of address of ptr
    */

    /*
    int a[20] = {1, 2, 3, 4};

    cout << &a[0] << endl;
    cout << &a << endl;
    cout << a << endl;
    cout << endl;

    int *p = &a[0];

    cout << p << endl;  // &a[0]
    cout << *p << endl; // a[1]
    cout << &p << endl; // address of p (pointer)
    */

    /*
    int arr[10] = {1, 2 ,3};
    cout << arr << endl;
    // arr = arr + 1;       --->       ERROR, arr is a constant pointer (declared in Symbol Table)

    int *ptr = &arr[0];
    ptr = ptr + 1;
    cout << ptr << endl;
    */
    
    return 0;
}