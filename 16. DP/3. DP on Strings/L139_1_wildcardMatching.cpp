// 44. Wildcard Matching
// LeetCode : https://leetcode.com/problems/wildcard-matching/

#include<iostream>
using namespace std;


class Solution {
    // method-3 : space optimization
    /*
    TC : O(m * n)
    SC : O(n)
    */
    // /*
    public:
    bool isMatch(string str, string pattern) {
        vector<bool> prev(pattern.length() + 1, false);
        vector<bool> curr(pattern.length() + 1, false);

        // from base cases
        prev[0] = true;
        for(int j = 1; j <= pattern.length(); j++) {
            bool flag = true;
            for(int k = 1; k <= j; k++) {
                if(pattern[k-1] != '*') {
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for(int i = 1; i <= str.length(); i++) {
            for(int j = 1; j <= pattern.length(); j++) {
                if(str[i-1] == pattern[j-1] || pattern[j-1] == '?')
                    curr[j] = prev[j-1];
                else if(pattern[j-1] == '*')
                    curr[j] = (prev[j] || curr[j-1]);
                else
                    curr[j] = false;
            }
            prev = curr;
        }

        return prev[pattern.length()];
    }
    // */



    // method-2 : tabulation
    /*
    TC : O(m * n)
    SC : O(m * n)
    */
    /*
    public:
    bool isMatch(string str, string pattern) {
        vector<vector<bool>> dp(str.length() + 1, vector<bool>(pattern.length() + 1, false));

        // from base cases
        dp[0][0] = true;
        for(int i = 1; i <= str.length(); i++) {
            dp[i][0] = false;
        }
        for(int j = 1; j <= pattern.length(); j++) {
            bool flag = true;
            for(int k = 1; k <= j; k++) {
                if(pattern[k-1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for(int i = 1; i <= str.length(); i++) {
            for(int j = 1; j <= pattern.length(); j++) {
                if(str[i-1] == pattern[j-1] || pattern[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(pattern[j-1] == '*')
                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
                else
                    dp[i][j] = false;
            }
        }

        return dp[str.length()][pattern.length()];
    }
    */



    // method-1.2 : '1' based indexing : recursion + memoization
    /*
    TC : O(m * n)
    SC : O(m * n)
    */
    /*
    bool solve(string& str, string& pattern, int i, int j, vector<vector<bool>>& dp) {
        // base cases
        if(i == 0 && j == 0)
            return true;
        if(i > 0 && j == 0)
            return false;
        if(i == 0 && j > 0) {
            for(int k = 1; k <= j; k++) {
                if(pattern[k-1] != '*') {
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        if(str[i-1] == pattern[j-1] || pattern[j-1] == '?')
            return dp[i][j] = solve(str, pattern, i-1, j-1, dp);
        else if(pattern[j-1] == '*')
            return dp[i][j] = (solve(str, pattern, i-1, j, dp) || solve(str, pattern, i, j-1, dp));
        else
            return dp[i][j] = false;
    }

    public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, -1));

        return solve(s, p, s.length(), p.length(), dp);
    }
    */



    // method-1.1 : '0' based indexing : recursion + memoization
    /*
    TC : O(m * n)
    SC : O(m * n)
    */
    /*
    bool solve(string& str, string& pattern, int i, int j, vector<vector<bool>>& dp) {
        // base cases
        if(i < 0 && j < 0)
            return true;
        if(i >= 0 && j < 0)
            return false;
        if(i < 0 && j >= 0) {
            for(int k = 0; k <= j; k++) {
                if(pattern[k] != '*') {
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        if(str[i] == pattern[j] || pattern[j] == '?')
            return dp[i][j] = solve(str, pattern, i-1, j-1, dp);
        else if(pattern[j] == '*')
            return dp[i][j] = (solve(str, pattern, i-1, j, dp) || solve(str, pattern, i, j-1, dp));
        else
            return dp[i][j] = false;
    }

    public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length(), vector<bool>(p.length(), -1));

        return solve(s, p, s.length()-1, p.length()-1, dp);
    }
    */



    // method-0 : recursion --> will give TLE
    /*
    bool solve(string& s, string& p, int i, int j) {
        // base cases
        if(i < 0 && j < 0)
            return true;
        if(i >= 0 && j < 0)
            return false;
        if(i < 0 && j >= 0) {
            for(int k = 0; k <= j; k++) {
                if(p[k] != '*') {
                    return false;
                }
            }
            return true;
        }

        if(s[i] == p[j] || p[j] == '?')
            return solve(s, p, i-1, j-1);
        else if(p[j] == '*')
            return (solve(s, p, i-1, j) || solve(s, p, i, j-1));
        else
            return false;
    }

    public:
    bool isMatch(string s, string p) {
        return solve(s, p, s.length()-1, p.length()-1);
    }
    */
};


int main() {
    
    return 0;
}