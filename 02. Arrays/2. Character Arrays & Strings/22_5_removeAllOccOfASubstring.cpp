// LeetCode: Remove All Occurences of a Subtring
/*
sample o/p_1:
daabcbaabcbc
abc

sample o/p_1:
dab
-----------------------------------------
sample o/p_2:
axxxxyyyyb
xy

sample o/p_2:
ab
*/

#include<iostream>

using namespace std;

string removeOccurrences(string s, string part) {
    while(s.length()!= 0 && s.find(part) < s.length()) {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main() {
    string s, part;
    cin>>s>>part;

    cout<<removeOccurrences(s, part)<<endl;

    return 0;
}