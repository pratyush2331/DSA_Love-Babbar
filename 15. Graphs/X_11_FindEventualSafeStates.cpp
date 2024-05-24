// 802. Find Eventual Safe States
// LeetCode : https://leetcode.com/problems/find-eventual-safe-states

/*
TC : O(V + E)
SC : O(2V)
*/

#include<bits/stdc++.h>
using namespace std;


// using DFS
class Solution {
    bool checkDFS(int node, vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto nbr : graph[node]) {
            if(!vis[nbr]) {
                if(checkDFS(nbr, graph, vis, pathVis)) return true;
            }
            else if(pathVis[nbr]) {
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, 0);
        vector<bool> pathVis(n, 0);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                checkDFS(i, graph, vis, pathVis);
            }
        }

        vector<int> safeNodes;
        for(int i = 0; i < n; i++) {
            if(!pathVis[i]) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};


int main() {
    
    return 0;
}