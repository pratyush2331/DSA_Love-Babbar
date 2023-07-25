// 1218. Longest Arithmetic Subsequence of Given Difference
// LeetCode : https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

// Topics : LIS, DP with Hashing

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        
        unordered_map<int, int> dp;

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int temp = arr[i] - difference; // since we are searching in left side of ith index, that's why we are subtracting 'difference' from 'arr[i]'
            int tempAns = 0;

            // check answer exists already for temp or not
            if(dp.count(temp))
                tempAns = dp[temp];
            
            // current answer update
            dp[arr[i]] = 1 + tempAns;
            
            // ans update
            ans = max(ans, dp[arr[i]]);
        }

        return ans;
    }
};


int main() {
    
    return 0;
}