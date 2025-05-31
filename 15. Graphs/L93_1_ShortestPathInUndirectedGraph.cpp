// Shortest Path in Undirected Graph
// GFG : https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1


#include<bits/stdc++.h>
using namespace std;


// BFS
/*
TC : O(V + E)
TC : O(V)
*/
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // BFS logic
        // dist[] array
        vector<int> dist(adj.size(), 1e9);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int& v : adj[u]) {
                if (dist[v] == 1e9) {
                    dist[v] = dist[u] + 1; // since unit weight graph
                    q.push(v);
                }
            }
        }
        
        for(int& d : dist) {
            if(d == 1e9) d = -1;
        }
        
        return dist;
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}