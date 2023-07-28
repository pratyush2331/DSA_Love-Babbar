// 188. Best Time to Buy and Sell Stock IV
// LeetCode : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include<iostream>
using namespace std;


class Solution {
    // method-3 : token/operation : space optimization
    /*
    TC : O(n*k)
    SC : O(k)
    */
    // /*
    public:
    int maxProfit(int k, vector<int>& prices) {
        // operationNo = even --> buy
        // operationNo = odd  --> sell

        int n = prices.size();

        vector<int> curr(2*k+1, 0);
        vector<int> next(2*k+1, 0);
        
        for(int index = n-1; index >= 0; index--) {
            for(int operationNo = 2*k-1; operationNo >= 0; operationNo--) {
                int profit = 0;

                if(!(operationNo & 1)) // even --> buy karo ya skip karo
                    profit = max(-prices[index] + next[operationNo+1], 0 + next[operationNo]);
                else // even --> sell karo ya skip karo
                    profit = max(+prices[index] + next[operationNo+1], 0 + next[operationNo]);

                curr[operationNo] = profit;
            }
            next = curr;
        }

        return next[0];
    }
    // */



    // method-2 : token/operation : tabulation
    /*
    TC : O(n*k)
    SC : O(n*k)
    */
    /*
    public:
    int maxProfit(int k, vector<int>& prices) {
        // operationNo = even --> buy
        // operationNo = odd  --> sell

        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
        
        for(int index = n-1; index >= 0; index--) {
            for(int operationNo = 2*k-1; operationNo >= 0; operationNo--) {
                int profit = 0;

                if(!(operationNo & 1)) // even --> buy karo ya skip karo
                    profit = max(-prices[index] + dp[index+1][operationNo+1], 0 + dp[index+1][operationNo]);
                else // even --> sell karo ya skip karo
                    profit = max(+prices[index] + dp[index+1][operationNo+1], 0 + dp[index+1][operationNo]);

                dp[index][operationNo] = profit;
            }
        }

        return dp[0][0];
    }
    */



    // method-1 : token/operation : recursion + memoization
    /*
    int solve(vector<int>& prices, int index, int operationNo, int k, vector<vector<int>>& dp) {
        if(index == prices.size())
            return 0;
        
        if(operationNo == 2*k)
            return 0;
        
        if(dp[index][operationNo] != -1)
            return dp[index][operationNo];
        
        int profit = 0;

        if(!(operationNo & 1)) // even --> buy karo ya skip karo
            profit = max(-prices[index] + solve(prices, index+1, operationNo+1, k, dp), 0 + solve(prices, index+1, operationNo, k, dp));
        else // even --> sell karo ya skip karo
            profit = max(+prices[index] + solve(prices, index+1, operationNo+1, k, dp), 0 + solve(prices, index+1, operationNo, k, dp));

        return dp[index][operationNo] = profit;
    }

    public:
    int maxProfit(int k, vector<int>& prices) {
        // operationNo = even --> buy
        // operationNo = odd  --> sell

        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2*k, -1));

        return solve(prices, 0, 0, k, dp);
    }
    */



    // method-0 : token/operation : recursion --> will give TLE
    /*
    int solve(vector<int>& prices, int index, int operationNo, int k) {
        if(index == prices.size())
            return 0;
        
        if(operationNo == 2*k)
            return 0;
        
        int profit = 0;

        if(!(operationNo & 1)) // even --> buy karo ya skip karo
            profit = max(-prices[index] + solve(prices, index+1, operationNo+1, k), 0 + solve(prices, index+1, operationNo, k));
        else // even --> sell karo ya skip karo
            profit = max(+prices[index] + solve(prices, index+1, operationNo+1, k), 0 + solve(prices, index+1, operationNo, k));

        return profit;
    }

    public:
    int maxProfit(int k, vector<int>& prices) {
        // operationNo = even --> buy
        // operationNo = odd  --> sell

        return solve(prices, 0, 0, k);
    }
    */
    
    
    
    // method-(-1) : space optimization
    /*
    TC : O(n*k)
    SC : O(k)
    */
    /*
    public:
    int solve(vector<int>& prices, int k) {
        int n = prices.size();
        
        // index -> 0 to n-1
        // buy   -> 0 or 1
        // limit -> 1 to k

        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        vector<vector<int>> next(2, vector<int>(k+1, 0));

        for(int index = n-1; index >= 0; index--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int limit = 1; limit <= k; limit++) {
                    int profit = 0;
                    
                    if(buy) // buy karo ya skip karo
                        profit = max(-prices[index] + next[0][limit], 0 + next[1][limit]);
                    else // sell karo ya skip karo
                        profit = max(+prices[index] + next[1][limit-1], 0 + next[0][limit]);
                    
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }

        return next[1][k];
    }

    public:
    int maxProfit(int k, vector<int>& prices) {
        return solve(prices, k);
    }
    */
};


int main() {
    
    return 0;
}