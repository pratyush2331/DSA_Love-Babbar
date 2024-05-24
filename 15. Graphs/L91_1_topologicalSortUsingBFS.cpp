// Topological sort using BFS - Kahn's Algorithm
// GFG : https://www.geeksforgeeks.org/problems/topological-sort/1
// CodeStudio : https://www.codingninjas.com/codestudio/problems/topological-sort_982938

/*
Topological sorting is a linear ordering of the vertices in a directed acyclic graph (DAG) such that for 
every directed edge (u, v), vertex u comes before vertex v in the ordering. It's used to represent tasks 
or dependencies in a way that ensures all prerequisites are completed before a task is started, making it 
a fundamental concept in project scheduling and dependency management.
*/

/*
TC : O(2 * (V+E))
SC : O(2V)
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> indegree(V, 0); // SC:O(V)
	    for(int i = 0; i < V; i++) { // TC:O(V + E)
	        for(auto nbr : adj[i]) {
	            indegree[nbr]++;
	        }
	    }
	    
	    queue<int> q; // SC:O(V)
	    for(int i = 0; i < V; i++) { // TC:O(V)
	        if(indegree[i] == 0) q.push(i);
	    }
	    
	    vector<int> topo; // SC:O(1)
	    while(!q.empty()) { // TC:O(V + E)
	        int front = q.front();
	        q.pop();
	        topo.emplace_back(front);
	        
	        for(auto nbr : adj[front]) {
	            indegree[nbr]--;
	            if(indegree[nbr] == 0) q.push(nbr);
	        }
	    }
	    return topo;
	}
};


int main() {
    
    return 0;
}