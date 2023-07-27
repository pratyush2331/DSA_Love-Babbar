// 121. Best Time to Buy and Sell Stock
// LeetCode : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<iostream>
using namespace std;


class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, mini = prices[0];
        for(int i = 0; i < prices.size(); i++) {
            int diff = prices[i] - mini;
            profit = max(profit, diff);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};


int main() {
    
    return 0;
}