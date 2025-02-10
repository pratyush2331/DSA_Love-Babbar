// 3174. Clear Digits
// LeetCode : https://leetcode.com/problems/clear-digits/

#include<bits/stdc++.h>
using namespace std;


// method : simple backward traversal with count variable
/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        int cnt = 0; // count consecutive digits
        for(int i = s.length()-1; i >= 0; i--) { // TC:O(n)
            if(s[i] >= '0' && s[i] <= '9') {
                cnt++;
            }
            else if(s[i] >= 'a' && s[i] <= 'z' && cnt > 0) {
                cnt--;
            }
            else { // s[i] >= 'a' && s[i] <= 'z' && cnt == 0
                ans += s[i];
            }
        }
        reverse(ans.begin(), ans.end()); // TC:O(n)
        return ans;
    }
};


int main() {
    
    return 0;
}