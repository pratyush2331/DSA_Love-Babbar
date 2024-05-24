// Detect cycle in a directed graph using DFS
// GFG : https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// CodeStudio : https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626

#include<bits/stdc++.h>
using namespace std;


// metho-0 : DFS : using 2 visied array [vis, pathVis]
/*
TC : O(V+E)
SC : O(2V)
*/
class Solution {
    bool dfsCheck(int node, vector<int> adj[], vector<bool>& vis, vector<bool>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto nbr : adj[node]) {
            if(!vis[nbr]) {
                if(dfsCheck(nbr, adj, vis, pathVis)) return true;
            }
            else if(pathVis[nbr]) {
                return true;
            }
        }
        
        pathVis[node] = 0;
        return false;
    }
    
public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V, 0);
        vector<bool> pathVis(V, 0);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfsCheck(i, adj, vis, pathVis)) return true;
            }
        }
        return false;
    }
};

// ----------------------------------------------------------------------------------------------------------------------------

// metho-1 : DFS : using 1 visied array [vis]
/*
TC : O(V+E)
SC : O(V)
*/
/*
0 --> not visited
1 --> visited
2 --> path visited
*/
class Solution {
    bool dfsCheck(int node, vector<int> adj[], vector<int>& vis) {
        vis[node] = 2;
        
        for(auto nbr : adj[node]) {
            if(!vis[nbr]) {
                if(dfsCheck(nbr, adj, vis)) return true;
            }
            else if(vis[nbr] == 2) {
                return true;
            }
        }
        
        vis[node] = 1;
        return false;
    }
    
public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfsCheck(i, adj, vis)) return true;
            }
        }
        return false;
    }
};


int main() {
    
  return 0;
}