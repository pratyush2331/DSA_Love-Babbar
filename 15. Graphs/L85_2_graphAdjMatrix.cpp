// Graph Intro - adjacency matrix

#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class graph {
    public:
    int n;
    // adjacency matrix
    vector<vector<bool>> adj; // SC: O(n^2) = O(V^2)

    graph(int numNodes) {
        n = numNodes;
        adj = vector<vector<bool>>(n, vector<bool>(n, 0));
    }

    void addEdge(T u, T v, bool direction) { // TC: O(1), SC: O(1)
        // direction = 0 --> undirected
        // direction = 1 --> directed

        // create an edge from u to v
        adj[u][v] = 1;

        if(direction == 0) {
            adj[v][u] = 1;
        }
    }

    void printAdjMatrix() { // TC: O(n^2) = O(V^2), SC: O(n^2) = O(V^2)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << adj[i][j] << " ";
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

    graph<int> g(n);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // creating an undirected graph (direction = 0)
        g.addEdge(u, v, 0);
    }

    // printing graph
    cout << "Adjacency Matrix : " << endl;
    g.printAdjMatrix();
    
    return 0;
}