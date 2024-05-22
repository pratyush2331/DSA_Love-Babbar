// Cycle Detection In Undirected Graph
// CodeStudio : https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// can have disconnected components

#include<bits/stdc++.h>
using namespace std;


class Solution {
    // using BFS
    /*
    TC : O(V + 2E) + O(V)
    SC : O(V)
    */
    bool BFS(int src, vector<int> adj[], vector<bool>& vis) {
        vis[src] = 1;
        queue<pair<int, int>> q; // SC:O(V)
        q.push({src, -1});
        while(!q.empty()) { // TC : O(V + 2E) --> for one component
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            
            for(auto nbr : adj[node]) {
                if(!vis[nbr]) {
                    vis[nbr] = 1;
                    q.push({nbr, node});
                }
                else if(nbr != par) {
                    return true;
                }
            }
        }
        return false;
    }


    // using DFS
    /*
    TC : O(V + 2E) + O(V)
    SC : O(V) + O(V) = O(V)
    */
    bool DFS(int node, int par, vector<int> adj[], vector<bool>& vis) {
        vis[node] = 1;
        for(auto nbr : adj[node]) {
            if(!vis[nbr]) {
                if(DFS(nbr, node, adj, vis)) return true;
            }
            else if(nbr != par) {
                return true;
            }
        }
        return false;
    }
    
    
    public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V, 0);
        for(int i = 0; i < V; i++) { // TC:O(V)
            if(!vis[i]) {
                if(BFS(i, adj, vis)) return true;
            }
        }
        return false;
    }
};


int main() {
    
    return 0;
}