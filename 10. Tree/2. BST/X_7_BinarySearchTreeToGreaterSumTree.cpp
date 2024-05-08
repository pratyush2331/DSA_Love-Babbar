// 1038. Binary Search Tree to Greater Sum Tree
// LeetCode : https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree

#include<bits/stdc++.h>
using namespace std;


class Solution {
    void reverseInorder(TreeNode* root, int& sum) {
        if(root == NULL) return;
        reverseInorder(root->right, sum);
        sum += root->val;
        root->val = sum;
        reverseInorder(root->left, sum);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        reverseInorder(root, sum);
        return root;
    }
};


int main() {
    
    return 0;
}