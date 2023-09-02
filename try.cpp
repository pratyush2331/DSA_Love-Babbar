// 

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template<typename T>
class graph {
    public:

    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction) {
        adj
    }

    void printAdjList() {

    }
};

int main() {
    int n;
    cout << "Enter no. of nodes : ";
    cin >> n;

    int m;
    cout << "Enter no. of edges : ";
    cin >> m;

    graph<int> g;

    cout << "Enter edges : " << endl;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v, 0);
    }

    cout << "Printing graph : " << endl;
    g.printAdjList();
    
    return 0;
}