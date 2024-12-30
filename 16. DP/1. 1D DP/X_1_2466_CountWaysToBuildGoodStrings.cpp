// 2466. Count Ways To Build Good Strings
// LeetCode : https://leetcode.com/problems/count-ways-to-build-good-strings/

#include<bits/stdc++.h>
using namespace std;


/*
TC : O(high)
SC : O(high)
*/
class Solution {
    const int MOD = 1e9+7;
    int solve(int low, int high, int zero, int one, int size, vector<int>& dp) {
        if(size > high) return 0;

        if(dp[size] != -1) return dp[size];

        int cnt = 0;
        if(size >= low && size <= high) cnt += 1;
        // take zero
        cnt += solve(low, high, zero, one, size + zero, dp);

        // take one
        cnt += solve(low, high, zero, one, size + one, dp);
        return dp[size] = cnt % MOD;
    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, -1);
        return solve(low, high, zero, one, 0, dp);
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}