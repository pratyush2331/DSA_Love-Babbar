// 1631. Path With Minimum Effort
// LeetCode : https://leetcode.com/problems/path-with-minimum-effort/

#include<bits/stdc++.h>
using namespace std;


// method-1 : OPTIMAL : with priority queue (Dijkstra's algorithm)
/*
TC : O(m * n * 4 * log(m * n)) = O(m * n * log(m * n))
SC : O(m * n)
*/
class Solution {
    vector<pair<int, int>> del = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // SC:O(1)

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        // min-heap {diff, {x, y}}; SC: O(m * n)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()) { // TC: O(m * n * 4 * log(m * n))
            int diff = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == m-1 && y == n-1) return diff;

            for(int i = 0; i < 4; i++) { // TC:O(1)
                int new_x = x + del[i].first;
                int new_y = y + del[i].second;

                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) {
                    int newEffort = max(diff, abs(heights[x][y] - heights[new_x][new_y]));
                    if(newEffort < dist[new_x][new_y]) {
                        dist[new_x][new_y] = newEffort;
                        pq.push({newEffort, {new_x, new_y}});
                    }
                }
            }
        }

        return 0; // unreachable
    }
};


// method-0 : Brute Force : with queue (simple BFS)
/*
TC : O(m * n * 4) = O(m * n)
SC : O(m * n)
*/
// NOTE: This method is not optimal, even though TC is less than method-1, and can lead to TLE for larger inputs.
class Solution {
    vector<pair<int, int>> del = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        queue<pair<int, pair<int, int>>> q; // {diff, {x, y}}
        dist[0][0] = 0;
        q.push({0, {0, 0}});

        while(!q.empty()) {
            int diff = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int new_x = x + del[i].first;
                int new_y = y + del[i].second;

                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) {
                    int newEffort = max(diff, abs(heights[x][y] - heights[new_x][new_y]));
                    if(newEffort < dist[new_x][new_y]) {
                        dist[new_x][new_y] = newEffort;
                        q.push({newEffort, {new_x, new_y}});
                    }
                }
            }
        }

        return dist[m-1][n-1];
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}