// 2116. Check if a Parentheses String Can Be Valid
// LeetCode : https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/

#include<bits/stdc++.h>
using namespace std;


// method-0 : using stack


// method-1 : Optimal Solution
/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(n&1) return 0; // odd length

        int open_p = 0, any_p = 0;
        for(int i = 0; i < n; i++) { // check left --> right
            if(locked[i] == '1') {
                (s[i] == '(') ? open_p++ : open_p--;
            }
            else {
                any_p++;
            }
            if(open_p + any_p < 0) return 0;
        }

        open_p = 0, any_p = 0;
        for(int i = n-1; i >= 0; i--) { //  check right --> left
            if(locked[i] == '1') {
                (s[i] == ')') ? open_p++ : open_p--;
            }
            else {
                any_p++;
            }
            if(open_p + any_p < 0) return 0;
        }

        return 1;
    }
};


int main() {
    
    return 0;
}