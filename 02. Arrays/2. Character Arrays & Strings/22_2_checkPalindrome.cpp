// LeetCode-125: Valid Palindrome
// Coding Ninjas: Check Palindrome
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

/*
sample i/p:
6                         <----------          no. of test case    (not required in this question)
c1 O$d@eeD o1c
N2 i&nJA?a& jnI2n
A1b22Ba
codingninjassajNiNgNidoc
5?36@6?35
aaBBa@

sample o/p:
1
1
0
1
1
0
*/


#include<iostream>

using namespace std;

// 2-pointer approach
bool checkPalindrome(string s)
{
    int n = s.size();
    
    int st = 0, e = n-1;
    while(st < e) {// jab tak (start < end) h
        if(isalnum(s[st]) && isalnum(s[e])) { // if both are alpha-numeric
            if(tolower(s[st]) != tolower(s[e])) { // if not same, return false
                return 0;
            }
            st++; // else start++, end--
            e--;
        }
        else if(!isalnum(s[st])) {
            st++;
        }
        else {
            e--;
        }
    }

    return 1;
}

int main() {
        char s[50];
        cout<<"Enter string: "<<endl;
        gets(s);

        cout<<"Palindrome or not ? "<<checkPalindrome(s)<<endl;

    return 0;
}