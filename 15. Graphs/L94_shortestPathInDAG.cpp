// Shortest Path in Weighted Directed Acyclic Graph
// Coding Ninjas Article : https://www.codingninjas.com/codestudio/library/shortest-path-in-a-directed-acyclic-graph

/*
TC : O(V + E)
SC : O(V + E)
*/


#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<stack>

using namespace std;

class Graph {

    public:
    unordered_map<int, list<pair<int,int>>> adjList;
    
    void addEdge(int u, int v, int weight) {
        pair<int,int> p = make_pair(v, weight);
        adjList[u].push_back(p);
    }

    void printAdjList() {
        for(auto i : adjList) {
            cout << i.first << " -> ";
            for(auto j : i.second) {
                cout << "(" << j.first << "," << j.second << "), ";
            }
            cout << endl;
        }
    }

    // for toplogical sort - DFS
    void dfs(int node, unordered_map<int, bool>& visited, stack<int>& s) {
        visited[node] = true;

        for(auto i : adjList[node]) {
            if(!visited[i.first]) {
                dfs(i.first, visited, s);
            }
        }

        s.push(node); // storing toplogical sort in stack 's'
    }

    void getShortestPath(int src, stack<int>& s, vector<int>& dist) {
        dist[src] = 0; // distance from src to src is 0

        while(!s.empty()) {
            int top = s.top();
            s.pop();

            if(dist[top] != INT_MAX) {
                for(auto i : adjList[top]) {
                    if(dist[top] + i.second < dist[i.first]) {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }

};

int main() {
    Graph g;

    // add edge with weight in adjList
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printAdjList();

    int n = 6; // no. of vertices

    // Topological Sort - DFS
    unordered_map<int, bool> visited;
    stack<int> s;
    for(int i = 0; i < n; i++) { // for loop is for disconnected graphs
        if(!visited[i]) {
            g.dfs(i, visited, s);
        }
    }

    // shortest path from "src = 1" will be stored in 'dist' array
    int src = 1;
    vector<int> dist(n);
    fill_n(dist.begin(), n, INT_MAX);

    g.getShortestPath(src, s, dist);

    cout << "asnwer is : ";
    for(int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    
    return 0;
}