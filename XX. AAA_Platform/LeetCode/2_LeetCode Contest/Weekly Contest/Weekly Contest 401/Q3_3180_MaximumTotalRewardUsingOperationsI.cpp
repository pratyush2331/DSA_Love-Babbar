// 3180. Maximum Total Reward Using Operations I
// LeetCode : https://leetcode.com/problems/maximum-total-reward-using-operations-i

#include<bits/stdc++.h>
using namespace std;


class Solution {
    vector<vector<int>> memo;

    int solve(int idx, vector<int>& rewardValues, int totalReward) {
        if (idx >= rewardValues.size()) return 0;

        if (memo[idx][totalReward] != -1) return memo[idx][totalReward];

        int notTake = solve(idx + 1, rewardValues, totalReward);

        int take = 0;
        if (rewardValues[idx] > totalReward) {
            take = rewardValues[idx] + solve(idx + 1, rewardValues, totalReward + rewardValues[idx]);
        }

        return memo[idx][totalReward] = max(take, notTake);
    }

public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());

        memo.assign(n, vector<int>(40000 + 1, -1));

        return solve(0, rewardValues, 0);
    }
};


int main() {
    
    return 0;
}