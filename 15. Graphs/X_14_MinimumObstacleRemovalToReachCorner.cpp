// 2290. Minimum Obstacle Removal to Reach Corner
// LeetCode : https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/

#include<bits/stdc++.h>
using namespace std;


/*
TC : O(m*n . log(m*n))
SC : O(m*n)
*/
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> cost(m, vector<int>(n, INT_MAX)); // SC:O(m*n)
        cost[0][0] = grid[0][0];

        // SC:O(m*n)
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq; // {cost, {i, j}}
        pq.push({cost[0][0], {0, 0}});

        vector<pair<int, int>> del = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        int row = 0, col = 0;
        while(!pq.empty()) { // TC:O(m*n . log(m*n))
            auto front = pq.top();
            pq.pop();

            int curr_cost = front.first;
            row = front.second.first;
            col = front.second.second;

            if(row == m-1 && col == n-1) return curr_cost;

            for(auto [delRow, delCol] : del) {
                int newRow = row + delRow;
                int newCol = col + delCol;

                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    int next_feasible_cost = curr_cost + grid[newRow][newCol];
                    if(next_feasible_cost < cost[newRow][newCol]) {
                        cost[newRow][newCol] = next_feasible_cost;
                        pq.push({cost[newRow][newCol], {newRow, newCol}});
                    }
                }
            }
        }

        return cost[m-1][n-1];
    }
};


int main() {
    
    return 0;
}