// 300. Longest Increasing Subsequence
// LeetCode : https://leetcode.com/problems/longest-increasing-subsequence/

#include<iostream>
using namespace std;


class Solution {
    // method-4 : DP with Binary Search
    /*
    TC : O(n.logn)
    SC : O(n)
    */
    public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // no need as n > 0 (in constraint)
        // if(n == 0)
        //     return 0;
        
        vector<int> ans;
        ans.push_back(nums[0]);
        
        for(int i = 1; i < n; i++) {
            if(nums[i] > ans.back()) {
                ans.push_back(nums[i]);
            }
            else {
                // find index of just greater element in ans[] array
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }

        return ans.size();
    }



    // method-3 : space optimization
    /*
    TC : O(n*n)
    SC : O(2n)
    */
    /*
    public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        
        for(int curr = n-1; curr >= 0; curr--) {
            for(int prev = curr-1; prev >= -1; prev--) {
                // take
                int take = 0;
                if(prev == -1 || nums[curr] > nums[prev])
                    take = 1 + nextRow[curr+1];
                
                // not-take
                int notTake = 0 + nextRow[prev+1];

                currRow[prev+1] = max(take, notTake);
            }
            nextRow = currRow;
        }

        return nextRow[0]; // return dp[0][-1+1];
    }
    */
    
    
    
    // method-2 : tabulation
    /*
    TC : O(n*n)
    SC : O(n*n)
    */
    /*
    public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int curr = n-1; curr >= 0; curr--) {
            for(int prev = curr-1; prev >= -1; prev--) {
                // take
                int take = 0;
                if(prev == -1 || nums[curr] > nums[prev])
                    take = 1 + dp[curr+1][curr+1];
                
                // not-take
                int notTake = 0 + dp[curr+1][prev+1];

                dp[curr][prev+1] = max(take, notTake);
            }
        }

        return dp[0][0]; // return dp[0][-1+1];
    }
    */



    // method-1 : recursion + memoization
    /*
    TC : O(n*n)
    SC : O(n*n)
    */
    /*
    int solve(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp) {
        if(curr == nums.size())
            return 0;
        
        if(dp[curr][prev+1] != -1)
            return dp[curr][prev+1];
        
        // take
        int take = 0;
        if(prev == -1 || nums[curr] > nums[prev])
            take = 1 + solve(nums, curr+1, curr, dp);
        
        // not-take
        int notTake = 0 + solve(nums, curr+1, prev, dp);

        dp[curr][prev+1] = max(take, notTake);
        return dp[curr][prev+1];
    }

    public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(nums, 0, -1, dp);
    }
    */



    // method-0 : recursion --> will give TLE
    /*
    TC : O(2^n)
    SC : O(n)
    */
    /*
    int solve(vector<int>& nums, int curr, int prev) {
        if(curr == nums.size())
            return 0;
        
        // take
        int take = 0;
        if(prev == -1 || nums[curr] > nums[prev])
            take = 1 + solve(nums, curr+1, curr);
        
        // not-take
        int notTake = 0 + solve(nums, curr+1, prev);

        return max(take, notTake);
    }

    public:
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums, 0, -1);
    }
    */
};


int main() {
    
    return 0;
}