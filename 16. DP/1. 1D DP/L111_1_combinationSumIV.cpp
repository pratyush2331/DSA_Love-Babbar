// 377. Combination Sum IV
// LeetCode : https://leetcode.com/problems/combination-sum-iv/

#include<iostream>
using namespace std;

class Solution {
    // method 3 : space optimization is not possible, as it's curent value for any number is dependent on whole elements of nums[] array.



    // method 2 : tabulation
    /*
    TC : O(n * target)
    SC : O(target)
    */
    public:
    int combinationSum4(vector<int>& nums, int target) {
        // step-1
        if(target < 0)
            return 0;
        else if(target == 0)
            return 1;
        
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        
        for(int i = 1; i <= target; i++) {
            long long ans = 0;
            for(int j = 0; j < nums.size(); j++) {
                if(i - nums[j] >= 0)
                    ans += dp[i - nums[j]];
            }
            dp[i] = ans;
        }

        // step-2
        return dp[target];
    }



    // method 1 : recursion + memoization
    /*
    TC : O(n * target)
    SC : 2 * O(target) --> dp[] array + recursive stack
    */
    /*
    int solve(vector<int>& nums, int target, vector<int>& dp) {
        if(target < 0)
            return 0;
        else if(target == 0)
            return 1;
        
        // step-3
        if(dp[target] != -1)
            return dp[target];
        
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            ans += solve(nums, target - nums[i], dp);
        }

        // step-2
        dp[target] = ans;
        return dp[target];
    }

    public:
    int combinationSum4(vector<int>& nums, int target) {
        // step-1
        vector<int> dp(target+1, -1);

        return solve(nums, target, dp);
    }
    */



    // method 0 : recursion --> will give TLE
    /*
    TC : O(n^target)
    SC : O(target)
    */
    /*
    int solve(vector<int>& nums, int target) {
        if(target < 0)
            return 0;
        else if(target == 0)
            return 1;
        
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) { // TC: O(n^n) --> for loop + recursion for every element
            ans += solve(nums, target - nums[i]); // SC: O(n) --> recursion
        }

        return ans;
    }

    public:
    int combinationSum4(vector<int>& nums, int target) {
        return solve(nums, target);
    }
    */
};


int main() {
    
    return 0;
}