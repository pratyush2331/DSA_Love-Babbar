// Boundary Traversal of binary tree
// GFG : https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

#include<iostream>
using namespace std;

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    void traverseLeft(Node* root, vector<int> &ans) {
        if((root == NULL) || (root->left == NULL && root->right == NULL)) // if NULL or LEAF Node
            return;
        
        ans.push_back(root->data);
        
        if(root->left)
            traverseLeft(root->left, ans);
        else
            traverseLeft(root->right, ans);
    }
    
    void traverseLeaf(Node* root, vector<int> &ans) { // preorder tarvesral
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL) { // checking: if root node is a leaf node
            ans.push_back(root->data);
            return;
        }
        
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }
    
    void traverseRight(Node* root, vector<int> &ans) {
        if((root == NULL) || (root->left == NULL && root->right == NULL)) // if NULL or LEAF Node
            return;
        
        if(root->right)
            traverseRight(root->right, ans);
        else
            traverseRight(root->left, ans);
        
        // wapas aate wakt print karalo
        ans.push_back(root->data);
    }

public:
    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        
        if(root == NULL) return ans;
        
        ans.push_back(root->data);
        
        // traverse left
        traverseLeft(root->left, ans);
        
        // traverse LEAF Nodes
        // left subtree
        traverseLeaf(root->left, ans);
        // right subtree
        traverseLeaf(root->right, ans);
        
        // traverse right
        traverseRight(root->right, ans);
        
        return ans;
    }
};

int main() {
    
    return 0;
}