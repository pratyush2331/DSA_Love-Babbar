// 1091. Shortest Path in Binary Matrix
// LeetCode : https://leetcode.com/problems/shortest-path-in-binary-matrix/
// GFG : https://practice.geeksforgeeks.org/problems/shortest-path-in-binary-matrix/1

#include<bits/stdc++.h>
using namespace std;


class Solution {
    vector<pair<int, int>> del = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {1,1}, {-1, -1}, {1, -1}, {-1, 1}};

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis = grid;
        queue<pair<int, int>> q;
        if(vis[0][0] == 0 && vis[n-1][n-1] == 0) {
            q.push({0, 0});
            vis[0][0] = 1;
        }
        int lvl = 1;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if(x == n-1 && y == n-1) return lvl;

                for(int i = 0; i < 8; i++) {
                    int new_x = x + del[i].first;
                    int new_y = y + del[i].second;
                    if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && vis[new_x][new_y] == 0) {
                        q.push({new_x, new_y});
                        vis[new_x][new_y] = 1;
                    }
                }
            }
            lvl++;
        }

        return -1;
    }
};


int main() {
    
    return 0;
}