// Count Ways To Reach The N-th Stairs
// CodeStudio : https://www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650

#include<iostream>
using namespace std;

// Method 3 (DP) : Space Optimization
/*
TC : O(n)
SC : O(1)
*/
#define MOD 1000000007

int countDistinctWays(int nStairs) {
    // base case
    if(nStairs == 0) {
        return 1;
    }
    if(nStairs == 1) { // not possible to start from -1 index
        return 1;
    }

    // step-2
    int prev1 = 1;
    int prev2 = 1;

    // step-3
    int ans;
    for(int i = 2; i <= nStairs; i++) {
        ans = (prev1 + prev2) % MOD;
        prev2 = prev1;
        prev1 = ans;
    }

    return ans;
}






// Method 2 (DP) : Bottom Up Approach = Tabulation
/*
TC : O(n)
SC : O(n)
*/
/*
#define MOD 1000000007

int countDistinctWays(int nStairs) {
    // base case
    if(nStairs == 0) {
        return 1;
    }
    if(nStairs == 1) {
        return 0;
    }

    // step-1
    vector<int> dp(nStairs+1);

    // step-2
    dp[0] = 1;
    dp[1] = 1;

    // step-3
    for(int i = 2; i <= nStairs; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }

    return dp[nStairs];
}
*/






// Method 1 (DP) : Top Down Approach = recursion + memoization
/*
TC : O(n)
SC : O(2n)
*/
/*
#define MOD 1000000007

int countWays(int nStairs, vector<int>& dp) {
    if(nStairs == 0)
        return 1;
    if(nStairs < 0) // not possible to start from -1 index
        return 0;

    if(dp[nStairs] != -1)
        return dp[nStairs];
    
    dp[nStairs] = (countWays(nStairs-1, dp) + countWays(nStairs-2, dp)) % MOD;

    return dp[nStairs];
}

int countDistinctWays(int nStairs) {
    vector<int> dp(nStairs+1, -1);
    return countWays(nStairs, dp);
}
*/






// Method 0 : using Recursion --> will give TLE
/*
TC : O(2^n)
SC : O(n)
*/
/*
#define MOD 1000000007

int countDistinctWays(int nStairs) {
    // base case
    if(nStairs == 0)
        return 1;
    if(nStairs < 0) // not possible to start from -1 index
        return 0;
    
    return (countDistinctWays(nStairs-1) + countDistinctWays(nStairs-2)) % MOD;
}
*/

int main() {
    
    return 0;
}