// Deletion in a Binary Tree
// GFG : https://practice.geeksforgeeks.org/problems/deletion-in-a-binary-tree/1

#include<bits/stdc++.h>

using namespace std;


void preOrderTraversal(Node* root, int key, int val) {
    if(root == NULL)
        return;
    
    // processing...
    if(root->data == key) {
        root->data = val;
        return;
    }
    
    preOrderTraversal(root->left, key, val);
    preOrderTraversal(root->right, key, val);
}

// you are required to complete this function
Node* deletionBT(Node* root, int key) {
    
    // step-1 : find the last node (bottommost and rightmost node) , store it's value and delete it.
    // level-order-traversal
    queue<Node*> q;
    q.push(root);
    
    Node* parentNode = NULL;
    int valToDelete = 0;
    while(!q.empty()) {
        int x = q.size();
        
        while(x--) {
            Node* front = q.front();
            q.pop();
            
            if(front->left) {
                q.push(front->left);
                parentNode = front;
                valToDelete = front->left->data;
            }
            
            if(front->right) {
                q.push(front->right);
                parentNode = front;
                valToDelete = front->right->data;
            }
        }
    }
    
    // got the valToDelete and parentNode.
    // Now delete it.
    if(parentNode->right) {
        parentNode->right = NULL;
    }
    else if(parentNode->left) {
        parentNode->left = NULL;
    }
    
    // step-2 : replace key with valToDelete
    preOrderTraversal(root, key, valToDelete);
    
    // step-3 : return root
    return root;
}


int main() {
    

    return 0;
}