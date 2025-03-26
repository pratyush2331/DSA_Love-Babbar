// 2033. Minimum Operations to Make a Uni-Value Grid
// LeetCode : https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // storing elements from matrix in an array and sorting it
        vector<int> nums;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] % x != grid[0][0] % x) return -1;
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(), nums.end());

        // adding distance from the middle
        int target = nums[nums.size()/2], cnt = 0;
        for(int& ele : nums) {
            cnt += abs(target - ele) / x;
        }
        return cnt;
    }
};


int main() {
    
    return 0;
}