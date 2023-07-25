// 1027. Longest Arithmetic Subsequence
// LeetCode : https://leetcode.com/problems/longest-arithmetic-subsequence/description

#include<iostream>
#include<vector>
using namespace std;


class Solution {
    // method-2 : tabulation
    // /*
    public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(1001, 0));
        // dp[i][diff] = longest Arith Subs ending at ith index with common diff = diff;
        
        int ans = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j] + 500; // to avoid -ve diff
                
                dp[i][diff] = dp[j][diff] > 0 ? dp[j][diff] + 1 : 2;

                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }
    // *



    // method-1 : recursion + memoization --> will give TLE :)
    /*
    int dp[1001][1001];

    int solve(int index, int diff, vector<int>& nums) {
        if(index < 0)
            return 0;
        
        if(dp[index][diff + 500] != -1)
            return dp[index][diff + 500];
        
        int ans = 0;
        for(int i = index-1; i >= 0; i--) {
            if(nums[index] - nums[i] == diff) {
                ans = max(ans, 1 + solve(i, diff, nums));
            }
        }
        return dp[index][diff + 500] = ans;
    }

    public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
            return n;

        memset(dp, -1, sizeof(dp));

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                ans = max(ans, 2 + solve(i, nums[j] - nums[i], nums));
            }
        }
        return ans;
    }
    */



    // method-0 : using recursion --> will give TLE
    /*
    int solve(int index, int diff, vector<int>& nums) {
        if(index < 0)
            return 0;
        
        int ans = 0;
        for(int i = index-1; i >= 0; i--) {
            if(nums[index] - nums[i] == diff) {
                ans = max(ans, 1 + solve(i, diff, nums));
            }
        }
        return ans;
    }

    public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
            return n;

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                ans = max(ans, 2 + solve(i, nums[j] - nums[i], nums));
            }
        }
        return ans;
    }
    */
};


int main() {
    
    return 0;
}