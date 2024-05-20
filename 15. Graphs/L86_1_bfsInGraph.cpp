// BFS in Graph
// GFG [directed connected graph] : https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// CodeStudio [undirected disconnected graph] : https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002

/*
TC : O(V) + O(2E)
SC : O(V)
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        bool vis[V] = {0};
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(auto nbr : adj[front]) {
                if(!vis[nbr]) {
                    vis[nbr] = 1;
                    q.push(nbr);
                }
            }
        }
        return ans;
    }
};


int main() {
    
    return 0;
}