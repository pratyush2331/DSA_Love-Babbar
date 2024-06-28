// 1038. Binary Search Tree to Greater Sum Tree
// LeetCode : https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    int sum;

    void reverseInorder(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        // RNL
        reverseInorder(root->right);
        sum += root->val;
        root->val = sum;
        reverseInorder(root->left);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        sum = 0;
        reverseInorder(root);
        return root;
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}