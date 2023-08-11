// 120. Triangle
// LeetCode : https://leetcode.com/problems/triangle/

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
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> curr(n, 0);
        vector<int> next(n, 0);
        
        // from base case (for i = n-1)
        for(int j = 0; j < n; j++) {
            next[j] = triangle[n-1][j];
        }

        for(int i = n-2; i >= 0; i--) {
            for(int j = i; j >= 0; j--) {
                int down = triangle[i][j] + next[j];
                int diagonal = triangle[i][j] + next[j+1];

                curr[j] = min(down, diagonal);
            }
            next = curr;
        }

        return next[0];
    }
    // */


    
    // method-2 : tabulation
    /*
    TC : O(N*N)
    SC : O(N*N)
    */
    /*
    public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // from base case (for i = n-1)
        for(int j = 0; j < n; j++) {
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i = n-2; i >= 0; i--) {
            for(int j = i; j >= 0; j--) {
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down, diagonal);
            }
        }

        return dp[0][0];
    }
    */


    
    // method-1 : recursion + memoization
    /*
    TC : O(N*N)
    SC : O(N) + O(N*N)
    */
    /*
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(i == triangle.size()-1)
            return triangle[i][j];
        if(j > triangle[i].size()-1) // no use
            return 1e9;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int down = triangle[i][j] + f(i+1, j, triangle, dp);
        int diagonal = triangle[i][j] + f(i+1, j+1, triangle, dp);

        return dp[i][j] = min(down, diagonal);
    }

    public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));

        return f(0, 0, triangle, dp);
    }
    */



    // method-0 : recursion --> will give TLE
    /*
    TC : O(2^N)
    SC : O(N)
    */
    /*
    int f(int i, int j, vector<vector<int>>& triangle) {
        if(i == triangle.size()-1)
            return triangle[i][j];
        if(j > triangle[i].size()-1) // not need
            return 1e9;
        
        int down = triangle[i][j] + f(i+1, j, triangle);
        int diagonal = triangle[i][j] + f(i+1, j+1, triangle);

        return min(down, diagonal);
    }

    public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return f(0, 0, triangle);
    }
    */
};


int main() {
    
    return 0;
}