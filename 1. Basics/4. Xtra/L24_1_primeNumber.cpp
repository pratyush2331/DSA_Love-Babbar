// Check Prime

#include<iostream>
using namespace std;

// Efficient Method : O(√n)
bool isPrime(int n) {
    if(n < 2) {
        return false;
    }

    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter n : ";
    cin >> n;

    // cout << n << " is Prime or not : " << isPrime(n) << endl;

    bool ans = isPrime(n);
    if(n < 2)
        cout << n << " is neither prime nor composite" << endl;
    else if(ans&1) 
        cout << n << " is Prime" << endl;
    else 
        cout << n << " is Composite" << endl;

    return 0;
}