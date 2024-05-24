// 785. Is Graph Bipartite?
// LeetCode : https://leetcode.com/problems/is-graph-bipartite

// Bipartite Graph : A graph that can be colored with 2 colors such that no 2 adjacent nodes have the same color.
/*
imp point :
if a graph has-
odd length cycle  -->  not a bipartite graph
even length cycle -->  bipartite graph
linear/no-cycle   -->  bipartite graph
*/
// approach : coloring the graph using any 2 colors by BFS/DFS.

/*
TC : O(V) + O(2E)
SC : O(V)
*/

#include<bits/stdc++.h>
using namespace std;


// method-0 : using BFS
class Solution {
    bool check_BFS(int node, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q; // SC:O(n)
        q.push(node);
        while(!q.empty()) { // TC:O(n)
            int front = q.front();
            q.pop();
            for(auto nbr : graph[front]) {
                if(color[nbr] == -1) {
                    color[nbr] = !color[front];
                    q.push(nbr);
                }
                else if(color[nbr] == color[front]) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1); // SC:O(n)
        for(int i = 0; i < graph.size(); i++) { // checking bipartite for dis-connected components
            if(color[i] == -1) {
                if(!check_BFS(i, graph, color)) return false;
            }
        }
        return true;
    }
};

// ----------------------------------------------------------------------------------------------------------------------------------

// method-1 : using DFS
class Solution {
    bool check_DFS(int node, int col, vector<vector<int>>& graph, vector<int>& color) {
        color[node] = col;
        for(auto nbr : graph[node]) {
            if(color[nbr] == -1) {
                if(!check_DFS(nbr, !col, graph, color)) return false;
            }
            else if(color[nbr] == col) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1); // SC:O(n)
        for(int i = 0; i < graph.size(); i++) { // checking bipartite for dis-connected components
            if(color[i] == -1) {
                if(!check_DFS(i, 0, graph, color)) return false;
            }
        }
        return true;
    }
};


int main() {
    
    return 0;
}