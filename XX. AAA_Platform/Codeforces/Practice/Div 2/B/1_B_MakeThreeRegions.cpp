// B. Make Three Regions
// Codeforces : https://codeforces.com/contest/1997/problem/B

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    int n;
    cin >> n;

    vector<string> grid(2);
    for(int i = 0; i < 2; i++) {
        cin >> grid[i];
    }

    int cnt = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 1; j < n-1; j++) {
            if(grid[i][j] == '.' && grid[i][j-1] == '.' && grid[i][j+1] == '.' && grid[(i+1)%2][j] == '.' 
            && grid[(i+1)%2][j-1] == 'x' && grid[(i+1)%2][j+1] == 'x') cnt++;
        }
    }

    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}