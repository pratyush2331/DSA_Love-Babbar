// B. Mahmoud and Ehab and the bipartiteness
// Codeforces : https://codeforces.com/problemset/problem/862/B

#include <bits/stdc++.h>
using namespace std;

void run() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n + 1, -1); // -1: unvisited, 0: set A, 1: set B
    long long setA = 0, setB = 0;

    // BFS to divide nodes into two sets
    queue<int> q;
    q.push(1);
    color[1] = 0;
    setA++;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (color[neighbor] == -1) {
                color[neighbor] = 1 - color[node]; // Alternate between 0 and 1
                if (color[neighbor] == 0)
                    setA++;
                else
                    setB++;
                q.push(neighbor);
            }
        }
    }

    // Total edges between sets
    long long ans = setA * setB - (n - 1); // Subtract existing tree edges
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) run();

    return 0;
}