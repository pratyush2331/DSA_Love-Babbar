// 2285. Maximum Total Importance of Roads
// LeetCode : https://leetcode.com/problems/maximum-total-importance-of-roads/

#include<bits/stdc++.h>
using namespace std;


// method-1 : optimized
/*
TC : O(n.logn)
SC : O(n)
*/
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        for(auto edge : roads) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        sort(degree.begin(), degree.end());
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += 1LL * (i+1) * degree[i];
        }
        return sum;
    }
};



// method-0 : brute-force
/*
TC : O(n.logn)
SC : O(n)
*/
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n, 0);
        for(auto edge : roads) {
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }
        vector<pair<int,int>> v; // {indeg, idx}
        for(int i = 0 ; i < n; i++) {
            v.push_back({indegree[i], i});
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++) {
            v[i].first = i+1; // idx --> imp ==> imp is assigned based on indegree
        }
        unordered_map<int,int> mp;
        for(auto ele : v) {
            mp[ele.second] = ele.first; // idx --> imp
        }
        long long sum = 0;
        for(auto edge : roads) {
            sum += mp[edge[0]] + mp[edge[1]];
        }
        return sum;
    }
};


int main() {
    
    return 0;
}
