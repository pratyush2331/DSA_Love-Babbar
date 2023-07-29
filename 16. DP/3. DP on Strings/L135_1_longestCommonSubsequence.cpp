// 1143. Longest Common Subsequence
// LeetCode : https://leetcode.com/problems/longest-common-subsequence/

#include<iostream>
using namespace std;


class Solution {
    // method-3 : space optimization
    /*
    TC : O(m*n)
    SC : O(min(m,n))
    */
    // /*
    public:
    int longestCommonSubsequence(string a, string b) {
        // to reduce SC further from O(n) to O(min(m,n))
        if(a.length() < b.length()) swap(a,b);

        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);

        for(int i = a.length()-1; i >= 0; i--) {
            for(int j = b.length()-1; j >=0; j--) {
                int ans = 0;

                if(a[i] == b[j]) // matched
                    ans = 1 + next[j+1];
                else // not matched
                    ans = max(next[j], curr[j+1]);
                
                curr[j] = ans;
            }
            next = curr;
        }

        return next[0];
    }
    // */



    // method-2 : tabulation
    /*
    TC : O(m*n)
    SC : O(m*n)
    */
    /*
    public:
    int longestCommonSubsequence(string a, string b) {
        vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));

        for(int i = a.length()-1; i >= 0; i--) {
            for(int j = b.length()-1; j >=0; j--) {
                int ans = 0;

                if(a[i] == b[j]) // matched
                    ans = 1 + dp[i+1][j+1];
                else // not matched
                    ans = max(dp[i+1][j], dp[i][j+1]);
                
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }
    */



    // method-1 : recursion + memoization
    /*
    TC : O(m*n)
    SC : O(m*n) + O(m+n)
    */
    /*
    int solve(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
        if(i == a.length() || j == b.length())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;

        if(a[i] == b[j]) // matched
            ans = 1 + solve(a, b, i+1, j+1, dp);
        else // not matched
            ans = max(solve(a, b, i+1, j, dp), solve(a, b, i, j+1, dp));
        
        return dp[i][j] = ans;
    }

    public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return solve(text1, text2, 0, 0, dp); // SC: O(m+n) --> recursive stack
    }
    */



    // method-0 : recursion --> will give TLE
    /*
    TC : O(2 ^ (m+n))
    SC : O(m+n)
    */
    /*
    int solve(string& a, string& b, int i, int j) {
        if(i == a.length() || j == b.length())
            return 0;
        
        int ans = 0;

        if(a[i] == b[j]) // matched
            ans = 1 + solve(a, b, i+1, j+1);
        else // not matched
            ans = max(solve(a, b, i+1, j), solve(a, b, i, j+1));
        
        return ans;
    }

    public:
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1, text2, 0, 0);
    }
    */
};


int main() {
    
    return 0;
}