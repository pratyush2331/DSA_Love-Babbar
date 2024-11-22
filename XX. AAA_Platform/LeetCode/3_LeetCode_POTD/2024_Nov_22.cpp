// 1072. Flip Columns For Maximum Number of Equal Rows
// LeetCode : https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

#include<bits/stdc++.h>
using namespace std;


// map + complement approach
/*
TC : O(m*n)
SC : O(m)
*/
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        unordered_map<string, int> mp;
        for(int i = 0; i < m; i++) { // go row wise
            string currRow, compRow; // IMP
            for(int j = 0; j < n; j++) {
                currRow += (matrix[i][j] == 1) ? '1' : '0';
                compRow += (matrix[i][j] == 1) ? '0' : '1';
            }
            mp[currRow]++;
            mp[compRow]++;
        }

        int maxi = INT_MIN;
        for(auto ele : mp) {
            maxi = max(maxi, ele.second);
        }
        return maxi;
    }
};


int main() {
    
    return 0;
}