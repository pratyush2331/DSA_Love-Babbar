// 897. Increasing Order Search Tree
// LeetCode : https://leetcode.com/problems/increasing-order-search-tree/

#include<bits/stdc++.h>
using namespace std;


// method-1 : by changing links
/*
TC : O(n)
SC : O(1) // excluding recursive stack space
*/
class Solution {
    TreeNode* dummyNode = new TreeNode(-1);
    TreeNode* curr = dummyNode;

    void inorderTraversal(TreeNode* root) {
        if(root == NULL) return;
        inorderTraversal(root->left);
        root->left = NULL;
        curr->right = root;
        curr = root;
        inorderTraversal(root->right);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        inorderTraversal(root);
        return dummyNode->right;
    }
};



// method-0 : by storing inorder-trvaersal in array and creating a new tree
/*
TC : O(n)
SC : O(n) // excluding recursive stack space
*/
/*
class Solution {
    void inorderTraversal(TreeNode* root, vector<int>& v) {
        if(root == NULL) return;
        inorderTraversal(root->left, v);
        v.push_back(root->val);
        inorderTraversal(root->right, v);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        inorderTraversal(root, v);
        TreeNode* dummyNode = new TreeNode(-1);
        TreeNode *prev = NULL;
        for(auto ele : v) {
            TreeNode* temp = new TreeNode(ele);
            if(prev) {
                prev->right = temp;
            }
            else {
                dummyNode->right = temp;
            }
            prev = temp;
        }
        return dummyNode->right;
    }
};
*/


int main() {

    return 0;
}