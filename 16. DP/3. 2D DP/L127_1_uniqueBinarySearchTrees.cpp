// 96. Unique Binary Search Trees
// LeetCode : https://leetcode.com/problems/unique-binary-search-trees/

#include<iostream>
using namespace std;


class Solution {
    // method-3 : using Catalan Number
    // /*
    long long catalanNumber(int n) {
        if(n <= 1)
            return 1;
        
        vector<long long> catalan(n+1, 0);

        catalan[0] = catalan[1] = 1;
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i-j-1];
            }
        }

        return catalan[n];
    }

    public:
    int numTrees(int n) {
        return catalanNumber(n);
    }
    // */



    // method-2 : tabulation
    /*
    public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;

        // i -> no. of nodes
        for(int i = 2; i <= n; i++) {
            // think j as root nodes
            for(int j = 1; j <= i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }

        return dp[n];
    }
    */



    // method-1 : recursion + memoization
    /*
    int solve(int n, vector<int>& dp) {
        if(n <= 1)
            return 1;

        if(dp[n] != -1) {
            return dp[n];
        }

        int ans = 0;
        // think i as root nodes
        for(int i = 1; i <= n; i++) {
            ans += solve(i-1, dp) * solve(n-i, dp);
        }

        return dp[n] = ans;
    }
    public:
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
    */

    

    // method-0 : recursion
    /*
    public:
    int numTrees(int n) {
        if(n <= 1)
            return 1;

        int ans = 0;
        // think i as root nodes
        for(int i = 1; i <= n; i++) {
            ans += numTrees(i-1) * numTrees(n-i);
        }

        return ans;
    }
    */
};


int main() {
    
    return 0;
}