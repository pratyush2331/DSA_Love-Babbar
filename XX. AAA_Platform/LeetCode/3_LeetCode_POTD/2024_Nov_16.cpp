// 3254. Find the Power of K-Size Subarrays I
// LeetCode : https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1, -1);
        for (int i = 0; i < n-k+1; i++) {
            bool isValid = true;
            for (int j = i; j < i+k-1; j++) {
                if (nums[j] + 1 != nums[j + 1]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                ans[i] = nums[i + k - 1]; // Maximum is the last element of the subarray
            }
        }
        return ans;
    }
};


int main() {
    
    return 0;
}