// Topological Sort
// CodeStudio : https://www.codingninjas.com/codestudio/problems/topological-sort_982938

/*
Topological sorting is a linear ordering of the vertices in a directed acyclic graph (DAG) such that for 
every directed edge (u, v), vertex u comes before vertex v in the ordering. It's used to represent tasks 
or dependencies in a way that ensures all prerequisites are completed before a task is started, making it 
a fundamental concept in project scheduling and dependency management.
*/

#include <bits/stdc++.h>
using namespace std;


// Kahn's Algorithm - Toplogical Sort using BFS
/*
TC : O(V+E)
SC : O(V+E)
*/

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // creat adjList
    vector<vector<int>> adjList(v);
    for(int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
    }

    // find all indegrees
    vector<int> indegree(v);
    for(int i = 0; i < v; i++) {
        for(int nbr : adjList[i]) {
            indegree[nbr]++;
        }
    }

    // push all nodes with 0 indegree into queue
    queue<int> q;
    for(int i = 0; i < v; i++) {
        if(!indegree[i]) q.push(i);
    }

    // do BFS
    vector<int> ans;
    while(!q.empty()) {
        int top = q.front();
        q.pop();

        // imp : store ans
        ans.push_back(frontNode);

        // decrement neighbour's indegree by 1
        for(int nbr : adjList[top]) {
            indegree[nbr]--;
            if(!indegree[nbr]) {
                q.push(nbr);
            }
        }
    }
    return ans;
}


int main() {
    
    return 0;
}