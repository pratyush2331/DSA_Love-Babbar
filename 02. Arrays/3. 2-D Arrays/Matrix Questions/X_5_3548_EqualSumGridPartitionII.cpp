// 3548. Equal Sum Grid Partition II
// LeetCode : https://leetcode.com/problems/equal-sum-grid-partition-ii/

/*
TC : O(m.n)
SC : O(m.n)
*/
using ll = long long;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        unordered_map<ll, ll> topMap, downMap, leftMap, rightMap; // SC: O(m.n)
        // get total sum
        ll totalSum = 0;
        for(auto& row : grid) { // TC: O(m.n)
            for(auto& ele : row) {
                totalSum += ele;
                topMap[ele]++;
                leftMap[ele]++;
            }
        }

        // checking possibility of horizontal partition
        ll topSum = totalSum, downSum = 0;
        for(int i = m-1; i >= 0; i--) { // TC: O(m.n)
            ll currRowSum = 0;
            for(int j = 0; j < n; j++) {
                currRowSum += grid[i][j];
                topMap[grid[i][j]]--;
                downMap[grid[i][j]]++;
            }
            downSum += currRowSum;
            topSum -= currRowSum;
            ll absDiff = abs(topSum - downSum);
            if(topSum == downSum) return 1;
            if(topSum > downSum) { // check for absDiff in topMap
                int rows = i;
                if(rows == 1) { // edge case: top partition size is of 1
                    if(absDiff == grid[0][0] || absDiff == grid[0][n-1])
                        return true;
                }
                else {
                    if(n == 1) { // edge case: 1-D column matrix
                        if(absDiff == grid[0][0] || absDiff == grid[i-1][0])
                            return true;
                    }
                    else if(topMap[absDiff])
                        return true;
                }
            }
            else { // check for absDiff in downMap
                int rows = m - i;
                if(rows == 1) { // edge case: down partition size is of 1
                    if(absDiff == grid[m-1][0] || absDiff == grid[m-1][n-1])
                        return true;
                }
                else {
                    if(n == 1) { // edge case: 1-D column matrix
                        if(absDiff == grid[i][0] || absDiff == grid[m-1][0])
                            return true;
                    }
                    else if(downMap[absDiff])
                        return true;
                }
            }
        }

        // checking possibility of vertical partition
        ll leftSum = totalSum, rightSum = 0;
        for(int j = n-1; j >= 0; j--) { // TC: O(m.n)
            ll currColSum = 0;
            for(int i = 0; i < m; i++) {
                currColSum += grid[i][j];
                leftMap[grid[i][j]]--;
                rightMap[grid[i][j]]++;
            }
            rightSum += currColSum;
            leftSum -= currColSum;
            ll absDiff = abs(leftSum - rightSum);
            if(leftSum == rightSum) return 1;
            if(leftSum > rightSum) { // check for absDiff in leftMap
                int cols = j;
                if(cols == 1) { // edge case: left partition size is of 1
                    if(absDiff == grid[0][0] || absDiff == grid[m-1][0])
                        return true;
                }
                else {
                    if(m == 1) { // edge case: 1-D row matrix
                        if(absDiff == grid[0][0] || absDiff == grid[0][j-1])
                            return true;
                    }
                    else if(leftMap[absDiff])
                        return true;
                }
            }
            else { // check for absDiff in rightMap
                int cols = n - j;
                if(cols == 1) { // edge case: right partition size is of 1
                    if(absDiff == grid[0][n-1] || absDiff == grid[m-1][n-1])
                        return true;
                }
                else {
                    if(m == 1) { // edge case: 1-D row matrix
                        if(absDiff == grid[0][j] || absDiff == grid[0][n-1])
                            return true;
                    }
                    else if(rightMap[absDiff])
                        return true;
                }
            }
        }

        // not possible
        return 0;
    }
};