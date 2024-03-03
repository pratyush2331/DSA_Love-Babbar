// 3067. Count Pairs of Connectable Servers in a Weighted Tree Network
// LeetCode : https://leetcode.com/problems/count-pairs-of-connectable-servers-in-a-weighted-tree-network/

#include<bits/stdc++.h>

using namespace std;


/*
TC : O(n^2)
SC : O(n + E) = O(2n) = O(n)
*/
class Solution {
    unordered_map<int, vector<pair<int, int>>> gr;
    int n, ss, cnt;

    void dfs(int node, int par, int d) {
        if(d%ss == 0) cnt++;
        for(auto [ch, dis] : gr[node]) {
            if(ch != par) {
                dfs(ch, node, d + dis);
            }
        }
    }

public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        n = edges.size() + 1; // no. of nodes/servers.
        ss = signalSpeed; // short form

        for (auto ele : edges) {
            int u = ele[0], v = ele[1], d = ele[2];
            gr[u].push_back({v, d});
            gr[v].push_back({u, d});
        }

        vector<int> fans(n, 0);
        for(int node = 0; node < n; node++) { // going to all nodes --> TC: O(n * n) = O(n^2) --> since, for every node, every other node is visited once.
            int sum = 0;
            vector<int> temp;
            for(auto [ch, d] : gr[node]) {
                cnt = 0;
                dfs(ch, node, d); // O(n)
                temp.push_back(cnt);
                sum += cnt;
            }

            int ans = 0;
            for(auto ele : temp) ans += (sum-ele)*ele;
            fans[node] = ans/2;
        }

        return fans;
    }
};


int main() {
    

    return 0;
}