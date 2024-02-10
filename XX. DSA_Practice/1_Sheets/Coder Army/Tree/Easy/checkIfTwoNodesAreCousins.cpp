// Check if two Nodes are Cousins
// GFG : https://practice.geeksforgeeks.org/problems/check-if-two-nodes-are-cousins/1

#include<bits/stdc++.h>

using namespace std;


// Logic : level-order-traversal
bool isCousins(Node *root, int a, int b) {
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        int x = q.size();
        
        pair<bool, int> aInfo = {0, NULL}; // {isFound, parent}
        pair<bool, int> bInfo = {0, NULL};
        while(x--) {
            Node* front = q.front();
            q.pop();
            
            // processing
            if(front->left) {
                q.push(front->left);
                
                if(front->left->data == a) {
                    aInfo.first = 1;
                    aInfo.second = front->data;
                }
                if(front->left->data == b) {
                    bInfo.first = 1;
                    bInfo.second = front->data;
                }
            }
            
            if(front->right) {
                q.push(front->right);
                
                if(front->right->data == a) {
                    aInfo.first = 1;
                    aInfo.second = front->data;
                }
                if(front->right->data == b) {
                    bInfo.first = 1;
                    bInfo.second = front->data;
                }
            }
        }
        
        if(aInfo.first && bInfo.first) { // enters, only when a and b both are in same level
            return aInfo.second != bInfo.second;
        }
    }
    
    return 0;
}


int main() {
    

    return 0;
}