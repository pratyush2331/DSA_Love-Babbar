// 3249. Count the Number of Good Nodes
// LeetCode : https://leetcode.com/problems/count-the-number-of-good-nodes/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    vector<vector<int>> adj;
    int ans;

    int dfs(int node, int par) {
        int subtreeSize = -1;
        bool isGood = true;
        int totalNodes = 0;

        for(int nbr : adj[node]) {
            if(nbr == par) continue;
            int childSize = dfs(nbr, node);
            if(subtreeSize == -1) {
                subtreeSize = childSize;
            }
            else if(childSize != subtreeSize) {
                isGood = false;
            }
            totalNodes += childSize;
        }

        if(isGood) ans++;
        // cout << node << ": " << totalNodes << "\n";
        return totalNodes + 1;
    }

public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        adj.resize(n);
        for(auto edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }

        ans = 0;
        dfs(0, -1); // 0 -> start_node, -1 -> parent_node
        return ans;
    }
};


int main() {
        
    return 0;
}