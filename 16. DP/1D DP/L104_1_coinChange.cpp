// 322. Coin Change
// LeetCode : https://leetcode.com/problems/coin-change/

#include<iostream>
using namespace std;

// Method-3 : 'space optimzation' is not possible, as it's curent value for any number is dependent on whole elements of coins[] array.



// Method 2 (DP) : Bottom Up approach : tabulation
/*
TC : O(amount * coins.size())
SC : O(amount)
*/
class Solution {
    public:
    int coinChange(vector<int>& coins, int amount) {
        // base case
        if(amount == 0)
            return 0;

        // step-1
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++) { //TC: O(amount * coins.size())
            // I'm trying to solve for every amount figure from 1 to amount
            for(int j = 0; j < coins.size(); j++) {
                if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
                }
            }
        }
        
        if(dp[amount] == INT_MAX) // NOT POSSIBLE
            return -1;
        return dp[amount];
    }
};



// Method 1 (DP) : Top Down approach : recursion + memoization
/*
TC : O(amount * coins.size())
SC : O(2*amount)
*/
/*
class Solution {
    int solve(vector<int>& coins, int amount, vector<int>& dp) { // TC: O(amount * coins.size()) --> as recursion + for loop
        // Base Case
        if(amount == 0)
            return 0;
        if(amount < 0) // INVALID (not possible)
            return INT_MAX;
        
        // step-3
        if(dp[amount] != -1)
            return dp[amount];
        
        // imp
        int mini = INT_MAX; // as we need minimum coins
        for(int i = 0; i < coins.size(); i++) {
            int ans = solve(coins, amount-coins[i], dp);
            if(ans != INT_MAX) // if answer is valid
                mini = min(mini, 1 + ans);
        }
        
        // step-2
        dp[amount] = mini;
        return dp[amount];
    }

    public:
    int coinChange(vector<int>& coins, int amount) {
        // step-1
        vector<int> dp(amount+1, -1); // SC: O(n)

        int ans = solve(coins, amount, dp);
        if(ans == INT_MAX) // NOT POSSIBLE
            return -1;
        return ans;
    }
};
*/



// Method 0 : using simple recursion --> will give TLE
/*
TC : O(coins.size() ^ amount)
SC : O(amount)
*/
/*
class Solution {
    int solve(vector<int>& coins, int amount) { // TC: O(coins.size() ^ amount)
        // Base Case
        if(amount == 0)
            return 0;
        if(amount < 0) // INVALID (not possible)
            return INT_MAX;
        
        int mini = INT_MAX; // as we need minimum coins
        for(int i = 0; i < coins.size(); i++) {
            int ans = solve(coins, amount-coins[i]);
            if(ans != INT_MAX) // answer is valid
                mini = min(mini, 1+ans);
        }
        return mini;
    }

    public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount);
        if(ans == INT_MAX) // NOT POSSIBLE
            return -1;
        return ans;
    }
};
*/

int main() {
    
    return 0;
}