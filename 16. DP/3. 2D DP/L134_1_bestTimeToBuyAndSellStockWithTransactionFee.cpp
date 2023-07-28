// 714. Best Time to Buy and Sell Stock with Transaction Fee
// LeetCode : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include<iostream>
using namespace std;


class Solution {
    // method-3 : space optimization
    /*
    TC : O(n)
    SC : O(1)
    */
    int solve(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        
        for(int index = n-1; index >= 0; index--) {
            for(int buy = 0; buy <= 1; buy++) {
                int profit = 0;

                if(buy) // buy karo ya skip karo
                    profit = max(-prices[index] + next[0], 0 + next[1]);
                else // sell karo ya skip karo
                    profit = max(+prices[index] + next[1] - fee, 0 + next[0]);
                
                curr[buy] = profit;
            }
            next = curr;
        }

        return next[1];
    }

    public:
    int maxProfit(vector<int>& prices, int fee) {
        return solve(prices, fee);
    }
};


int main() {
    
    return 0;
}