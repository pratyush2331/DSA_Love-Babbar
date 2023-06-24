// multiset - STL
// -same as set
//only diff is : can contains duplicates

#include<iostream>
#include<set>
using namespace std;

int main() {
    multiset<int> s;

    s.insert(1);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(5);

    for(auto i : s) {
        cout << i << " ";
    }
    cout << endl;

    // s.erase(3); // it erases all occurences of 3

    s.erase(s.find(3)); // it erases only first occ of 3
    // s.erase(s.lower_bound(3)); // can use lower_bound() inside erase() function
    // s.erase(s.upper_bound(3)); // can use upper_bound() inside erase() function

    for(auto i : s) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}