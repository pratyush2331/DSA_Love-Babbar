// 198. House Robber
// LeetCode : https://leetcode.com/problems/house-robber/

/****************************************************QUESTION****************************************************
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can 
rob tonight without alerting the police.
****************************************************************************************************************/

#include<iostream>
using namespace std;

class Solution {
    // Method3 (Dp) : space optimization
    /*
    TC : O(n)
    SC : O(1)
    */
    // /*
    public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int prev2 = 0;
        int prev1 = nums[0];
        
        for(int i = 1; i < n; i++) {
            int incl = prev2 + nums[i];
            int excl = prev1 + 0;

            int ans = max(incl, excl);

            // shifting
            prev2 = prev1;
            prev1 = ans;
        }

        return prev1;
    }
    // */



    // Method2 (Dp) : tabulation
    /*
    TC : O(n)
    SC : O(n)
    */
    /*
    public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 0);

        dp[0] = nums[0];
        if(n > 1)
            dp[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < n; i++) {
            int incl = dp[i-2] + nums[i];
            int excl = dp[i-1] + 0;

            dp[i] = max(incl, excl);
        }

        return dp[n-1];
    }
    */



    // Method 1 (DP) : Top Down approach : recursion + memoization
    /*
    TC : O(n)
    SC : O(2*n)
    */
    /*
    int solve(vector<int>& nums, int n, vector<int>& dp) {
        // base case
        if(n < 0)
            return 0;
        else if(n == 0)
            return nums[0];
        
        if(dp[n] != -1)
            return dp[n];
        
        int incl = solve(nums, n-2, dp) + nums[n];
        int excl = solve(nums, n-1, dp) + 0;

        dp[n] = max(incl, excl);
        return dp[n];
    }

    public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = solve(nums, n-1, dp);
        return ans;
    }
    */



    // Method 0 : using simple recursion --> will give TLE
    /*
    TC : O(2^n)
    SC : O(n)
    */
    /*
    int solve(vector<int>& nums, int n) {
        // base case
        if(n < 0)
            return 0;
        else if(n == 0)
            return nums[0];
        
        int incl = solve(nums, n-2) + nums[n];
        int excl = solve(nums, n-1) + 0;

        return max(incl, excl);
    }

    public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = solve(nums, n-1);
        return ans;
    }
    */
};


int main() {
    
    return 0;
}