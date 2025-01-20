// 2661. First Completely Painted Row or Column
// LeetCode : https://leetcode.com/problems/first-completely-painted-row-or-column/

#include<bits/stdc++.h>
using namespace std;


/*
TC : O(m.n) + O(m.n)
SC : O(m.n) + O(m+n)
*/
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        unordered_map<int, pair<int, int>> mp; // {ele, {i, j}}, SC:O(m.n)
        for(int i = 0; i < m; i++) { // TC:O(m.n)
            for(int j = 0; j < n; j++) {
                mp[mat[i][j]] = {i, j};
            }
        }

        vector<int> rows(m, n), cols(n, m); // will track number of visited cells, SC:O(m+n)
        for(int i = 0; i < arr.size(); i++) { // TC:O(m.n)
            int i_ = mp[arr[i]].first;
            int j_ = mp[arr[i]].second;
            rows[i_]--;
            cols[j_]--;
            if(rows[i_] == 0 || cols[j_] == 0) return i;
        }
        return -1;
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