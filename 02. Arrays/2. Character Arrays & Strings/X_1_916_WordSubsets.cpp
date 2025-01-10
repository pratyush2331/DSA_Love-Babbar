// 916. Word Subsets
// LeetCode : https://leetcode.com/problems/word-subsets/

#include<bits/stdc++.h>
using namespace std;


// optimized code
/*
TC : O(m . 26)
SC : O(m . 26)
*/
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<unordered_map<char, int>> mp1(words1.size()); // words1 -> word -> freq(ch)
        int idx = 0;
        for(auto& word : words1) {
            for(auto&ch : word) {
                mp1[idx][ch]++;
            }
            idx++;
        }

        unordered_map<char, int> mp2; // words2 -> max_freq(ch)
        for(auto& word : words2) {
            unordered_map<char, int> freq;
            for(auto&ch : word) {
                freq[ch]++;
                mp2[ch] = max(mp2[ch], freq[ch]);
            }
        }

        vector<string> ans;
        idx = 0;
        for(auto& v1 : mp1) {
            bool flag = 1;
            for(auto& ele : mp2) {
                if(v1[ele.first] < ele.second) {
                    flag = 0;
                    break;
                }
            }
            if(flag) ans.emplace_back(words1[idx]);
            idx++;
        }
        return ans;
    }
};


// will give TLE
/*
TC : O(m.n)
SC : O(m.26 + n.26)
*/
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<unordered_map<char, int>> mp1(words1.size()); // word1 -> word -> fre(ch)
        int idx = 0;
        for(auto& word : words1) {
            for(auto&ch : word) {
                mp1[idx][ch]++;
            }
            idx++;
        }

        vector<unordered_map<char, int>> mp2(words2.size()); // word2 -> word -> fre(ch)
        idx = 0;
        for(auto& word : words2) {
            for(auto&ch : word) {
                mp2[idx][ch]++;
            }
            idx++;
        }

        vector<string> ans;
        idx = 0;
        for(auto v1 : mp1) {
            bool flag = 1;
            cout << " idx =  " << idx << "\n";
            for(auto v2 : mp2) {
                for(auto ele : v2) {
                    cout << v2[ele.first] << " " << v1[ele.first] << "\n";
                    if(v2[ele.first] > v1[ele.first]) {flag = 0; break;}
                }
                if(!flag) break;
            }
            if(flag) ans.emplace_back(words1[idx]);
            idx++;
        }
        return ans;
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