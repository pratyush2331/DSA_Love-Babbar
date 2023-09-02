// Graph revision

#include<iostream>
using namespace std;

template<typename T>
class graph {
    public:

};

int main() {
    int n;
    cout << "Enter no. of nodes : ";
    cin >> n;

    int m;
    cout << "Enter no. of edges : ";
    cin >> m;

    graph<int> g;

    cout << "enter edges : " << endl;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    cout << "printing graph " << endl;
    g.printAdjList();
    
    return 0;
}