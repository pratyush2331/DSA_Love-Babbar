// 121. Best Time to Buy and Sell Stock
// LeetCode : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<iostream>
using namespace std;


/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, min_price = prices[0];
        for(int price : prices) { // TC:O(n)
            max_profit = max(max_profit, price - min_price);
            min_price = min(min_price, price);
        }
        return max_profit;
    }
};


int main() {
    
    return 0;
}