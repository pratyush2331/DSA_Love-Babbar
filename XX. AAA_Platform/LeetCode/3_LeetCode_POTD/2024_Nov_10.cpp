// 3097. Shortest Subarray With OR at Least K II
// LeetCode : https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/

#include<bits/stdc++.h>
using namespace std;


// using dynamic sliding window
/*
TC : O(n*32) = O(n)
SC : O(32) = O(1)
*/
class Solution {
    void addContribution(int val, vector<int>& bitArray, bool isAdd) {
        int i = 31;
        while(val) {
            if(val&1) bitArray[i] += (isAdd ? 1 : -1);
            val >>= 1;
            i--;
        }
    }

    bool isContributionMoreThanEqualToK(vector<int>& bitArray, int k) {
        int bitVal = 0;
        for(int i = 0; i < 32; i++) {
            if(bitArray[i]) bitVal |= 1<<(31-i);
        }
        return bitVal >= k;
    }

public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        int i = 0, j = 0;
        vector<int> bitArray(32, 0);
        while(j < n) {
            addContribution(nums[j], bitArray, true);
            while(isContributionMoreThanEqualToK(bitArray, k) && i <= j) {
                ans = min(ans, j-i+1);
                addContribution(nums[i], bitArray, false);
                i++;
            }
            j++;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};


int main() {
    
    return 0;
}