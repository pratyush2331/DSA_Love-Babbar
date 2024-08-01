// D. Maximize the Root
// Codeforces : https://codeforces.com/contest/1997/problem/D

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

// using 0-based indexing
void run() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> adj[n];
    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;
        adj[p-1].push_back(i);
    }

    function<ll(int node)>dfs = [&](int node)->ll{ // lambda function
        ll mini = 1e9;
        for(auto nbr : adj[node]) {
            mini = min(mini, dfs(nbr));
        }

        if(node == 0) return mini + v[0]; // root node
        if(mini == 1e9) return v[node]; // leaf node

        if(v[node] >= mini) return mini;
        else return (mini + v[node]) / 2;
    };

    cout << dfs(0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}