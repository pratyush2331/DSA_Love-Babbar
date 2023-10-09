// Reference Variable

#include<iostream>
using namespace std;

// pass by value
void update1(int n) {
    n++;
}

// pass by reference
void update2(int &n) {
    n++;
}

// return by reference ---> DO NOT USE (local variable, out of scope)
/*
int& func(int n) {
    int a = n;
    int& ans = a;
    return ans;
}
*/

// return by pointer ---> DO NOT USE (local variable, out of scope)
/*
int* fun(int n) {
    int* ptr = &n;
    return ptr;
}
*/

int main() {
    /*
    int i = 5;
    cout << "i = " << i << endl;
    // refence variable
    int &j = i; // j is a reference to i
    cout << "j = " << j << endl;
    */

    int n = 5;
    // /*
    cout << "Before : " << n << endl;
    update1(n);
    cout << "After  : " << n << endl;
    cout << endl;
    
    cout << "Before : " << n << endl;
    update2(n);
    cout << "After  : " << n << endl;
    // */


    // cout << func(n) << endl; ---> DO NOT USE
    
    // fun(n); ---> DO NOT USE
    
    return 0;
}