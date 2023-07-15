// 221. Maximal Square
// LeetCode : https://leetcode.com/problems/maximal-square/

#include<iostream>
using namespace std;


class Solution {
    // method-3 : space optimization
    /*
    TC : O(n*m)
    SC : O(m)
    */
    // /*
    public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;

        int n = matrix.size(); // # of rows
        int m = matrix[0].size(); // # of cols

        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];

                if(matrix[i][j] == '1') {
                    curr[j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, curr[j]);
                }
                else {
                    curr[j] = 0;
                }
            }
            next = curr;
        }

        return maxi * maxi; // return area
    }
    // */



    // method-2 : tabulation
    /*
    TC : O(n*m)
    SC : O(n*m)
    */
    /*
    public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;

        int n = matrix.size(); // # of rows
        int m = matrix[0].size(); // # of cols

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];

                if(matrix[i][j] == '1') {
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }

        return maxi * maxi; // return area
    }
    */



    // method-1 : recursion + memoization
    /*
    TC : O(n*m)
    SC : O(n*m) + O(n+m)
    */
    /*
    int solve(vector<vector<char>>& matrix, int i, int j, int& maxi, vector<vector<int>>& dp) {
        if(i >= matrix.size() || j >= matrix[0].size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int right = solve(matrix, i, j+1, maxi, dp);
        int diagonal = solve(matrix, i+1, j+1, maxi, dp);
        int down = solve(matrix, i+1, j, maxi, dp);

        if(matrix[i][j] == '1') {
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else {
            dp[i][j] = 0;
            return dp[i][j];
        }
    }

    public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;

        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        solve(matrix, 0, 0, maxi, dp);

        return maxi * maxi; // return area
    }
    */



    // method-0 : recursion --> will give TLE
    /*
    TC : O(3^(n+m))
    SC : O(n+m)
    */
    /*
    int solve(vector<vector<char>>& matrix, int i, int j, int& maxi) {
        if(i >= matrix.size() || j >= matrix[0].size())
            return 0;
        
        int right = solve(matrix, i, j+1, maxi);
        int diagonal = solve(matrix, i+1, j+1, maxi);
        int down = solve(matrix, i+1, j, maxi);

        if(matrix[i][j] == '1') {
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;
        }
        else {
            return 0;
        }
    }

    public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;

        solve(matrix, 0, 0, maxi);

        return maxi * maxi; // return area
    }
    */
};


int main() {
    
    return 0;
}