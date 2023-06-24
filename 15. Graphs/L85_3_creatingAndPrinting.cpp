// Creating and Printing
// CodeStudio : https://www.codingninjas.com/codestudio/problems/create-a-graph-and-print-it_1214551

/*
Given - undirected graph of edges(u,v)

Task - create and print adjacency list
*/

/*
Input: 
4 6

0 1
0 2
0 3
1 2
1 3
2 3

Output: 
0 1 2 3
1 0 2 3
2 0 1 3
3 0 1 2
*/

#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>>& edges) {
    // Write your code here.

    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++) {
        adj[i].push_back(i);
    }

    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    return adj;
}

int main() {
    
    return 0;
}