// 3233. Find the Count of Numbers Which Are Not Special
// LeetCode : https://leetcode.com/problems/find-the-count-of-numbers-which-are-not-special

#include<bits/stdc++.h>
using namespace std;

using ll = long long;


// using Sieve of Eratosthenes
class Solution {
    vector<int> primes;

    // precomputing prime numbers till 'r'
    void sieve(int limit) {
        vector<bool> is_prime(limit + 1, true);
        is_prime[0] = is_prime[1] = false;
        for(int i = 2; i <= limit; i++) {
            if(is_prime[i]) {
                primes.push_back(i);
                for(int j = i * i; j <= limit; j += i) {
                    is_prime[j] = false;
                }
            }
        }
    }

public:
    int nonSpecialCount(int l, int r) {
        int limit = sqrt(r);
        sieve(limit);

        vector<int> specialNumbers;
        for(int prime : primes) {
            int special = prime * prime;
            if(special >= l && special <= r) {
                specialNumbers.push_back(special);
            }
        }

        int totalNumbers = r - l + 1;
        int specialCount = specialNumbers.size();
        return totalNumbers - specialCount;
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}