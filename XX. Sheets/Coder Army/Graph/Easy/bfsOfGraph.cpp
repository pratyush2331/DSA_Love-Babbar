// BFS of graph
// GFG : https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include<bits/stdc++.h>

using namespace std;


 Solution {
    public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        
        // visited array of bool type
        vector<bool> vis(V, false);
        
        queue<int> q;
        q.push(0);
        vis[0] = true;
        
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            
            ans.push_back(front);
            
            for(auto nbr : adj[front]) {
                if(!vis[nbr]) {
                    q.push(nbr);
                    vis[nbr] = true;
                }
            }
        }
        
        return ans;
    }
};


int main() {
    

    return 0;
}