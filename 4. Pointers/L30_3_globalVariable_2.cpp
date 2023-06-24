// 

#include<iostream>
using namespace std;

double pi = 3.14;

void fun1() {
    pi++;
    cout << pi << endl;
}

void fun2() {
    cout << pi << endl;
}

int main() {
    cout << pi << endl;
    
    fun1();
    
    pi++;
    cout << pi << endl;
    
    fun2();
    
    return 0;
}