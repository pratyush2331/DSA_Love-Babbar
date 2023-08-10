// https://leetcode.com/problems/unique-paths/
// LeetCode : 62. Unique Paths

#include<iostream>
using namespace std;


class Solution {
    // method-4 : combinatorics
    /*
    TC : O(min(m-1, n-1))
    SC : O(1)
    */
    // /*
    public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int r = (m-1 < n-1) ? m-1 : n-1;
        double res = 1;
        for(int i = 1; i <= r; i++) {
            res = res * (N - r + i)/i;
        }
        return (int)res;
    }
    // */



    // method-3 : space optimization
    /*
    TC : O(m * n)
    SC : O(n)
    */
    /*
    public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // from base case
                if(i == 0 && j == 0) {
                    curr[0] = 1;
                    continue;
                }
                
                int up = 0;
                if(i > 0)
                    up = prev[j];
                int left = 0;
                if(j > 0)
                    left = curr[j-1];

                curr[j] = up + left;
            }
            prev = curr;
        }

        return prev[n-1];
    }
    */



    // method-2 : tabulation
    /*
    TC : O(m * n)
    SC : O(m * n)
    */
    /*
    public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // from base case
                if(i == 0 && j == 0) {
                    dp[0][0] = 1;
                    continue;
                }
                
                int up = 0;
                if(i > 0)
                    up = dp[i-1][j];
                int left = 0;
                if(j > 0)
                    left = dp[i][j-1];

                dp[i][j] = up + left;
            }
        }

        return dp[m-1][n-1];
    }
    */



    // method-1 : recursion + memoization
    /*
    TC : O(m * n)
    SC : O((m-1) + (n-1)) + O(m*n)
    */
    /*
    int f(int i, int j, vector<vector<int>>& dp) {
        if(i == 0 && j == 0)
            return 1;
        if(i < 0 || j < 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = f(i-1, j, dp);
        int left = f(i, j-1, dp);

        return dp[i][j] = up + left;
    }

    public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1, n-1, dp);
    }
    */



    // method-0 : recursion --> will give TLE
    /*
    TC : O(2 ^ (m*n))
    SC : O((m-1) + O(n-1))
    */
    /*
    int f(int i, int j) {
        if(i == 0 && j == 0)
            return 1;
        if(i < 0 || j < 0)
            return 0;
        
        int up = f(i-1, j);
        int left = f(i, j-1);

        return up + left;
    }

    public:
    int uniquePaths(int m, int n) {
        return f(m-1, n-1);
    }
    */
};


int main() {
    
    return 0;
}