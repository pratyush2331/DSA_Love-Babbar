// 3163. String Compression III
// LeetCode : https://leetcode.com/problems/string-compression-iii/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string compressedString(string word) {
        string ans;
        char prevCh = word[0];
        int cnt = 1;
        for(int i = 1; i < word.length(); i++) {
            if(cnt == 9 || word[i] != prevCh) {
                ans += to_string(cnt) + prevCh;
                cnt = 0;
                prevCh = word[i];
            }
            cnt++;
        }
        ans += to_string(cnt) + prevCh;
        return ans;
    }
};


int main() {
    
    return 0;
}