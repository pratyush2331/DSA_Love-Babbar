// 102. Binary Tree Level Order Traversal
// LeetCode : https://leetcode.com/problems/binary-tree-level-order-traversal/

#include<iostream>
#include<vector>
#include<queue>
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

/*
TC : O(n)
SC : O(n)
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; // SC:O(1)

        if(root == NULL) return ans;

        queue<TreeNode*> q; // SC:O(n)
        q.push(root);

        while(!q.empty()) { // TC:O(n)
            int x = q.size();
            vector<int> temp;
            while(x--) {
                TreeNode* frontNode = q.front();
                q.pop();

                temp.push_back(frontNode->val);
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

int main() {
    
    return 0;
}