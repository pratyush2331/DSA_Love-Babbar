// Q2 (Hard)

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric> // For iota (used in Union-Find initialization)
using namespace std;

// Union-Find (Disjoint Set Union) helper functions
int findParent(vector<int>& parent, int node) {
    if (parent[node] != node) {
        parent[node] = findParent(parent, parent[node]); // Path compression
    }
    return parent[node];
}

void unionNodes(vector<int>& parent, vector<int>& rank, int u, int v) {
    int pu = findParent(parent, u);
    int pv = findParent(parent, v);
    if (pu != pv) {
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
}

vector<int> getMinimumBitwiseAND(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight, vector<vector<int>> queries) {
    // Initialize Union-Find
    vector<int> parent(g_nodes + 1), rank(g_nodes + 1, 0);
    iota(parent.begin(), parent.end(), 0); // Each node is its own parent initially

    // Map to store the minimum AND for each connected component
    unordered_map<int, int> componentMinAnd;

    // Step 1: Build connected components
    int g_edges = g_from.size();
    for (int i = 0; i < g_edges; i++) {
        unionNodes(parent, rank, g_from[i], g_to[i]);
    }

    // Step 2: Calculate minimum AND for each connected component
    for (int i = 0; i < g_edges; i++) {
        int pu = findParent(parent, g_from[i]);
        int pv = findParent(parent, g_to[i]);
        int root = findParent(parent, pu); // Representative of the component
        if (componentMinAnd.find(root) == componentMinAnd.end()) {
            componentMinAnd[root] = g_weight[i];
        } else {
            componentMinAnd[root] &= g_weight[i];
        }
    }

    // Step 3: Process queries
    vector<int> result;
    for (const auto& query : queries) {
        int u = query[0];
        int v = query[1];
        int pu = findParent(parent, u);
        int pv = findParent(parent, v);

        if (pu == pv) {
            result.push_back(componentMinAnd[pu]); // Minimum AND for the component
        } else {
            result.push_back(-1); // Not in the same connected component
        }
    }

    return result;
}


int main() {
    
    return 0;
}