// Hash Map

#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main() {
    // creation
    unordered_map<string, int> m; // unordered map
    
    // map<string, int> m; // ordered map



    // insertion

    // 1
    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);

    // 2
    pair<string, int> p2("love", 2);
    m.insert(p2);

    // 3
    m["mera"] = 1;



    // search

    cout << m["mera"] << endl;
    cout << m["love"] << endl;
    cout << m.at("babbar") << endl;

    // cout << m.at("xyz") << endl; // agar entry nhi hai to error dega ('std::out_of_range')
    cout << m["xyz"] << endl; // agar entry nhi hai to new entry bna dega with val = 0
    
    // size
    cout << "size of map : " << m.size() << endl;

    // to check presence
    cout << "is love present : " << m.count("love") << endl;
    cout << "is Love present : " << m.count("Love") << endl;
    cout << "is bro present : " << m.count("bro") << endl;

    // erase
    m.erase("love");
    cout << "size of map after erasing \"love\" : " << m.size() << endl;

    // print
    cout << endl << "elements in map are : " << endl;
    for(auto i : m) {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;

    // iterator
    cout << endl << "elements in map are : " << endl;
    unordered_map<string, int> :: iterator it = m.begin();
    while(it != m.end()) {
        cout << it->first << " " << it->second << endl;
        it++;
    }
    cout << endl;

    return 0;
}