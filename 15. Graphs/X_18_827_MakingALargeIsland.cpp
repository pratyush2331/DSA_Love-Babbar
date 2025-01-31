// 827. Making A Large Island
// LeetCode : https://leetcode.com/problems/making-a-large-island/

/*
Approach
Stored the size of every island, and also map it some group using bfs/dfs, also stored indices of zeros. 
In the 2nd iteration, went through the zero_indices and merge it's diff. neighbour islands, and also 
tracked the max island_size, and return in last.

TC : O(m.n)
SC : O(m.n)
*/

#include<bits/stdc++.h>
using namespace std;


#define F first
#define S second

using ll = long long;
using pii = pair<int, int>;

class Solution {
    int m, n;
    vector<pii> del = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int grp, int& size) {
        vis[i][j] = grp;
        size++;
        for (pii& d : del) {
            int i_ = i + d.F;
            int j_ = j + d.S;
            if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] == 1 && vis[i_][j_] == -1) {
                dfs(i_, j_, grid, vis, grp, size);
            }
        }
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, -1));
        int grp = 0;
        vector<int> mp = {0};
        vector<pii> zeros;
        int maxSize = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] == -1) {
                    int size = 0;
                    grp++;
                    dfs(i, j, grid, vis, grp, size);
                    mp.push_back(size);
                    maxSize = max(maxSize, size);
                }
                else if (grid[i][j] == 0) {
                    zeros.push_back({i, j});
                }
            }
        }

        if (zeros.empty()) return maxSize;

        for (pii& zero : zeros) {
            int i = zero.F, j = zero.S;
            unordered_set<int> nbrGrps;
            int newSize = 1;

            for (pii& d : del) {
                int i_ = i + d.F;
                int j_ = j + d.S;
                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && vis[i_][j_] > 0) {
                    nbrGrps.insert(vis[i_][j_]);
                }
            }

            for (int group : nbrGrps) {
                newSize += mp[group];
            }

            maxSize = max(maxSize, newSize);
        }

        return maxSize;
    }
};


int main() {
    
    return 0;
}