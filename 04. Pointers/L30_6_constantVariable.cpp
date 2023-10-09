// constant variable in C++

#include<iostream>
using namespace std;

const int a = 5;

int main() {

    const int b = 10;
    const int* ptr = &b;

    // a++; ---> ERROR, as a is a constant constant variable
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    // (*ptr)++; ---> ERROR, as ptr is a constant pointer
    cout << "*ptr = " << *ptr << endl;
    
    return 0;
}