// 931. Minimum Falling Path Sum
// LeetCode : https://leetcode.com/problems/minimum-falling-path-sum/

#include<iostream>
using namespace std;


class Solution {
    // method-3 : space optimization
    /*
    TC : O(N*N)
    SC : O(2*N) = O(N)
    */
    // /*
    public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> prev(n, 0);
        vector<int> curr(n, 0);

        // from base case
        for(int j = 0; j < n; j++) {
            prev[j] = matrix[0][j];
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // 3 possibilities : (i-1, j-1), (i-1, j), (i-1, j+1)
                int diagLeft = 1e9;
                if(j-1 >= 0)
                    diagLeft = matrix[i][j] + prev[j-1];
                int up = matrix[i][j] + prev[j];
                int diagRight = 1e9;
                if(j+1 < n)
                    diagRight = matrix[i][j] + prev[j+1];

                curr[j] = min(diagLeft, min(up, diagRight));
            }
            prev = curr;
        }

        int mini = 1e9;
        for(int j = 0; j < n; j++) {
            mini = min(mini, prev[j]);
        }
        return mini;
    }
    // */



    // method-2 : tabulation
    /*
    TC : O(N*N)
    SC : O(N*N)
    */
    /*
    public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // from base case
        for(int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // 3 possibilities : (i-1, j-1), (i-1, j), (i-1, j+1)
                int diagLeft = 1e9;
                if(j-1 >= 0)
                    diagLeft = matrix[i][j] + dp[i-1][j-1];
                int up = matrix[i][j] + dp[i-1][j];
                int diagRight = 1e9;
                if(j+1 < n)
                    diagRight = matrix[i][j] + dp[i-1][j+1];

                dp[i][j] = min(diagLeft, min(up, diagRight));
            }
        }

        int mini = 1e9;
        for(int j = 0; j < n; j++) {
            mini = min(mini, dp[n-1][j]);
        }
        return mini;
    }
    */



    // method-1 : recursion + memoization
    /*
    TC : O(N*N)
    SC : O(N) + O(M*N)
    */
    /*
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();
        if(j < 0 || j >= n)
            return 1e9;
        if(i == 0)
            return matrix[0][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // 3 possibilities : (i-1, j-1), (i-1, j), (i-1, j+1)
        int diagLeft = matrix[i][j] + f(i-1, j-1, matrix, dp);
        int up = matrix[i][j] + f(i-1, j, matrix, dp);
        int diagRight = matrix[i][j] + f(i-1, j+1, matrix, dp);

        return dp[i][j] = min(diagLeft, min(up, diagRight));
    }

    public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int mini = 1e9;
        for(int j = 0; j < n; j++) {
            mini = min(mini, f(n-1, j, matrix, dp));
        }
        return mini;
    }
    */



    // method-0 : recursion --> will give TLE
    /*
    TC : O()
    SC : O()
    */
    /*
    int f(int i, int j, vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(j < 0 || j >= n)
            return 1e9;
        if(i == 0)
            return matrix[0][j];
        
        // 3 possibilities : (i+1, j-1), (i+1, j), (i+1, j+1)
        int diagLeft = matrix[i][j] + f(i-1, j-1, matrix);
        int up = matrix[i][j] + f(i-1, j, matrix);
        int diagRight = matrix[i][j] + f(i-1, j+1, matrix);

        return min(diagLeft, min(up, diagRight));
    }

    public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int mini = 1e9;
        for(int j = 0; j < n; j++) {
            mini = min(mini, f(n-1, j, matrix));
        }
        return mini;
    }
    */
};


int main() {
    
    return 0;
}