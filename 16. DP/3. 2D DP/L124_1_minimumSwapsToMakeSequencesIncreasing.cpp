// 801. Minimum Swaps To Make Sequences Increasing
// LeetCode : https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/

#include<iostream>
using namespace std;


class Solution {
    // method-2 : space optimization
    /*
    TC : O(n)
    SC : O(1)
    */
    // /*
    public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // it means that the previous indexes were swapped or not
        
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        
        int n = nums1.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int index = n-1; index >= 1; index--) {
            for(int swapped = 1; swapped >= 0; swapped--) {
                int ans = INT_MAX;
                
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];
                
                if(swapped)
                    swap(prev1, prev2);
                
                // no swap
                if(nums1[index] > prev1 && nums2[index] > prev2)
                    ans = dp[index+1][0];
                
                // swap
                if(nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + dp[index+1][1]);
                
                dp[index][swapped] = ans;
            }
        }

        return dp[1][0];
    }
    // */



    // method-2 : using tabulation
    /*
    TC : O(n)
    SC : O(n)
    */
    public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // it means that the previous indexes were swapped or not
        
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        
        int n = nums1.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int index = n-1; index >= 1; index--) {
            for(int swapped = 1; swapped >= 0; swapped--) {
                int ans = INT_MAX;
                
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];
                
                if(swapped)
                    swap(prev1, prev2);
                
                // no swap
                if(nums1[index] > prev1 && nums2[index] > prev2)
                    ans = dp[index+1][0];
                
                // swap
                if(nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + dp[index+1][1]);
                
                dp[index][swapped] = ans;
            }
        }

        return dp[1][0];
    }



    // method-1 : using recursion + memoization
    /*
    TC : O()
    SC : O()
    */
    /*
    int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>>& dp) {
        // base case
        if(index == nums1.size())
            return 0;
        
        if(dp[index][swapped] != -1)
            return dp[index][swapped];
        
        int ans = INT_MAX;
        
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];
        
        if(swapped)
            swap(prev1, prev2);
        
        // no swap
        if(nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1, nums2, index+1, 0, dp);
        
        // swap
        if(nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1 + solve(nums1, nums2, index+1, 1, dp));
        
        return dp[index][swapped] = ans;
    }

    public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // it means that the previous indexes were swapped or not
        bool swapped = 0;
        
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(nums1, nums2, 1, swapped, dp);
    }
    */



    // method-0 : recursion --> will give TLE
    /*
    int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped) {
        // base case
        if(index == nums1.size())
            return 0;
        
        int ans = INT_MAX;
        
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];
        
        if(swapped)
            swap(prev1, prev2);
        
        // no swap
        if(nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1, nums2, index+1, 0);
        
        // swap
        if(nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1 + solve(nums1, nums2, index+1, 1));
        
        return ans;
    }

    public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // it means that the previous indexes were swapped or not
        bool swapped = 0;
        
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        
        return solve(nums1, nums2, 1, swapped);
    }
    */
};


int main() {
    
    return 0;
}