// 3266. Final Array State After K Multiplication Operations II
// LeetCode : https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-ii/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    // modular exponentiation
    int powMod(long long base, int exp, int mod){
        long long res = 1;
        while(exp) {
            if(exp&1) {
                res *= base;
                res %= mod;
            }
            base *= base;
            base %= mod;
            exp >>= 1;
        }
        return res;
    }

public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier == 1) return nums; // imp

        int n = nums.size();
        const int MOD = 1e9 + 7;

        // min heap --> {ele, idx}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }

        const long maxi = *max_element(nums.cbegin(), nums.cend());
        while(k && 1LL * multiplier * pq.top().first <= maxi) { // making all elements <= maxi
            auto [num, idx] = pq.top();
            pq.pop();

            pq.push({num * multiplier, idx});
            k--;
        }

        long pow = powMod(multiplier, k/n, MOD);
        while(!pq.empty()) {
            auto [num, idx] = pq.top();
            pq.pop();

            if(k%n != 0) {
                nums[idx] = ((1LL * multiplier * pow) % MOD * num ) % MOD;
                k--; // imp
            }
            else {
                nums[idx] = (1LL * pow * num) % MOD;
            }
        }

        return nums;
    }
};


int main() {
        
    return 0;
}