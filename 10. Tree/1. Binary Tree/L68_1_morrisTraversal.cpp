// Morris Trvaersal --> for Inorder traversal
// LeetCode : https://leetcode.com/problems/binary-tree-inorder-traversal

/*
TC : O(n)
SC : O(1)
*/

#include<iostream>
using namespace std;


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;

        TreeNode *curr = root, *pred;
        while(curr) {
            if(curr->left == NULL) { // when no left part
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else { // if left part is present
                // get predecessor
                pred = curr->left;
                while(pred->right && pred->right != curr) {
                    pred = pred->right;
                }
                
                // temp link creation
                if(pred->right == NULL) {
                    pred->right = curr;
                    curr = curr->left;
                }
                // temp link removal
                else {
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};


int main() {
    
    return 0;
}