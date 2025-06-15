// Prim's Algorithm for MST(Minimum Spanning Tree)
// CodeStudio : https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633


#include <bits/stdc++.h>
using namespace std;

// OPTIMIZED APPROACH : using Priority Queue to find min key value
// TC : O(V logV)
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>>& g)
{
    // create adjList
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < m; i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adjList[u].push_back({ v,w });
        adjList[v].push_back({ u,w });
    }

    // 3 Data Structures needed
    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    key[1] = 0;

    // Priority queue to get the vertex with minimum key value
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        mst[u] = true;

        for (auto neighbor : adjList[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if (mst[v] == false && w < key[v]) {
                parent[v] = u;
                key[v] = w;
                pq.push({ w, v });
            }
        }
    }

    // store in ans
    vector<pair<pair<int, int>, int>> ans;
    for (int i = 2; i <= n; i++) {
        ans.push_back({ {parent[i],i}, key[i] });
    }

    return ans;
}


// TC : O(V^2)
/*
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.

    // create adjList
    unordered_map<int, list<pair<int,int>>> adjList;
    for(int i = 0; i < m; i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
    
        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }

    // 3 Data Structures needed
    vector<int> key(n+1, INT_MAX);
    vector<bool> mst(n+1, false);
    vector<int> parent(n+1, -1);

    key[1] = 0;

    for(int i = 1; i < n; i++) { // do for 'n' times
        int mini = INT_MAX;
        int u;

        // get min node
        for(int j = 1; j <= n; j++) {
            if(mst[j] == false && key[j] < mini) {
                u = j;
                mini = key[j];
            }
        }

        // mark min node as 'true'
        mst[u] = true;

        for(auto neighbor : adjList[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if(mst[v] == false && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    // store in ans
    vector<pair<pair<int,int>, int>> ans;
    for(int i = 2; i <= n; i++) {
        ans.push_back({{parent[i],i}, key[i]});
    }

    return ans;
}
*/


int main() {
    
    return 0;
}