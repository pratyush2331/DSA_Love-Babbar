// Dijkstra's Algorithm - using set and BFS
// CodeStudio : https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469

/*
TC : O(E logV)
SC : O(V + E)
*/

#include <bits/stdc++.h> 
using namespace std;


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Code here
    
    // create adjList
    unordered_map<int, list<pair<int,int>>> adjList;
    for(int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }
    
    // Initialize distance from source to all vertices as infinity
    vector<int> dist(vertices);
    fill_n(dist.begin(), vertices, INT_MAX);

    // set to store nodes and their distances {node, distance}
    // we can also use min heap
    set<pair<int,int>> st;
    // distance from sorce = 0
    dist[source] = 0;
    st.insert(make_pair(0,source));
    
    while(!st.empty()) {
        // fetch top record
        auto top = *(st.begin());
        // pair<int,int> top = st.top();
        st.erase(st.begin());
        
        int nodeDistance = top.first;
        int topNode = top.second;
        
        // traverse neighbours
        for(auto neighbor : adjList[topNode]) {
            if(nodeDistance + neighbor.second < dist[neighbor.first]) {
                // check if it's already present in the set
                auto record = st.find(make_pair(dist[neighbor.first],neighbor.first));
                
                // if record found then erase it
                if(record != st.end()) {
                    st.erase(record);
                }
                
                // distance update
                dist[neighbor.first] = nodeDistance + neighbor.second;
                
                // push record in set
                st.insert(make_pair(dist[neighbor.first],neighbor.first));
            }
        }
    }
    
    return dist;
}


int main() {
    
    return 0;
}