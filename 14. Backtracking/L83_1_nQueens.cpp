// 51. N Queens
// LeetCode : https://leetcode.com/problems/n-queens/

/**************************************************************QUESTION**************************************************************
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
*************************************************************************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

// OPTIMIZED SOLUTION - using Backtracking & Hashmap
/*
TC : O(n!)
SC : O(n*n) = O(n^2)
*/
// /*
class Solution {
    void solve(int col, vector<string> &board, int n, vector<int> &leftrow, vector<int> &lowerdiagonal, vector<int> &upperdiagonal, vector<vector<string>> &ans){ // TC: O(n*(n-1)*(n-2)*(n-3)...) = O(n!)
        // base case
        if(col == n){
            ans.push_back(board);
            return;
        }

        // solve 1 case and rest recurssion will take care
        for(int row=0; row<n; row++){
            if(leftrow[row] == 0 && lowerdiagonal[row+col] == 0 && upperdiagonal[n-1+col-row] == 0){ // isSafe func() --> TC: O(1)
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lowerdiagonal[row+col] = 1;
                upperdiagonal[n-1+col-row] = 1;
                solve(col+1, board, n, leftrow, lowerdiagonal, upperdiagonal, ans);
                // backtrack
                board[row][col] = '.';
                leftrow[row] = 0;
                lowerdiagonal[row+col] = 0;
                upperdiagonal[n-1+col-row] = 0;
            }
        }
    }

    public:
    vector<vector<string>> solveNQueens(int n) {
        // write your code here

        vector<string> board(n, string(n, '.')); // SC: O(n*n)
        vector<vector<string>> ans; // SC: O(n*n*n)
        
        vector<int> leftrow(n, 0); // SC: O(n)
        vector<int> lowerdiagonal(2*n-1, 0); // SC: O(n)
        vector<int> upperdiagonal(2*n-1, 0); // SC: O(n)
        
        solve(0, board, n, leftrow, lowerdiagonal, upperdiagonal, ans);
        
        return ans;
    }
};
// */



// Solution - using Backtracking
/*
TC : O(n!) * O(n)
SC : O(n*n) = O(n^2)
*/
/*
class Solution {
    bool isSafe(int row, int col, vector<string> &board, int n) { // TC: O(n)
        // check for same row
        int x = row;
        int y = col;
        while(y >= 0) {
            if(board[x][y] == 'Q')
                return false;
            y--;
        }

        // check for digonals

        // check for LU diagonal
        x = row;
        y = col;
        while(x >= 0 && y >= 0) {
            if(board[x][y] == 'Q')
                return false;
            x--;
            y--;
        }
        // check for LD diagonal
        x = row;
        y = col;
        while(x < n && y >= 0) {
            if(board[x][y] == 'Q')
                return false;
            x++;
            y--;
        }

        return true;
    }

    void solve(int col, vector<string> &board, int n, vector<vector<string>> &ans) { // TC: O(n*(n-1)*(n-2)*(n-3)...) * O(n) = O(n!) * O(n)
        // base case
        if(col == n) {
            ans.push_back(board);
            return;
        }

        // solve 1 case and rest recurssion will take care
        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, board, n)) { // isSafe func() --> TC: O(n)
                board[row][col] = 'Q';
                solve(col+1, board, n, ans);
                // backtrack
                board[row][col] = '.';
            }
        }
    }

    public:
    vector<vector<string>> solveNQueens(int n) {
        // write your code here

        vector<string> board(n, string(n, '.')); // SC: O(n*n)
        vector<vector<string>> ans; // SC: O(n*n*n)

        solve(0, board, n, ans);

        return ans;
    }
};
*/

int main() {
    
    return 0;
}