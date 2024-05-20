// 200. Number of Islands
// LeetCode : https://leetcode.com/problems/number-of-islands

/*
TC : O(mn + mn)
SC : O(mn)
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    vector<pair<int, int>> del = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; // {delRow, delCol}

    // using DFS
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        vis[i][j] = 1;
        for(auto [delRow, delCol] : del) { // nbr
            int newRow = i + delRow;
            int newCol = j + delCol;
            if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() 
            && grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {
                dfs(newRow, newCol, grid, vis);
            }
        }
    }

    // using BFS
    /*
    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        queue<pair<int, int>> q;
        vis[i][j] = 1;
        q.push({i, j});
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(auto [delRow, delCol] : del) { // nbr
                int newRow = row + delRow;
                int newCol = col + delCol;
                if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() 
                && grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
    */

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    cnt++;
                    // bfs(i, j, grid, vis);
                    dfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};


int main() {
    
    return 0;
}