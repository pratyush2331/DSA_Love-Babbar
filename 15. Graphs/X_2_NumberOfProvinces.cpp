// 547. Number of Provinces
// LeetCode : https://leetcode.com/problems/number-of-provinces

/*
TC : O(V) + O(V + 2E)
SC : O(V)
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    void dfs(int node, vector<int> adj[], vector<bool>& vis) {
        vis[node] = 1;
        for(auto nbr : adj[node]) {
            if(!vis[nbr]) {
                dfs(nbr, adj, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n+1];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j]) adj[i+1].push_back(j+1);
            }
        }
        int cnt = 0;
        vector<bool> vis(n+1, 0);
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};


int main() {
    
    return 0;
}