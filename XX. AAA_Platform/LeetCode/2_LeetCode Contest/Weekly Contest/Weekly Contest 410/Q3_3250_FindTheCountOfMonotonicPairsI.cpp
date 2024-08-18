// 3250. Find the Count of Monotonic Pairs I
// LeetCode : https://leetcode.com/problems/find-the-count-of-monotonic-pairs-i/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    static const int MOD = 1'000'000'007;
    vector<vector<vector<int>>> dp; // 3D dp

    int findPairs(vector<int>& nums, int idx, int prev1, int prev2) {
        if (idx >= nums.size()) return 1;
        if (dp[idx][prev1][prev2] != -1) return dp[idx][prev1][prev2];

        int ans = 0;
        for (int i = 0; i <= nums[idx]; i++) {
            int arr1Val = i;
            int arr2Val = nums[idx] - i;
            if (arr1Val >= prev1 && arr2Val <= prev2) {
                ans = (ans + findPairs(nums, idx + 1, arr1Val, arr2Val)) % MOD;
            }
        }

        return dp[idx][prev1][prev2] = ans;
    }

public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<vector<int>>(51, vector<int>(51, -1)));
        return findPairs(nums, 0, 0, 50);
    }
};


int main() {
    
    return 0;
}