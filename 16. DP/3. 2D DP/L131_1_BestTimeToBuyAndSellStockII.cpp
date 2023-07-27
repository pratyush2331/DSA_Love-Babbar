// 122. Best Time to Buy and Sell Stock II
// LeetCode : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

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
        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        
        for(int index = n-1; index >= 0; index--) {
            for(int buy = 0; buy <= 1; buy++) {
                int profit = 0;

                if(buy) // buy karo ya skip karo
                    profit = max(-prices[index] + next[0], 0 + next[1]);
                else // sell karo ya skip karo
                    profit = max(+prices[index] + next[1], 0 + next[0]);
                
                curr[buy] = profit;
            }
            next = curr;
        }

        return next[1];
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
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        for(int index = n-1; index >= 0; index--) {
            for(int buy = 0; buy <= 1; buy++) {
                int profit = 0;

                if(buy) // buy karo ya skip karo
                    profit = max(-prices[index] + dp[index+1][0], 0 + dp[index+1][1]);
                else // sell karo ya skip karo
                    profit = max(+prices[index] + dp[index+1][1], 0 + dp[index+1][0]);
                
                dp[index][buy] = profit;
            }
        }

        return dp[0][1];
    }
    */



    // method-1 : recursion + memoization
    /*
    int solve(vector<int>& prices, int index, int buy, vector<vector<int>>& dp) {
        if(index == prices.size())
            return 0;
        
        if(dp[index][buy] != -1)
            return dp[index][buy];
        
        int profit = 0;

        if(buy) // buy karo ya skip karo
            profit = max(-prices[index] + solve(prices, index+1, 0, dp), 0 + solve(prices, index+1, 1, dp));
        else // sell karo ya skip karo
            profit = max(+prices[index] + solve(prices, index+1, 1, dp), 0 + solve(prices, index+1, 0, dp));
        
        return dp[index][buy] = profit;
    }

    public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(prices, 0, 1, dp);
    }
    */



    // method-0 : recursion -- > will give TLE
    /*
    int solve(vector<int>& prices, int index, int buy) {
        if(index == prices.size())
            return 0;
        
        int profit = 0;

        if(buy) // buy karo ya skip karo
            profit = max(-prices[index] + solve(prices, index+1, 0), 0 + solve(prices, index+1, 1));
        else // sell karo ya skip karo
            profit = max(+prices[index] + solve(prices, index+1, 1), 0 + solve(prices, index+1, 0));
        
        return profit;
    }

    public:
    int maxProfit(vector<int>& prices) {
        return solve(prices, 0, 1);
    }
    */
};


int main() {
    
    return 0;
}