// 2924. Find Champion II
// LeetCode : https://leetcode.com/problems/find-champion-ii/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findChampion(int n, vector < vector < int >> & edges) {
        vector < int > vis(n, 0);
        vector < vector < int >> adj(n, vector < int > ());

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].emplace_back(edges[i][1]);
        }

        for (int i = 0; i < n; i++) {
            vis[i]++;
            for (auto nbr: adj[i]) {
                vis[nbr]++;
            }
        }

        vector < int > ans;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 1) ans.emplace_back(i);
        }

        return ans.size() == 1 ? ans[0] : -1;
    }
};


int main() {
    
    return 0;
}