// C++ list in STL
// List is dynamic
// List in STL is implemented using doubly linked list
// Elements in List is not stored in contiguous memory location
// It provides only sequential access. Random Access to any middle element is not possible
// list is not stored in sorted way
// list can store duplicates

#include<iostream>
#include<list>

using namespace std;

int main() {
    list<int> l;

    l.push_back(1);
    l.push_front(0);
    l.push_back(2);
    l.push_back(10);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);

    cout<<"Print l"<<endl;
    for(int i : l) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;

    l.erase(l.begin());
    
    cout<<"After erase"<<endl;
    for(int i : l) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;

    l.pop_back();

    cout<<"Print l"<<endl;
    for(int i : l) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;

    l.pop_front();
    
    cout<<"Print l"<<endl;
    for(int i : l) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;

    cout<<"size -> "<<l.size()<<endl;
    cout<<endl;

    list<int> a(5);               // it'll initialize all elements with 0, by default
    cout<<"Print a"<<endl;
    for(int i : a) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;

    list<int> b(5, 100);          // initializing all elements with 100
    cout<<"Print b"<<endl;
    for(int i : b) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;

    list<int> c(l);               // making copy of l vector
    cout<<"Print c"<<endl;
    for(int i : c) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;

    return 0;
}