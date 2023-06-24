// Detect Cycle In A Directed Graph
// CodeStudio : https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626

#include<bits/stdc++.h>
using namespace std;


// using DFS
/*
TC : O(V+E)
SC : O(V+E)
*/

bool isCyclicDFS(int node, unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited) { // TC: O(V+E)
  visited[node] = true;
  dfsVisited[node] = true;

  for(auto i : adjList[node]) {
    if(visited[i] == true && dfsVisited[i] == true) {
      // cycle is present
      return true;
    }
    if(!visited[i]) {
      // dfs ke liye call kardo
      bool ans = isCyclicDFS(i, adjList, visited, dfsVisited);
      if(ans == true)
        return true;
    }
  }

  dfsVisited[node] = false;

  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

  // create adjList
  unordered_map<int, list<int>> adjList; // SC: O(E)
  for(int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;

    adjList[u].push_back(v);
  }

  // call dfs for all components
  unordered_map<int, bool> visited; // SC: O(E)
  unordered_map<int, bool> dfsVisited; // SC: O(E)
  for(int i = 0; i < edges.size(); i++) {
    if(!visited[i]) {
      // using DFS
      bool ans = isCyclicDFS(i, adjList, visited, dfsVisited);
      if(ans == true)
        return true;
    }
  }

  return false;
}


int main() {
    
  return 0;
}