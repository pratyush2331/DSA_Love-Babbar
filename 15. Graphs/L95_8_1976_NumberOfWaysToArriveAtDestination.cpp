// 1976. Number of Ways to Arrive at Destination
// LeetCode Problem Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

#include<bits/stdc++.h>
using namespace std;


// approach : simple Dijkstra + ways[]
/*
TC : O(E.logV)
SC : O(V)
*/
class Solution {
    const int MOD = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        // min heap {dis, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dist(n, 1e15);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto [dis, u] = pq.top();
            pq.pop();

            for(auto [v, wv] : adj[u]) {
                if(dis + wv < dist[v]) {
                    dist[v] = dis + wv;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if(dis + wv == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};


int main() {
    
    return 0;
}