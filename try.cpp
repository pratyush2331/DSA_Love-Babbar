// 

#include<iostream>
using namespace std;

// Euclid's Algo
int GCD(int a, int b) {

}

// normal method
/*
int GCD(int a, int b) {
    if(a == 0) return b;
    if(b == 0) return a;

    int mini = min(a,b);

    for(int i = 2; i <= mini; i++) {
        if(a%i == 0 && b%i == 0)
            return i;
    }

    return 1;
}
*/

int main() {
    int a, b;
    cin >> a >> b;

    cout << GCD(a, b);
    
    return 0;
}