// reverse a string using recursion

#include<iostream>
using namespace std;

void reverseString(string& str, int s, int e) {
    // base case
    if(s >= e)
        return ;

    swap(str[s++], str[e--]);

    return reverseString(str, s, e);
}

int main() {
    string str;
    cin >> str;

    cout << endl;

    reverseString(str, 0, str.length()-1);
    
    cout << "After reverse : " << str << endl;

    return 0;
}