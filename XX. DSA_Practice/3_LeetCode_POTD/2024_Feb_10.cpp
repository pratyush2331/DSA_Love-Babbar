// 647. Palindromic Substrings
// LeetCode : https://leetcode.com/problems/palindromic-substrings/

#include<bits/stdc++.h>

using namespace std;


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