// 416. Partition Equal Subset Sum
// LeetCode : https://leetcode.com/problems/partition-equal-subset-sum/

#include<iostream>
using namespace std;


class Solution {
    // method-3 : space optimization
    /*
    TC : O(n * sum)
    SC : O(2 * sum)
    */
    // /*
    public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(auto ele : nums)
            total += ele;
        

        // checking if total is odd --> return 'false
        if(total & 1)
            return false;
        

        // proceed for even
        int target = total/2;

        int n = nums.size();
        vector<int> curr(target+1, 0);
        vector<int> next(target+1, 0);

        curr[0] = 1;
        next[0] = 1;

        for(int index = n-1; index >= 0; index--) {
            for(int t = 0; t <= target; t++) {
                bool inc = 0;
                if((t - nums[index]) >= 0)
                    inc = next[t - nums[index]];
                
                bool exc = next[t - 0];

                curr[t] = inc || exc;
            }
            next = curr;
        }
        
        return curr[target];
    }
    // */



    // method-2 : tabulation
    /*
    TC : O(n * sum)
    SC : O(n * sum)
    */
    /*
    public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(auto ele : nums)
            total += ele;
        

        // checking if total is odd --> return 'false
        if(total & 1)
            return false;
        

        // proceed for even
        int target = total/2;

        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

        // analysing from base case
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for(int index = n-1; index >= 0; index--) {
            for(int t = 0; t <= target; t++) {
                bool inc = 0;
                if((t - nums[index]) >= 0)
                    inc = dp[index + 1][t - nums[index]];
                
                bool exc = dp[index + 1][t - 0];

                dp[index][t] = inc || exc;
            }
        }
        
        return dp[0][target];
    }
    */



    // method-1 : recursion + memoization
    /*
    TC : O()
    SC : O()
    */
    /*
    bool solve(vector<int>& nums, int index, int target, vector<vector<int>>& dp) {
        // base case
        if(index >= nums.size())
            return false;
        
        if(target < 0)
            return false;
        
        if(target == 0)
            return true;
        

        if(dp[index][target] != -1)
            return dp[index][target];


        bool inc = solve(nums, index + 1, target - nums[index], dp);
        bool exc = solve(nums, index + 1, target - 0, dp);

        return dp[index][target] = inc || exc;
    }

    public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(auto ele : nums)
            total += ele;
        
        // checking if total is odd --> return 'false
        if(total & 1)
            return false;
        
        // proceed for even
        int target = total/2;

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        
        return solve(nums, 0, target, dp);
    }
    */



    // method-0 : recursion --> will give TLE
    /*
    TC : O()
    SC : O()
    */
    /*
    bool solve(vector<int>& nums, int index, int target) {
        // base case
        if(index >= nums.size())
            return false;
        
        if(target < 0)
            return false;
        
        if(target == 0)
            return true;
        

        bool inc = solve(nums, index + 1, target - nums[index]);
        bool exc = solve(nums, index + 1, target - 0);

        return inc || exc;
    }

    public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(auto ele : nums)
            total += ele;
        
        // checking if total is odd --> return 'false
        if(total & 1)
            return false;
        
        // proceed for even
        int target = total/2;
        
        return solve(nums, 0, target);
    }
    */
};


int main() {
    
    return 0;
}