// 3417. Zigzag Grid Traversal With Skip
// LeetCode : https://leetcode.com/problems/zigzag-grid-traversal-with-skip/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        bool odd = 1;
        int diff = 0;
        for(int i = 0; i < grid.size(); i++) {
            if(odd) {
                int j = 0;
                if(diff) j++;
                for(; j < grid[0].size(); j += 2) {
                    ans.emplace_back(grid[i][j]);
                }
                if(j == grid[0].size()+1) diff = 1;
                else diff = 0;
            }
            else {
                int j = grid[0].size()-1;
                if(diff) j--;
                for(; j >= 0; j -= 2) {
                    ans.emplace_back(grid[i][j]);
                }
                if(j == -2) diff = 1;
                else diff = 0;
            }
            odd = !odd;
        }
        return ans;
    }
};


int main() {
    
    return 0;
}