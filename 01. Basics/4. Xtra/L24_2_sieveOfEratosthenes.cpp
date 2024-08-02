// 204. Count Primes [OR] Sieve of Eratosthenes
// LeetCode : https://leetcode.com/problems/count-primes/

/*
total primes strictly less than n
*/

#include<iostream>
#include<vector>
using namespace std;

using ll = long long;


// Method-2: Sieve of Eratosthenes, TC : O(n*log(logn))

// class Solution {
    int sieve(int n) {
        vector<bool> is_prime(n+1, true);
        is_prime[0] = is_prime[1] = false;
        int cnt = 0;
        for(int i = 2; i < n; i++) {
            if(is_prime[i]) {
                cnt++;
                for(ll j = 1LL*i*i; j < n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        return cnt;
    }

// public:
    int countPrimes(int n) {
        return sieve(n);
    }
// };


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
            // cout << i << " ";
            count++;
        }
    }
    return count;
}
*/


int main() {
    int n;
    cout << "Enter n : ";
    cin >> n;

    cout << countPrimes(n) << endl;
    
    return 0;
}