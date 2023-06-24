// Validate BST (2 Questions - BST && Partial BST)

/*
TC : O(n)
SC : O(h)
*/

#include<iostream>
using namespace std;

// 98. Validate Binary Search Tree
// LeetCode : https://leetcode.com/problems/validate-binary-search-tree/
class Solution {
    bool isBST(TreeNode* root, long min, long max) {
        if(root == NULL)
            return true;
        
        if(root->val > min && root->val < max) {
            bool left = isBST(root->left, min, root->val);
            bool right = isBST(root->right, root->val, max);
            return left && right;
        }
        else {
            return false;
        }
    }

public:
    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
    }
};

// Partial BST
// CodeStudio : https://www.codingninjas.com/codestudio/problems/validate-bst_799483?leftPanelTab=0
/*
bool isBST(BinaryTreeNode<int> *root, int min, int max) {
    if(root == NULL)
        return true;
    
    if(root->data >= min && root->data <= max) {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    else {
        return false;
    }
}

bool validateBST(BinaryTreeNode<int> *root) {
    return isBST(root, INT_MIN, INT_MAX);
}
*/

int main() {
    
    return 0;
}