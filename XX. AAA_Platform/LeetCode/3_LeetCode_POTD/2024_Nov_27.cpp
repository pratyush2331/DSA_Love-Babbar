// 3243. Shortest Distance After Road Addition Queries I
// LeetCode : https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    int bfs(int n, vector<int> adj[]) {
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int distance = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int front = q.front();
                q.pop();

                if (front == n - 1) return distance;

                for (auto nbr : adj[front]) {
                    if (!vis[nbr]) {
                        vis[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
            distance++;
        }
        return -1;
    }

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> adj[n];
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        vector<int> ans(queries.size());
        for(int i = 0; i < queries.size(); i++) {
            adj[queries[i][0]].push_back(queries[i][1]);
            ans[i] = bfs(n, adj);
        }
        return ans;
    }
};


int main() {
    
    return 0;
}