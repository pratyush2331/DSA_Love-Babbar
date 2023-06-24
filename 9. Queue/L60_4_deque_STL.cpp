// Deque using STL

#include<iostream>
#include<queue>
// #include<dequeue>

using namespace std;

int main() {
    deque<int> d;

    d.push_front(12);
    d.push_back(14);

    cout << d.front() << endl;
    cout << d.back() << endl;

    d.pop_front();

    cout << d.front() << endl;
    cout << d.back() << endl;

    d.pop_front();

    if(d.empty()) {
        cout << " Queue is Empty " << endl;
    }
    else {
        cout << " Queue is not empty " << endl;
    }

    return 0;
}