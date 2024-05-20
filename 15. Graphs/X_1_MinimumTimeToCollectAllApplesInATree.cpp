// 1443. Minimum Time to Collect All Apples in a Tree
// LeetCode : https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree

#include<bits/stdc++.h>
using namespace std;


class Solution {
    int dfs(int node, int par, vector<int> adj[], vector<bool>& hasApple) {
        int time = 0;
        for(auto nbr : adj[node]) {
            if(nbr != par) {
                int timeFromChild = dfs(nbr, node, adj, hasApple);
                if(timeFromChild > 0 || hasApple[nbr]) {
                    time += (timeFromChild+2);
                }
            }
        }
        return time;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(0, -1, adj, hasApple);
    }
};


int main() {

    return 0;
}