// 2^n using recursion

#include<iostream>
using namespace std;

int power(int n) {
    // base case
    if(n == 0) 
        return 1;

    // recurrence relation
    return 2 * power(n-1);
}

int main() {
    int n;
    cin >> n;

    cout << "2^" << n << " = " << power(n) << endl;

    return 0;
}