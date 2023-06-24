// Topological Sort
// CodeStudio : https://www.codingninjas.com/codestudio/problems/topological-sort_982938

#include <bits/stdc++.h>
using namespace std;


// Kahn's Algorithm - Toplofical Sort using BFS
/*
TC : O(V+E)
SC : O(V+E)
*/
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    // Write your code here

    // creat adjList
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    // find all indegrees
    vector<int> indegree(v);
    for(auto i : adjList) {
        for(auto j : i.second) {
            indegree[j]++;
        }
    }

    // push all nodes with 0 indegree into queue
    queue<int> q;
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

    // do BFS
    vector<int> ans;
    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();

        // store ans
        ans.push_back(frontNode);

        // neighbour indegree--
        for(auto i : adjList[frontNode]) {
            indegree[i]--;
            if(indegree[i] == 0)
                q.push(i);
        }
    }

    return ans;
}


int main() {
    
    return 0;
}