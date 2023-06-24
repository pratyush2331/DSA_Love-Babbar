// Reverse Stack Using Recursion9==8 
// CodeStudio : https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int x) {
    if(s.empty()) {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    insertAtBottom(s, x);

    s.push(num);
}

void reverseStack(stack<int> &stack) {
    // base case
    if(stack.empty()) {
        return;
    }

    int num = stack.top();
    stack.pop();

    // recursive call
    reverseStack(stack);

    insertAtBottom(stack, num);
}

int main() {
    
    return 0;
}