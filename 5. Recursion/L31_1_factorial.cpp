// factorial using recursion

#include<iostream>
using namespace std;

int factorial(int n) {
    
    // base case
    if(n == 0 || n == 1)
        return 1;

    // recurrence relation
    return n * factorial(n-1);
}

int main() {
    int n;
    cin >> n;

    cout << n << "! = " << factorial(n) << endl;
    
    return 0;
}