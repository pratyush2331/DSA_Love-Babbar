// 235. Lowest Common Ancestor of a Binary Search Tree
// LeetCode : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

#include<iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// using Iteration - TC : O(n), SC : O(1)
class Solution {
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root != NULL) {
            if(p->val < root->val && q->val < root->val) // ans left part me hai
                root = root->left;
            
            else if(p->val > root->val && q->val > root->val) // ans left part me hai
                root = root->right;
            
            else // ans hai
                return root;
        }
        return NULL;
    }
};

// using Recursion - TC : O(n), SC : O(h)
/*
class Solution {
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root == NULL)
            return NULL;
        
        if(p->val < root->val && q->val < root->val) // ans left part me hai
            return lowestCommonAncestor(root->left, p, q);
        
        if(p->val > root->val && q->val > root->val) // ans left part me hai
            return lowestCommonAncestor(root->right, p, q);
        
        return root; // ans hai
    }
};
*/

int main() {
    
    return 0;
}