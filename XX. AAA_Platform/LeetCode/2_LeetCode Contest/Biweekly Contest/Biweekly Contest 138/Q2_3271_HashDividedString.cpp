// 3271. Hash Divided String
// LeetCode : https://leetcode.com/problems/hash-divided-string/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string stringHash(string s, int k) {
        string result;

        int sum = 0;
        for(int i = 0; i < s.length(); i++) {
            sum += (s[i]-'a');
            if((i+1)%k == 0) {
                result += 'a' + (sum%26);
                sum = 0;
            }
        }

        return result;
    }
};


int main() {
        
    return 0;
}