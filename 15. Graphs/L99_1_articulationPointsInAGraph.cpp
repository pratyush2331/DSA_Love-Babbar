// Articulation Points in a Graph using Tarjan's Algorithm
// CodeStudio Article Link : https://www.codingninjas.com/studio/library/articulation-points-in-a-graph

/*
TC : O(V + E)
SC : O(V)
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int>& disc, vector<int>& low, 
        unordered_map<int, bool>& vis, unordered_map<int, list<int>>& adjList, 
        vector<bool>& ap) {

    vis[node] = true;
    disc[node] = low[node] =timer++;

    // imp
    int child = 0;

    for(auto neighbor : adjList[node]) {
        if(neighbor == parent)
            continue;
        
        if(!vis[neighbor]) {
            dfs(neighbor, node, timer, disc, low, vis, adjList, ap);
            // while returning
            low[node] = min(low[node], low[neighbor]);
            // To check AP
            if(low[neighbor] >= disc[node] && parent != -1) {
                ap[node] = true;
            }
            // imp
            child++;
        }
        else {
            // Back edge
            low[node] = min(low[node], disc[neighbor]);
        }
    }

    // check ap exclusively for starting node
    if(parent == -1 && child > 1)
        ap[node] = true;
}

int main() {
    int n = 5; // no. of nodes
    int e = 5; // no. of edges
    vector<pair<int,int>> edges;
    edges.push_back({0, 3});
    edges.push_back({3, 4});
    edges.push_back({0, 4});
    edges.push_back({0, 1});
    edges.push_back({1, 2});

    // adjList
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < e; i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // 4 Data Structures needed
    int timer = 0;
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    int parent = -1; // no need of array
    unordered_map<int, bool> vis;

    // to store articulation points
    vector<bool> ap(n, false);

    // do dfs
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, parent, timer, disc, low, vis, adjList, ap);
        }
    }

    // print ap
    cout << "articulation points : ";
    for(int i = 0; i < n; i++) {
        if(ap[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
    
    return 0;
}