// Rat in a Maze Problem - I
// GFG : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

/*
sample input:
4
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1

sample output:
DDRDRR DRDDRR
*/

// using Backtracking

/*
TC : O(4^(n*n)) = O(4^(n^2))
SC : O(n*n) = O(n^2)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    bool isSafe(int new_x, int new_y, vector<vector<int>> &arr, int n, vector<vector<bool>> &visited) {
        if( ((new_x >= 0 && new_x < n) && (new_y >= 0 && new_y < n)) && (arr[new_x][new_y] == 1) && (visited[new_x][new_y] != 1)) {
            return true;
        }
        return false;
    }
    
    void solve(int x, int y, vector<vector<int>> &arr, int n, vector<vector<bool>> &visited, string path, vector<string> &ans) {
        // base case
        if(x == n-1 && y == n-1) {
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        // 4 movements --> D,L,R,U
        
        /*
        // using single for loop and single if statement
        
        int newx[4] = {x+1, x, x, x-1};
        int newy[4] = {y, y-1, y+1, y};
        string movement = "DLRU";
        
        for(int i = 0; i < 4; i++) {
            if(isSafe(newx[i], newy[i], arr, n, visited)) {
                solve(newx[i], newy[i], arr, n, visited, path + movement[i], ans);
            }
        }
        */
        
        // /*
        // using multiple if statements
        
        // Down
        if(isSafe(x+1, y, arr, n, visited)) {
            // visited[x][y] = 1;
            solve(x+1, y, arr, n, visited, path + 'D', ans);
            // visited[x][y] = 0;
        }
        
        // Left
        if(isSafe(x, y-1, arr, n, visited)) {
            // visited[x][y] = 1;
            solve(x, y-1, arr, n, visited, path + 'L', ans);
            // visited[x][y] = 0;
        }
        
        // Right
        if(isSafe(x, y+1, arr, n, visited)) {
            // visited[x][y] = 1;
            solve(x, y+1, arr, n, visited, path + 'R', ans);
            // visited[x][y] = 0;
        }
        
        // Up
        if(isSafe(x-1, y, arr, n, visited)) {
            // visited[x][y] = 1;
            solve(x-1, y, arr, n, visited, path + 'U', ans);
            // visited[x][y] = 0;
        }
        // */
        
        visited[x][y] = 0;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string> ans;
        vector<vector<bool>> visited(n, vector<bool> (n,0));
        string path = "";
        
        // EDGE CASE --> rat is not in the maze
        if(m[0][0] == 0)
            return ans;
        
        solve(0, 0, m, n, visited, path, ans);
        
        return ans;
    }
};

int main() {
    
    return 0;
}