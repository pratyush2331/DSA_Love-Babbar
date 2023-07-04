// 509. Fibonacci Number
// LeetCOde : https://leetcode.com/problems/fibonacci-number/

#include<iostream>
using namespace std;


// METHOD-3
// using DP : space optimization
/*
TC : O(1)
SC : O(1)
*/
// /*
class Solution {
    public:
    int fib(int n) {
        // base case
        if(n <= 1) { // as n can be 0, otherwise it'll give runtime error
            return n;
        }

        // step-2
        int prev2 = 0;
        int prev1 = 1;

        // step-3
        int ans;
        for(int i = 2; i <= n; i++) {
            ans = prev1 + prev2;
            prev2 = prev1;
            prev1 = ans;
        }

        return ans;
    }
};
// */



// METHOD-2
// using DP- Bottom Up approach : tabulation
/*
TC : O(n)
SC : O(n)
*/
/*
class Solution {
    public:
    int fib(int n) {
        // base case
        if(n <= 1) { // as n can be 0, otherwise it'll give runtime error
            return n;
        }

        // step-1
        vector<int> dp(n+1);

        // step-2
        dp[0] = 0;
        dp[1] = 1;

        // step-3
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};
*/



// METHOD-1
// using DP- Top Down approach : recursion + memoization
/*
TC : O(n)
SC : O(2n)
*/
/*
class Solution {
    int func(int n, vector<int>& dp) { // TC: O(n)
        // base case
        if(n <= 1)
            return n;
        
        // step-3
        if(dp[n] != -1)
            return dp[n];

        // step-2
        dp[n] = func(n-1, dp) + func(n-2, dp);
        return dp[n];
    }

    public:
    int fib(int n) {
        // step-1
        vector<int> dp(n+1, -1);

        return func(n, dp); // SC: O(n) --> due to recursive call stack
    }
};
*/



// METHOD-0
// using recursion
/*
TC : O(2^n)
SC : O(n)
*/
/*
class Solution {
    public:
    int fib(int n) {
        // base case
        if(n <= 1) { // as n can be 0, otherwise it'll give runtime error
            return n;
        }

        return fib(n-1) + fib(n-2);
    }
};
*/


int main() {
    
    return 0;
}