// Reverse First K elements of Queue
// GFG : https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // step-1: pop first k elements from q and put into Stack
    stack<int> s;
    for(int i = 0; i < k ; i++) {
        int val = q.front();
        q.pop();
        s.push(val);
    }
    
    // step-2: fetch from stack and push into q
    while(!s.empty()) {
        int val = s.top();
        s.pop();
        q.push(val);
    }
    
    // step-3: fetch first (n-k) element from q and push_back
    int t = q.size() - k;
    while(t--) {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    
    return q;
}

int main() {
    
    return 0;
}