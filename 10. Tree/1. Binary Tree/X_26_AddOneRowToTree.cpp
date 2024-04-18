// 623. Add One Row to Tree
// LeetCode : https://leetcode.com/problems/add-one-row-to-tree

#include<bits/stdc++.h>
using namespace std;


class Solution {
    void dfsTraversal(TreeNode* root, int val, int depth) {
        if(root == NULL) return;
        if(depth == 1) {
            TreeNode* newNode1 = new TreeNode(val);
            newNode1->left = root->left;
            root->left = newNode1;
            
            TreeNode* newNode2 = new TreeNode(val);
            newNode2->right = root->right;
            root->right = newNode2;
            return; // no need to go in further depth
        }
        dfsTraversal(root->left, val, depth-1);
        dfsTraversal(root->right, val, depth-1);
    }

public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        depth--; // depth'll start from zero
        if(depth == 0) { // edge case
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        dfsTraversal(root, val, depth);
        return root;
    }
};


int main() {

    return 0;
}