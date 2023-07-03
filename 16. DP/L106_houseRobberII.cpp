// 213. House Robber II
// LeetCode : https://leetcode.com/problems/house-robber-ii/

/****************************************************QUESTION****************************************************
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed.
All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two 
adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can 
rob tonight without alerting the police.
****************************************************************************************************************/

#include<iostream>
using namespace std;


class Solution {
    // Method2 (Dp) : further space optimization
    /*
    TC : O(n)
    SC : O(1)
    */
    // /*
    public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // special case : when (n = 1)
        if(n == 1)
            return nums[0];
        
        // exclude element at last index and find 'ans1'
        int prev2 = 0;
        int prev1 = nums[0];
        
        for(int i = 1; i < n-1; i++) {
            int incl = prev2 + nums[i];
            int excl = prev1 + 0;

            int ans = max(incl, excl);

            // shifting
            prev2 = prev1;
            prev1 = ans;
        }

        int ans1 = prev1;


        // exclude element at first index and find 'ans2'
        int prev4 = 0;
        int prev3 = nums[1];
        
        for(int i = 2; i < n; i++) {
            int incl = prev4 + nums[i];
            int excl = prev3 + 0;

            int ans = max(incl, excl);

            // shifting
            prev4 = prev3;
            prev3 = ans;
        }

        int ans2 = prev3;

        return max(ans1, ans2);
    }
    // */





    // Method1 (Dp) : space optimization
    /*
    TC : O(n)
    SC : O(n)
    */
    /*
    public:
    int solve(vector<int>& nums) {
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

    public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];
        
        vector<int> first, last; // SC: O(2n)
        for(int i = 0; i < n; i++) { // TC: O(n)
            if(i != n-1)
                first.push_back(nums[i]);
            if(i != 0)
                last.push_back(nums[i]);
        }

        return max(solve(first), solve(last)); // TC: O(2n)
    }
    */
};


int main() {
    
    return 0;
}