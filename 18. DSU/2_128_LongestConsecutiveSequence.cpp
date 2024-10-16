// 128. Longest Consecutive Sequence
// LeetCode : https://leetcode.com/problems/longest-consecutive-sequence/

#include<bits/stdc++.h>
using namespace std;


// by size
class DisjointSet {
public:
    vector<int> size, parent;
    DisjointSet(int n) {
        size.resize(n+1, 1); // will work for both '0' and '1' based indexing
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) { // TC: O(4α) = constant
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]); // path compression
    }

    void unionBySize(int u, int v) { // TC: O(4α) = constant
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        DisjointSet dsu(nums.size());
        unordered_map<int, int> mp;
        // Create DSU with union of consecutive elements
        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(nums[i]) != mp.end()) continue; // Skip duplicates

            mp[nums[i]] = i;  // Map the number to its index in DSU
            if(mp.find(nums[i] - 1) != mp.end()) {
                dsu.unionBySize(i, mp[nums[i] - 1]);
            }
            if(mp.find(nums[i] + 1) != mp.end()) {
                dsu.unionBySize(i, mp[nums[i] + 1]);
            }
        }

        // Find the largest set
        int maxSize = 0;
        for(int i = 0; i < nums.size(); i++) {
            int root = dsu.findUPar(i);
            maxSize = max(maxSize, dsu.size[root]);
        }
        return maxSize;
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