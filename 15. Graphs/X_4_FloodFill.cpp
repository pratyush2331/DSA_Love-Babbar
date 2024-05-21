// 733. Flood Fill
// LeetCode : https://leetcode.com/problems/flood-fill

/*
TC : O(mn) + O(4 * mn) = O(mn)
SC : O(mn)
*/

#include<bits/stdc++.h>
using namespace std;


// using BFS / DFS
class Solution {
    vector<pair<int, int>> del = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    // using DFS
    void dfs(int sr, int sc, vector<vector<int>>& image, int prevColor, int color) {
        image[sr][sc] = color;
        for(auto [delRow, delCol] : del) {
            int newRow = sr + delRow;
            int newCol = sc + delCol;
            if(newRow >= 0 && newRow < image.size() && newCol >= 0 && newCol < image[0].size() 
            && image[newRow][newCol] == prevColor) {
                dfs(newRow, newCol, image, prevColor, color);
            }
        }
    }

    // using BFS
    /*
    void bfs(int sr, int sc, vector<vector<int>>& image, int prevColor, int color) {
        queue<pair<int, int>> q;
        image[sr][sc] = color;
        q.push({sr, sc});
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(auto [delRow, delCol] : del) {
                int newRow = row + delRow;
                int newCol = col + delCol;
                if(newRow >= 0 && newRow < image.size() && newCol >= 0 && newCol < image[0].size() 
                && image[newRow][newCol] == prevColor) {
                    image[newRow][newCol] = color;
                    q.push({newRow, newCol});
                }
            }
        }
    }
    */

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        // if(image[sr][sc] != color) bfs(sr, sc, image, image[sr][sc], color);
        if(image[sr][sc] != color) dfs(sr, sc, image, image[sr][sc], color);
        return image;
    }
};



// using recursion
/*
class Solution {
    void solve(vector<vector<int>>& image, int i, int j, int color, int pixel) {
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != pixel) {
            return;
        }

        image[i][j] = color;

        solve(image, i, j+1, color, pixel);
        solve(image, i, j-1, color, pixel);
        solve(image, i+1, j, color, pixel);
        solve(image, i-1, j, color, pixel);
    }

    public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] != color) solve(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};
*/


int main() {
    
    return 0;
}