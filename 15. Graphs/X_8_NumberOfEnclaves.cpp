// 1020. Number of Enclaves
// LeetCode : https://leetcode.com/problems/number-of-enclaves

/*
TC : O(mn)
SC : O(mn)
*/

#include<bits/stdc++.h>
using namespace std;


// using DFS
class Solution {
    vector<pair<int,int>> del = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    void DFS(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, int& boundaryOnes) {
        vis[i][j] = 1;
        for(auto [delRow, delCol] : del) {
            int newRow = i + delRow;
            int newCol = j + delCol;
            if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == 1 && !vis[newRow][newCol]) {
                boundaryOnes++;
                DFS(newRow, newCol, grid, vis, boundaryOnes);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0)); // SC:O(mn)
        int totalOnes = 0, boundaryOnes = 0;
        for(int i = 0; i < m; i++) { // TC:O(mn), SC:O(mn) including DFS() call
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) totalOnes++;
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && grid[i][j] == 1 && !vis[i][j]) {
                    boundaryOnes++;
                    DFS(i, j, grid, vis, boundaryOnes);
                }
            }
        }
        return totalOnes - boundaryOnes;
    }
};

// ----------------------------------------------------------------------------------------------------------------------------

// using BFS
class Solution {
    vector<pair<int,int>> del = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; // SC:O(1)

    void BFS(queue<pair<int,int>>& q, vector<vector<int>>& grid, vector<vector<bool>>& vis, int& boundaryOnes) {
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(auto [delRow, delCol] : del) {
                int newRow = row + delRow;
                int newCol = col + delCol;
                if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == 1 && !vis[newRow][newCol]) {
                    boundaryOnes++;
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0)); // SC:O(mn)
        queue<pair<int,int>> q; // SC:O(mn)
        int totalOnes = 0, boundaryOnes = 0;
        for(int i = 0; i < m; i++) { // TC:O(mn)
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) totalOnes++;
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && grid[i][j] == 1) {
                    boundaryOnes++;
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }

        BFS(q, grid, vis, boundaryOnes); // TC:(mn)

        return totalOnes - boundaryOnes;
    }
};


int main() {
    
    return 0;
}