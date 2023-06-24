// BFS in Graph
// CodeStudio : https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002

/*
You are given an undirected and disconnected graph G(V,E) having V vertices numbered from 0 to V-1 and E edges.
For each node, the correct order of printing the connected nodes will be sorted order.
*/

/*
Sample Input:
4 4

0 1
0 3
1 2
2 3

Sample Output:
0 1 3 2
*/


/*
TC : O(V + E)
SC : O(V + E)
*/

#include <bits/stdc++.h>
using namespace std;

void getAdjList(vector<pair<int, int>>& edges, unordered_map<int, set<int>> &adjList) {
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void BFS(int node, unordered_map<int, set<int>>& adjList, unordered_map<int, bool> &visited, vector<int> &ans) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();

        // store frontNode into ans
        ans.push_back(frontNode);

        // traverse all neighbours of frontNode
        for(auto i : adjList[frontNode]) { // traversing adjacency list of 'frontNode'
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here

    // vertex --> total no. of vertices/nodes

    vector<int> ans;

    unordered_map<int, set<int>> adjList; // we are using 'set' instead of 'list' because we want answer in sorted order
    unordered_map<int, bool> visited; // to mark a particular node as visited after visiting that node

    getAdjList(edges, adjList); // store adjacency list in 'adjList'

    // for connected graph --> no need of for loop, directly call BFS() for 0th node

    // traverse all components of disconnected graph
    for (int i = 0; i < vertex; i++) {
        if(!visited[i]) {
            BFS(i, adjList, visited, ans);
        }
    }

    return ans;
}

int main() {
    
    return 0;
}