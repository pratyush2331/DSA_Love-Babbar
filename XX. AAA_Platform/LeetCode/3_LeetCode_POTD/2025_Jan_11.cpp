// 1400. Construct K Palindrome Strings
// LeetCode : https://leetcode.com/problems/construct-k-palindrome-strings/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> freq(26, 0);
        for(auto& ch : s) {
            freq[ch - 'a']++;
        }

        int cntOddFreq = 0;
        for(int& f : freq) {
            if(f&1) cntOddFreq++;
        }
        return (cntOddFreq <= k) && (s.length() >= k);
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