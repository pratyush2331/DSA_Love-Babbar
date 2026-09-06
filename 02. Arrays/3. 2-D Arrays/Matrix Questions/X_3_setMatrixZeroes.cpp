// 73. Set Matrix Zeroes
// LeetCode : https://leetcode.com/problems/set-matrix-zeroes/

#include<iostream>
using namespace std;


// OPTIMAL SOLUTION
/*
TC : O(m.n)
SC : O(1)
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int col0 = 1, row0 = 1;
        for(int i = 0; i < m; i++) { // checking 0 in 0th-column; TC:O(m)
            if(!matrix[i][0]) col0 = 0;
        }
        for(int j = 0; j < n; j++) { // checking 0 in 0th-row; TC:O(n)
            if(!matrix[0][j]) row0 = 0;
        }

        for(int i = 1; i < m; i++) { // checking any cell is 0 except from 0th-row,col; TC:O(m.n)
            for(int j = 1; j < n; j++) {
                if(!matrix[i][j]) { // mark it's row & col as 0 in 0th-row,col
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < m; i++) { // fill all remaining corresponding cols & rows with 0 if 0th-row,col is marked with 0; TC:O(m.n)
            for(int j = 1; j < n; j++) {
                if(!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(!col0) { // fill 0th col with 0; TC:O(m)
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }

        if(!row0) { // fill 0th row with 0; TC:O(n)
            for(int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};




// BRUTE FORCE
/*
TC : O(n*m)
SC : O(n + m)
*/
/*
class Solution {
    public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row(n, 0); // SC: O(n)
        vector<int> col(m, 0); // SC: O(m)

        // mark the row and col corresponding to element 0
        for(int i = 0; i < n; i++) { // TC: O(n*m)
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // set all row and col as 0
        for(int i = 0; i < n; i++) { // TC: O(n*m)
            for(int j = 0; j < m; j++) {
                if(row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
*/


int main() {
    
    return 0;
}