// nth fibonacci number

#include<iostream>
using namespace std;

// Method - 1 : iterative aproach
/*
int fib(int n) {
    if(n <= 1)
        return n;
    
    int a = 0, b = 1, c;
    for(int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    
    return c;
}
*/

// Method - 2 : recursive approach
int fib(int n) {
    // base case
    if(n <= 1)
        return n;
    
    // recurrence relation
    return fib(n-1) + fib(n-2);
}

int main() {
    int n;
    cin >> n;

    cout << endl;

    cout << fib(n) << endl;
    
    return 0;
}