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
            if(p->val < root->val && q->val < root->val) root = root->left;
            else if(p->val > root->val && q->val > root->val) root = root->right;
            else return root;
        }
        return NULL;
    }
};

// using Recursion - TC : O(n), SC : O(h)
/*
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
        else if(p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
        else return root;
    }
};
*/

int main() {
    
    return 0;
}