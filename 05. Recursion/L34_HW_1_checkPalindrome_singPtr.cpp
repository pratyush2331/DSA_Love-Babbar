// Check Palindrome using recursion

#include<iostream>
using namespace std;

bool checkPalindrome(string str, int s) {
    // base case - 1
    if(s > str.length()-1-s) {
        return 1;
    }

    // base case - 2
    if(str[s] != str[str.length()-1-s]) {
        return 0;
    }

    s++;

    // recurrence relation
    return checkPalindrome(str, s);
}

int main() {
    string str;
    getline(cin, str);

    cout << "Palindome or not : " << checkPalindrome(str, 0) << endl;

    return 0;
}