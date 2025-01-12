// 3418. Maximum Amount of Money Robot Can Earn
// LeetCode : https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/

#include<bits/stdc++.h>
using namespace std;

// 0/1 knapsack dp --> take / not take dp
/*
TC : O(m*n*3)
SC : O(m*n*3) + O(m+n+3)
*/
class Solution {
    int m, n;
    vector<vector<vector<int>>> dp;
    
    int solve(int i, int j, int supPow, vector<vector<int>>& coins) {
        if(i == m-1 && j == n-1) {
            if(coins[i][j] >= 0) return coins[i][j];
            else {
                if(supPow > 0) return 0;
                else return coins[i][j];
            }
        }

        if(i >= m || j >= n) return -1e9;

        if(dp[i][j][supPow] != -1e9) return dp[i][j][supPow];

        int down = -1e9, right = -1e9;

        if(coins[i][j] < 0) { // may or may not use --> super power
            if(supPow > 0) { // using super power
                down = solve(i+1, j, supPow-1, coins);
                right = solve(i, j+1, supPow-1, coins);
            }
        }
        // not using super power
        down = max(down, coins[i][j] + solve(i+1, j, supPow, coins));
        right = max(right, coins[i][j] + solve(i, j+1, supPow, coins));

        return dp[i][j][supPow] = max(down, right);
    }

public:
    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(3, -1e9))); // SC:O(m*n*3)
        return solve(0, 0, 2, coins); // TC:O(m*n*3), SC:O(m+n+3)
    }
};



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}