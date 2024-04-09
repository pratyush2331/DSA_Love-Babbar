// 114. Flatten Binary Tree to Linked List
// LeetCode : https://leetcode.com/problems/flatten-binary-tree-to-linked-list
// GFG : https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

/*
Given the root of a binary tree, flatten the tree into a "linked list":
    1. The "linked list" should use the same Node class where the right child pointer points to the next node in the list and the left child pointer is always null.
    2. The "linked list" should be in the same order as a pre-order traversal of the binary tree.
*/

#include<iostream>
using namespace std;


// method-3 : using preorder morris-traversal
/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        TreeNode *curr = root, *pred;
        while(curr) {
            if(curr->left) {
                pred = curr->left;
                while(pred->right) {
                    pred = pred->right;
                }
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};


// method-2 : using stack and reverse-preorder-traversal
/*
TC : O(n)
SC : O(n)
*/
/*
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
            if(!st.empty()) curr->right = st.top();
            curr->left = NULL;
        }
    }
};
*/


// method-1 : using reverse-pre-order-traversal
/*
TC : O(n)
SC : O(n)
*/
/*
class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};
*/


// method-0 : using post-order-traversal
/*
TC : O(n)
SC : O(n)
*/
/*
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flatten(root->left);
        flatten(root->right);
        if(root->left) {
            TreeNode* temp = root->right;
            root->right = root->left;
            TreeNode* pred = root->left;
            while(pred->right) {
                pred = pred->right;
            }
            pred->right = temp;
            root->left = NULL;
        }
    }
};
*/


int main() {
    
    return 0;
}