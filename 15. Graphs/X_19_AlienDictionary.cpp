// Alien Dictionary
// GFG : https://www.geeksforgeeks.org/problems/alien-dictionary/1
// LeetCode : https://leetcode.com/problems/alien-dictionary/

#include<bits/stdc++.h>
using namespace std;


// method-1: Topological Sort using DFS
/*
TC : O(n.m)
SC : O(1)
*/
class Solution {
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, string& result) {
        visited[node] = 2; // Mark as visited, path visited
        for (int neighbor : adj[node]) {
            if (visited[neighbor] == 2) return false; // Cycle detected
            if (visited[neighbor] == 0) {
                if (!dfs(neighbor, adj, visited, result)) return false;
            }
        }
        visited[node] = 1; // Mark as visited, path unvisited
        result += (char)(node + 'a');
        return true;
    }

public:
    string findOrder(vector<string>& words) {
        // adjacency list
        vector<vector<int>> adj(26);
        // to track visited and pathVisited
        vector<int> visited(26, 0);
        // tracks which characters are present
        vector<bool> exists(26, false);

        // mark existing characters
        for(const string& word : words) {
            for(char ch : word) {
                exists[ch - 'a'] = true;
            }
        }

        // build the graph from adjacent words
        for (int i = 0; i < words.size() - 1; ++i) {
            string& w1 = words[i];
            string& w2 = words[i + 1];

            int len = min(w1.size(), w2.size());
            int j = 0;
            while (j < len && w1[j] == w2[j]) ++j;
            
            if (j < len) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';
                adj[u].push_back(v);
            }
            else if (w1.size() > w2.size()) {
                return ""; // Invalid case: prefix rule violated
            }
        }

        string result;
        for (int i = 0; i < 26; ++i) {
            if (exists[i] && visited[i] == 0) {
                if (!dfs(i, adj, visited, result)) return ""; // Cycle detected
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};


// method-0: Topological Sort using BFS (Kahn's Algorithm)
/*
TC : O(n.m)
SC : O(1)
*/
class Solution {
    string findTopoSort(vector<vector<int>>& adj, vector<int>& indegree, vector<bool>& exists) {
        queue<int> q;
        for(int i = 0; i < 26; i++) {
            if(exists[i] && indegree[i] == 0) q.push(i);
        }

        string topoSort;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            topoSort += (char)(front + 'a');

            for(int nbr : adj[front]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }

        int totalCharsInExists = 0;
        for(int i = 0; i < 26; i++) totalCharsInExists += exists[i];

        return topoSort.length() == totalCharsInExists ? topoSort : "";
    }

public:
    string findOrder(vector<string>& words) {
        // adjacency list
        vector<vector<int>> adj(26);
        // indegree of each character
        vector<int> indegree(26, 0);
        // tracks which characters are present
        vector<bool> exists(26, false);

        // mark existing characters
        for(const string& word : words) {
            for(char ch : word) {
                exists[ch - 'a'] = true;
            }
        }

        // build the graph from adjacent words
        for(int i = 0; i < words.size() - 1; i++) {
            const string& w1 = words[i];
            const string& w2 = words[i + 1];

            int len = min(w1.size(), w2.size());
            int j = 0;
            while (j < len && w1[j] == w2[j]) j++;

            if(j < len) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';
                adj[u].push_back(v);
                indegree[v]++;
            }
            else if(w1.length() > w2.length()) {
                return ""; // Invalid case: prefix rule violated
            }
        }

        // call modified topoSort function
        return findTopoSort(adj, indegree, exists);
    }
};


int main() {
    
    return 0;
}