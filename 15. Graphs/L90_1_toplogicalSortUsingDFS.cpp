// Topological Sort
// CodeStudio : https://www.codingninjas.com/codestudio/problems/topological-sort_982938

#include <bits/stdc++.h> 
using namespace std;


// using DFS
/*
TC : O(V+E)
SC : O(V+E)
*/

void topoSort(int node, vector<vector<int>>& adjList, vector<bool>& visited, stack<int>& s) {
    visited[node] = true;

    for(int nbr : adjList[node]) {
        if(!visited[nbr]) {
            topoSort(nbr, adjList, visited, s);
        }
    }
    
    // imp
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    // create adjList
    // unordered_map<int, list<int>> adjList;
    vector<vector<int>> adjList(v); // optimising adjList : unordered_map<int, int> to vector<vector<int>>
    for(int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    // call toplogical sort util function for all components
    // unordered_map<int, bool> visited; // giving TLE
    vector<bool> visited(v); // optimising visited map
    stack<int> s;
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            topoSort(i, adjList, visited, s);
        }
    }

    vector<int> ans;
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}


int main() {
    
    return 0;
}