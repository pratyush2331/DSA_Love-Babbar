// 

#include<bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << '] (' << #__VA_ARGS__ << '):', dbg_out(__VA_ARGS__)

using ll = long long;

void run() {
    int n, k;
    cin >> n >> k;

    vector<vector<char>> matrix(n, vector<char>(n));
    vector<vector<char>> ans(n/k, vector<char>(n/k));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if(i%k == 0 && j%k == 0) ans[i/k][j/k] = matrix[i][j];
        }
    }

    for(int i = 0; i < n/k; i++) {
        for(int j = 0; j < n/k; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}