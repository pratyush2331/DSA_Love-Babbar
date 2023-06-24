// 1382. Balance a Binary Search Tree
// LeetCode : https://leetcode.com/problems/balance-a-binary-search-tree/

#include<iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// TC : O(n), SC : O(n)
class Solution {
    // SPACE EFFICIENT : storing inorder using morris traversal
    void inorderTraversal(TreeNode* root, vector<int> &arr) {
        if(root == NULL)
            return;
        
        TreeNode *curr, *predecessor;
        curr = root;
        while(curr != NULL) {
            if(curr->left == NULL) {
                // cout << curr->cal << " ";
                arr.push_back(curr->val);
                curr = curr->right;
            }
            else {
                predecessor = curr->left;
                while(predecessor->right != NULL && predecessor->right != curr) {
                    predecessor = predecessor->right;
                }

                // temp link creation
                if(predecessor->right == NULL) {
                    predecessor->right = curr;
                    curr = curr->left;
                }
                // temp link deletion
                else {
                    predecessor->right = NULL;
                    // cout << curr->cal << " ";
                    arr.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
    }

    // storing inorder using recursion
    /*
    void inorderTraversal(TreeNode* root, vector<int> &arr) {
        if(root == NULL)
            return;
        
        inorderTraversal(root->left, arr);
        arr.push_back(root->val);
        inorderTraversal(root->right, arr);
    }
    */

    TreeNode* inorderToBBST(int s, int e, vector<int> &arr) { // & --> to not use extra space in function and during recursion calls
        // base case
        if(s > e)
            return NULL;
        
        // mid nikal lo
        int mid = s + (e-s)/2;
        TreeNode* root = new TreeNode(arr[mid]);

        // left aur right ke liye caal kardo
        root->left = inorderToBBST(s, mid-1, arr);
        root->right = inorderToBBST(mid+1, e, arr);

        // root ko return kardo
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        // store inorder
        vector<int> arr;
        inorderTraversal(root, arr);

        // BBST banalo
        return inorderToBBST(0, arr.size()-1, arr);
    }
};

int main() {
    
    return 0;
}