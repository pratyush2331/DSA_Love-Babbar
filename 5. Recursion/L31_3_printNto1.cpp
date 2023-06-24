// print N to 1 using recursion

#include<iostream>
using namespace std;

// Tail Recursion
void print(int n) {

    // base case
    if(n == 0)
        return ;

    // processing
    cout << n << endl;

    // recurrence relation
    print(n-1);
}

int main() {
    int n;
    cin >> n;
    cout << endl;

    print(n);
    
    return 0;
}