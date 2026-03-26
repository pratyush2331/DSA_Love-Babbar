// 3546. Equal Sum Grid Partition I
// LeetCode : https://leetcode.com/problems/equal-sum-grid-partition-i/

using ll = long long;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // get total sum
        ll totalSum = 0;
        for(auto& row : grid) {
            for(auto& ele : row) {
                totalSum += ele;
            }
        }

        // not possible: oddSum can't be devided into two integer numbers
        if(totalSum&1) return 0;

        // checking possibility of horizontal partition
        ll topSum = totalSum, downSum = 0;
        for(int i = m-1; i >= 0; i--) {
            ll currRowSum = 0;
            for(int j = 0; j < n; j++) {
                currRowSum += grid[i][j];
            }
            topSum -= currRowSum;
            downSum += currRowSum;
            if(topSum == downSum) return 1;
        }

        // checking possibility of vertical partition
        ll leftSum = totalSum, rightSum = 0;
        for(int j = n-1; j >= 0; j--) {
            ll currColSum = 0;
            for(int i = 0; i < m; i++) {
                currColSum += grid[i][j];
            }
            leftSum -= currColSum;
            rightSum += currColSum;
            if(leftSum == rightSum) return 1;
        }

        // not possible
        return 0;
    }
};