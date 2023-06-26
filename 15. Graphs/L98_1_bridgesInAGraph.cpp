// Bridges In A Graph
// CodeStudio : https://www.codingninjas.com/studio/problems/bridges-in-graph_893026

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
        vector<vector<int>>& ans) {

    vis[node] = true;
    disc[node] = low[node] = timer++;

    for(auto neighbor : adjList[node]) {
        if(neighbor == parent)
            continue;
        
        if(!vis[neighbor]) {
            dfs(neighbor, node, timer, disc, low, vis, adjList, ans);
            // while returning
            low[node] = min(low[node], low[neighbor]);
            // To check BRIDGE
            if(low[neighbor] > disc[node]) {
                vector<int> temp{node, neighbor};
                ans.push_back(temp);
            }
        }
        else {
            // node already visited and not parent
            // Back edge
            low[node] = min(low[node], disc[neighbor]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here

    // create adjList
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // 4 Data Structures needed
    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1; // no need of array
    unordered_map<int, bool> vis;

    // to store vertices of bridges
    vector<vector<int>> ans;

    // do dfs
    for(int i = 0; i < v; i++) { // do for all nodes
        if(!vis[i]) {
            dfs(i, parent, timer, disc, low, vis, adjList, ans);
        }
    }

    return ans;
}


int main() {
    
    return 0;
}