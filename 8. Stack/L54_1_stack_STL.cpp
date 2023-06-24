// stack using STL

#include<iostream>
#include<stack>
using namespace std;

int main() {
    
    // creation of stack
    stack<int> s;

    // push operation
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    // pop operation
    s.pop();
    s.pop();

    // top element
    cout << " top element : " << s.top() << endl;

    // empty or not
    if(s.empty()) {
        cout << " stack is empty !" << endl;
    }
    else {
        cout << " stack is not empty !" << endl;
    }

    cout << " size of stack : " << s.size() << endl;

    return 0;
}