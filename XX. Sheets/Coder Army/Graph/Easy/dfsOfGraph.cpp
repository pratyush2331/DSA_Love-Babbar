// DFS of Graph
// GFG : https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

#include<bits/stdc++.h>

using namespace std;


class Solution {
    void dfs(int node, vector<int> adj[], vector<bool>& vis, vector<int>& ans) {
        vis[node] = true;
        
        ans.push_back(node);
        
        for(auto nbr : adj[node]) {
            if(!vis[nbr]) {
                dfs(nbr, adj, vis, ans);
            }
        }
    }
    
    public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        
        // visited array of boolean type
        vector<bool> vis(V, false);
        
        dfs(0, adj, vis, ans);
        
        return ans;
    }
};


int main() {
    

    return 0;
}