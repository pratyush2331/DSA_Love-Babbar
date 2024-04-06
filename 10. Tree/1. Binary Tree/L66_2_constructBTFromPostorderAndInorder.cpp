// 106. Construct Binary Tree from Inorder and Postorder Traversal
// LeetCode : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
// GFG : https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

#include<iostream>
using namespace std;


/*
TC : O(n)
SC : O(n)
*/
class Solution {
    TreeNode* solve(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inMap) {
        // postorder --> LRN
        // inorder --> LNR
        if(postStart > postEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int rootIdxIn = inMap[root->val]; // root idx in inorder
        int x = rootIdxIn - inStart; // number of nodes in left of root in Inorder

        root->left = solve(postorder, postStart, postStart + x - 1, inorder, inStart, rootIdxIn - 1, inMap);
        root->right = solve(postorder, postStart + x, postEnd - 1, inorder, rootIdxIn + 1, inEnd, inMap);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap; // {inorder, idx} for searching element
        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = solve(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        return root;
    }
};


int main() {
    
    return 0;
}