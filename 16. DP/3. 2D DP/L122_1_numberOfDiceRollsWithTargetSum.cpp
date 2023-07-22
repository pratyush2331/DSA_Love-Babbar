// 1155. Number of Dice Rolls With Target Sum
// LeetCode : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

#include<iostream>
using namespace std;


class Solution {
    int mod = 1000000007;

    // method-3 : space optimization
    /*
    TC : O(d * f * t)
    SC : O(2 * t)
    */

    // /*
    public:
    int numRollsToTarget(int d, int f, int t) {
        vector<int> prev(t+1, 0);
        vector<int> curr(t+1, 0);

        // after analysing base acse : when dice and target both are 0 from (rec + memo code)
        prev[0] = 1;

        for(int dice = 1; dice <= d; dice++) {
            for(int target = 1; target <= t; target++) {
                int ans = 0;
                for(int i = 1; i <= f; i++) {
                    if((target - i) >= 0)
                        ans = ans%mod + prev[target - i] % mod;
                }
                curr[target] = ans%mod;
            }
            prev = curr;
        }

        return prev[t];
    }
    // */



    // method-2 : tabulation
    /*
    TC : O(d * f * t)
    SC : O(d * t)
    */

    /*
    public:
    int numRollsToTarget(int d, int f, int t) {
        vector<vector<int>> dp(d+1, vector<int>(t+1, 0));

        // after analysing base acse : when dice and target both are 0 from (rec + memo code)
        dp[0][0] = 1;

        for(int dice = 1; dice <= d; dice++) {
            for(int target = 1; target <= t; target++) {
                int ans = 0;
                for(int i = 1; i <= f; i++) {
                    if((target - i) >= 0)
                        ans = ans%mod + dp[dice-1][target - i] % mod;
                }
                dp[dice][target] = ans%mod;
            }
        }

        return dp[d][t];
    }
    */



    // method-1 : recursion + memoization
    /*
    int solve(int dice, int faces, int target, vector<vector<int>>& dp) {
        if(target < 0)
            return 0;
        
        if((dice == 0 && target != 0) || (dice != 0 && target == 0))
            return 0;
        
        if(dice == 0 && target == 0)
            return 1;
        
        // checking if 'ans' is already calculated
        if(dp[dice][target] != -1)
            return dp[dice][target];
        
        
        int ans = 0;
        for(int i = 1; i <= faces; i++) {
            ans = ans%mod + solve(dice-1, faces, target - i, dp)%mod;
        }
        return dp[dice][target] = ans%mod;
    }

    public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve(n, k, target, dp);
    }
    */



    // method-0 : recursion --> will give TLE
    /*
    int solve(int dice, int faces, int target) {
        if(target < 0)
            return 0;
        
        if((dice == 0 && target != 0) || (dice != 0 && target == 0))
            return 0;
        
        if(dice == 0 && target == 0)
            return 1;
        
        int ans = 0;
        for(int i = 1; i <= faces; i++) {
            ans = ans + solve(dice-1, faces, target - i)%mod;
        }
        return ans%mod;
    }

    public:
    int numRollsToTarget(int n, int k, int target) {
        return solve(n, k, target);
    }
    */
};


int main() {
    
    return 0;
}