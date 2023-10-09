// set - STL
/*
- Duplication is not allowed
- implemented using BST
- Elements are in sorted order
- Random access is not possible, i.e., you cannot get i'th element in O(1)/O(logn).
- Element modification is not possible in set, only insertion & deletion is possible
*/

#include<iostream>
#include<set>

using namespace std;

int main() {
    /*
    set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);

    // printing the element in the set
    for(auto i : s) {
        cout << i << " ";
    }
    cout << endl;
    for(auto i = s.begin(); i != s.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    // print in reverse
    for(auto i = s.rbegin(); i != s.rend(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    cout << endl;

    cout << "size : " << s.size() << endl;
    */

    /*
    set<int, greater<int>> s1;

    s1.insert(1);
    s1.insert(2);
    s1.insert(2);
    s1.insert(3);

    for(auto i : s1) {
        cout << i << " ";
    }
    cout << endl;
    for(auto i = s1.begin(); i != s1.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    // in reverse order
    for(auto i = s1.rbegin(); i != s1.rend(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    cout << s1.size() << endl;
    */

    /*
    // lower bound & uper bound
    // lower bound : =>
    // upper bound : >
    set<int> s;

    s.insert(1);
    s.insert(5);
    s.insert(8);

    cout << "\nupper bound\n";
    cout << *s.lower_bound(0) << endl;
    cout << *s.lower_bound(1) << endl;
    cout << *s.lower_bound(2) << endl;
    cout << *s.lower_bound(5) << endl;
    cout << *s.lower_bound(8) << endl;
    cout << (s.lower_bound(9) == s.end()) << endl; // element nhi hai to s.end() return kar dega

    cout << "\nlower bound\n";
    cout << *s.upper_bound(0) << endl;
    cout << *s.upper_bound(1) << endl;
    cout << *s.upper_bound(2) << endl;
    cout << *s.upper_bound(5) << endl;
    cout << (s.upper_bound(8) == s.end()) << endl;
    cout << (s.upper_bound(9) == s.end()) << endl;
    */

    // erase() fuunction
    set<int> s;

    s.insert(1);
    s.insert(1);
    s.insert(3);
    s.insert(5);

    for(auto i : s) {
        cout << i << " ";
    }
    cout << endl;

    s.erase(3);

    for(auto i : s) {
        cout << i << " ";
    }
    cout << endl;

    s.erase(s.begin());

    for(auto i : s) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

/*
int main() {
    set<int> s;

    // insert, find, erase, count   --->   O(logn)
    // size, begin, end, empty      --->   O(1)
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(1);
    s.insert(6);
    s.insert(0);
    s.insert(0);
    s.insert(0);
    s.insert(3);

    cout<<"Empty or not -> "<<s.empty()<<endl;
    cout<<endl;

    cout<<"print s"<<endl;
    for(auto i : s) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;

    s.erase(s.begin());
    
    cout<<"After erasing 0th Index element"<<endl;
    for(auto i : s) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;

    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);
    
    cout<<"After erasing 1st Index element"<<endl;
    for(auto i : s) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;

    cout<<"5 is present or not ? -> "<<s.count(5)<<endl;
    cout<<"-5 is present or not ? -> "<<s.count(-5)<<endl;
    cout<<endl;

    set<int>::iterator itr = s.find(5);
    // auto itr = s.find(5);

    cout<<"value present at itr -> "<<*itr<<endl;
    cout<<endl;


    return 0;
}
*/