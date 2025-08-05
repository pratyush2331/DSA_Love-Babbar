// Prim's Algorithm
// Minimum Spanning Tree
// GFG : https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include<bits/stdc++.h>
using namespace std;


// for getting sum
/*
TC : O(E.logE)
SC : O(V + E)
*/
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // min-heap: {weight, node}, SC: O(E)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<bool> vis(V, 0); // SC: O(V)
        pq.push({0, 0});
        int sum = 0;
        // TC: O(E.logE) + O(E.logE) = O(E.logE)
        while(!pq.empty()) { // will run for E times
            int wt = pq.top().first; // TC:O(logE)
            int node = pq.top().second;
            pq.pop();
            
            // if node not visited
            // add it to the mst, and mark visited
            if(vis[node]) continue;
            vis[node] = 1;
            sum += wt;
            for(auto nbr : adj[node]) { // will run for E.logE times
                int nbrNode = nbr[0];
                int nbrWt = nbr[1];
                if(!vis[nbrNode]) {
                    pq.push({nbrWt, nbrNode});
                }
            }
        }
        return sum;
    }
};


// for getting sum & mst
/*
TC : O(E.logE)
SC : O(V + E)
*/
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    vector<pair<int, int>> spanningTree(int V, vector<vector<int>> adj[]) {
        // to store the edges of the mst, {parent, node}
        vector<pair<int, int>> mst; // SC:O(V)
        // min-heap: {weight, node, parent}, SC: O(E)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        // vis array, SC: O(V)
        vector<bool> vis(V, 0); // SC: O(V)
        pq.push({0, {0, -1}});
        int sum = 0;
        // TC: O(E.logE) + O(E.logE) = O(E.logE)
        while(!pq.empty()) { // will run for E times
            int wt = pq.top().first; // TC:O(logE)
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();
            
            // if node not visited
            // add it to the mst, and mark visited
            if(vis[node]) continue;
            vis[node] = 1;
            sum += wt; // add weight to sum
            if(parent != -1) { // if parent is not -1
                mst.push_back({parent, node}); // add edge to mst
            }
            for(auto nbr : adj[node]) { // will run for E.logE times
                int nbrNode = nbr[0];
                int nbrWt = nbr[1];
                if(!vis[nbrNode]) {
                    pq.push({nbrWt, {nbrNode, node}});
                }
            }
        }
        return mst;
    }
};


int main() {
    
    return 0;
}