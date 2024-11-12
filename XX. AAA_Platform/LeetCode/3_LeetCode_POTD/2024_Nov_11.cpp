// 2601. Prime Subtraction Operation
// LeetCode : https://leetcode.com/problems/prime-subtraction-operation/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    // Helper function to generate primes up to a given limit
    void generatePrimes(int limit, vector<int>& primes) {
        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (int j = i * 2; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

public:
    bool primeSubOperation(vector<int>& nums) {
        // Precompute primes up to 1000
        vector<int> primes;
        generatePrimes(1000, primes);

        int n = nums.size();
        int prev = nums[n - 1];
        bool flag = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < prev) {
                prev = nums[i];
                continue;
            }

            // Try to find a prime to subtract so that `nums[i] - prime < prev`
            flag = 1;
            for (int sub = 0; sub < primes.size() && primes[sub] < nums[i]; sub++) {
                if (nums[i] - primes[sub] < prev) {
                    prev = nums[i] - primes[sub];
                    flag = 0;
                    break;
                }
            }
            if (flag) return false;
        }
        return true;
    }
};


int main() {
    
    return 0;
}