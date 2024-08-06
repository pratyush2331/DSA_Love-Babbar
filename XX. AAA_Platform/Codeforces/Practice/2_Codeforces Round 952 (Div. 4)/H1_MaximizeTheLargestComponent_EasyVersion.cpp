// H1. Maximize the Largest Component (Easy Version)
// Codeforces : https://codeforces.com/contest/1985/problem/H1

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

// by size
class DisjointSet {
public:
    vector<int> size, parent;

    DisjointSet(int n) {
        size.resize(n+1, 1); // will work for both '0' and '1' based indexing
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) { // TC: O(4α) = constant
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]); // path compression
    }

    void unionBySize(int u, int v) { // TC: O(4α) = constant
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

void run() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    DisjointSet ds(n*m);

    // Union adjacent '#' cells
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '#') {
                if(i-1 >= 0 && grid[i-1][j] == '#') {
                    ds.unionBySize(m*i + j, m*(i-1) + j);
                }
                if(j-1 >= 0 && grid[i][j-1] == '#') {
                    ds.unionBySize(m*i + j, m*i + (j-1));
                }
            }
        }
    }

    ll ans = 0;

    for(int i = 0; i < n; i++) { // for row
        ll c = 0;
        set<int> s; // store unique leaders/parents
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '#') {
                s.insert(ds.findUPar(m*i + j));
            }
            else {
                c++; // curr cell will be '#'
                if(i-1 >= 0 && grid[i-1][j] == '#') {
                    s.insert(ds.findUPar(m*(i-1) + j));
                }
                if(i+1 < n && grid[i+1][j] == '#') {
                    s.insert(ds.findUPar(m*(i+1) + j));
                }
            }
        }
        for(auto ele : s) {
            c += ds.size[ele];
        }
        ans = max(ans, c);
    }

    for(int j = 0; j < m; j++) { // for col
        ll c = 0;
        set<int> s; // store unique leaders/parents
        for(int i = 0; i < n; i++) {
            if(grid[i][j] == '#') {
                s.insert(ds.findUPar(m*i + j));
            }
            else {
                c++; // curr cell will be '#'
                if(j-1 >= 0 && grid[i][j-1] == '#') {
                    s.insert(ds.findUPar(m*i + (j-1)));
                }
                if(j+1 < m && grid[i][j+1] == '#') {
                    s.insert(ds.findUPar(m*i + (j+1)));
                }
            }
        }
        for(auto ele : s) {
            c += ds.size[ele];
        }
        ans = max(ans, c);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}