// 2369. Check if There is a Valid Partition For The Array
// LeetCode : https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/

#include<iostream>
using namespace std;


class Solution {
    // method-3 : space optimization
    // /*
    public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n+1, false);

        // fropm base case
        bool plus1, plus2, plus3;
        plus1 = true;
        
        for(int i = n-1; i >= 0; i--) {
            bool ans1 = false, ans2 = false, ans3 = false;
            // case 1
            if(i+1 < nums.size() && nums[i] == nums[i+1]) {
                ans1 = plus2;
            }
            // case 2
            if(i+2 < nums.size() && nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) {
                ans2 = plus3;
            }
            // case 3
            if(i+2 < nums.size() && nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1) {
                ans3 = plus3;
            }

            bool curr = ans1 || ans2 || ans3;

            plus3 = plus2;
            plus2 = plus1;
            plus1 = curr;
        }

        return plus1;
    }
    // */



    // method-2 : tabulation
    /*
    public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n+1, false);

        // fropm base case
        dp[n] = true;
        
        for(int i = n-1; i >= 0; i--) {
            bool ans1 = false, ans2 = false, ans3 = false;
            // case 1
            if(i+1 < nums.size() && nums[i] == nums[i+1]) {
                ans1 = dp[i+2];
            }
            // case 2
            if(i+2 < nums.size() && nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) {
                ans2 = dp[i+3];
            }
            // case 3
            if(i+2 < nums.size() && nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1) {
                ans3 = dp[i+3];
            }

            dp[i] = ans1 || ans2 || ans3;
        }

        return dp[0];
    }
    */



    // method-1 : recursion + memoization
    /*
    bool f(int i, vector<int>& nums, vector<int>& dp) {
        if(i == nums.size())
            return true;
        
        if(dp[i] != -1)
            return dp[i];
        
        bool ans1 = false, ans2 = false, ans3 = false;
        // case 1
        if(i+1 < nums.size() && nums[i] == nums[i+1]) {
            ans1 = f(i+2, nums, dp);
        }
        // case 2
        if(i+2 < nums.size() && nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) {
            ans2 = f(i+3, nums, dp);
        }
        // case 3
        if(i+2 < nums.size() && nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1) {
            ans3 = f(i+3, nums, dp);
        }

        return dp[i] = ans1 || ans2 || ans3;
    }

    public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(0, nums, dp);
    }
    */

    

    // method-0 : recursion --> will give TLE
    /*
    bool f(int i, vector<int>& nums) {
        if(i == nums.size())
            return true;
        
        bool ans1 = false, ans2 = false, ans3 = false;
        // case 1
        if(i+1 < nums.size() && nums[i] == nums[i+1]) {
            ans1 = f(i+2, nums);
        }
        // case 2
        if(i+2 < nums.size() && nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) {
            ans2 = f(i+3, nums);
        }
        // case 3
        if(i+2 < nums.size() && nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1) {
            ans3 = f(i+3, nums);
        }

        return ans1 || ans2 || ans3;
    }

    public:
    bool validPartition(vector<int>& nums) {
        return f(0, nums);
    }
    */
};


int main() {
    
    return 0;
}