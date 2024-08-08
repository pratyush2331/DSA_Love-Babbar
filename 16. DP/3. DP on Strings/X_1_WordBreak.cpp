// 139. Word Break
// LeetCode : https://leetcode.com/problems/word-break/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    bool solve(int i, string& s, unordered_map<string,int>& mp, vector<int>& dp) { // checking every possible prefix starting from 'i'
        if(i == s.length()) return true;

        if(dp[i] != -1) return dp[i];// already computed the result for the substring starting at 'i'

        bool ans = false;
        string str;
        for(int k = i; k < s.length(); k++) {
            str += s[k];
            if(mp[str]) {
                ans |= solve(k+1, s, mp, dp);
            }
        }
        return dp[i] = ans;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> mp;
        for(auto ele : wordDict) {
            mp[ele] = 1;
        }

        vector<int> dp(s.length(), -1);
        return solve(0, s, mp, dp);
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        
    return 0;
}