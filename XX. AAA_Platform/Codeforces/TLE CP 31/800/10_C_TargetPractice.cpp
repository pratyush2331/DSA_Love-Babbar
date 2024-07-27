// C. Target Practice
// Codeforces : https://codeforces.com/problemset/problem/1873/C

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    vector<vector<char>> matrix(10, vector<char>(10));
    int score = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] == 'X') { // calc. score
                int x = i+1;
                int y = j+1;
                if(x > 5) x = 10 - x + 1;
                if(y > 5) y = 10 - y + 1;
                score += min(x,y);
            }
        }
    }

    cout << score << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}