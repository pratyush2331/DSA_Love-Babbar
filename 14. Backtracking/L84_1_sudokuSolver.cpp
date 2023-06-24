// 37. Sudoku Solver
// LeetCode : https://leetcode.com/problems/sudoku-solver/

/*
TC : O(9^m);    m --> no. of empty cells
SC : O(1);      as maximum recursive call stacks = 9*9 = 81
*/

#include<iostream>
using namespace std;

class Solution {
    bool isSafe(int row, int col, vector<vector<char>>& board, int n, char val) {
        for(int i = 0; i < n; i++) {
            // row check
            if(board[row][i] == val)
                return false;
            // col check
            if(board[i][col] == val)
                return false;
            // 3*3 matrix check
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        int n = board.size(); // n = 9

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                // cell is empty
                if(board[row][col] == '.') {
                    for(char val = '1'; val <= '9'; val++) {
                        if(isSafe(row, col, board, n, val)) {
                            board[row][col] = val;
                            // recursive call
                            if(solve(board)) {
                                return true;
                            }
                            // backtrack
                            else {
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

int main() {
    
    return 0;
}