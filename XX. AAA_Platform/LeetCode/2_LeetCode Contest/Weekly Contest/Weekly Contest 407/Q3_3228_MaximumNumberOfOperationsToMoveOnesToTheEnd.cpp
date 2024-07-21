// 3228. Maximum Number of Operations to Move Ones to the End
// LeetCode : https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        
        int ans = 0;
        int ones = 0, i = 0;
        while(i < n) {
            if(s[i] == '1') {
                ones++;
                i++;
            }
            if(s[i] == '0') {
                ans += ones;
                while(s[i] == '0') {
                    i++;
                }
            }
        }
        
        return ans;
    }
};


int main() {
    
    return 0;
}