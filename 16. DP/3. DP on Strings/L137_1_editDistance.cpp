// 72. Edit Distance
// LeetCode : https://leetcode.com/problems/edit-distance/

#include<iostream>
using namespace std;


class Solution {
    // method-2 : space optimization {IMP}
    /*
    TC : O(m*n)
    SC : O(min(m,n))
    */
    // /*
    public:
    int minDistance(string a, string b) {
        // to reduce SC further from O(n) to O(min(m,n))
        if(a.length() < b.length()) swap(a, b);

        // EDGE CASE : when a is empty or b is empty
        if(a.length() == 0)
            return b.length();
        if(b.length() == 0)
            return a.length();

        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);

        // IMP from Base Case
        for(int j = 0; j < b.length(); j++)
            next[j] = b.length() - j;
        
        for(int i = a.length()-1; i >= 0; i--) {
            for(int j = b.length()-1; j >= 0; j--) {

                // IMP from Base Case
                curr[b.length()] = a.length() - i;

                int ans = 0;
                if(a[i] == b[j]) { // matched
                    ans = next[j+1];
                }
                else { // not matched
                    // insert
                    int insertAns = 1 + curr[j+1];

                    // delete
                    int deleteAns = 1 + next[j];

                    // replace
                    int replaceAns = 1 + next[j+1];

                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                curr[j] = ans;
            }
            next = curr;
        }

        return next[0];
    }
    // */



    // method-2 : tabulation
    /*
    public:
    int minDistance(string a, string b) {
        vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));

        for(int j = 0; j < b.length(); j++)
            dp[a.length()][j] = b.length() - j;
        
        for(int i = 0; i < a.length(); i++)
            dp[i][b.length()] = a.length() - i;
        
        for(int i = a.length()-1; i >= 0; i--) {
            for(int j = b.length()-1; j >= 0; j--) {
                int ans = 0;
                if(a[i] == b[j]) { // matched
                    ans = dp[i+1][j+1];
                }
                else { // not matched
                    // insert
                    int insertAns = 1 + dp[i][j+1];

                    // delete
                    int deleteAns = 1 + dp[i+1][j];

                    // replace
                    int replaceAns = 1 + dp[i+1][j+1];

                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }
    */



    // method-1 : recursion + memoization
    /*
    int solve(string a, string b, int i, int j, vector<vector<int>>& dp) {
        if(i == a.length())
            return b.length() - j;
        if(j == b.length())
            return a.length() - i;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        if(a[i] == b[j]) { // matched
            ans = solve(a, b, i+1, j+1, dp);
        }
        else { // not matched
            // insert
            int insertAns = 1 + solve(a, b, i, j+1, dp);

            // delete
            int deleteAns = 1 + solve(a, b, i+1, j, dp);

            // replace
            int replaceAns = 1 + solve(a, b, i+1, j+1, dp);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return dp[i][j] = ans;
    }

    public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));

        return solve(word1, word2, 0, 0, dp);
    }
    */



    // method-0 : recursion --> will give MLE
    /*
    int solve(string a, string b, int i, int j) {
        if(i == a.length())
            return b.length() - j;
        if(j == b.length())
            return a.length() - i;
        
        int ans = 0;
        if(a[i] == b[j]) { // matched
            ans = solve(a, b, i+1, j+1);
        }
        else { // not matched
            // insert
            int insertAns = 1 + solve(a, b, i, j+1);

            // delete
            int deleteAns = 1 + solve(a, b, i+1, j);

            // replace
            int replaceAns = 1 + solve(a, b, i+1, j+1);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return ans;
    }

    public:
    int minDistance(string word1, string word2) {
        return solve(word1, word2, 0, 0);
    }
    */
};


int main() {
    
    return 0;
}