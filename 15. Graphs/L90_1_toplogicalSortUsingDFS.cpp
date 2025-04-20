// Topological sort using DFS
// GFG : https://www.geeksforgeeks.org/problems/topological-sort/1
// CodeStudio : https://www.codingninjas.com/codestudio/problems/topological-sort_982938

/*
Topological sorting is a linear ordering of the vertices in a directed acyclic graph (DAG) such that for 
every directed edge (u, v), vertex u comes before vertex v in the ordering. It's used to represent tasks 
or dependencies in a way that ensures all prerequisites are completed before a task is started, making it 
a fundamental concept in project scheduling and dependency management.
*/

#include <bits/stdc++.h> 
using namespace std;


// metho-1 : DFS using 2 visied array [vis, pathVis]
/*
TC : O(V+E)
SC : O(3V)
*/
class Solution {
    bool DFS(int node, vector<int> adj[], vector<bool>& vis, vector<bool>& pathVis, stack<int>& st) {
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto nbr : adj[node]) {
            if(!vis[nbr]) {
                if(DFS(nbr, adj, vis, pathVis, st)) return true;
            }
            else if(pathVis[nbr]) {
                return true;
            }
        }
        
        pathVis[node] = 0;
		st.push(node);
		return false;
    }
    
public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V, 0);
        vector<bool> pathVis(V, 0);
		stack<int> st;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(DFS(i, adj, vis, pathVis, st)) return {}; // topo sort NOT POSSIBLE
            }
        }
		
	    vector<int> topo;
	    while(!st.empty()) {
	        topo.emplace_back(st.top());
	        st.pop();
	    }
	    return topo;
    }
};


/*
TC : O(V+E)
SC : O(2V)
*/
// method-0
// problem with this code : it'll fail for DCG
// so, for that cases, we have to integrate the code for cycle detection in directed graph
class Solution {
    void DFS(int node, vector<int> adj[], vector<bool>& vis, stack<int>& st) {
        vis[node] = 1;
        for(auto nbr : adj[node]) {
            if(!vis[nbr]) {
                DFS(nbr, adj, vis, st);
            }
        }
        st.push(node);
    }
    
public:
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<bool> vis(V, 0);
	    stack<int> st;
	    for(int i = 0; i < V; i++) {
	        if(!vis[i]) {
	            DFS(i, adj, vis, st);
	        }
	    }
	    
	    vector<int> topo;
	    while(!st.empty()) {
	        topo.emplace_back(st.top());
	        st.pop();
	    }
	    return topo;
	}
};


int main() {
    
    return 0;
}