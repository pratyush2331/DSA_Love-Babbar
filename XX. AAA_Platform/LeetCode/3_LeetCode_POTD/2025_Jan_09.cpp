// 2185. Counting Words With a Given Prefix
// LeetCode : https://leetcode.com/problems/counting-words-with-a-given-prefix/

#include<bits/stdc++.h>
using namespace std;


// Method - 1
/*
TC : O(n * m)
SC : O(1)
*/
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(auto& word : words) if(word.find(pref) == 0) cnt++;
        return cnt;
    }
};


// Method - 0
/*
TC : O(n * m)
SC : O(1)
*/
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(auto& word : words) {
            if(word.size() < pref.size()) continue;
            int i;
            for(i = 0; i < pref.size() && word[i] == pref[i]; i++);
            if(i == pref.size()) cnt++;
        }
        return cnt;
    }
};


int main() {
    
    return 0;
}