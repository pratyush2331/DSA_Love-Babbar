// 1639. Number of Ways to Form a Target String Given a Dictionary
// LeetCode : https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/

#include<bits/stdc++.h>
using namespace std;


// approach : recursion + memoization [2D DP]
/*
TC : O(words.length() * word.length) + O(target.length * word.length)
SC : O(target.length * word.length)
*/

class Solution {
    const int MOD = 1e9+7;

    int solve(int target_i, int word_i, string& target, vector<vector<int>>& freq, vector<vector<int>>& dp) {
        if(target_i == target.length()) return 1;
        if(word_i == freq[0].size()) return 0;

        if(dp[target_i][word_i] != -1) return dp[target_i][word_i];

        // not take
        long long ways = solve(target_i, word_i + 1, target, freq, dp);

        // take
        char ch = target[target_i];
        if(freq[ch - 'a'][word_i] > 0) {
            ways += (long long)freq[ch - 'a'][word_i] * solve(target_i + 1, word_i + 1, target, freq, dp);
        }

        return dp[target_i][word_i] = ways % MOD;
    }

public:
    int numWays(vector<string>& words, string target) {
        // freq = {'ch', [freq(ch_at_0), freq(ch_at_1), ...]}
        vector<vector<int>> freq(26, vector<int>(words[0].length(), 0)); // SC:O(26 * word.length)
        for(string& word : words) { // TC:O(words.length * word.length)
            for(int i = 0; i < words[0].length(); i++) {
                freq[word[i] - 'a'][i]++;
            }
        }
        
        vector<vector<int>> dp(target.length(), vector<int>(words[0].length(), -1)); // SC:O(target.length * word.length)
        return solve(0, 0, target, freq, dp); // TC:O(target.length * word.length), SC:O(target.length + word.length)
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}