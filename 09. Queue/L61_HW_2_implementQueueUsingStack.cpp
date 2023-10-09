// 232. Implement Queue using Stacks
// LeetCode : https://leetcode.com/problems/implement-queue-using-stacks/

#include<iostream>
#include<stack>
using namespace std;

// TC : O(1) amortised, SC : O(N)
class MyQueue {
    stack<int> s1;
    stack<int> s2;
    public:
    MyQueue() {
    }
    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if(!s2.empty()) {
            int val = s2.top();
            s2.pop();
            return val;
        }
        else {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            int val = s2.top();
            s2.pop();
            return val;
        }
    }
    
    int peek() {
        if(!s2.empty()) {
            return s2.top();
        }
        else {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    
    bool empty() {
        if(s1.empty() && s2.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};

// TC : O(N), SC : O(N)
/*
class MyQueue {
    stack<int> s1; // main stack
    stack<int> s2; // helping stack
public:
    MyQueue() {
    }
    
    void push(int x) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int val = s1.top();
        s1.pop();
        return val;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};
*/

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
    
    return 0;
}