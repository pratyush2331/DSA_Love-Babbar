// 647. Palindromic Substrings
// LeetCode : https://leetcode.com/problems/palindromic-substrings/

#include<bits/stdc++.h>

using namespace std;

// /*
// Method-2 : DP
// TC: O(n^2), SC: O(n^2)
class Solution {
public:
int countSubstrings(string str) {
    int cnt = 0;

    int n = str.length();
    vector<vector<bool>> dp(n, vector<bool>(n, 0));

    // initializing for 1 length
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
        cnt++;
    }

    // initializing for 2 length
    for(int i = 0; i < n-1; i++) {
        if(str[i] == str[i+1]) {
            dp[i][i+1] = 1;
            cnt++;
        }
    }

    // Now, do DP tabulation
    for(int len = 3; len <= n; len++) {
        for(int i = 0; i < n-len+1; i++) {
            if(dp[i+1][i+len-2] && str[i] == str[i+len-1]) {
                dp[i][i+len-1] = 1;
                cnt++;
            }
        }
    }
    
    return cnt;
}
};
// */


// /*
// Method-1 : Optimal Approach - iterating to every index of string and moving left and right pointer to check palindrome
// TC: O(n^2), SC: O(1)
class Solution {
public:
int countSubstrings(string str) {
    int cnt = 0;

    int n = str.length();
    for(int mid = 0; mid < n; mid++) {
        // for odd letters
        int l = mid, r = mid;
        while(l >= 0 && r < n && str[l] == str[r]) {
            cnt++;
            l--; r++;
        }

        // for even letters
        l = mid, r = mid+1;
        while(l >= 0 && r < n && str[l] == str[r]) {
            cnt++;
            l--; r++;
        }
    }

    return cnt;
}
};
// */


// Method-0 : Brute Force -checking all sub arrays
// TC: O(n^3), SC: O(1)
/*
class Solution {
public:
bool isPalindrome(string str) {
    int s = 0, e = str.length()-1;
    while(s < e) {
        if(str[s++] != str[e--]) return 0;
    }
    return 1;
}

int countSubstrings(string str) {
    int cnt = 0;

    int n = str.length();
    for(int s = 0; s < n; s++) {
        string tempStr = "";
        for(int e = s; e < n; e++) {
            tempStr += str[e];
            // cout << tempStr << " ";
            if(isPalindrome(tempStr)) cnt++;
        }
        cout << endl;
    }
    return cnt;
}
};
*/


int main() {
    

    return 0;
}