// 2161. Partition Array According to Given Pivot
// LeetCode : https://leetcode.com/problems/partition-array-according-to-given-pivot/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int l = 0, m = 0, r = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] < pivot) m++;
                else if(nums[i] == pivot) r++;
            }
            r += m;
            vector<int> ans(nums.size());
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] < pivot) ans[l++] = nums[i];
                else if(nums[i] == pivot) ans[m++] = nums[i];
                else ans[r++] = nums[i];
            }
            return ans;
        }
    };


int main() {
    
    return 0;
}