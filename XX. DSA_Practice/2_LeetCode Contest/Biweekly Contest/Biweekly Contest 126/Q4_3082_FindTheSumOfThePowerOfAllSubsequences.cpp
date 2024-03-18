// 3082. Find the Sum of the Power of All Subsequences
// LeetCOde : https://leetcode.com/problems/find-the-sum-of-the-power-of-all-subsequences

#include<bits/stdc++.h>

using namespace std;


// method-1 : 2d dp (optimized approach : eliminating cnt)
/*
TC : O(n * k * logn)
SC : O(n * k)
*/
#define ll long long

class Solution {
    const int MOD = 1e9+7;

    ll power(ll a, ll b) {
        int ans = 1;
        while(b) {
            if(b&1) ans = (ans * a) % MOD;
            a = (a * a) % MOD;
            b /= 2;
        }
        return ans;
    }

    int solve(int i, int sum, vector<int>& nums, int k, vector<vector<int>>& dp) {
        if(sum == k) return power(2ll, (ll)nums.size()-i);
        if (sum > k || i == nums.size()) return 0;

        if(dp[i][sum] != -1) return dp[i][sum];

        ll take = solve(i+1, sum + nums[i], nums, k, dp);
        ll notTake = 2 * solve(i+1, sum, nums, k, dp);

        return dp[i][sum] = (take + notTake) % MOD;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int sumOfPower(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size(), vector<int>(k+1, -1)); // {i, cnt, sum}

        return solve(0, 0, nums, k, dp);
    }
};



// method-0 : 3d dp
/*
TC : O(n^2 * k * logn)
SC : O(n^2 * k)
*/
/*
#define ll long long

class Solution {
    const int MOD = 1e9+7;

    ll power(ll a, ll b) {
        int ans = 1;
        while(b) {
            if(b&1) ans = (ans * a) % MOD;
            a = (a * a) % MOD;
            b /= 2;
        }
        return ans;
    }

    int solve(int i, int cnt, int sum, vector<int>& nums, int k, vector<vector<vector<int>>>& dp) {
        if(sum == k) return power(2ll, (ll)nums.size()-cnt);
        if (sum > k || i == nums.size()) return 0;

        if(dp[i][cnt][sum] != -1) return dp[i][cnt][sum];

        ll take = solve(i+1, cnt+1, sum + nums[i], nums, k, dp);
        ll notTake = solve(i+1, cnt, sum, nums, k, dp);

        return dp[i][cnt][sum] = (take + notTake) % MOD;
    }

public:
    int sumOfPower(vector<int>& nums, int k) {
        vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(nums.size(), vector<int>(k+1, -1))); // {i, cnt, sum}

        return solve(0, 0, 0, nums, k, dp);
    }
};
*/


int main() {
    

    return 0;
}