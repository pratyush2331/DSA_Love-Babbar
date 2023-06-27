// Bellman Ford Algorithm
// CodeStudio : https://www.codingninjas.com/studio/problems/bellmon-ford_2041977

/*
TC : O(V * E)
SC : O(V)
*/

#include <bits/stdc++.h> 
using namespace std;


int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.

    vector<int> dist(n+1, 1e9); // as 1 based indexing, SC: O(V)
    dist[src] = 0;

    for(int i = 1; i <= n; i++) { // (n-1) times, TC: O(V*E)
        // traverse on edge list
        for(int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != 1e9 && ((dist[u] + wt) < dist[v])) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // check for negative cycle
    bool flag = false;
    // one more time, traverse on edge list
    for(int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if(dist[u] != 1e9 && ((dist[u] + wt) < dist[v])) {
            flag = true;
            break;
        }
    }

    // -ve cycle is present, so solution is not possible
    if(flag) return 1e9;

    return dist[dest];
}


int main() {
    
    return 0;
}