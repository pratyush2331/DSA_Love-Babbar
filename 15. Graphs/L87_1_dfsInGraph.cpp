// DFS Traversal
// GFG [undirected connected graph] : https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// CodeStudio [undirected disconnected graph] : https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?leftPanelTab=0

/*
TC : O(V) + O(2E)
SC : O(V)
*/

#include<iostream>
using namespace std;


class Solution {
    void dfs(int node, vector<int> adj[], bool vis[], vector<int>& ans) {
        vis[node] = 1;
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
        bool vis[V] = {0};
        dfs(0, adj, vis, ans);
        return ans;
    }
};


int main() {
    
    return 0;
}