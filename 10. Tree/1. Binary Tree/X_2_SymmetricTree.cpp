// 101. Symmetric Tree
// LeetCode : https://leetcode.com/problems/symmetric-tree

#include<bits/stdc++.h>

using namespace std;


class Solution {
    bool solve(TreeNode* r1, TreeNode* r2) {
        if(r1 == NULL || r2 == NULL) return r1 == r2;

        int left = solve(r1->left, r2->right);
        int right = solve(r1->right, r2->left);
        return left && right && r1->val == r2->val;
    }

public:
    bool isSymmetric(TreeNode* root) {
        return solve(root, root);
    }
};


int main() {
    

    return 0;
}