// 63. Unique Paths II
// LeetCode : https://leetcode.com/problems/unique-paths-ii/

#include<iostream>
using namespace std;


class Solution {
    // method-2 : space optimization
    /*
    TC : O(M*N)
    SC : O(2*N) = O(N)
    */
    // /*
    public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> prev(n, 0);
        vector<int> curr(n, 0);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // from base cases
                if(obstacleGrid[i][j] == 1) {
                    curr[j] = 0;
                    continue;
                }
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
    // */



    // method-2 : tabulation
    /*
    TC : O(M*N)
    SC : O(M*N)
    */
    /*
    public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // from base cases
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
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
    TC : O(M*N)
    SC : O((M-1)+(N-1)) + O(M*N)
    */
    /*
    int f(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if(i < 0 || j < 0 || obstacleGrid[i][j] == 1)
            return 0;
        if( i == 0 && j == 0)
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = f(i-1, j, obstacleGrid, dp);
        int left = f(i, j-1, obstacleGrid, dp);

        return dp[i][j] = up + left;
    }

    public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return f(obstacleGrid.size()-1, obstacleGrid[0].size()-1, obstacleGrid, dp);
    }
    */



    // method-0 : recursion --> will give TLE
    /*
    TC : O()
    SC : O()
    */
    /*
    int f(int i, int j, vector<vector<int>>& obstacleGrid) {
        if(i < 0 || j < 0 || obstacleGrid[i][j] == 1)
            return 0;
        if(i == 0 && j == 0)
            return 1;
        
        int up = f(i-1, j, obstacleGrid);
        int left = f(i, j-1, obstacleGrid);

        return up + left;
    }

    public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return f(obstacleGrid.size()-1, obstacleGrid[0].size()-1, obstacleGrid);
    }
    */
};


int main() {
    
    return 0;
}