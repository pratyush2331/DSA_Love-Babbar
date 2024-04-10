// 617. Merge Two Binary Trees
// LeetCode : https://leetcode.com/problems/merge-two-binary-trees

#include<bits/stdc++.h>

using namespace std;


// method-1 : merging both trees
/*
TC : O(n)
SC : O(n) // recursive_call_stack only
*/
class Solution {
    TreeNode* solve(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) {
            return NULL;
        }
        else if(root1 == NULL && root2) {
            return root2;
        }
        else if(root1 && root2 == NULL) {
            return root1;
        }
        else { // we can return any root
            root1->val += root2->val;
            root1->left = solve(root1->left, root2->left);
            root1->right = solve(root1->right, root2->right);
            return root1;
        }
    }

public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return solve(root1, root2);
    }
};


// method-0 : creating new tree
/*
TC : O(n)
SC : O(n) + O(n) // recursive_call_stack + new_tree
*/
/*
class Solution {
    TreeNode* solve(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) {
            return NULL;
        }
        else if(root1 == NULL && root2) {
            TreeNode* newNode = new TreeNode(root2->val);
            newNode->left = solve(NULL, root2->left);
            newNode->right = solve(NULL, root2->right);
            return newNode;
        }
        else if(root1 && root2 == NULL) {
            TreeNode* newNode = new TreeNode(root1->val);
            newNode->left = solve(root1->left, NULL);
            newNode->right = solve(root1->right, NULL);
            return newNode;
        }
        else {
            TreeNode* newNode = new TreeNode(root1->val + root2->val);
            newNode->left = solve(root1->left, root2->left);
            newNode->right = solve(root1->right, root2->right);
            return newNode;
        }
    }

public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return solve(root1, root2);
    }
};
*/


int main() {

    return 0;
}