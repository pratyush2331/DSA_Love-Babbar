// 746. Min Cost Climbing Stairs
// LeetCode : https://leetcode.com/problems/min-cost-climbing-stairs/

#include<iostream>
using namespace std;

// Method3 (Dp) : space optimization
/*
TC : O(n)
SC : O(1)
*/
// /*
class Solution {
    public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i = 2; i < n; i++) {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return min(prev1, prev2);
    }
};
// */



// Method2 (Dp) : tabulation
/*
TC : O(n)
SC : O(n)
*/
/*
class Solution {
    public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        vector<int> dp(n+1); // SC: O(n)
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        
        return min(dp[n-1], dp[n-2]);
    }
};
*/



// Method1 (Dp) : recursion + memoization
/*
TC : O(n)
SC : O(2n)
*/
/*
class Solution {
    int solve(vector<int>& cost, int n, vector<int>& dp) { // TC: O(n)
        // base case
        if(n == 0)
            return cost[0];
        if(n == 1)
            return cost[1];
        
        if(dp[n] != -1)
            return dp[n];
        
        dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return dp[n];
    }

    public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1); // SC: O(n)
        int ans = min(solve(cost, n-1, dp), solve(cost, n-2, dp)); // SC: O(n)
        return ans;
    }
};
*/



// Method 0 : using simple recursion --> will give TLE
/*
TC : O(2^n)
SC : O(n)
*/
/*
class Solution {
    int solve(vector<int>& cost, int n) {
        // base case
        if(n == 0)
            return cost[0];
        if(n == 1)
            return cost[1];
        
        int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
        return ans;
    }

    public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int ans = min(solve(cost, n-1), solve(cost, n-2));
        return ans;
    }
};
*/

int main() {
    
    return 0;
}