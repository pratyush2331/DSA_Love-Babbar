// D. Manhattan Circle
// Codeforces : https://codeforces.com/contest/1985/problem/D

#include<bits/stdc++.h>
using namespace std;

using ll = long long;


// method-1 : less calculation
void run() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    pair<int,int> row = {0, -1};
    pair<int,int> col = {0, -1};
    bool flag = 0;
    for(int i = 0; i < n; i++) { // for row
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '#') {
                if(!flag) {
                    col.first = j; // first '#' encountered
                    flag = 1;
                }
                col.second = j; // last '#' encountered
            }
        }
    }

    flag = 0;
    for(int j = 0; j < m; j++) { // for col
        for(int i = 0; i < n; i++) {
            if(grid[i][j] == '#') {
                if(!flag) {
                    row.first = i; // first '#' encountered
                    flag = 1;
                }
                row.second = i; // last '#' encountered
            }
        }
    }

    cout << ((row.first+row.second)/2)+1 << " " << ((col.first + col.second)/2)+1 << "\n";
}


// method-0 : more calculation
/*
void run() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    pair<int,int> row = {0, -1};
    pair<int,int> col = {0, -1};
    for(int i = 0; i < n; i++) { // for row
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '#') {
                int s = j;
                while(j < m && grid[i][j] == '#') {
                    j++;
                }
                int e = j-1;
                if(e-s+1 > col.second-col.first+1) {
                    col.first = s;
                    col.second = e;
                }
            }
        }
    }

    for(int j = 0; j < m; j++) { // for col
        for(int i = 0; i < n; i++) {
            if(grid[i][j] == '#') {
                int s = i;
                while(i < n && grid[i][j] == '#') {
                    i++;
                }
                int e = i-1;
                if(e-s+1 > row.second-row.first+1) {
                    row.first = s;
                    row.second = e;
                }
            }
        }
    }

    cout << ((row.first+row.second)/2)+1 << " " << ((col.first + col.second)/2)+1 << "\n";
}
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}