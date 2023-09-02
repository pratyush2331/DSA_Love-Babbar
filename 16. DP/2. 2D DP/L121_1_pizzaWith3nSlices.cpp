// 1388. Pizza With 3n Slices
// LeetCode : https://leetcode.com/problems/pizza-with-3n-slices/

#include<iostream>
using namespace std;


class Solution {
    // method-3 : space optimization
    /*
    TC : O(k^2)
    SC : O(3k)
    */
    // /*
    public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        
        // for case-1
        vector<int> prev(k+2, 0);
        vector<int> curr(k+2, 0);
        vector<int> next(k+2, 0);

        for(int index = k-2; index >= 0; index--) {
            for(int n = 1; n <= k/3; n++) {
                // take
                int take = slices[index] + next[n-1];

                // not-take
                int notTake = 0 + curr[n];

                prev[n] = max(take, notTake);
            }
            next = curr;
            curr = prev;
        }
        int case1 = prev[k/3];


        // for case-2

        // again initialising dp[] array with -1
        for(int i = 0; i < k+2; i++) {
            prev[i] = 0;
            curr[i] = 0;
            next[i] = 0;
        }

        for(int index = k-1; index >= 1; index--) {
            for(int n = 1; n <= k/3; n++) {
                // take
                int take = slices[index] + next[n-1];

                // not-take
                int notTake = 0 + curr[n];

                prev[n] = max(take, notTake);
            }
            next = curr;
            curr = prev;
        }
        int case2 = prev[k/3];


        return max(case1, case2);
    }
    // */



    // method-2 : using tabulation
    /*
    TC : O(k^2)
    SC : O(k*k)
    */
    /*
    public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        
        // for case-1
        vector<vector<int>> dp(k+2, vector<int>(k+2, 0));

        for(int index = k-2; index >= 0; index--) {
            for(int n = 1; n <= k/3; n++) {
                // take
                int take = slices[index] + dp[index+2][n-1];

                // not-take
                int notTake = 0 + dp[index+1][n];

                dp[index][n] = max(take, notTake);
            }
        }
        int case1 = dp[0][k/3];


        // for case-2

        // again initialising dp[] array with -1
        for(int i = 0; i < k+2; i++) {
            for(int j = 0; j < k+2; j++) {
                dp[i][j] = 0;
            }
        }

        for(int index = k-1; index >= 1; index--) {
            for(int n = 1; n <= k/3; n++) {
                // take
                int take = slices[index] + dp[index+2][n-1];

                // not-take
                int notTake = 0 + dp[index+1][n];

                dp[index][n] = max(take, notTake);
            }
        }
        int case2 = dp[1][k/3];


        return max(case1, case2);
    }
    */



    // method-1 : using recursion + memoization
    /*
    int solve(int index, int endIndex, vector<int>& slices, int n, vector<vector<int>>& dp) {
        if(n == 0 || index > endIndex)
            return 0;
        
        if(dp[index][n] != -1)
            return dp[index][n];
        
        // take
        int take = slices[index] + solve(index+2, endIndex, slices, n-1, dp);

        // not-take
        int notTake = 0 + solve(index+1, endIndex, slices, n, dp);

        dp[index][n] = max(take, notTake);
        return dp[index][n];
    }

    public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        
        vector<vector<int>> dp(k, vector<int>(k, -1));
        int case1 = solve(0, k-2, slices, k/3, dp);

        // again initialising dp[] array with -1
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                dp[i][j] = -1;
            }
        }
        int case2 = solve(1, k-1, slices, k/3, dp);
        return max(case1, case2);
    }
    */



    // method-0 : using recursion --> will give TLE
    /*
    int solve(int index, int endIndex, vector<int>& slices, int n) {
        if(n == 0 || index > endIndex)
            return 0;
        
        // take
        int take = slices[index] + solve(index+2, endIndex, slices, n-1);

        // not-take
        int notTake = 0 + solve(index+1, endIndex, slices, n);

        return max(take, notTake);
    }

    public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        int case1 = solve(0, k-2, slices, k/3);
        int case2 = solve(1, k-1, slices, k/3);
        return max(case1, case2);
    }
    */
};


int main() {
    
    return 0;
}