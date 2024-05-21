// 994. Rotting Oranges
// LeetCode : https://leetcode.com/problems/rotting-oranges

/*
TC : O(mn) + O(4 * mn) = O(mn)
SC : O(mn)
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    vector<pair<int,int>> del = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    int bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid, int& cntFresh) {
        int time = 0;
        while(cntFresh && !q.empty()) {
            int qSize = q.size();
            while(qSize--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(auto [delRow, delCol] : del) {
                    int newRow = row + delRow;
                    int newCol = col + delCol;
                    if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == 1) {
                        cntFresh--;
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                    }
                }
            }
            time++;
        }
        return time;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int cntFresh = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1) {
                    cntFresh++;
                }
            }
        }

        int ans = bfs(q, grid, cntFresh);

        return cntFresh ? -1 : ans;
    }
};


int main() {
    
    return 0;
}