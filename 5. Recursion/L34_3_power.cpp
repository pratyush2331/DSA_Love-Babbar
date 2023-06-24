// pow(a, b) using recursion

#include<iostream>
using namespace std;

int power(int a, int b) {
    // base case - 1
    if(b == 0) {
        return 1;
    }

    // base case - 2
    if(b == 1) {
        return a;
    }

    // recurrence relation
    int temp = power(a, b/2);

    if(b&1) { // ODD
        return temp * temp * a;
    }
    else { // EVEN
        return temp * temp;
    }
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << a << "^" << b << " = " << power(a, b) << endl;
    
    return 0;
}