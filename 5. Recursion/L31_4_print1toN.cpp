// print 1 to N using recursion

#include<iostream>
using namespace std;

// Head Recusrion
void print(int n) {

    // base case
    if(n == 0)
        return ;
    
    // recurrence relation
    print(n-1);

    // processing
    cout << n << endl;
}

int main() {
    int n;
    cin >> n;
    cout << endl;

    print(n);

    return 0;
}