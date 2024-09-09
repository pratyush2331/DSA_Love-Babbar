// 3276. Select Cells in Grid With Maximum Score
// LeetCode : https://leetcode.com/problems/select-cells-in-grid-with-maximum-score/

#include<bits/stdc++.h>
using namespace std;


// method-2 : dp(memoization) + set + bitmasking
/*
TC : O((mn)*(mn))
SC : O(mn)
*/
class Solution {
    int n; // vector size or set size
    unordered_map<int, vector<int>> mp;  // {ele, row_nos}
    int dp[101][1024];

    int solve(int i, vector<int>& v, int mask) {
        if(i == n) return 0;

        if(dp[i][mask] != -1) return dp[i][mask];

        int currMax = 0;
        // take curr max ele
        for(auto row : mp[v[i]]) {
            if((mask & (1 << row)) == 0) {
                currMax = max(currMax, v[i] + solve(i+1, v, mask | (1 << row)));
            }
        }
        // skip curr max ele
        currMax = max(currMax, solve(i+1, v, mask));
        return dp[i][mask] = currMax;
    }

public:
    int maxScore(vector<vector<int>>& grid) {
        set<int> st;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                st.insert(grid[i][j]);
            }
        }
        vector<int> v;
        for(auto ele : st) {
            v.push_back(ele);
        }
        sort(v.begin(), v.end(), greater<int>());
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                mp[grid[i][j]].push_back(i);
            }
        }
        n = v.size(); // OR st.size()
        memset(dp, -1, sizeof(dp));
        return solve(0, v, 0);
    }
};



// method-1 : recursion + set + bitmasking --> will give TLE
/*
TC : O((mn)^(mn))
SC : O(mn)
*/
/*
class Solution {
    int n; // vector size or set size
    unordered_map<int, vector<int>> mp;  // {ele, row_nos}

    int solve(int i, vector<int>& v, int mask) {
        if(i == n) return 0;

        int currMax = 0;
        // take curr max ele
        for(auto row : mp[v[i]]) {
            if((mask & (1 << row)) == 0) {
                currMax = max(currMax, v[i] + solve(i+1, v, mask | (1 << row)));
            }
        }
        // skip curr max ele
        currMax = max(currMax, solve(i+1, v, mask));
        return currMax;
    }

public:
    int maxScore(vector<vector<int>>& grid) {
        set<int> st;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                st.insert(grid[i][j]);
            }
        }
        vector<int> v;
        for(auto ele : st) {
            v.push_back(ele);
        }
        sort(v.begin(), v.end(), greater<int>());
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                mp[grid[i][j]].push_back(i);
            }
        }
        n = v.size(); // OR st.size()
        return solve(0, v, 0);
    }
};
*/



// method-0 : recursion --> will give TLE
// approach : trying out all possible combinations
/*
TC : O((mn)^(mn))
SC : O(mn)
*/
/*
class Solution {
    int m, n;
    unordered_map<int, int> mp;

    int solve(int i, vector<vector<int>>& grid) {
        if(i == m) return 0;

        int currMax = 0;
        // take from curr row
        for(int j = 0; j < n; j++) {
            if(mp[grid[i][j]] == 0) {
                mp[grid[i][j]] = 1;
                currMax = max(currMax, grid[i][j] + solve(i+1, grid));
                mp[grid[i][j]] = 0;
            }
        }
        // skip curr row
        currMax = max(currMax, solve(i+1, grid));
        return currMax;
    }

public:
    int maxScore(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        return solve(0, grid);
    }
};
*/


int main() {
    
    return 0;
}