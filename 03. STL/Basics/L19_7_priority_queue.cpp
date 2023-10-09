// C++ priority_queue in STL
// Note: By default, C++ creates a max-heap for priority queue

#include<iostream>
#include<queue>

using namespace std;

int main() {
    priority_queue<int> maxi;                                  // max-heap (default)

    priority_queue<int, vector<int>, greater<int>> mini;       // min-heap

    maxi.push(1);
    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);

    cout<<"Print maxi"<<endl;
    int n = maxi.size();
    for(int i = 0; i < n; i++) {
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    cout<<endl;
    cout<<endl;

    mini.push(5);
    mini.push(1);
    mini.push(0);
    mini.push(4);
    mini.push(3);

    cout<<"Print mini"<<endl;
    int m = mini.size();
    for(int i = 0; i < m; i++) {
        cout<<mini.top()<<" ";
        mini.pop();
    }
    cout<<endl;
    cout<<endl;

    cout<<"khaali h kya bhai ?? -> "<<mini.empty()<<endl;
    cout<<endl;

    return 0;
}