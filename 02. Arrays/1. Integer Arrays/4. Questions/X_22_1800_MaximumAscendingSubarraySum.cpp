// 1800. Maximum Ascending Subarray Sum
// LeetCode : https://leetcode.com/problems/maximum-ascending-subarray-sum/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0], sum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i-1] < nums[i]) sum += nums[i];
            else {
                ans = max(ans, sum);
                sum = nums[i];
            }
        }
        return max(ans, sum);
    }
};


int main() {
    
    return 0;
}