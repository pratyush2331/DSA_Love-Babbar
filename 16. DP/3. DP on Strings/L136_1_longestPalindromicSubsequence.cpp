// 516. Longest Palindromic Subsequence
// LeetCode : https://leetcode.com/problems/longest-palindromic-subsequence/

#include<iostream>
using namespace std;


class Solution {
    // method-3 : space optimization code of LCS
    /*
    TC : O(n*n)
    SC : O(n)
    */
    int longestCommonSubsequence(string a, string b) {
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

    public:
    int longestPalindromeSubseq(string str) {
        string revStr = str;
        reverse(revStr.begin(), revStr.end());

        return longestCommonSubsequence(str, revStr);
    }
};


int main() {
    
    return 0;
}