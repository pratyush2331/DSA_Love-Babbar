// 279. Perfect Squares
// LeetCode : https://leetcode.com/problems/perfect-squares/

#include<iostream>
using namespace std;


class Solution {
    // method 3 : space optimization is not possible



    // Method-2 : tabulation
    /*
    TC : O(sqrt(n) * n)
    SC : O(n)
    */
    // /*
    public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j*j <= i; j++) {
                // if(i - j*j >= 0) --> No need to check
                dp[i] = min(dp[i], 1 + dp[i - j*j]);
            }
        }

        return dp[n];
    }
    // */



    // Method-1 : recursion + memoization
    /*
    TC : O(sqrt(n) * n)
    SC : O(n) + O(n)
    */
    /*
    int solve(int n, vector<int>& dp) {
        if(n == 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        int ans = n; // at max 'ans' will store n. So, no need to initialize with INT_MAX;
        for(int i = 1; i*i <= n; i++) {
            ans = min(ans, 1 + solve(n - i*i, dp));
        }

        dp[n] = ans;
        return dp[n];
    }

    public:
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
    */



    // Method-0 : recursion --> will give TLE
    /*
    TC : O(sqrt(n) ^ n)
    SC : O(n)
    */
    /*
    int solve(int n) {
        if(n == 0)
            return 0;
        
        int ans = n;
        for(int i = 1; i*i <= n; i++) {
            ans = min(ans, 1 + solve(n - i*i));
        }

        return ans;
    }

    public:
    int numSquares(int n) {
        return solve(n);
    }
    */
};



int main() {
    
    return 0;
}