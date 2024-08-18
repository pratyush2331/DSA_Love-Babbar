// D. Determine Winning Islands in Race

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

vector<vector<int>> main_adj, alt_adj;
vector<int> memo;
int n;

bool canBessieWin(int s) {
    if (s == n) return true;  // Bessie wins if she reaches island n
    if (memo[s] != -1) return memo[s];  // Return already computed result
    
    bool result = false;
    // Check main bridges
    for (int next : main_adj[s]) {
        if (!canBessieWin(next)) {
            result = true;
            break;
        }
    }
    // Check alternative bridges
    if (!result) {
        for (int next : alt_adj[s]) {
            if (!canBessieWin(next)) {
                result = true;
                break;
            }
        }
    }
    return memo[s] = result;
}

void run() {
    int m;
    cin >> n >> m;
    
    main_adj.assign(n + 1, vector<int>());
    alt_adj.assign(m + 1, vector<int>());
    memo.assign(n + 1, -1);

    for (int i = 1; i < n; ++i) {
        main_adj[i].push_back(i + 1);
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        alt_adj[u].push_back(v);
    }

    string result;
    for (int s = n-1; s >= 1; s--) {
        result += (canBessieWin(s) ? '1' : '0');
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}