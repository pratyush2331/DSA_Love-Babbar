// 105. Construct Binary Tree from Preorder and Inorder Traversal
// LeetCode : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
// GFG : https://practice.geeksforgeeks.org/problems/construct-tree-1/1

#include<iostream>
using namespace std;


/*
TC : O(n)
SC : O(n)
*/
class Solution {
    TreeNode* solve(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inMap) {
        // preorder --> NLR
        // inorder --> LNR
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int rootIdxIn = inMap[root->val]; // root idx in inorder
        int x = rootIdxIn - inStart; // number of nodes in left of root in Inorder

        root->left = solve(preorder, preStart + 1, preStart + x, inorder, inStart, rootIdxIn - 1, inMap);
        root->right = solve(preorder, preStart + x + 1, preEnd, inorder, rootIdxIn + 1, inEnd, inMap);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap; // {inorder, idx} for searching element
        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = solve(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        return root;
    }
};


int main() {
    
    return 0;
}