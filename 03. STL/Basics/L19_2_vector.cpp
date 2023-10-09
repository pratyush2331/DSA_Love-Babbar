// C++ Vector in STL
// Vector is dynamic
// Elements in Veector is stored in contiguous memory location

#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> v;     // Size = 0, Capacity = 0
    cout<<"Empty or not -> "<<v.empty()<<endl;
    cout<<"Size -> "<<v.size()<<endl;
    cout<<"Capacity -> "<<v.capacity()<<endl;
    cout<<endl;

    v.push_back(10);    // Size = 1, Capacity = 1
    cout<<"Empty or not -> "<<v.empty()<<endl;
    cout<<"Size -> "<<v.size()<<endl;
    cout<<"Capacity -> "<<v.capacity()<<endl;
    cout<<endl;

    // cout << endl << " at is working or not : " << v.at(0) << endl;

    v.push_back(2);    // Size = 2, Capacity = 2
    cout<<"Size -> "<<v.size()<<endl;
    cout<<"Capacity -> "<<v.capacity()<<endl;
    cout<<endl;

    v.push_back(3);    // Size = 3, Capacity = 4
    cout<<"Size -> "<<v.size()<<endl;
    cout<<"Capacity -> "<<v.capacity()<<endl;
    cout<<endl;

    cout<<"Element at 2nd Index = "<<v.at(2)<<endl;
    cout<<endl;

    cout<<"First element -> "<<v.front()<<endl;
    cout<<"Last element -> "<<v.back()<<endl;
    cout<<endl;

    cout<<"Before pop"<<endl;
    for(int i : v) {
        cout<<i<<" ";
    }
    cout<<endl;

    v.pop_back();

    cout<<"After pop"<<endl;
    for(int i : v) {
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<endl;    // Size = 2, Capacity = 4
    cout<<"Size -> "<<v.size()<<endl;
    cout<<"Capacity -> "<<v.capacity()<<endl;

    v.shrink_to_fit();    // Size = 2, Capacity = 2

    cout<<"Size -> "<<v.size()<<endl;
    cout<<"Capacity -> "<<v.capacity()<<endl;
    cout<<endl;

    v.clear();    // Size = 0, Capacity = 2
    cout<<"Empty or not -> "<<v.empty()<<endl;
    cout<<"Size -> "<<v.size()<<endl;
    cout<<"Capacity -> "<<v.capacity()<<endl;
    cout<<endl;

    vector<int> a(5);              // it'll initialize all elements with 0, by default
    cout<<"print a"<<endl;
    for(int i : a) {
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int> b(5, 1);           // initializing all elements with 1
    cout<<"print b"<<endl;
    for(int i : b) {
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int> c(b);              // making copy of b vector
    cout<<"print c"<<endl;
    for(int i : c) {
        cout<<i<<" ";
    }
    cout<<endl;
}