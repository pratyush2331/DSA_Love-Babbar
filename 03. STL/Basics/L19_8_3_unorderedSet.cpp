// unordered_set - STL
/*
- Duplication is not allowed
- implemented using Hasing
- Elements are in random order
- Random access is not possible, i.e., you cannot get i'th element in O(1)/O(logn).
- Element modification is not possible in set, only insertion & deletion is possible
*/

// Time Complexities
// - insertion : O(1) in avg case, O(N) in worst case
// - deletion : O(1) in avg case, O(N) in worst case
// - Lower/Upper bound : NA

#include<iostream>
#include<unordered_set>
using namespace std;

int main() {
    unordered_set<int> s;

    s.insert(1);
    s.insert(1);
    s.insert(3);
    s.insert(5);
    s.insert(8);

    for(auto i : s) {
        cout << i << " ";
    }
    cout << endl;

    for(auto i = s.begin(); i != s.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    cout << "size : " << s.size() << endl;

    s.erase(3);

    for(auto i = s.begin(); i != s.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    s.erase(s.find(1));

    for(auto i = s.begin(); i != s.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    
    return 0;
}