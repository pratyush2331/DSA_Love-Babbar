// 3186. Maximum Total Damage With Spell Casting
// LeetCode : https://leetcode.com/problems/maximum-total-damage-with-spell-casting/

#include<bits/stdc++.h>
using namespace std;


// method-1
/*
TC : O(n)
SC : O(n)
*/
#define ll long long
class Solution {
    unordered_map<int,int> freq;
    vector<ll> dp;

    ll solve(int n, vector<int>& power) {
        if(n < 0) {
            return 0;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        int idx = n;
        ll sum = freq[power[n]] * (ll)power[n];
        idx -= freq[power[n]];
        int diffIdx = idx;
        while(idx >= 0 && (power[n] - power[idx]) <= 2) { // maximum it'll run for 2 times
            idx -= freq[power[idx]];
        }

        ll take = sum + solve(idx, power);
        ll notTake = solve(diffIdx, power);

        return dp[n] = max(take, notTake);
    }

public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        for(auto ele : power) {
            freq[ele]++;
        }
        
        sort(power.begin(), power.end());

        dp.resize(n, -1);
        return solve(n-1, power);
    }
};


// method-0
/*
TC : O(n.logn)
SC : O(n)
*/
# define ll long long
class Solution {
    map<int,int> freq;
    vector<ll> dp;
    vector<int> nextIdx;

    ll solve(int idx, vector<int>& power) {
        if(idx == power.size()) {
            return 0;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        ll take = (freq[power[idx]] * (ll)power[idx]) + solve(nextIdx[idx], power);
        ll notTake = solve(idx + freq[power[idx]], power);

        return dp[idx] = max(take, notTake);
    }

public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        for(auto ele : power) {
            freq[ele]++;
        }

        sort(power.begin(), power.end());

        nextIdx.resize(n, n);
        for(int i = 0; i < n; i++) {
            nextIdx[i] = upper_bound(power.begin() + i + 1, power.end(), power[i] + 2) - power.begin();
        }

        dp.resize(n, -1);
        return solve(0, power);
    }
};


int main() {
    return 0;
}