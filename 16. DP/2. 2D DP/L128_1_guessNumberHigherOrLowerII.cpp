// 375. Guess Number Higher or Lower II
// LeetCode : https://leetcode.com/problems/guess-number-higher-or-lower-ii/

#include<iostream>
using namespace std;


class Solution {
    // method-3 : space optimization --> not possible



    // method-2 : tabulation
    // /*
    public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        
        for(int start = n; start >= 1; start--) {
            for(int end = start+1; end <= n; end++) {
                // if(start >= end) // --> if you put end = 1
                //     continue;
                int mini = INT_MAX;
                for(int i = start; i <= end; i++) {
                    mini = min(mini, i + max(dp[start][i-1], dp[i+1][end]));
                }
                dp[start][end] = mini;
            }
        }

        return dp[1][n];
    }
    // */



    // method-1 : recursion + memoization
    /*
    int solve(int start, int end, vector<vector<int>>& dp) {
        if(start >= end)
            return 0;
        
        if(dp[start][end] != -1)
            return dp[start][end];
        
        int mini = INT_MAX;
        for(int i = start; i <= end; i++) {
            mini = min(mini, i + max(solve(start, i-1, dp), solve(i+1, end, dp)));
        }
        return dp[start][end] = mini;
    }

    public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(1, n, dp);
    }
    */



    // method-0 : recursion
    /*
    int solve(int start, int end) {
        if(start >= end)
            return 0;
        
        int mini = INT_MAX;
        for(int i = start; i <= end; i++) {
            mini = min(mini, i + max(solve(start, i-1), solve(i+1, end)));
        }
        return mini;
    }

    public:
    int getMoneyAmount(int n) {
        return solve(1, n);
    }
    */
};


int main() {
    
    return 0;
}