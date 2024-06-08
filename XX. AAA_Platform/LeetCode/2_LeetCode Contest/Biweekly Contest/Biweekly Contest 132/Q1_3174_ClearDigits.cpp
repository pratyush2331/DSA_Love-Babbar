// 3174. Clear Digits
// LeetCode : https://leetcode.com/problems/clear-digits

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string clearDigits(string s) {
        for(int j = s.length()-1; j >= 0; j--) {
            if(s[j] >= '0' && s[j] <= '9') {
                for(int i = j-1; i >= 0; i--) {
                    if(s[i] >= 'a' && s[i] <= 'z') {
                        s.erase(j,1);
                        s.erase(i,1);
                        i = -1;
                        break;
                    }
                }
            }
        }
        return s;
    }
};


int main() {
    
    return 0;
}