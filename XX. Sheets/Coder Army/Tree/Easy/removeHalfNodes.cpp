// Remove half Nodes
// GFG : https://practice.geeksforgeeks.org/problems/remove-half-nodes/1

#include<bits/stdc++.h>

using namespace std;


// post-order-traversal
Node *RemoveHalfNodes(Node *root) {
    if(root == NULL)
        return NULL;
    
    root->left = RemoveHalfNodes(root->left);
    root->right = RemoveHalfNodes(root->right);
    
    // processing...
    if(root->left == NULL && root->right == NULL) { // leaf node
        return root;
    }
    if(root->left != NULL && root->right != NULL) { // not a leaf node or a half node
        return root;
    }
    if(root->left != NULL && root->right == NULL) { // root is a half node which has only left child
        Node* newNode = root->left;
        free(root);
        return newNode;
    }
    if(root->left == NULL && root->right != NULL) { // root is a half node which has only right child
        Node* newNode = root->right;
        free(root);
        return newNode;
    }
}


int main() {
    

    return 0;
}