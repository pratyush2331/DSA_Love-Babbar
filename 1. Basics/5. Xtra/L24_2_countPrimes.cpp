// LeetCode-204 : Count Primes
/*
total primes strictly less than n
*/

#include<iostream>
#include<vector>
using namespace std;


// Method-1: Normal Method, TC : O(n*√n)
/*
bool isPrime(int n) {
    for(int i = 2; i*i <= n; i++) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;
}

int countPrimes(int n) {
    int count = 0;
    for(int i = 2; i < n; i++) {
        if(isPrime(i)) {
            count++;
        }
    }
    return count;
}
*/


// Method-2: Sieve of Eratosthenes, TC : O(n*log(logn))
// /*
int countPrimes(int n) {
    vector<bool> prime(n+1, 1); // sb ko prime kr de rhe h

    prime[0] = prime[1] = 0; // 0 aur 1 ko non-prime kr diye

    int count = 0;
    for(int i = 2; i < n; i++) {
        if(prime[i]) {
            count++;
            for(int j = i*i; j < n; j = j+i) {
                prime[j] = 0;
            }
        }
    }
    return count;
}
// */

int main() {
    int n;
    cout << "Enter n : ";
    cin >> n;

    cout << countPrimes(n) << endl;
    
    return 0;
}