// 404. Sum of Left Leaves
// LeetCode : https://leetcode.com/problems/sum-of-left-leaves

#include<bits/stdc++.h>

using namespace std;


class Solution {
    int preorder(TreeNode* root, bool isLeft) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL && isLeft) {
            return root->val;
        }
        // 1 for left, 0 for right
        return preorder(root->left, 1) + preorder(root->left, 0);
    }

public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return preorder(root, 0);
    }
};


int main() {

    return 0;
}