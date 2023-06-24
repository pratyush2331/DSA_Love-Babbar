// Dijkstra's Algorithm - using priority queue and BFS
// CodeStudio : https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469

/*
TC : O(E logV)
SC : O(V + E)
*/

#include <bits/stdc++.h> 
using namespace std;


vector<int> dijkstra(vector<vector<int>>& vec, int vertices, int edges, int source) {
    // Create adjacency list
    unordered_map<int, vector<pair<int, int>>> adjList;
    for (int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }

    // Initialize distance from source to all vertices as infinity
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;

    // Priority queue (min heap) to store nodes and their distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int node = pq.top().second;
        int nodeDistance = pq.top().first;
        pq.pop();

        // If the nodeDistance is greater than the distance from the source to this node,
        // it means that this node has already been visited with a shorter distance,
        // so we can skip it.
        if (nodeDistance > dist[node])
            continue;

        // Traverse neighbors
        for (auto neighbor : adjList[node]) {
            int neighborNode = neighbor.first;
            int edgeWeight = neighbor.second;

            if (dist[node] + edgeWeight < dist[neighborNode]) {
                dist[neighborNode] = dist[node] + edgeWeight;
                pq.push(make_pair(dist[neighborNode], neighborNode));
            }
        }
    }

    return dist;
}

int main() {
    
    return 0;
}