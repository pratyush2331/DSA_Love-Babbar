// 1008. Construct Binary Search Tree from Preorder Traversal
// LeetCode : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal

#include<iostream>
using namespace std;

/*
TC : O(3n) = O(n)
SC : O(h) --> recursive stack space
*/
class Solution {
    TreeNode* buildBST(vector<int>& preorder, int& i, int upperBound) {
        if(i == preorder.size() || preorder[i] > upperBound) return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = buildBST(preorder, i, root->val);
        root->right = buildBST(preorder, i, upperBound);
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return buildBST(preorder, i, INT_MAX);
    }
};

int main() {
    
    return 0;
}