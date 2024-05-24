// Detect Cycle In A Directed Graph using BFS/Topo-sort/Kahn's-algorithm
// GFG : https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// CodeStudio : https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626

#include<bits/stdc++.h>
using namespace std;


// metho-0 : topo-sort-BFS : using topo array
/*
TC : O(2 * (V + E))
SC : O(3V)
*/
class Solution {
public:
    bool isCyclic(int V, vector<int> adj[]) {
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
        
        vector<int> topo; // SC:O(V)
        while(!q.empty()) { // TC:O(V + E)
            int front = q.front();
            q.pop();
            topo.emplace_back(front);
            
            for(auto nbr : adj[front]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
        
        return topo.size() < V;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------

// metho-1 : topo-sort-BFS : using cnt
/*
TC : O(2 * (V + E))
SC : O(2V)
*/
class Solution {
public:
    bool isCyclic(int V, vector<int> adj[]) {
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
        
        int cnt = 0; // SC:O(1)
        while(!q.empty()) { // TC:O(V + E)
            int front = q.front();
            q.pop();
            cnt++;
            
            for(auto nbr : adj[front]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
        
        return cnt < V;
    }
};


int main() {
    
    return 0;
}