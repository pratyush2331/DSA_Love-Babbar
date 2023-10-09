// C++ Stack in STL
// Operations: push(), pop(), top()

#include<iostream>
#include<stack>

using namespace std;

int main() {
    stack<string> s;

    s.push("Love");
    s.push("Babbar");
    s.push("Kumar");

    cout<<"Size before pop -> "<<s.size()<<endl;

    cout<<"Top element -> "<<s.top()<<endl;

    s.pop();

    cout<<"Top element -> "<<s.top()<<endl;

    cout<<"Size after pop -> "<<s.size()<<endl;

    cout<<"Empty or not -> "<<s.empty()<<endl;

    return 0;
}