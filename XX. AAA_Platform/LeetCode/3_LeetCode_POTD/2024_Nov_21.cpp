// 2257. Count Unguarded Cells in the Grid
// LeetCode : https://leetcode.com/problems/count-unguarded-cells-in-the-grid/

#include<bits/stdc++.h>
using namespace std;


// method-0 : Brute-force
/*
TC : O((m*n)^2)
SC : O(m*n)
*/

class Solution {
    /*
    0 --> not-visited path
    1 --> wall/guard
    2 --> visited path
    */
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // mark all guards cell as visited
        for(int idx = 0; idx < guards.size(); idx++) {
            int i = guards[idx][0];
            int j = guards[idx][1];
            grid[i][j] = 1;
        }

        // mark all walls cell as visited
        for(int idx = 0; idx < walls.size(); idx++) {
            int i = walls[idx][0];
            int j = walls[idx][1];
            grid[i][j] = 1;
        }
        
        // go through all guards cell and go in all 4 possible directions and mark accordingly
        // but with a different number... :)
        for(int idx = 0; idx < guards.size(); idx++) {
            // check top
            int i = guards[idx][0]-1;
            int j = guards[idx][1];
            while(i >= 0) {
                if(grid[i][j] == 1) break;
                grid[i][j] = 2;
                i--;
            }

            // check right
            i = guards[idx][0];
            j = guards[idx][1]+1;
            while(j < n) {
                if(grid[i][j] == 1) break;
                grid[i][j] = 2;
                j++;
            }

            // check down
            i = guards[idx][0]+1;
            j = guards[idx][1];
            while(i < m) {
                if(grid[i][j] == 1) break;
                grid[i][j] = 2;
                i++;
            }

            // // check left
            i = guards[idx][0];
            j = guards[idx][1]-1;
            while(j >= 0) {
                if(grid[i][j] == 1) break;
                grid[i][j] = 2;
                j--;
            }
        }

        // count all unvisited nodes
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
};


int main() {
    
    return 0;
}