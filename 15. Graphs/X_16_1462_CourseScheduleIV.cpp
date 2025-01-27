// 1462. Course Schedule IV
// LeetCode : https://leetcode.com/problems/course-schedule-iv/

#include<bits/stdc++.h>
using namespace std;


// method-1 : topo sort variant
/*
TC : O(V^3)
SC : O(V^)
*/
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses); // SC:O(V+E) = O(V^2)
        vector<int> indeg(numCourses); // SC:O(V)
        for(auto& course : prerequisites) { // TC:O(E) = O(V^2)
            adj[course[0]].emplace_back(course[1]);
            indeg[course[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) { // TC:O(V)
            if(indeg[i] == 0) q.push(i);
        }

        vector<unordered_set<int>> preReq(numCourses); // SC:O(V^2)
        while(!q.empty()) { // TC:O(V+E) . O(V) = O(V^2) . O(V) = O(V^3)
            int front = q.front();
            q.pop();

            for(int& nbr : adj[front]) {
                preReq[nbr].insert(front);
                for(int pr : preReq[front]) { // TC:O(V)
                    preReq[nbr].insert(pr);
                }
                if(--indeg[nbr] == 0) q.push(nbr);
            }
        }

        vector<bool> ans(queries.size());
        int i = 0;
        for(auto& qry : queries) { // TC:O(Q)
            ans[i++] = preReq[qry[1]].count(qry[0]); // TC:O(1)
        }
        return ans;
    }
};


// method-0 : simple dfs/bfs for every query
/*
TC : O(V^4)
SC : O(V^2)
*/
class Solution {
    bool dfs(int src, int dest, vector<int> adj[], vector<bool>& vis) {
        vis[src] = 1;
        if(src == dest) return 1;

        bool found = 0;
        for(auto& nbr:  adj[src]) {
            if(!vis[nbr]) found = dfs(nbr, dest, adj, vis);
            if(found) return 1;
        }
        return found;
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> adj[numCourses]; // SC:O(V+E) = O(V^2)
        for(auto& course : prerequisites) { // TC:O(E) = O(V^2)
            adj[course[0]].emplace_back(course[1]);
        }

        vector<bool> ans(queries.size());
        int i = 0;
        for(auto& qry : queries) { // TC:O(Q) . O((V+E)) = O(Q . V^2)
            vector<bool> vis(numCourses, 0);
            ans[i++] = dfs(qry[0], qry[1], adj, vis); // TC:O(V+E) = O(V^2)
        }
        return ans;
    }
};


int main() {
    
    return 0;
}