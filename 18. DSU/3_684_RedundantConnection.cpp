// 684. Redundant Connection
// LeetCode : https://leetcode.com/problems/redundant-connection/description/

#include<bits/stdc++.h>
using namespace std;


// DSU [union by size]
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

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet ds(edges.size()); // node from 1 to n, SC:O(n)
        for(auto& edge : edges) {
            if(ds.findUPar(edge[0]) == ds.findUPar(edge[1])) {
                return edge;
            }
            ds.unionBySize(edge[0], edge[1]); // TC:O(n.α(n)) = O(n)
        }
        return {};
    }
};


int main() {
    
    return 0;
}