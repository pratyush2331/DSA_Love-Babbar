// Pointers - Intro

#include<iostream>
using namespace std;

int main() {
    int num = 5;

    cout << "num = " << num << endl;

    // address of operator - &
    cout << " address of num is " << &num << endl;

    int *ptr = &num;

    // value at address - *
    cout << "value of num is " << *ptr << endl;
    cout << " address of num is " << ptr << endl;
    cout << " address of ptr is " << &ptr << endl;

// ---------------------------------------------------------------------

    double d = 4.2;
    double *p = &d;

    cout << "value of d is " << *p << endl;
    cout << "address of d is " << p << endl;
    
    cout << " size of integer : " << sizeof(num) << endl;
    cout << " size of double : " << sizeof(d) << endl;
    cout << " size of integer pointer : " << sizeof(ptr) << endl;
    cout << " size of double pointer : " << sizeof(p) << endl;

    return 0;
}