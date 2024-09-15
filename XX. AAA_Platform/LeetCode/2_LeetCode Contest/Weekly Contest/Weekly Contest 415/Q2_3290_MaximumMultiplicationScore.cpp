// 3290. Maximum Multiplication Score
// LeetCode : https://leetcode.com/problems/maximum-multiplication-score/

#include<bits/stdc++.h>
using namespace std;


// using DP
/*
TC : O(m*n)
SC : O(m*n)
*/
#define ll long long
class Solution {
    vector<vector<ll>> dp;

    ll solve(int i1, int i2, vector<int>& a, vector<int>& b) {
        if(i1 == 4) return 0LL;
        if(i2 == b.size()) return -1e6;

        if(dp[i1][i2] != -1e6) return dp[i1][i2];

        // take
        ll take = 1LL * a[i1] * b[i2] + solve(i1+1, i2+1, a, b);

        // not take
        ll notTake = solve(i1, i2+1, a, b);

        return dp[i1][i2] = max(take, notTake);
    }

public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        dp.resize(4, vector<ll>(b.size(), -1e6));
        return solve(0, 0, a, b);
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