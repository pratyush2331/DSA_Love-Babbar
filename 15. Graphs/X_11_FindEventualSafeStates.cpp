// 802. Find Eventual Safe States
// LeetCode : https://leetcode.com/problems/find-eventual-safe-states


#include<bits/stdc++.h>
using namespace std;


// method-0 : using DFS --> using 2 arrays
/*
TC : O(V + E)
SC : O(2V)
*/
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


// method-1 : using DFS --> using 1 array
/*
TC : O(V + E)
SC : O(V)
*/
class Solution {
    bool checkDFS(int node, vector<vector<int>>& graph, vector<int>& vis) {
        vis[node] = 2;
        for(auto nbr : graph[node]) {
            if(!vis[nbr]) {
                if(checkDFS(nbr, graph, vis)) return true;
            }
            else if(vis[nbr] == 2) {
                return true;
            }
        }
        vis[node] = 1;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0); // vis, pathVis --> both in same
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                checkDFS(i, graph, vis);
            }
        }

        vector<int> safeNodes;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 1) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};


int main() {
    
    return 0;
}