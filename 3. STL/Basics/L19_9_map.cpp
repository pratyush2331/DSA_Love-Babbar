// C++ map in STL
// map = key-value pair

#include<iostream>
#include<map>

using namespace std;

int main() {
    map<int, string> m;

    /* insert, erase, find, count    ---->    O(logn)
    because this map (Ordered map) is implemented using Red-Black Tree OR Balanced Tree

    while, Unordered map is implemented using HashTable   ==>   find (Unoredered map) has O(1) time complexity
    */

    m[1] = "Love";           // 1 ---> key,    Love ---> value
    m[13] = "Kumar";
    m[2] = "Babbar";

    m.insert({5, "Bheem"});

    for(auto i : m) {
        cout<<i.first<<" - "<<i.second<<endl;
    }
    cout<<endl;

    cout<<"13 is present or not ? -> "<<m.count(13)<<endl;
    cout<<"-13 is present or not ? -> "<<m.count(-13)<<endl;
    cout<<endl;

    cout<<"Before erase"<<endl;
    for(auto i : m) {
        cout<<i.first<<" - "<<i.second<<endl;
    }
    cout<<endl;

    m.erase(13);

    cout<<"After erase"<<endl;
    for(auto i : m) {
        cout<<i.first<<" - "<<i.second<<endl;
    }
    cout<<endl;

    map<int, string>::iterator it = m.find(5);
    // auto it = m.find(5);

    cout<<"(*it).first -> "<<(*it).first<<endl;
    cout<<endl;

    return 0;
}