// 3176. Find the Maximum Length of a Good Subsequence I
// LeetCode : https://leetcode.com/problems/find-the-maximum-length-of-a-good-subsequence-i/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    int n;
    vector<vector<int>> dp;

    int solve(int idx, int k, int prevIdx, vector<int>& nums) {
        if(idx == n) {return 0;}
        if(dp[prevIdx+1][k] != -1) {return dp[prevIdx+1][k];}

        // take
        int take = 0;
        if(prevIdx == -1 || nums[prevIdx] == nums[idx]) {
            take = 1 + solve(idx+1, k, idx, nums);
        }
        else if(prevIdx != -1 && nums[prevIdx] != nums[idx] && k > 0) {
            take = 1 + solve(idx+1, k-1, idx, nums);
        }

        // not-take
        int notTake = solve(idx+1, k, prevIdx, nums);

        return dp[prevIdx+1][k] = max(take, notTake);
    }

public:
    int maximumLength(vector<int>& nums, int k) {
        n = nums.size();
        dp.resize(n+1, vector<int>(k+1, -1));
        return solve(0, k, -1, nums);
    }
};


int main() {

    return 0;
}