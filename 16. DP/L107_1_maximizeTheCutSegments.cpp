// Maximize The Cut Segments
// GFG : https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

#include<iostream>
using namespace std;


class Solution
{
    // Method-3 : 'space optimzation' is not possible, as it's curent value 'i' can have dependency on any previous number.
    
    
    
    // Method2 (Dp) : tabulation
    /*
    TC : O(n)
    SC : O(n)
    */
    // /*
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        
        vector<int> dp(n+1, INT_MIN);
        
        dp[0] = 0;
        
        int op1 = INT_MIN, op2 = INT_MIN, op3 = INT_MIN;
        for(int i = 1; i <= n; i++) {
            if(i-x >= 0)
                op1 = dp[i-x];
            if(i-y >= 0)
                op2 = dp[i-y];
            if(i-z >= 0)
                op3 = dp[i-z];
            
            dp[i] = max(op1, max(op2, op3)) + 1;
        }
        
        if(dp[n] < 0)
            return 0;
        return dp[n];
    }
    // */
    
    
    
    // Method 1 (DP) : Top Down approach : recursion + memoization
    /*
    TC : O(n)
    SC : O(2*n)
    */
    /*
    int solve(int n, int x, int y, int z, vector<int>& dp) {
        // base case
        if(n == 0)
            return 0;
        else if(n < 0)
            return INT_MIN;
        
        if(dp[n] != -1)
            return dp[n];
        
        int op1 = solve(n-x, x, y, z, dp);
        int op2 = solve(n-y, x, y, z, dp);
        int op3 = solve(n-z, x, y, z, dp);
        
        dp[n] = max(op1, max(op2, op3)) + 1;
        return dp[n];
    }
    
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        
        vector<int> dp(n+1, -1);
        int ans = solve(n, x, y, z, dp);
        if(ans < 0)
            return 0;
        return ans;
    }
    */
    
    
    
    // Method 0 : using simple recursion --> will give TLE
    /*
    TC : O(3^n)
    SC : O(n)
    */
    /*
    int solve(int n, int x, int y, int z) {
        // base case
        if(n == 0)
            return 0;
        else if(n < 0)
            return INT_MIN;
        
        int op1 = solve(n-x, x, y, z);
        int op2 = solve(n-y, x, y, z);
        int op3 = solve(n-z, x, y, z);
        
        int ans = max(op1, max(op2, op3)) + 1;
        return ans;
    }
    
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        
        int ans = solve(n, x, y, z);
        if(ans < 0)
            return 0;
        return ans;
    }
    */
};


int main() {
    
    return 0;
}