// 1422. Maximum Score After Splitting a String
// LeetCode : https://leetcode.com/problems/maximum-score-after-splitting-a-string/

#include<bits/stdc++.h>
using namespace std;


// method-2 : optimal solution
/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    int maxScore(string s) {
        int cnt0 = 0, cnt1 = 0, ans = 0;
        for(char ch : s) cnt1 += (ch == '1'); // TC:O(n)
        for(int i = 0; i < s.length()-1; i++) { // TC:O(n)
            cnt0 += (s[i] == '0');
            cnt1 -= (s[i] == '1');

            ans = max(ans, cnt0 + cnt1);
        }
        return ans;
    }
};


// method-1 : better solution
/*
TC : O(n)
SC : O(n)
*/
class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int> zeroPrefix(n, 0), oneSuffix(n, 0); // SC:O(2n)
        zeroPrefix[0] = (s[0] == '0');
        for(int i = 1; i < n; i++) zeroPrefix[i] += zeroPrefix[i-1] + (s[i] == '0'); // TC:O(n)
        oneSuffix[n-1] = (s[n-1] == '1');
        for(int i = n-2; i >= 0; i--) oneSuffix[i] += oneSuffix[i+1] + (s[i] == '1'); // TC:O(n)

        int ans = 0;
        for(int i = 0; i < n-1; i++) { // TC:O(n)
            ans = max(ans, zeroPrefix[i] + oneSuffix[i+1]);
        }
        return ans;
    }
};


// method-0 : Brute force
/*
TC : O(n^2)
SC : O(1)
*/
class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        for(int mid = 0; mid < s.length()-1; mid++) {
            int score = 0;
            for(int i = 0; i <= mid; i++) score += (s[i] == '0');
            for(int i = mid+1; i < s.length(); i++) score += (s[i] == '1');
            ans = max(ans, score);
        }
        return ans;
    }
};


int main() {
    
    return 0;
}