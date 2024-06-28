// 1791. Find Center of Star Graph
// LeetCode : https://leetcode.com/problems/find-center-of-star-graph/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> count(n+2, 0);
        for(auto edge : edges) {
            count[edge[0]]++;
            count[edge[1]]++;
        }
        for(int i = 1; i <= n+1; i++) {
            if(count[i] == n) return i;
        }
        return -1;
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}