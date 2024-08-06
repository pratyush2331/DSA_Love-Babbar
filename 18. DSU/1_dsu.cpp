// Disjoint Set Union

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

// by size
class DisjointSet {
    vector<int> size, parent;

public:
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


// by rank
/*
class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank.resize(n+1, 0); // will work for both '0' and '1' based indexing
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
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
*/


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    DisjointSet ds(7);

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    // if 3 and 7 are same or not
    if(ds.findUPar(3) == ds.findUPar(7)) cout << "Same\n";
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    // if 3 and 7 are same or not
    if(ds.findUPar(3) == ds.findUPar(7)) cout << "Same\n";
    else cout << "Not same\n";
        
    return 0;
}