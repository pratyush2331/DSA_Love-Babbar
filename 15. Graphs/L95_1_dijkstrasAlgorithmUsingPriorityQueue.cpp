// Dijkstra's Algorithm - using priority queue and BFS
// CodeStudio : https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469

/*
TC : O(E logV)
SC : O(V + E)
*/

#include <bits/stdc++.h> 
using namespace std;

#define INF INT_MAX

vector<int> dijkstra(vector<vector<int>>& vec, int vertices, int edges, int source) {
    // Code here

    // Create adjList
    unordered_map<int, vector<pair<int, int>>> adjList;
    for (int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }

    // Initialize distance from source to all vertices as infinity
    vector<int> dist(vertices, INF);
    // distance from sorce to source = 0
    dist[source] = 0;

    // Priority queue (min heap) to store nodes and their distances {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

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
            }
        }
    }

    return dist;
}

int main() {
    
    return 0;
}