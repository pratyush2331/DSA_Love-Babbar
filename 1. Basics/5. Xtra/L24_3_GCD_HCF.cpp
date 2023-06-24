// GCD/HCF of 2 numbers

#include<iostream>
using namespace std;

// Naive Approach
/*
int gcd(int a, int b) {
    if(a == 0) return b;
    if(b == 0) return a;

    int ans = 1;
    int mini = a<b ? a : b;
    for(int i = 1; i <= mini; i++) {
        if((a%i == 0) && (b%i == 0)) {
            ans = i;
        }
    }
    return ans;
}
*/

// ---------------------------------------------------------------------------------------------------------------

// Eucledean Algorithm : using minus (time consuming)
/*
int gcd(int a, int b) {
    if(a == 0) return b;
    if(b == 0) return a;

    while(a != b) { // while(a != 0 && b != 0) {            Reason: kyonki koi ek number dusre k equal ho k 0 bnega
        if(a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
    return a;
}
*/

// ----------------------------------------------------------------------------------------------------------------

// Eucledean Algorithm : using modulo (Optimal Method)
// TC : O(Log min(a,b))
// /*
int gcd(int a, int b) {
    if(a == 0) return b;
    if(b == 0) return a;

    while(a != 0 && b != 0) {
        if(a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    return a>b ? a : b;
}
// */

int main() {
    int a, b;
    cout << "Enter 2 numbers : ";
    cin >> a >> b;

    cout << "GCD of " << a << " & " << b << " is " << gcd(a, b) << endl;
    
    return 0;
}