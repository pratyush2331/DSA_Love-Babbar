// 1472. Design Browser History
// LeetCode : https://leetcode.com/problems/design-browser-history/

#include<bits/stdc++.h>
using namespace std;


// method-2 : using 2 stacks (history, future)
class BrowserHistory {
    stack<string> history; // current and backward urls
    stack<string> future; // forward urls

public:
    BrowserHistory(string homepage) {
        history.push(homepage);
    }
    
    void visit(string url) {
        history.push(url);
        future = stack<string>();
    }
    
    string back(int steps) {
        while(steps-- && history.size() > 1) {
            future.push(history.top());
            history.pop();
        }
        return history.top();
    }
    
    string forward(int steps) {
        while(steps-- && !future.empty()) {
            history.push(future.top());
            future.pop();
        }
        return history.top();
    }
};



// method-1 : using array/vector
class BrowserHistory {
    int pos = 0;
    vector<string>v;

public:
    BrowserHistory(string homepage) {
        v.push_back(homepage);
    }
    
    void visit(string url) {
        ++pos;
        v.resize(pos);
        v.push_back(url);        
    }
    
    string back(int steps) {
        pos = max(0,pos-steps);
        return v[pos];
    }
    
    string forward(int steps) {
        pos = min((int)v.size()-1,pos+steps);
        return v[pos];
    }
};



// method-0 : using DLL
class Node{
public:
    string data;
    Node* prev;
    Node* next;

    Node(string data) {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory {
    Node* root;

public:
    BrowserHistory(string homepage) {
        root = new Node(homepage);
    }
    
    void visit(string url) {
        root->next = new Node(url);
        root->next->prev = root;
        root = root->next;
    }
    
    string back(int steps) {
        while(steps-- && root->prev) {
            root = root->prev;
        }
        return root->data;
    }
    
    string forward(int steps) {
        while(steps-- && root->next) {
            root = root->next;
        }
        return root->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}