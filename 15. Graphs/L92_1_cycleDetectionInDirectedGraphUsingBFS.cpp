// Detect Cycle In A Directed Graph
// CodeStudio : https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626

#include<bits/stdc++.h>
using namespace std;


// using BFS - Kahn's Algorithm
/*
TC : O(V+E)
SC : O(V+E)
*/

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    // Write your code here.

    // creat adjList
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < edges.size(); i++) {
        // node value - 1, as index starts from 1, so we are changing 1 to 0
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        adjList[u].push_back(v);
    }

    // find all indegrees
    vector<int> indegree(n);
    for(auto i : adjList) {
        for(auto j : i.second) {
            indegree[j]++;
        }
    }

    // push all nodes with 0 indegree into queue
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

    // do BFS
    int cnt = 0;
    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();

        // inc count
        cnt++;

        // neighbour indegree--
        for(auto i : adjList[frontNode]) {
            indegree[i]--;
            if(indegree[i] == 0)
                q.push(i);
        }
    }

    return cnt != n;
}


int main() {
    
    return 0;
}