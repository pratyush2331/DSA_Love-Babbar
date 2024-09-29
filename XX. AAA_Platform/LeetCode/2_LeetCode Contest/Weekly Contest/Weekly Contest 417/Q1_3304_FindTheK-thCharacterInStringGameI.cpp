// 3304. Find the K-th Character in String Game I
// LeetCode : https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/

#include<bits/stdc++.h>
using namespace std;


// Brute-force
/*
TC : O(k)
SC : O(k)
*/
class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.length() <= k) {
            string temp = s;
            for(auto ch : temp) {
                if(ch == 'z') s += 'a';
                else s += ch+1;
            }
        }
        // cout << s;
        return s[k-1];
    }
};


int main() {
    
    return 0;
}