// 3196. Maximize Total Cost of Alternating Subarrays
// LeetCode : https://leetcode.com/problems/maximize-total-cost-of-alternating-subarrays/

#include<bits/stdc++.h>
using namespace std;


// using DP : recursion + memoization
/*
TC : O(n)
SC : O(n)
*/
#define ll long long
class Solution {
    int n;

    // flag --> true ==> -(nums[i]) nahi kr skta hai
    // flag --> false ==> -(nums[i]) kr skta hai
    ll solve(int idx, bool flag, vector<int>& nums,N vector<vector<ll>>& dp) {
        if(idx == n) {
            return 0;
        }
        if(dp[idx][flag] != -1) {
            return dp[idx][flag];
        }

        // take --> alternate +/-
        ll take = 0;
        if(flag) {
            take = nums[idx] + solve(idx+1, false, nums, dp);
        }
        else {
            take = -nums[idx] + solve(idx+1, true, nums, dp);
        }
        // not take --> only +
        ll notTake = nums[idx] + solve(idx+1, false, nums, dp);;
        return dp[idx][flag] = max(take, notTake);
    }

public:
    long long maximumTotalCost(vector<int>& nums) {
        n = nums.size();
        vector<vector<ll>> dp(n, vector<ll>(2, -1));
        return solve(0, true, nums, dp);
    }
};


int main() {
    
    return 0;
}