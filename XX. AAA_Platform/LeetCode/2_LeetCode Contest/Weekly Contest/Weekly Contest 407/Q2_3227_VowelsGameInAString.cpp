// 3227. Vowels Game in a String
// LeetCode : https://leetcode.com/problems/vowels-game-in-a-string/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool doesAliceWin(string s) {
        int vowelCnt = 0;
        for(auto ch : s) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return 1;
        }
        return 0;
    }
};


int main() {
    
    return 0;
}