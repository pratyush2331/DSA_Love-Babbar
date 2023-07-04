// Count derangements [OR] Hat Check Problem
// CodeStudio : https://www.codingninjas.com/studio/problems/count-derangements_873861


#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007


// Method3 (Dp) : space optimization
/*
TC : O(n)
SC : O(1)
*/
// /*
long long int countDerangements(int n) {
    // Write your code here.

    long long int prev2 = 0;
    long long int prev1 = 1;

    for(int i = 3; i <= n; i++) {
        long long int ans = (((i-1) %MOD) * ((prev1 %MOD + prev2 %MOD) %MOD)) %MOD;
        
        // shifting
        prev2 = prev1;
        prev1 = ans;
    }
    
    return prev1;
}
// */



// Method2 (Dp) : tabulation
/*
TC : O(n)
SC : O(n)
*/
/*
long long int countDerangements(int n) {
    // Write your code here.

    vector<long long int> dp(n+1, 0);

    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3; i <= n; i++) {
        dp[i] = (((i-1) %MOD) * ((dp[i-1] %MOD + dp[i-2] %MOD) %MOD)) %MOD;
    }
    
    return dp[n];
}
*/



// Method 1 (DP) : Top Down approach : recursion + memoization
/*
TC : O(n)
SC : O(2*n)
*/
/*
long long int solve(int n, vector<long long int>& dp) {
    // base case
    if(n == 1)
        return 0;
    else if(n == 2)
        return 1;
    
    if(dp[n] != -1)
        return dp[n];
    
    dp[n] = (((n-1) %MOD) * ((solve(n-1, dp) %MOD + solve(n-2, dp) %MOD) %MOD)) %MOD;
    return dp[n];
}

long long int countDerangements(int n) {
    // Write your code here.

    vector<long long int> dp(n+1, -1);
    return solve(n, dp);
}
*/



// Method 0 : using simple recursion --> will give TLE
/*
TC : O(2^n)
SC : O(n)
*/
/*
long long int countDerangements(int n) {
    // Write your code here.

    // base case
    if(n == 1)
        return 0;
    else if(n == 2)
        return 1;
    
    int ans = (n-1) * (countDerangements(n-1) + countDerangements(n-2));

    return ans % MOD;
}
*/


int main() {
    
    return 0;
}