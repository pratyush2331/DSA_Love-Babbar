// C++ Queue in STL
// Operations: push(), pop(), front()

#include<iostream>
#include<queue>

using namespace std;

int main() {
    queue<string> q;

    q.push("Love");
    q.push("Babbar");
    q.push("Kumar");

    cout<<"Size before pop -> "<<q.size()<<endl;

    cout<<"First element -> "<<q.front()<<endl;

    q.pop();

    cout<<"First element -> "<<q.front()<<endl;

    cout<<"Size after pop -> "<<q.size()<<endl;

    cout<<"Empty or not -> "<<q.empty()<<endl;

    return 0;
}