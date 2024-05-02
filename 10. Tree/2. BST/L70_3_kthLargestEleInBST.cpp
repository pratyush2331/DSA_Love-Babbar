#include<iostream>
using namespace std;

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Kth largest element in BST
// GFG : https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
// using Reverse Morris Traversal (Inorder) - TC : O(n), SC : O(1)
class Solution
{
    int reverseMorrisTraversal(Node* root, int k) {
        if(root == NULL)
            return -1;
            
        Node *current, *successor;
        current = root;
        
        int i = 0;
        
        while(current) {
            if(current->right == NULL) {
                i++;
                if(i == k)
                    return current->data;
                current = current->left;
            }
            else {
                successor = current->right;
                while(successor->left != NULL && successor->left != current) {
                    successor = successor->left;
                }
                
                // temp link creation
                if(successor->left == NULL) {
                    successor->left = current;
                    current = current->right;
                }
                // temp link deletion
                else {
                    successor->left = NULL;
                    i++;
                    if(i == k)
                        return current->data;
                    current = current->left;
                }
            }
        }
        
        return -1;
    }
    
    public:
    int kthLargest(Node *root, int k) {
        return reverseMorrisTraversal(root, k);
    }
};


// 230. Kth Smallest Element in a BST
// LeetCode : https://leetcode.com/problems/kth-smallest-element-in-a-bst
// using Inorder Traversal - TC : O(n), SC : O(height)
class Solution {
    void inorderTraversal(TreeNode* root, int& k, int& ans) {
        if(root == NULL) return;
        inorderTraversal(root->left, k, ans);
        k--;
        if(k == 0) {
            ans = root->val;
            return;
        }
        inorderTraversal(root->right, k, ans);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        inorderTraversal(root, k, ans);
        return ans;
    }
};


int main() {
    
    return 0;
}