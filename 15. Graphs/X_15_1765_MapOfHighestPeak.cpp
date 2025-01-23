// 1765. Map of Highest Peak
// LeetCode : https://leetcode.com/problems/map-of-highest-peak/

#include<bits/stdc++.h>
using namespace std;


// multi-source bfs
/*
TC : O(m.n)
SC : O(m.n)
*/
class Solution {
    vector<pair<int, int>> del = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, -1));

        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j]) {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            int x = q.size();
            while(x--) {
                auto [i, j] = q.front();
                q.pop();
                for(auto& d : del) {
                    int i_ = i + d.first;
                    int j_ = j + d.second;
                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && height[i_][j_] == -1) {
                        height[i_][j_] = 1 + height[i][j];
                        q.push({i_, j_});
                    }
                }
            }
        }

        return height;
    }
};


int main() {
    
    return 0;
}