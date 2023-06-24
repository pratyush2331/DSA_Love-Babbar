// 1572. Matrix Diagonal Sum
// LeetCode : https://leetcode.com/problems/matrix-diagonal-sum/

#include<iostream>
#include<vector>
using namespace std;

// Optimized Solution - TC : O(n), SC : O(1)
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();

        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += (mat[i][i] + mat[i][n-1-i]);
        }

        if(n&1)
            sum -= mat[n/2][n/2];
        
        return sum;
    }
};


// Brute Force - TC : O(n^2), SC : O(1)
/*
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();

        int sum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // primary diag
                if(i == j)
                    sum += mat[i][j];
                
                // secondary diag
                if(i+j == n-1)
                    sum += mat[i][j];
            }
        }

        if(n&1)
            sum -= mat[n/2][n/2];
        
        return sum;
    }
};
*/

int main(){
    
    return 0;
}