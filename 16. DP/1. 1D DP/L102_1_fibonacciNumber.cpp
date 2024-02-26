// 509. Fibonacci Number
// LeetCOde : https://leetcode.com/problems/fibonacci-number/

/*
fibonacci series : 
f(0) = 0, 
f(1) = 1, 
f(2) = 1, 
f(3) = 1, 
f(4) = 2, 
f(5) = 3, 
f(6) = 5,...
*/

#include<iostream>
using namespace std;


// METHOD-4
// using DP : matrix exponentiation
/*
TC : O(logn)
SC : O(1)
*/
// /*
class Solution {
public:
    // function to multiply 2 matrices
    vector<vector<int>> matrixMultiply(vector<vector<int>>& a, vector<vector<int>>& b) {
        int sz = 2; // a.size();
        vector<vector<int>> ans(sz, vector<int>(sz, 0));
        for(int i = 0; i < sz; i++) {
            for(int j = 0; j < sz; j++) {
                for(int k = 0; k < sz; k++) {
                    ans[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return ans;
    }

    // function to exponentiate
    vector<vector<int>> matrixExponentiate(vector<vector<int>>& a, int n) {
        if(n < 0) {
            cout << "n can't be less than zero!\n";
            // exit;
            vector<vector<int>> ans(2, vector<int>(2, 0));
            return ans;
        }
        if(n == 0) { // return identity matrix
            int sz = 2; // a.size();
            vector<vector<int>> ans(sz, vector<int>(sz, 0));
            ans[0][0] = ans[1][1] = 1;
            return ans;
        }
        if(n == 1) {
            return a;
        }

        // binary exponentitation + DP logic
        vector<vector<int>> temp = matrixExponentiate(a, n/2);
        vector<vector<int>> ans = matrixMultiply(temp, temp);
        if(n&1) { // odd power
            ans = matrixMultiply(ans, a);
        }
        return ans;
    }

    public:
    int fib(int n) {
        vector<vector<int>> a = {{1,1}, {1,0}};
        int sz = 2; // a.size();

        vector<vector<int>> ans = matrixExponentiate(a, n);

        // printing the a^n (fibonacci matrix)
        // for(int i = 0; i < sz; i++) {
        //     for(int j = 0; j < sz; j++) {
        //         cout << ans[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        return ans[0][1];
    }
};
// */



// METHOD-3
// using DP : space optimization
/*
TC : O(n)
SC : O(1)
*/
/*
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
*/



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