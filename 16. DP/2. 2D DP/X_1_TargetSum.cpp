// 494. Target Sum
// LeetCode : https://leetcode.com/problems/target-sum/

#include<bits/stdc++.h>
using namespace std;


// method-1 : recursion + memoization
/*
TC : O(n.10^3)
SC : O(n.10^3)
*/
class Solution {
    int solve(int idx, int currSum, vector<int>& nums, int target, vector<vector<int>>& dp) { // will return count
        if(idx == nums.size()) return (currSum == target);
        if(dp[idx][currSum+1000] != -1) return dp[idx][currSum+1000];
        // +
        int pos = solve(idx+1, currSum+nums[idx], nums, target, dp);
        // -
        int neg = solve(idx+1, currSum-nums[idx], nums, target, dp);
        return dp[idx][currSum+1000] = pos + neg;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(2*1000+1, -1));
        return solve(0, 0, nums, target, dp);
    }
};


// method-0 : recursion
/*
TC : O(2^n)
SC : O(n) // recursive stack space
*/
class Solution {
    int solve(int idx, int currSum, vector<int>& nums, int target) { // will return count
        if(idx == nums.size()) return (currSum == target);
        // +
        int pos = solve(idx+1, currSum+nums[idx], nums, target);
        // -
        int neg = solve(idx+1, currSum-nums[idx], nums, target);
        return pos + neg;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, 0, nums, target);
    }
};


int main() {
    
    return 0;
}