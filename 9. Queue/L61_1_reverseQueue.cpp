// Queue Reversal
// GFG: https://practice.geeksforgeeks.org/problems/queue-reversal/1

#include<iostream>
using namespace std;

// using RECURSION, TC: O(n), SC: O(1)
void solve(queue<int>& q) {
    if(q.empty()) {
        return;
    }
    
    int ele = q.front();
    q.pop();
    
    solve(q);
    
    q.push(ele);
}

queue<int> rev(queue<int> q)
{
    solve(q);
    return q;
}

// using STACK, TC: O(n), SC: O(n)
/*
queue<int> rev(queue<int> q)
{
    stack<int> s;
    
    while(!q.empty()) {
        int ele = q.front();
        q.pop();
        s.push(ele);
    }
    
    while(!s.empty()) {
        int ele = s.top();
        s.pop();
        q.push(ele);
    }
    
    return q;
}
*/



int main() {
    
    return 0;
}