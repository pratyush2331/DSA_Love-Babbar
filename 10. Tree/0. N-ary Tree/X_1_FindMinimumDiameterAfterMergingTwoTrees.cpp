// 3203. Find Minimum Diameter After Merging Two Trees
// LeetCode : https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/

#include<bits/stdc++.h>
using namespace std;


// method : little modifications to code of diameter of binary tree
/*
TC : O(V1+E1 + V2+E2) = O(V1+V2)
SC : O(V1+2.E1 + V2+2.E2) = O(V1+V2)
where, E = V-1
*/
class Solution {
    int solve(int node, int parent, unordered_map<int, vector<int>>& adj, int& diameter) {
        int longest = 0, secondLongest = 0;
        for(int nbr : adj[node]) {
            if(nbr != parent) {
                int pathLength = solve(nbr, node, adj, diameter);

                if(pathLength > longest) {
                    secondLongest = longest;
                    longest = pathLength;
                }
                else if(pathLength > secondLongest) {
                    secondLongest = pathLength;
                }
            }
        }
        diameter = max(diameter, longest + secondLongest);
        return 1 + longest;
    }

    int findDiameter(unordered_map<int, vector<int>>& adj) {
        int diameter = 0;
        solve(0, -1, adj, diameter);
        return diameter;
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1, adj2; // SC:O(V1+2.E1 + V2+2.E2) = O(V1+V2)

        for(auto edge : edges1) { // TC:O(E1)
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for(auto edge : edges2) { // TC:O(E2)
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        int d1 = findDiameter(adj1); // TC:O(V1+E1)
        int d2 = findDiameter(adj2); // TC:O(V2+E2)
        int d12 = ceil((double)d1 / 2) + ceil((double)d2 / 2) + 1;

        return max(d12, max(d1, d2));
    }
};


int main() {
    
    return 0;
}