// Painting the Fence
// GFG : https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1

#include<bits/stdc++.h>
using namespace std;


#define MOD 1000000007

class Solution{
    
    // utility function for addition and multiplication
    long long add(int a, int b) {
        return (a%MOD + b%MOD) % MOD;
    }
    
    long long mul(int a, int b) {
        return (a%MOD * 1ll * b%MOD) % MOD; // type casting to 'long long', as it may be the case when product of 2 integers can't be stored in integer
    }
    
    
    
    
    // Method3 (Dp) : space optimization
    /*
    TC : O(n)
    SC : O(1)
    */
    // /*
    public:
    long long countWays(int n, int k) {
        // Write your code here.
        
        // special case
        if(n == 1)
            return k;
        
        long long prev2 = k;
        long long prev1 = add(k, mul(k, k-1));
    
        for(int i = 3; i <= n; i++) {
            long long same = mul(prev2, k-1);
            long long diff = mul(prev1, k-1);
            
            long long ans = add(same, diff);
    
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
    public:
    long long countWays(int n, int k) {
        // Write your code here.
    
        vector<long long> dp(n+1, -1);
        
        dp[1] = k;
        dp[2] = add(k, mul(k, k-1));
    
        for(int i = 3; i <= n; i++) {
            long long same = mul(dp[i-2], k-1);
            long long diff = mul(dp[i-1], k-1);
            dp[i] = add(same, diff);
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
    long long solve(int n, int k, vector<long long>& dp) {
        // base case
        if(n == 1)
            return k;
        else if(n == 2)
            return add(k, mul(k, k-1));
        
        if(dp[n] != -1)
            return dp[n];
        
        long long same = mul(solve(n-2, k, dp), k-1);
        long long diff = mul(solve(n-1, k, dp), k-1);
        dp[n] = add(same, diff);
        return dp[n];
    }
    
    public:
    long long countWays(int n, int k){
        // code here
        vector<long long> dp(n+1, -1);
        return solve(n, k, dp);
    }
    */
    
    
    
    
    // Method 0 : using simple recursion --> will give TLE
    /*
    TC : O(2^n)
    SC : O(n)
    */
    /*
    long long solve(int n, int k) {
        // base case
        if(n == 1)
            return k;
        else if(n == 2)
            return add(k, mul(k, k-1));
        
        long long same = mul(solve(n-2, k), k-1);
        long long diff = mul(solve(n-1, k), k-1);
        long long ans = add(same, diff);
        return ans;
    }
    
    public:
    long long countWays(int n, int k){
        // code here
        return solve(n, k);
    }
    */
    
};


int main() {
    
    return 0;
}