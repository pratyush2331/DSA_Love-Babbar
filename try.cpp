// 

#include<iostream>
using namespace std;

int main() {

    int n = 45;
    while(n) {
        cout << (n&1) << " ";
        n = n >> 1;
    }
    
    return 0;
}