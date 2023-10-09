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

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>> m, int n, vector<vector<int>> visited) {
    if( (x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1) {
        return true;
    }
    return false;
}

void solve(vector<vector<int>> m, int n, vector<string>& ans, int x, int y, vector<vector<int>> visited, string path) {
    
    // YOU HAVE REACHED x,y HERE
    
    // base case
    if(x == n-1 && y == n-1) {
        ans.push_back(path);
        return;
    }
    
    visited[x][y] = 1;
    
    // 4-choices - D, L, R, U
    
    // down
    int newx = x+1;
    int newy = y;
    if(isSafe(newx, newy, m, n, visited)) {
        path.push_back('D');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    
    // left
    newx = x;
    newy = y-1;
    if(isSafe(newx, newy, m, n, visited)) {
        path.push_back('L');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    
    // right
    newx = x;
    newy = y+1;
    if(isSafe(newx, newy, m, n, visited)) {
        path.push_back('R');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    
    // up
    newx = x-1;
    newy = y;
    if(isSafe(newx, newy, m, n, visited)) {
        path.push_back('U');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    
    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    // Your code goes here
    vector<string> ans;
    
    if(m[0][0] == 0) {
        return ans;
    }
    
    int srcx = 0;
    int srcy = 0;
    
    vector<vector<int>> visited = m;
    // initialize with zero
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
    
    string path = "";
    solve(m, n, ans, srcx, srcy, visited, path);
    
    sort(ans.begin(), ans.end());
    
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> m;

    for(int i = 0; i < n; i++) {
        vector<int> temp;
        for(int j = 0; j < n; j++) {
            int data;
            cin >> data;
            temp.push_back(data);
        }
        m.push_back(temp);
    }

    vector<string> ans =  findPath(m, n);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}