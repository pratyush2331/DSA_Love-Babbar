// C++ Deque in STL
// Deque is dynamic
// Elements in Deque is not stored in contiguous memory location

#include<iostream>
#include<deque>

using namespace std;

int main() {
    deque<int> d;

    d.push_back(1);
    d.push_front(0);
    d.push_back(2);
    
    cout<<"Print d"<<endl;
    for(int i : d) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;

    d.pop_back();

    cout<<"Print d"<<endl;
    for(int i : d) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;

    d.pop_front();
    
    cout<<"Print d"<<endl;
    for(int i : d) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;

    d.push_back(2);
    d.push_back(3);
    d.push_back(4);

    cout<<"Print d"<<endl;
    for(int i : d) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;

    cout<<"Element at 1st Index -> "<<d.at(1);
    cout<<endl;
    cout<<endl;

    cout<<"First element -> "<<d.front()<<endl;
    cout<<"Last element -> "<<d.back()<<endl;
    cout<<endl;

    cout<<"Empty or not -> "<<d.empty()<<endl;
    cout<<endl;

    cout<<"Before erase, size -> "<<d.size()<<endl;
    d.erase(d.begin(), d.begin()+1);
    cout<<"After erase, size -> "<<d.size()<<endl;
    cout<<endl;

    cout<<"Print d"<<endl;
    for(int i : d) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;

    return 0;
}