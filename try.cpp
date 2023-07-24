// 

#include<iostream>
using namespace std;

int main() {
    int a = 1, b = 4;
    int z = ++a + b++;
    b /= z;
    cout << b-a;
    
    return 0;
}