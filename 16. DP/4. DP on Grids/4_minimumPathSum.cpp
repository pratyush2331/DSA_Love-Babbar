// 64. Minimum Path Sum
// LeetCode : https://leetcode.com/problems/minimum-path-sum/

#include<iostream>
using namespace std;


class Solution {
    // method-3 : space optimization
    /*
    TC : O(M*N)
    SC : O(2*N) = O(N)
    */
    // /*
    public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, 0);
        vector<int> curr(n, 0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // from base case
                if(i == 0 && j == 0) {
                    curr[0] = grid[0][0];
                    continue;
                }

                int up = 1e9;
                if(i > 0)
                    up = grid[i][j] + prev[j];
                int left = 1e9;
                if(j > 0)
                    left = grid[i][j] + curr[j-1];

                curr[j] = min(up, left);
            }
            prev = curr;
        }

        return prev[n-1];
    }
    // */



    // method-2 : tabulation
    /*
    TC : O(M*N)
    SC : O(M*N)
    */
    /*
    public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // from base case
                if(i == 0 && j == 0) {
                    dp[0][0] = grid[0][0];
                    continue;
                }

                int up = 1e9;
                if(i > 0)
                    up = grid[i][j] + dp[i-1][j];
                int left = 1e9;
                if(j > 0)
                    left = grid[i][j] + dp[i][j-1];

                dp[i][j] = min(up, left);
            }
        }

        return dp[m-1][n-1];
    }
    */



    // method-1 : recursion + memoization
    /*
    TC : O(M*N)
    SC : O((M-1)+(N-1)) + O(M*N)
    */
    /*
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(i < 0 || j < 0)
            return 1e9;
        if(i == 0 && j == 0)
            return grid[0][0];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = grid[i][j] + f(i-1, j, grid, dp);
        int left = grid[i][j] + f(i, j-1, grid, dp);

        return dp[i][j] = min(up, left);
    }

    public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return f(m-1, n-1, grid, dp);
    }
    */



    // method-0 : recursion --> will give TLE
    /*
    TC : O()
    SC : O((M-1)+(N-1))
    */
    /*
    int f(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 || j < 0)
            return 1e9;
        if(i == 0 && j == 0)
            return grid[0][0];
        
        int up = grid[i][j] + f(i-1, j, grid);
        int left = grid[i][j] + f(i, j-1, grid);

        return min(up, left);
    }

    public:
    int minPathSum(vector<vector<int>>& grid) {
        return f(grid.size()-1, grid[0].size()-1, grid);
    }
    */
};


int main() {
    
    return 0;
}