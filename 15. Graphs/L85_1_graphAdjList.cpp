// Graph Intro - adjacency list

#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;


template<typename T>
class graph {
    public:
    
    // adjacency list
    unordered_map<T, list<T>> adjList; // SC: O(n*(n-1)/2) = O(n^2) = O(V^2)

    void addEdge(T u, T v, bool direction) { // TC: O(1), SC: O(1)
        // direction = 0 --> undirected
        // direction = 1 --> directed

        // create an edge from u to v
        adjList[u].push_back(v);

        if(direction == 0) {
            adjList[v].push_back(u);
        }
    }

    void printAdjList() { // TC: O(V + E), SC: O(V + E)
        for(auto i : adjList) {
            cout << i.first << " -> ";
            for(auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};


int main() {
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;

    int m;
    cout << "Enter the number of edges : ";
    cin >> m;

    graph<int> g;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // creating an undirected graph (direction = 0 --> undirected)
        g.addEdge(u, v, 0);
    }

    // printing graph
    cout << "Adjacency List : " << endl;
    g.printAdjList();
    
    return 0;
}