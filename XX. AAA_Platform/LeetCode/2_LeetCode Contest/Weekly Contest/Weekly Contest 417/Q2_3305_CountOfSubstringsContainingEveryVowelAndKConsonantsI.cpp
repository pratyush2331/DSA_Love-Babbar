// 3305. Count of Substrings Containing Every Vowel and K Consonants I
// LeetCode : https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-i/

#include<bits/stdc++.h>
using namespace std;


// Brute-force
/*
TC : O(n^2)
SC : O(n)
*/
class Solution {
    bool isVowel(char ch) { return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'); }

public:
    int countOfSubstrings(string word, int k) {
        int cnt = 0;

        // findind all possible substrings
        for(int i = 0; i < word.length(); i++) {
            int cnt_cons = 0;
            unordered_map<char, int> mp;
            for(int j = i; j < word.length(); j++) {
                if(isVowel(word[j])) mp[word[j]]++;
                else cnt_cons++;
                if(cnt_cons == k+1) break; // move to next starting index
                if(mp.size() == 5 && cnt_cons == k) cnt++;
            }
        }
        return cnt;
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