// 226. Invert Binary Tree
// LeetCode : https://leetcode.com/problems/invert-binary-tree

#include<bits/stdc++.h>

using namespace std;


class Solution {
    void solve(TreeNode* root) {
        if(root == NULL) return;
        swap(root->left, root->right);
        solve(root->left);
        solve(root->right);
    }

public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};


int main() {
    

    return 0;
}