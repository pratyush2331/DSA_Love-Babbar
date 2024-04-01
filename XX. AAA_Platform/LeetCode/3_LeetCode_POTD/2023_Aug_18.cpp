// 1615. Maximal Network Rank
// LeetCode : https://leetcode.com/problems/maximal-network-rank/

#include<iostream>
using namespace std;


class Solution {
    public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // preparing adjMatrix
        vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
        vector<int> indegree(n, 0);
        for(auto road : roads) {
            int u = road[0];
            int v = road[1];

            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;

            indegree[u]++;
            indegree[v]++;
        }

        // caculating network rank
        int ans = 0;
        vector<int> network_rank(n);
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                network_rank[i] = indegree[i] + indegree[j] - adjMatrix[i][j];
                ans = max(ans, network_rank[i]);
            }
        }

        // returning the maximum
        return ans;
    }
};


int main() {
    
    return 0;
}