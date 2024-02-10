// Level order traversal in spiral form
// GFG : https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1

#include<bits/stdc++.h>

using namespace std;


void reverse(queue<Node*>& q) {
    stack<Node*> s;
    while(!q.empty()) {
        Node* front = q.front();
        s.push(front);
        q.pop();
    }
    
    while(!s.empty()) {
        Node* top = s.top();
        q.push(top);
        s.pop();
    }
}

vector<int> findSpiral(Node *root) {
    vector<int> ans;
    
    queue<Node*> q;
    q.push(root);
    
    int lvl = 0;
    while(!q.empty()) {
        int x = q.size();
        
        // algo for queue reversing
        reverse(q);
        
        while(x--) {
            Node* front = q.front();
            q.pop();
            
            ans.push_back(front->data);
            
            // if(lvl&1) --> left se right
            // else --> right se left
            
            if(lvl&1) {
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            else {
                if(front->right) q.push(front->right);
                if(front->left) q.push(front->left);
            }
        }
        
        lvl++;
    }
    
    return ans;
}


int main() {
    

    return 0;
}