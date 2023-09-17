// DFS Traversal
// GFG [undirected connected graph] : https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// CodeStudio [undirected disconnected graph] : https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?leftPanelTab=0

#include<iostream>
using namespace std;

void DFS(int node, unordered_map<int, set<int>>& adjList, unordered_map<int, bool>& visited, vector<int>& component) {
    component.push_back(node);
    visited[node] = true;

    // go to depth
    for(auto i : adjList[node]) {
        if(!visited[i]) {
            DFS(i, adjList, visited, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> ans;

    // preparing adj list
    unordered_map<int, set<int>> adjList;
    for(int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    // visited map
    unordered_map<int, bool> visited;
    // since, graph can be disconnected
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            vector<int> component;
            DFS(i, adjList, visited, component);
            ans.push_back(component);
        }
    }

    return ans;
}

int main() {
    
    return 0;
}