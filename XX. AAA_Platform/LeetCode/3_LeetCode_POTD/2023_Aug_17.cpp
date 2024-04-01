// 542. 01 Matrix
// LeetCode : https://leetcode.com/problems/01-matrix/

#include<iostream>
using namespace std;


class Solution {
    public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans = mat;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(ans[i][j] != 0) {
                    int op1 = 1e9, op2 = 1e9;
                    if(i > 0) {
                        op1 = ans[i-1][j];
                    }
                    if(j > 0)
                        op2 = ans[i][j-1];
                    ans[i][j] = 1 + min(op1, op2);
                }
            }
        }

        for(int i = mat.size()-1; i >= 0; i--) {
            for(int j = mat[0].size()-1; j >= 0; j--) {
                if(ans[i][j] != 0) {
                    int op1 = 1e9, op2 = 1e9;
                    if(i < m-1) {
                        op1 = ans[i+1][j];
                    }
                    if(j < n-1)
                        op2 = ans[i][j+1];
                    ans[i][j] = min(ans[i][j], 1 + min(op1, op2));
                }
            }
        }

        return ans;
    }
};


int main() {
    
    return 0;
}