// Interleave the first half of the queue with second half
// GFG : https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// using Stack, TC : O(n), SC : O(n)
void interLeaveQueue(queue<int>& q) {
    int n = q.size();

    stack<int> s;
    for(int i = 0; i < n/2; i++) { // queue se stack me
        s.push(q.front());
        q.pop();
    }

    for(int i = 0; i < n/2; i++) { // stack se queue me
        q.push(s.top());
        s.pop();
    }

    for(int i = 0; i < n/2; i++) { // queue se queue me
        q.push(q.front());
        q.pop();
    }

    for(int i = 0; i < n/2; i++) { // queue se stack me
        s.push(q.front());
        q.pop();
    }

    for(int i = 0; i < n/2; i++) { // queue aur stack se queue me
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

// using Queue, TC : O(n), SC : O(n)
/*
void interLeaveQueue(queue<int>& q) {
    int n = q.size();

    queue<int> q2; // helping queue
    for(int i = 0; i < n/2; i++) {
        q2.push(q.front());
        q.pop();
    }

    for(int i = 0; i < n/2; i++) {
        q.push(q2.front());
        q2.pop();
        q.push(q.front());
        q.pop();
    }
}
*/

int main() {
    queue<int> q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    interLeaveQueue(q);
    
    int length = q.size();
    for (int i = 0; i < length; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
    return 0;
}