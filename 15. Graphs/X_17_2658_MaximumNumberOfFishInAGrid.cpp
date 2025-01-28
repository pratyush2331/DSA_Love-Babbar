// 2658. Maximum Number of Fish in a Grid
// LeetCode : https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
using pii = pair<int, int>;

class Solution {
    int m, n;
    vector<pii> del = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int bfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        vis[i][j] = 1;
        queue<pii> q; // SC:O(m.n)
        q.push({i, j});
        int ans = grid[i][j];
        while(!q.empty()) {
            pii front = q.front();
            q.pop();
            for(pii& d : del) {
                int i_ = front.F + d.F;
                int j_ = front.S + d.S;
                if(i_ < 0 || i_ >= m || j_ < 0 || j_ >= n) continue;
                if(grid[i_][j_] && !vis[i_][j_]) {
                    ans += grid[i_][j_];
                    q.push({i_, j_});
                }
                vis[i_][j_] = 1;
            }
        }
        return ans;
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0)); // SC:O(m.n)
        int ans = 0;
        for(int i = 0; i < m; i++) { // overall TC:O(m.n), as each cell is visited once
            for(int j = 0; j < n; j++) {
                if(grid[i][j] && !vis[i][j]) ans = max(ans, bfs(i, j, grid, vis));
            }
        }
        return ans;
    }
};


int main() {
    
    return 0;
}