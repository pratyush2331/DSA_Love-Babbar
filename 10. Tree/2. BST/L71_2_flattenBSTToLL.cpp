// Flatten BST To A Sorted List
// CodeStudio : https://www.codingninjas.com/codestudio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

// it can be solved using Morris Traversal in SC : O(1)


// TC : O(n), SC : O(h); h --> height of BST
void inorderTraversal(TreeNode<int>* curr, TreeNode<int>* &prev) {
    if(curr == NULL)
        return;
    
    inorderTraversal(curr->left, prev);
    prev->left = NULL;
    prev->right = curr;
    prev = curr;
    inorderTraversal(curr->right, prev);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    // Dummy node
    TreeNode<int>* dummy = new TreeNode<int>(-1);

    // Pointer to previous element
    TreeNode<int>* prev = dummy;

    // calling the inorder traversal
    inorderTraversal(root, prev);

    // now, prev is pointing to last node
    // make left and right to NULL
    prev->left = NULL;
    prev->right = NULL;

    // delete dummy pointer/head
    TreeNode<int>* newRoot = dummy->right;
    delete newRoot;
    
    // return new root
    return newRoot;
}

int main() {
    
    return 0;
}