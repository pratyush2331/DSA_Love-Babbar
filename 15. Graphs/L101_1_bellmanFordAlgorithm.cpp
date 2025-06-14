// Bellman Ford Algorithm (SSSP: Single Source Shortest Path)
// CodeStudio : https://www.codingninjas.com/studio/problems/bellmon-ford_2041977


/*
* It's used for directed graphs with -ve weights.
* Helps to detect -ve cycle in directed graphs.
* Can be used for undirected or directed graphs with +ve weights, or +ve cycles. 
  But, it's better to use Dijkstra's algorithm, because of lesser TC.
*/

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
            return 1e9; // negative cycle detected
        }
    }

    return dist[dest];
}


int main() {
    
    return 0;
}