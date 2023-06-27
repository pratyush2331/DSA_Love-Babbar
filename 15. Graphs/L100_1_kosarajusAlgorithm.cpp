// Count Strongly Connected Components (Kosaraju’s Algorithm)
// CodeStudio : https://www.codingninjas.com/studio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151

/*
TC : O(V + E)
SC : O(V + E)
*/

#include<bits/stdc++.h>
using namespace std;


void dfs(int node, unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& vis, stack<int>& st) {
	vis[node] = true;
	
	for(auto nbr : adjList[node]) {
		if(!vis[nbr]) {
			dfs(nbr, adjList, vis, st);
		}
	}
	
	st.push(node);
}

void dfsNormal(int node, unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& vis) {
	vis[node] = true;
	
	for(auto nbr : adjList[node]) {
		if(!vis[nbr]) {
			dfsNormal(nbr, adjList, vis);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.

	// create adjList
	unordered_map<int, list<int>> adjList;
	for(int i = 0; i < edges.size(); i++) {
		int u = edges[i][0];
		int v = edges[i][1];
		
		adjList[u].push_back(v);
		// transposeAdjList[v].push_back(u);
	}
	
	// step-1: topo sort
	stack<int> st;
	unordered_map<int, bool> vis;
	for(int i = 0; i < v; i++) {
		if(!vis[i]) {
			dfs(i, adjList, vis, st);
		}
	}
	
	// step-2: create a transpose graph
	unordered_map<int, list<int>> transposeAdjList;
	for(int i = 0; i < v; i++) {
		vis[i] = false; // reset vis
		for(auto nbr : adjList[i]) {
			transposeAdjList[nbr].push_back(i);
		}
	}
	
	// step-3: dfs call using above ordering
	int count = 0; // to count SCCs
	while(!st.empty()) {
		int top = st.top();
		st.pop();
		
		if(!vis[top]) {
			count++;
			dfsNormal(top, transposeAdjList, vis);
		}
	}
	
	return count;
}


int main() {
    
    return 0;
}