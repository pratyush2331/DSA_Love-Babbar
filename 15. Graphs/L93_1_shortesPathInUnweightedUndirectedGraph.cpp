// Shortest path in an unweighted undirected graph
// CodeStudio : https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297

// Approach : using BFS
/*
TC : O(V+E)
SC : O(V+E)
*/

#include<bits/stdc++.h>
using namespace std;


vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	// Write your code here
	// n -> vertices
	// m -> edges
	// s -> source
	// t -> destination
	
	// create adjList
	unordered_map<int, list<int>> adjList;
	for(int i = 0; i < m; i++) {
		int u = edges[i].first;
		int v = edges[i].second;

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	// do BFS
	unordered_map<int, bool> visited;
	unordered_map<int, int> parent;
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while(!q.empty()) {
		int frontNode = q.front();
		q.pop();

		for(auto i : adjList[frontNode]) {
			if(!visited[i]) {
				q.push(i);
				visited[i] = true;
				parent[i] = frontNode;
			}
		}
	}

	// prepare shortest path
	vector<int> ans;
	int currNode = t;
	ans.push_back(t);

	while(currNode != s) {
		currNode = parent[currNode];
		ans.push_back(currNode);
	}

	// reverse ans vector
	reverse(ans.begin(), ans.end());
	return ans;
}


int main() {
    
    return 0;
}