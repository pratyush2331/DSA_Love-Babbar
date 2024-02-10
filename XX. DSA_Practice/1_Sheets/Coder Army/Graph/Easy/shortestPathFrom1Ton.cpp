// Shortest path from 1 to n
// GGF : https://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n0156/1

#include<bits/stdc++.h>

using namespace std;


// method3 : basic maths
// optimal solution; by identifying the pattern
class Solution{
    public:
    int minimumStep(int n){
        int ans = 0;
        
        while(n > 1) {
            if(n%3 == 0)  {
                n = n/3;
                ans++;
            }
            else {
                n--;
                ans++;
            }
        }
        
        return ans;
    }
};



// method2 : tabulation
// sometime fails
/*
class Solution{
    public:
    int minimumStep(int n){
        vector<int> dp(n+1, -1);
        
        dp[0] = 0;
        dp[1] = 0;
        
        
        for(int i = 2; i <= n; i++) {
            int choice1 = dp[i-1];
            int choice2 = (i%3 == 0) ? dp[i/3] : 1e9;
            
            dp[i] = 1 + min(choice1, choice2);
        }
        
        return dp[n];
    }
};
*/



// method1 : recursion + memoization
/*
class Solution{
    int solve(int n, vector<int>& dp) {
        if(n == 1)
            return 0;
        else if(n < 1)
            return 1e9;
        
        if(dp[n] != -1)
            return dp[n];
        
        int choice1 = solve(n-1, dp);
        int choice2 = (n%3 == 0) ? solve(n/3, dp) : 1e9;
        
        return dp[n] = 1 + min(choice1, choice2);
    }
    
    public:
    int minimumStep(int n){
        vector<int> dp(n+1, -1);
        
        return solve(n, dp);
    }
};
*/



// method0 : recursion
// will give TLE
/*
class Solution{   
    public:
    int minimumStep(int n){
        if(n == 1)
            return 0;
        else if(n < 1)
            return 1e9;
        
        int choice1 = minimumStep(n-1);
        int choice2 = (n%3 == 0) ? minimumStep(n/3) : 1e9;
        
        return 1 + min(choice1, choice2);
    }
};
*/


int main() {


    return 0;
}