// 3195. Find the Minimum Area to Cover All Ones I
// LeetCode : https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        pair<int,int> x = {INT_MAX,INT_MIN};
        pair<int,int> y = {INT_MAX,INT_MIN};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    x.first = min(x.first, i);
                    x.second = max(x.second, i);
                    y.first = min(y.first, j);
                    y.second = max(y.second, j);
                }
            }
        }
        
        return (x.second - x.first + 1) * (y.second - y.first + 1);
    }
};


int main() {
    
    return 0;
}