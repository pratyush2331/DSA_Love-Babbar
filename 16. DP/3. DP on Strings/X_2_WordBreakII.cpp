// 140. Word Break II
// LeetCode : https://leetcode.com/problems/word-break-ii/

#include<bits/stdc++.h>
using namespace std;


/*
TC : O(2^n)
*/

class Solution {
    void solve(int i, string& curr, string& s, unordered_map<string,int>& mp, vector<string>& ans) {
        if(i == s.length()) {
            ans.push_back(curr);
            return;
        }

        string str;
        for(int k = i; k < s.length(); k++) {
            str += s[k];
            if(mp[str]) {
                string prev = curr.empty() ? str : (curr + " " + str);
                solve(k+1, prev, s, mp, ans);
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;

        unordered_map<string,int> mp;
        for(auto ele : wordDict) {
            mp[ele] = 1;
        }

        string curr;
        solve(0, curr, s, mp, ans);

        return ans;
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        
    return 0;
}