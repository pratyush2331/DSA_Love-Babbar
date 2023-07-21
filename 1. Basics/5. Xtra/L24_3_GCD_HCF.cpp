// GCD/HCF of 2 numbers

#include<iostream>
using namespace std;

// Naive Approach --> will give TLE
/*
int gcd(int a, int b) {
    if(a == 0) return b;
    if(b == 0) return a;
    
    int mini = min(a,b);
    for(int i = mini; i >= 2; i--) {
        if(a%i == 0 && b%i == 0) return i;
    }
    
    return 1;
}
*/

// ---------------------------------------------------------------------------------------------------------------

// Eucledean Algorithm : using minus (time consuming)
/*
int gcd(int a, int b) {
    if(a == 0) return b;
    if(b == 0) return a;

    while(a != 0 && b != 0) {
        if(a > b) a = a-b;
        else b = b-a;
    }
    return max(a,b);
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
        if(a > b) a = a%b;
        else b = b%a;
    }
    return max(a,b);
}
// */

int main() {
    int a, b;
    cout << "Enter 2 numbers : ";
    cin >> a >> b;

    cout << "GCD of " << a << " & " << b << " is " << gcd(a, b) << endl;
    
    return 0;
}