// 542. 01 Matrix
// LeetCode : https://leetcode.com/problems/01-matrix

/*
TC : O(mn)
SC : O(mn)
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    vector<pair<int,int>> del = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    void BFS(queue<pair<int,int>>& q, vector<vector<int>>& mat, vector<vector<bool>>& vis) {
        int cnt = 0;
        while(!q.empty()) {
            int qsize = q.size();
            cnt++;
            while(qsize--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(auto [delRow, delCol] : del) {
                    int newRow = row + delRow;
                    int newCol = col + delCol;
                    if(newRow >= 0 && newRow < mat.size() && newCol >= 0 && newCol < mat[0].size() 
                    && mat[newRow][newCol] == 1 && !vis[newRow][newCol]) {
                        vis[newRow][newCol] = 1;
                        mat[newRow][newCol] = cnt;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist = mat; // we'll not change 'mat'
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
        
        BFS(q, dist, vis);

        return dist;
    }
};


int main() {
    
    return 0;
}