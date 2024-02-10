// 2806. Account Balance After Rounded Purchase
// LeetCode : https://leetcode.com/contest/biweekly-contest-110/problems/account-balance-after-rounded-purchase/

// Topic : problem solving, maths

#include<iostream>
using namespace std;


class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int digit = purchaseAmount%10;
        if(digit < 5) {
            purchaseAmount -= digit;
        }
        else {
            purchaseAmount += 10-digit;
        }
        
        return (100-purchaseAmount);
    }
};


int main() {
    
    return 0;
}