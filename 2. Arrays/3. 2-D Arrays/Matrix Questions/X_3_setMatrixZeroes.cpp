// 73. Set Matrix Zeroes
// LeetCode : https://leetcode.com/problems/set-matrix-zeroes/

#include<iostream>
using namespace std;


// OPTIMAL SOLUTION
/*
TC : O(n*m)
SC : O(1)
*/
class Solution {
    public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        bool firstRowZero = false;
        bool firstColZero = false;
        
        // Check if the first row and first column need to be set to zero
        for (int j = 0; j < m; j++) { // TC: O(m)
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }
        
        for (int i = 0; i < n; i++) { // TC: O(n)
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }
        
        // Mark the corresponding entry in the first row and first column as zero
        for (int i = 1; i < n; i++) { // TC: O(n*m)
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // Set the elements in rows and columns (excluding the first row and first column) to zero
        for (int i = 1; i < n; i++) { // TC: O(n*m)
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Set the first row to zero if necessary
        if (firstRowZero) { // TC: O(m)
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }
        
        // Set the first column to zero if necessary
        if (firstColZero) { // TC: O(n)
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
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