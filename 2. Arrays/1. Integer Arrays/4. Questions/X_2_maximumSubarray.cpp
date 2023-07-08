// 53. Maximum Subarray [OR] Kadane's Algorithm
// LeetCode : https://leetcode.com/problems/maximum-subarray/

#include<iostream>
using namespace std;

// Kadane's Algorithm - TC : O(n), SC : O(1)
class Solution {
    public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans = max(ans, sum);
            if(sum < 0) sum = 0;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}