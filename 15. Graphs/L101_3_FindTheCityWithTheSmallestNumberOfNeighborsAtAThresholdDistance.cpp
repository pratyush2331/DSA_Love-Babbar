// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
// LeetCode : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#include<bits/stdc++.h>
using namespace std;


// method-1 : using Dijkstra's algorithm for every node
/*
TC : O(n.m.logn)
SC : O(n+m)
*/
class Solution {
    const int INF = 1e9;

    vector<int> dijkstra(int source, int vertices, vector<vector<pair<int, int>>>& adj) {
        vector<int> dist(vertices, INF);

        set<pair<int,int>> st; // {distance, node}
        dist[source] = 0;
        st.insert({0, source});
        
        while(!st.empty()) {
            auto [nodeDistance, topNode] = *(st.begin());
            st.erase(st.begin());
            
            for(auto neighbor : adj[topNode]) {
                if(nodeDistance + neighbor.second < dist[neighbor.first]) {
                    if(dist[neighbor.first] != INF) {
                        st.erase({dist[neighbor.first],neighbor.first});
                    }
                    
                    dist[neighbor.first] = nodeDistance + neighbor.second;
                    
                    st.insert(make_pair(dist[neighbor.first],neighbor.first));
                }
            }
        }
        
        return dist;
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // create adj list for undirected graph
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }


        int cityCnt = n, cityNo = -1;
        for(int i = 0; i < n; i++) {
            // calling dijkstra for every individual node
            vector<int> dist = dijkstra(i, n, adj);
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && dist[j] <= distanceThreshold) cnt++;
            }
            if(cnt <= cityCnt) {
                cityCnt = cnt;
                cityNo = i;
            }
        }

        return cityNo;
    }
};


// method-0 : using Floyd Warshall algorithm
/*
TC : O(n^3)
SC : O(n^2)
*/
class Solution {
    const int INF = 1e9;
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // create adj matrix for undirected graph
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for(int i = 0; i < edges.size(); i++) {
            dist[edges[i][0]][edges[i][1]] = edges[i][2];
            dist[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        int cityCnt = n, cityNo = -1;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && dist[i][j] <= distanceThreshold) cnt++;
            }
            if(cnt <= cityCnt) {
                cityCnt = cnt;
                cityNo = i;
            }
        }

        return cityNo;
    }
};


int main() {
    
    return 0;
}