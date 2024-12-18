// 1475. Final Prices With a Special Discount in a Shop
// LeetCode : https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

#include<bits/stdc++.h>
using namespace std;


// method-1 : Monotonic Stack
/*
TC : O(2n) = O(n)
SC : O(n)
*/
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.size());
        stack<int> s;
        for(int i = prices.size()-1; i >= 0; i--) {
            while(!s.empty() && s.top() > prices[i]) s.pop();

            ans[i] = prices[i];
            if(!s.empty()) ans[i] -= s.top();

            s.push(prices[i]);
        }
        return ans;
    }
};


// method-0 : brute-force
/*
TC : O(n^2)
SC : O(1) // not counting answer array
*/
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.size());
        for(int i = 0; i < prices.size(); i++) {
            ans[i] = prices[i];
            for(int j = i+1; j < prices.size(); j++) {
                if(prices[j] <= prices[i]) {ans[i] -= prices[j]; break;}
            }
        }
        return ans;
    }
};


int main() {
    
    return 0;
}