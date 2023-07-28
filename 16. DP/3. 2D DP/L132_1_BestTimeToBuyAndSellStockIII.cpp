// 123. Best Time to Buy and Sell Stock III
// LeetCode : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include<iostream>
using namespace std;


class Solution {
    // method-3 : space optimization
    /*
    TC : O(n)
    SC : O(1)
    */
    // /*
    public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // index -> 0 to n-1
        // buy   -> 0 or 1
        // limit -> 1 or 2

        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));

        for(int index = n-1; index >= 0; index--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int limit = 1; limit <= 2; limit++) {
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

        return next[1][2];
    }
    // */



    // method-2 : tabulation
    /*
    TC : O(n)
    SC : O(n)
    */
    /*
    public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // index -> 0 to n-1
        // buy   -> 0 or 1
        // limit -> 1 or 2

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int index = n-1; index >= 0; index--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int limit = 1; limit <= 2; limit++) {
                    int profit = 0;
                    
                    if(buy) // buy karo ya skip karo
                        profit = max(-prices[index] + dp[index+1][0][limit], 0 + dp[index+1][1][limit]);
                    else // sell karo ya skip karo
                        profit = max(+prices[index] + dp[index+1][1][limit-1], 0 + dp[index+1][0][limit]);
                    
                    dp[index][buy][limit] = profit;
                }
            }
        }

        return dp[0][1][2];
    }
    */



    // method-1 : recursion + memoization
    /*
    int solve(vector<int>& prices, int index, int buy, int limit, vector<vector<vector<int>>>& dp) {
        if(index == prices.size())
            return 0;
        
        if(limit == 0)
            return 0;
        
        if(dp[index][buy][limit] != -1)
            return dp[index][buy][limit];
        
        int profit = 0;
        
        if(buy) // buy karo ya skip karo
            profit = max(-prices[index] + solve(prices, index+1, 0, limit, dp), 0 + solve(prices, index+1, 1, limit, dp));
        else // sell karo ya skip karo
            profit = max(+prices[index] + solve(prices, index+1, 1, limit-1, dp), 0 + solve(prices, index+1, 0, limit, dp));
        
        return dp[index][buy][limit] = profit;
    }

    public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // index -> 0 to n-1
        // buy   -> 0 or 1
        // limit -> 1 or 2

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return solve(prices, 0, 1, 2, dp);
    }
    */



    // method-0 : recursion --> will give TLE
    /*
    int solve(vector<int>& prices, int index, int buy, int limit) {
        if(index == prices.size())
            return 0;
        
        if(limit == 0)
            return 0;
        
        int profit = 0;
        
        if(buy) // buy karo ya skip karo
            profit = max(-prices[index] + solve(prices, index+1, 0, limit), 0 + solve(prices, index+1, 1, limit));
        else // sell karo ya skip karo
            profit = max(+prices[index] + solve(prices, index+1, 1, limit-1), 0 + solve(prices, index+1, 0, limit));
        
        return profit;
    }

    public:
    int maxProfit(vector<int>& prices) {
        return solve(prices, 0, 1, 2);
    }
    */
};


int main() {
    
    return 0;
}