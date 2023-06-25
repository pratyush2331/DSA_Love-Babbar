// Shortest Path in Weighted undirected graph
// GFG : https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

/*
TC : O(E logV)
SC : O(V + E)
*/

#include<iostream>
using namespace std;

#define INF INT_MAX

class Solution {
    public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        // n -> no. of vertices
        // m -> no. of edges
        // shortest path from 1 to n = ??
        
        // create adjList
        unordered_map<int, list<pair<int,int>>> adjList;
        for(int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adjList[u].push_back(make_pair(v,w));
            adjList[v].push_back(make_pair(u,w));
        }
        
        vector<int> dist(n+1, INF);
        dist[1] = 0;
        
        vector<int> parent(n+1); // 1 based indexing
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        
        while(!pq.empty()) {
            int nodeDistance = pq.top().first;
            int topNode = pq.top().second;
            pq.pop();
    
            // traverse neighbors
            for(auto neighbor : adjList[topNode]) {
                if(nodeDistance + neighbor.second < dist[neighbor.first]) { // means (new_dist < old_dist)
                    // distance update
                    dist[neighbor.first] = nodeDistance + neighbor.second;
    
                    // push record in priority queue
                    pq.push(make_pair(dist[neighbor.first], neighbor.first));
                    
                    // update parent
                    parent[neighbor.first] = topNode;
                }
            }
        }
        
        if(dist[n] == INF) return {-1};
        
        // get the path from n to 1 using parent array
        vector<int> path;
        int node = n;
        while(parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        // reverse to get path from 1 to n
        reverse(path.begin(), path.end());
        
        // return path array
        return path;
    }
};


int main() {
    
    return 0;
}