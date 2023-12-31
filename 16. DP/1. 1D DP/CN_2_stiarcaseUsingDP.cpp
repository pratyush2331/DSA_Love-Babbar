// Coding Ninjas : Staircase using DP

/***********************************************************QUESTION***********************************************************
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time.
Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.

Constraint:
print the answer with mod(10^9+7)

Input-1:
2
Output-1:
3

Input-2:
3
Output-2:
4

Input-3:
5
Output-3:
13

Input-4:
10
Output-4:
274
******************************************************************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

#define MOD 1000000007

// Method-3 (DP) : space optimization
/*
TC : O(n)
SC : O(1)
*/
// /*
int countWays(int n) {
    if(n == 0)
        return 1;
    if(n == 1 || n == 2)
        return n;
    
    //vector<long> dp(n+1, -1);

    long a = 1;
    long b = 1;
    long c = 2;

    long ans;
    for(int i = 3; i <= n; i++) {
        ans = a + b + c;
        // shifting
        a = b;
        b = c;
        c = ans;
    }
    
    return ans;
}
// */



// Method-2 (DP) : bottom-up approach = tabulation
/*
TC : O(n)
SC : O(n)
*/
/*
int countWays(int n) {
    if(n == 0)
        return 1;
    if(n == 1 || n == 2)
        return n;
    
    vector<long> dp(n+1, -1);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    
    return dp[n];
}
*/


// */
// Method-1 (DP) : top-down approach = recursion + memoization
/*
TC : O(n)
SC : O(2n)
*/
/*
int solve(int n, vector<int>& dp) {
    if(n == 0)
        return 1;
    else if(n < 0)
        return 0;
    
    if(dp[n] != -1) {
        return dp[n];
    }
    
    dp[n] = (solve(n-1, dp) + solve(n-2, dp) + solve(n-3, dp)) % MOD;
    return dp[n];
}

int countWays(int n) {
    vector<int> dp(n+1, -1);
    
    return solve(n, dp);
}
*/



// Method-0 : using simple recursion --> will give TLE
/*
TC : O(3^n)
SC : O(n)
*/
/*
int countWays(int n) {
    if(n == 0)
        return 1;
    else if(n < 0)
        return 0;
    
    return (countWays(n-1) + countWays(n-2) + countWays(n-3)) % MOD;
}
*/

int main() {
    int n;
    cin >> n;

    cout << countWays(n) << endl;
    
    return 0;
}