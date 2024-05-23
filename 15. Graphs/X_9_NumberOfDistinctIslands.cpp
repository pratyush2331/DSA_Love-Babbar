// Number of Distinct Islands
// GFG : https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

/*
TC : O(mn)
SC : O(mn)
*/

#include<bits/stdc++.h>
using namespace std;


// using DFS
class Solution {
    vector<pair<int,int>> del = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    void DFS(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, vector<pair<int,int>>& v, int row0, int col0) {
        vis[i][j] = 1;
        v.push_back({i-row0, j-col0});
        for(auto d : del) {
            int newRow = i + d.first;
            int newCol = j + d.second;
            if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == 1 && !vis[newRow][newCol]) {
                DFS(newRow, newCol, grid, vis, v, row0, col0);
            }
        }
    }
    
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        set<vector<pair<int,int>>> s; // SC:O(mn)
        for(int i = 0; i < m; i++) { // TC:O(mn) * O(log(mn)) + 4 * O(mn)
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    vector<pair<int,int>> v;
                    DFS(i, j, grid, vis, v, i, j);
                    s.insert(v);
                }
            }
        }
        for(auto ele : s) {
            for(auto data : ele) cout << "{" << data.first << " " << data.second << "}, ";
            cout << "\n";
        }
        return s.size();
    }
};

// --------------------------------------------------------------------------------------------------------------------------

// using BFS
class Solution {
    vector<pair<int,int>> del = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    void BFS(int row0, int col0, vector<vector<int>>& grid, vector<vector<bool>>& vis, vector<pair<int,int>>& v) {
        queue<pair<int,int>> q; // SC:O(mn)
        q.push({row0, col0});
        vis[row0][col0] = 1;
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            v.push_back({row-row0, col-col0});
            
            for(auto d : del) {
                int newRow = row + d.first;
                int newCol = col + d.second;
                if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == 1 && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
    
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        set<vector<pair<int,int>>> s; // SC:O(mn)
        for(int i = 0; i < m; i++) { // TC:O(mn) * O(log(mn)) + 4 * O(mn)
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    vector<pair<int,int>> v;
                    BFS(i, j, grid, vis, v);
                    s.insert(v);
                }
            }
        }
        
        return s.size();
    }
};


int main() {
    
    return 0;
}