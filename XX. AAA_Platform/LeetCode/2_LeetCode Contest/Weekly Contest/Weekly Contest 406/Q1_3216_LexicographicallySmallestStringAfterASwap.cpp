// 3216. Lexicographically Smallest String After a Swap
// LeetCode : https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string getSmallestString(string s) {
        string ans = s;
        for(int i = 0; i < s.length(); i++) {
            if((i+1) < s.length() && (s[i]&1) == (s[i+1]&1) && s[i+1] < s[i]) {
                string temp = "";
                temp = s.substr(0, i);
                temp += s[i+1];
                temp += s[i];
                if((i+2) <= s.length()-1) temp += s.substr(i+2, s.length()-1);
                // cout << temp << " ";
                ans = min(ans, temp);
            }
        }
        return ans;
    }
};


int main() {
    
    return 0;
}