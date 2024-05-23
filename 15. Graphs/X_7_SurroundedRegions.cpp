// 130. Surrounded Regions
// LeetCode : https://leetcode.com/problems/surrounded-regions

/*
TC : O(2m) + O(2n) + O(mn) = O(mn)
SC : O(2mn) = O(mn)
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    vector<pair<int,int>> del = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    void DFS(int i, int j, vector<vector<char>>& board, vector<vector<char>>& vis) {
        vis[i][j] = 'O';
        for(auto [delRow, delCol] : del) {
            int newRow = i + delRow;
            int newCol = j + delCol;
            if(newRow >= 0 && newRow < vis.size() && newCol >=0 && newCol < vis[0].size() && board[newRow][newCol] == 'O' && vis[newRow][newCol] != 'O') {
                DFS(newRow, newCol, board, vis);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<char>> vis(m, vector<char>(n, 'X'));
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O' && vis[0][j] != 'O') DFS(0, j, board, vis);
            if(board[m-1][j] == 'O' && vis[m-1][j] != 'O') DFS(m-1, j, board, vis);
        }
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O' && vis[i][0] != 'O') DFS(i, 0, board, vis);
            if(board[i][n-1] == 'O' && vis[i][n-1] != 'O') DFS(i, n-1, board, vis);
        }
        board = vis;
    }
};


int main() {
    
    return 0;
}