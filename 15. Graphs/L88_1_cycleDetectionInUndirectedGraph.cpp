// Cycle Detection In Undirected Graph
// CodeStudio : https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670

#include<bits/stdc++.h>
using namespace std;


// using BFS
/*
TC : O(V+E)
SC : O(V+E)
*/
bool isCyclicBFS(int node, unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& visited) { // TC: O(V + E)
    unordered_map<int, int> parent; //SC: O(V)

    queue<int> q;
    q.push(node);
    visited[node] = true;
    parent[node] = -1;

    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();

        for(auto i : adjList[frontNode]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
                parent[i] = frontNode;
            }
            else if(visited[i] == true && i != parent[frontNode]) {
                return true;
            }
        }
    }

    return false;
}

// using DFS
/*
TC : O(V+E)
SC : O(V+E)
*/
bool isCyclicDFS(int node, int parent, unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& visited) { // TC: O(V+E)
    visited[node] = true;

    for(auto i : adjList[node]) {
        if(!visited[i]) {
            bool ans = isCyclicDFS(i, node, adjList, visited);
            if(ans)
                return true;
        }
        else if(visited[i] == true && i != parent) {
            return true;
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.

    // prepare adjList
    unordered_map<int, list<int>> adjList; // SC: O(E)
    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // visited map
    unordered_map<int, bool> visited; // SC: O(V)

    // to handle disconnected components
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            // bool ans = isCyclicBFS(i, adjList, visited);
            bool ans = isCyclicDFS(i, -1, adjList, visited);
            
            if(ans == true)
                return "Yes";
        }
    }

    return "No";
}


int main() {
    
    return 0;
}