// Check Palindrome using recursion

#include<iostream>
using namespace std;

bool checkPalindrome(string str, int s, int e) {
    // base case - 1
    if(s > e) {
        return 1;
    }

    // base case - 2
    if(str[s++] != str[e--]) {
        return 0;
    }

    // recurrence relation
    return checkPalindrome(str, s, e);
}

int main() {
    string str;
    getline(cin, str);

    cout << "Palindome or not : " << checkPalindrome(str, 0, str.length()-1) << endl;

    return 0;
}