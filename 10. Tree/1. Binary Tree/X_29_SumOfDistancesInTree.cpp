// 834. Sum of Distances in Tree
// LeetCode : https://leetcode.com/problems/sum-of-distances-in-tree

#include<bits/stdc++.h>
using namespace std;


// method-0 : using DFS
/*
TC : O(2n) = O(n)
SC : O(n)
*/
class Solution {
    long root_result = 0; // ans for root node
    vector<int> count_child; // to store 'X' --> no. of child nodes including the node itself
    int N; // making n global

    int dfs_root(int node, int parent, int depth, vector<int> adj[]) {
        root_result += depth;
        int total_node = 1;
        for(int nbr : adj[node]) {
            if(nbr != parent) {
                total_node += dfs_root(nbr, node, depth+1, adj);
            }
        }
        return count_child[node] = total_node;
    }

    void dfs(int node, int parent, vector<int> adj[], vector<int>& ans) {
        for(int nbr : adj[node]) {
            if(nbr != parent) {
                ans[nbr] = ans[node] - count_child[nbr] + (N-count_child[nbr]); // derived formula
                dfs(nbr, node, adj, ans);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n, 0);
        N = n;
        count_child.resize(n,0);

        // creating adjList from edges
        vector<int> adj[n];
        for(auto ele : edges) {
            adj[ele[0]].emplace_back(ele[1]);
            adj[ele[1]].emplace_back(ele[0]);
        }

        // calling dfs for root-0, and calculating ans for root-0
        dfs_root(0, -1, 0, adj);
        // storing answer for root-0
        ans[0] = root_result;
        // calling dfs for root-0, and calculating ans for all other nodes
        dfs(0, -1, adj, ans);

        return ans;
    }
};



// method-0 : using BFS for every node --> will give TLE
/*
TC : O(n^2)
SC : O(n)
*/
/*
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n);

        // creating adjList from edges
        vector<int> adj[n];
        for(auto ele : edges) {
            adj[ele[0]].emplace_back(ele[1]);
            adj[ele[1]].emplace_back(ele[0]);
        }

        for(int i = 0; i < n; i++) {
            queue<int> q;
            q.push(i);
            vector<bool> vis(n, 0);
            vis[i] = 1;
            int dist = 0, lvl = 1;
            while(!q.empty()) {
                int x = q.size();
                while(x--) {
                    int front = q.front();
                    q.pop();
                    for(int nbr : adj[temp]) {
                        if(!vis[nbr]) {
                            q.push(nbr);
                            vis[nbr] = 1;
                            dist += lvl;
                        }
                    }
                }
                lvl++;
            }
            ans[i] = dist;
        }

        return ans;
    }
};
*/


int main() {

    return 0;
}