// Redundant Brackets
// CodeStudio : https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473?leftPanelTab=0

#include <bits/stdc++.h> 

bool findRedundantBrackets(string &s)
{
    stack<int> stack;

    for(int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            stack.push(ch);
        }
        else { // ch ya to ')' hai ya 'lower case letter' hai
            if(ch == ')') {
                bool isRedundant = true;
                while(stack.top() != '(') {
                    isRedundant = false;
                    stack.pop();
                }

                if(isRedundant) {
                    return true;
                }
                stack.pop();
            }
        }
    }
    return false;
}

using namespace std;

int main() {
    
    return 0;
}