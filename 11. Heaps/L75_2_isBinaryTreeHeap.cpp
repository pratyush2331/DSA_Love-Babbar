// Is Binary Tree Heap
// GFG : https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1

/*
Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.
*/

#include<iostream>
using namespace std;

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

// TC : O(n)+O(n)+O(n) = O(n), SC : O(h)+O(h)+O(h) = O(h)

class Solution {
    int countNodes(struct Node* root) { // TC : O(n), SC : O(h)
        if(root == NULL) {
            return 0;
        }
        
        int ans = countNodes(root->left) + countNodes(root->right) + 1;
        return ans;
    }
    
    bool isCBT(struct Node* root, int index, int nodeCount) { // TC : O(n), SC : O(h)
        if(root == NULL) {
            return true;
        }
        
        if(index >= nodeCount) {
            return false;
        }
        else {
            bool left = isCBT(root->left, 2*index+1, nodeCount);
            bool right = isCBT(root->right, 2*index+2, nodeCount);
            return (left && right);
        }
    }
    
    bool isMaxOrder(struct Node* root) { // TC : O(n), SC : O(h)
        if(root->left == NULL && root->right == NULL) {
            return true;
        }
        
        if(root->right == NULL) {
            return root->data > root->left->data;
        }
        else {
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            return ((left && right) && (root->data > root->left->data && root->data > root->right->data));
        }
    }
    
    public:
    bool isHeap(struct Node* root) {
        // code here
        int index = 0;
        int nodeCount = countNodes(root);
        if(isCBT(root, index, nodeCount) && isMaxOrder(root)) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    
    return 0;
}